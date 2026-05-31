# Makefile for Buddy Memory Allocator

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

TARGET = dma
SRC = buddy_allocator.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
