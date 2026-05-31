#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For sbrk() (though replaced by mmap)
#include <sys/mman.h> // For mmap() and munmap()

#define TOTAL_MEMORY_SIZE (2 * 1024 * 1024)

#define SMALL_BLOCK_SIZE (1 * 1024)
#define MEDIUM_BLOCK_SIZE (5 * 1024)
#define LARGE_BLOCK_SIZE (20 * 1024)

#define SMALL_POOL_SIZE (512 * 1024)
#define MEDIUM_POOL_SIZE (102 * 5 * 1024)
#define LARGE_POOL_SIZE (51 * 20 * 1024)

#define MAX_SMALL_BLOCKS (SMALL_POOL_SIZE / SMALL_BLOCK_SIZE)
#define MAX_MEDIUM_BLOCKS (MEDIUM_POOL_SIZE / MEDIUM_BLOCK_SIZE)
#define MAX_LARGE_BLOCKS (LARGE_POOL_SIZE / LARGE_BLOCK_SIZE)

#if (SMALL_POOL_SIZE + MEDIUM_POOL_SIZE + LARGE_POOL_SIZE) > TOTAL_MEMORY_SIZE
#error "Total defined pool size for categories exceeds TOTAL_MEMORY_SIZE. Adjust pool sizes."
#endif

typedef struct MemoryBlock {
    size_t size;
    int is_free;
    void* data_ptr;
    struct MemoryBlock* next_free; // Pointer to the next free block in the free list
} MemoryBlock;

typedef struct MemoryPool {
    unsigned char* base_address;

    MemoryBlock small_blocks[MAX_SMALL_BLOCKS];
    MemoryBlock medium_blocks[MAX_MEDIUM_BLOCKS];
    MemoryBlock large_blocks[MAX_LARGE_BLOCKS];

    // Pointers to the head of the free list for each category
    MemoryBlock* free_small_list;
    MemoryBlock* free_medium_list;
    MemoryBlock* free_large_list;

    size_t small_block_count;
    size_t medium_block_count;
    size_t large_block_count;
} MemoryPool;

static MemoryPool global_memory_pool;

void init_memory_pool();
void cleanup_memory_pool(); // New function for munmap()

void* xmalloc(size_t required_memory);

void xfree(void* ptr);

void print_memory_status();

void init_memory_pool() {
    	global_memory_pool.base_address = (unsigned char*)mmap(NULL, TOTAL_MEMORY_SIZE,PROT_READ | PROT_WRITE,MAP_PRIVATE | MAP_ANONYMOUS,-1, 0); 
	// Request memory from the operating system using mmap()
	if (global_memory_pool.base_address == MAP_FAILED) { // mmap returns MAP_FAILED on error
        	perror("Failed to allocate memory with mmap()");
        	exit(EXIT_FAILURE); // Exit if memory allocation fails
    	}

    	// memset is technically redundant for MAP_ANONYMOUS, but harmless and good practice
    	memset(global_memory_pool.base_address, 0, TOTAL_MEMORY_SIZE);

    	// --- Initialize Small Blocks Pool and Free List ---
    	global_memory_pool.small_block_count = MAX_SMALL_BLOCKS;
    	global_memory_pool.free_small_list = NULL; // Start with an empty free list
    	unsigned char* current_pool_addr = global_memory_pool.base_address;
    	for (size_t i = 0; i < MAX_SMALL_BLOCKS; ++i) {
        	global_memory_pool.small_blocks[i].size = SMALL_BLOCK_SIZE;
        	global_memory_pool.small_blocks[i].is_free = 1;
        	global_memory_pool.small_blocks[i].data_ptr = current_pool_addr;

        	// Add block to the head of the free list
        	global_memory_pool.small_blocks[i].next_free = global_memory_pool.free_small_list;
        	global_memory_pool.free_small_list = &global_memory_pool.small_blocks[i];

        current_pool_addr += SMALL_BLOCK_SIZE;
    }
    printf("  - Initialized %zu small blocks (1KB each), total %zu KB.\n",
           MAX_SMALL_BLOCKS, SMALL_POOL_SIZE / 1024);

    // --- Initialize Medium Blocks Pool and Free List ---
    global_memory_pool.medium_block_count = MAX_MEDIUM_BLOCKS;
    global_memory_pool.free_medium_list = NULL; // Start with an empty free list
    current_pool_addr = global_memory_pool.base_address + SMALL_POOL_SIZE;
    for (size_t i = 0; i < MAX_MEDIUM_BLOCKS; ++i) {
        global_memory_pool.medium_blocks[i].size = MEDIUM_BLOCK_SIZE;
        global_memory_pool.medium_blocks[i].is_free = 1;
        global_memory_pool.medium_blocks[i].data_ptr = current_pool_addr;

        // Add block to the head of the free list
        global_memory_pool.medium_blocks[i].next_free = global_memory_pool.free_medium_list;
        global_memory_pool.free_medium_list = &global_memory_pool.medium_blocks[i];

        current_pool_addr += MEDIUM_BLOCK_SIZE;
    }
    printf("  - Initialized %zu medium blocks (5KB each), total %zu KB.\n",
           MAX_MEDIUM_BLOCKS, MEDIUM_POOL_SIZE / 1024);

    // --- Initialize Large Blocks Pool and Free List ---
    global_memory_pool.large_block_count = MAX_LARGE_BLOCKS;
    global_memory_pool.free_large_list = NULL; // Start with an empty free list
    current_pool_addr = global_memory_pool.base_address + SMALL_POOL_SIZE + MEDIUM_POOL_SIZE;
    for (size_t i = 0; i < MAX_LARGE_BLOCKS; ++i) {
        global_memory_pool.large_blocks[i].size = LARGE_BLOCK_SIZE;
        global_memory_pool.large_blocks[i].is_free = 1;
        global_memory_pool.large_blocks[i].data_ptr = current_pool_addr;

        // Add block to the head of the free list
        global_memory_pool.large_blocks[i].next_free = global_memory_pool.free_large_list;
        global_memory_pool.free_large_list = &global_memory_pool.large_blocks[i];

        current_pool_addr += LARGE_BLOCK_SIZE;
    }
    printf("  - Initialized %zu large blocks (20KB each), total %zu KB.\n",
           MAX_LARGE_BLOCKS, LARGE_POOL_SIZE / 1024);

    printf("Memory pool initialization complete. Total managed memory: %zu KB.\n",
           (SMALL_POOL_SIZE + MEDIUM_POOL_SIZE + LARGE_POOL_SIZE) / 1024);
    printf("Remaining unmanaged memory (at end of buffer): %zu bytes.\n",
           TOTAL_MEMORY_SIZE - (SMALL_POOL_SIZE + MEDIUM_POOL_SIZE + LARGE_POOL_SIZE));
}

// Function to unmap the memory allocated by mmap()
void cleanup_memory_pool() {
    if (global_memory_pool.base_address != NULL && global_memory_pool.base_address != MAP_FAILED) {
        if (munmap(global_memory_pool.base_address, TOTAL_MEMORY_SIZE) == -1) {
            perror("Failed to unmap memory with munmap()");
        } else {
            printf("Memory pool unmapped successfully.\n");
        }
        global_memory_pool.base_address = NULL; // Clear the base address after unmapping
    }
}

void* xmalloc(size_t required_memory) {
    MemoryBlock* allocated_block = NULL;

    if (required_memory == 0) {
        printf("xmalloc: Error: Cannot allocate 0 bytes.\n");
        return NULL;
    }
    if (required_memory > LARGE_BLOCK_SIZE) {
        printf("xmalloc: Error: Requested size %zu bytes is too large for any available block type (max %u bytes).\n",
               required_memory, LARGE_BLOCK_SIZE);
        return NULL;
    }

    // Best-fit allocation strategy using free lists:
    // Try to allocate from the smallest block category that can fit the request.
    // If a free block exists in that category's free list, take it.
    // If not, fail the allocation for that size.

    if (required_memory <= SMALL_BLOCK_SIZE) {
        if (global_memory_pool.free_small_list != NULL) {
            allocated_block = global_memory_pool.free_small_list;
            global_memory_pool.free_small_list = allocated_block->next_free; // Move head of free list
            allocated_block->is_free = 0;
            allocated_block->next_free = NULL; // Clear next_free for allocated block
            printf("xmalloc: Allocated a 1KB small block for %zu bytes (at %p).\n",
                   required_memory, allocated_block->data_ptr);
            return allocated_block->data_ptr;
        }
        printf("xmalloc: Failed to allocate %zu bytes. No free 1KB small block found.\n", required_memory);
        return NULL;
    }

    if (required_memory <= MEDIUM_BLOCK_SIZE) {
        if (global_memory_pool.free_medium_list != NULL) {
            allocated_block = global_memory_pool.free_medium_list;
            global_memory_pool.free_medium_list = allocated_block->next_free; // Move head of free list
            allocated_block->is_free = 0;
            allocated_block->next_free = NULL; // Clear next_free for allocated block
            printf("xmalloc: Allocated a 5KB medium block for %zu bytes (at %p).\n",
                   required_memory, allocated_block->data_ptr);
            return allocated_block->data_ptr;
        }
        printf("xmalloc: Failed to allocate %zu bytes. No free 5KB medium block found.\n", required_memory);
        return NULL;
    }

    if (required_memory <= LARGE_BLOCK_SIZE) {
        if (global_memory_pool.free_large_list != NULL) {
            allocated_block = global_memory_pool.free_large_list;
            global_memory_pool.free_large_list = allocated_block->next_free; // Move head of free list
            allocated_block->is_free = 0;
            allocated_block->next_free = NULL; // Clear next_free for allocated block
            printf("xmalloc: Allocated a 20KB large block for %zu bytes (at %p).\n",
                   required_memory, allocated_block->data_ptr);
            return allocated_block->data_ptr;
        }
        printf("xmalloc: Failed to allocate %zu bytes. No free 20KB large block found.\n", required_memory);
        return NULL;
    }

    printf("xmalloc: Failed to allocate %zu bytes. No suitable block type found.\n", required_memory);
    return NULL;
}

void xfree(void* ptr) {
    if (ptr == NULL) {
        printf("xfree: Warning: Attempted to free a NULL pointer. No action taken.\n");
        return;
    }

    // Iterate through all block categories to find the matching data_ptr
    // and add it back to the head of its respective free list.

    for (size_t i = 0; i < global_memory_pool.small_block_count; ++i) {
        if (global_memory_pool.small_blocks[i].data_ptr == ptr) {
            if (global_memory_pool.small_blocks[i].is_free) {
                printf("xfree: Warning: Attempted to free an already free 1KB small block at %p.\n", ptr);
            }
            global_memory_pool.small_blocks[i].is_free = 1;
            // Add to the head of the small free list
            global_memory_pool.small_blocks[i].next_free = global_memory_pool.free_small_list;
            global_memory_pool.free_small_list = &global_memory_pool.small_blocks[i];
            printf("xfree: Freed a 1KB small block at %p.\n", ptr);
            return;
        }
    }

    for (size_t i = 0; i < global_memory_pool.medium_block_count; ++i) {
        if (global_memory_pool.medium_blocks[i].data_ptr == ptr) {
            if (global_memory_pool.medium_blocks[i].is_free) {
                printf("xfree: Warning: Attempted to free an already free 5KB medium block at %p.\n", ptr);
            }
            global_memory_pool.medium_blocks[i].is_free = 1;
            // Add to the head of the medium free list
            global_memory_pool.medium_blocks[i].next_free = global_memory_pool.free_medium_list;
            global_memory_pool.free_medium_list = &global_memory_pool.medium_blocks[i];
            printf("xfree: Freed a 5KB medium block at %p.\n", ptr);
            return;
        }
    }

    for (size_t i = 0; i < global_memory_pool.large_block_count; ++i) {
        if (global_memory_pool.large_blocks[i].data_ptr == ptr) {
            if (global_memory_pool.large_blocks[i].is_free) {
                printf("xfree: Warning: Attempted to free an already free 20KB large block at %p.\n", ptr);
            }
            global_memory_pool.large_blocks[i].is_free = 1;
            // Add to the head of the large free list
            global_memory_pool.large_blocks[i].next_free = global_memory_pool.free_large_list;
            global_memory_pool.free_large_list = &global_memory_pool.large_blocks[i];
            printf("xfree: Freed a 20KB large block at %p.\n", ptr);
            return;
        }
    }

    printf("xfree: Error: Attempted to free an invalid or unmanaged pointer %p.\n", ptr);
}

void print_memory_status() {
    size_t free_small = 0;
    size_t allocated_small = 0;
    // Count free blocks by traversing the free list
    MemoryBlock* current = global_memory_pool.free_small_list;
    while (current != NULL) {
        free_small++;
        current = current->next_free;
    }
    allocated_small = global_memory_pool.small_block_count - free_small;


    size_t free_medium = 0;
    size_t allocated_medium = 0;
    current = global_memory_pool.free_medium_list;
    while (current != NULL) {
        free_medium++;
        current = current->next_free;
    }
    allocated_medium = global_memory_pool.medium_block_count - free_medium;

    size_t free_large = 0;
    size_t allocated_large = 0;
    current = global_memory_pool.free_large_list;
    while (current != NULL) {
        free_large++;
        current = current->next_free;
    }
    allocated_large = global_memory_pool.large_block_count - free_large;

    printf("\n--- Memory Pool Status ---\n");
    printf("Small Blocks (1KB each): Free: %zu, Allocated: %zu, Total: %zu\n",
           free_small, allocated_small, global_memory_pool.small_block_count);
    printf("Medium Blocks (5KB each): Free: %zu, Allocated: %zu, Total: %zu\n",
           free_medium, allocated_medium, global_memory_pool.medium_block_count);
    printf("Large Blocks (20KB each): Free: %zu, Allocated: %zu, Total: %zu\n",
           free_large, allocated_large, global_memory_pool.large_block_count);
    printf("--------------------------\n");
}

int main() {
    printf("Starting custom memory allocator demonstration.\n");

    init_memory_pool();
    print_memory_status();

    // Example usage to demonstrate the optimized behavior
    printf("\n--- Demonstrating Optimized xmalloc/xfree ---\n");
    void* p1 = xmalloc(100); // Small block
    void* p2 = xmalloc(4000); // Medium block
    void* p3 = xmalloc(18000); // Large block
    print_memory_status();

    xfree(p1);
    xfree(p3);
    print_memory_status();

    void* p4 = xmalloc(500); // Should reuse the freed small block
    void* p5 = xmalloc(19000); // Should reuse the freed large block
    print_memory_status();

    // Test exhaustion
    /*printf("\n--- Testing Small Block Exhaustion (Optimized) ---\n");
    void* small_blocks_test[MAX_SMALL_BLOCKS];
    for (int i = 0; i < MAX_SMALL_BLOCKS; ++i) {
        small_blocks_test[i] = xmalloc(100);
    }
    void* fail_ptr_small = xmalloc(100); // This should now fail as small blocks are exhausted
    if (fail_ptr_small == NULL) {
        printf("Successfully failed to allocate a small block after exhaustion.\n");
    }
    print_memory_status();

    // Clean up
    xfree(p2);
    xfree(p4);
    xfree(p5);
    for (int i = 0; i < MAX_SMALL_BLOCKS; ++i) {
        if (small_blocks_test[i] != NULL) {
            xfree(small_blocks_test[i]);
        }
    }*/
    print_memory_status();

    printf("Custom memory allocator demonstration complete.\n");

    // Clean up the mmap'd memory
    cleanup_memory_pool();

    return 0;
}
