#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#define TOTAL_POOL_SIZE (2 * 1024 * 1024) // 2MB
#define MIN_BLOCK_SIZE 1024               // 1KB
#define MAX_LEVELS 12                     // log2(2MB / 1KB) + 1

typedef struct BuddyBlock {
    int is_free;
    int level;
    struct BuddyBlock* next;
} BuddyBlock;

static unsigned char* base_memory = NULL;
static BuddyBlock* free_lists[MAX_LEVELS] = {0};

// Utility functions
static int size_to_level(size_t size) {
    size_t s = MIN_BLOCK_SIZE;
    for (int i = 0; i < MAX_LEVELS; i++, s <<= 1) {
        if (size <= s) return i;
    }
    return -1;
}

static size_t level_to_size(int level) {
    return MIN_BLOCK_SIZE << level;
}

// Splits a block from a higher level to the desired level
static void split_block(int level) {
    if (level >= MAX_LEVELS - 1 || !free_lists[level + 1]) return;

    BuddyBlock* big = free_lists[level + 1];
    free_lists[level + 1] = big->next;

    size_t size = level_to_size(level);
    BuddyBlock* b1 = (BuddyBlock*)big;
    BuddyBlock* b2 = (BuddyBlock*)((unsigned char*)b1 + size);

    b1->is_free = 1;
    b1->level = level;
    b1->next = b2;

    b2->is_free = 1;
    b2->level = level;
    b2->next = free_lists[level];

    free_lists[level] = b1;
}

// Initialize memory pool and top-level free block
void init_buddy_allocator() {
    base_memory = mmap(NULL, TOTAL_POOL_SIZE, PROT_READ | PROT_WRITE,
                       MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (base_memory == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    BuddyBlock* initial = (BuddyBlock*)base_memory;
    initial->is_free = 1;
    initial->level = MAX_LEVELS - 1;
    initial->next = NULL;

    free_lists[MAX_LEVELS - 1] = initial;

    printf("Buddy allocator initialized with %u bytes.\n", TOTAL_POOL_SIZE);
}

// Allocate memory using the buddy system
void* xmalloc(size_t size) {
    if (size == 0 || size > TOTAL_POOL_SIZE) return NULL;

    int level = size_to_level(size + sizeof(BuddyBlock));
    if (level == -1) return NULL;

    for (int i = level; i < MAX_LEVELS; i++) {
        if (free_lists[i]) {
            while (i > level) {
                split_block(i - 1);
                i--;
            }

            BuddyBlock* block = free_lists[level];
            free_lists[level] = block->next;
            block->is_free = 0;
            block->next = NULL;

            return (unsigned char*)block + sizeof(BuddyBlock);
        }
    }

    return NULL;
}

// Try to merge a block with its buddy
static void try_merge(BuddyBlock* block) {
    size_t offset = (unsigned char*)block - base_memory;
    size_t size = level_to_size(block->level);
    size_t buddy_offset = offset ^ size;
    BuddyBlock* buddy = (BuddyBlock*)(base_memory + buddy_offset);

    if ((unsigned char*)buddy < base_memory ||
        (unsigned char*)buddy >= base_memory + TOTAL_POOL_SIZE ||
        !buddy->is_free || buddy->level != block->level) {
        return;
    }

    // Remove both from the free list
    BuddyBlock** curr = &free_lists[block->level];
    while (*curr && *curr != block) curr = &((*curr)->next);
    if (*curr) *curr = block->next;

    curr = &free_lists[buddy->level];
    while (*curr && *curr != buddy) curr = &((*curr)->next);
    if (*curr) *curr = buddy->next;

    BuddyBlock* merged = (offset < buddy_offset) ? block : buddy;
    merged->level++;
    merged->is_free = 1;
    merged->next = free_lists[merged->level];
    free_lists[merged->level] = merged;

    try_merge(merged);
}

// Free memory and merge buddies if possible
void xfree(void* ptr) {
    if (!ptr) return;

    BuddyBlock* block = (BuddyBlock*)((unsigned char*)ptr - sizeof(BuddyBlock));
    block->is_free = 1;
    block->next = free_lists[block->level];
    free_lists[block->level] = block;

    try_merge(block);
}

// Display current memory status
void print_buddy_status() {
    printf("\n-- Buddy Allocator Status --\n");
    for (int i = 0; i < MAX_LEVELS; i++) {
        int count = 0;
        BuddyBlock* curr = free_lists[i];
        while (curr) {
            count++;
            curr = curr->next;
        }
        printf("Level %2d (%5zu bytes): %d free block(s)\n", i, level_to_size(i), count);
    }
    printf("-----------------------------\n");
}

// Clean up memory
void cleanup_buddy_allocator() {
    if (base_memory && base_memory != MAP_FAILED) {
        munmap(base_memory, TOTAL_POOL_SIZE);
        base_memory = NULL;
        printf("Buddy allocator memory unmapped.\n");
    }
}

// Sample usage
int main() {
    init_buddy_allocator();
    print_buddy_status();

    void* a = xmalloc(1000);
    void* b = xmalloc(5000);
    void* c = xmalloc(8000);

    print_buddy_status();

    xfree(b);
    xfree(a);
    xfree(c);

    print_buddy_status();
    cleanup_buddy_allocator();
    return 0;
}
