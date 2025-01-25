/*
 * loadmem.c / Asignment_2_Part_2_2_Memory Management
 *
 * JinYoung Park / CS5600 / Northeastern University
 * Spring 2025 / Jan 21, 2025
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct
typedef struct {
    int *data;
    size_t size;
} dyn_block;

// function allocated block
dyn_block* alloc_dyn_block(size_t size) {
    dyn_block *block = malloc(sizeof(dyn_block));
    if (!block) {
        return NULL;
    }
    block->data = malloc(size * sizeof(int));
    if (!block->data) {
        free(block);
        return NULL;
    }
    block->size = size;
    return block;
}

// function save dynamic block data
dyn_block* store_line_in_block(const char *line) {
    size_t size = 0;
    int temp[2048];
    const char *ticket = strtok((char *)line, " ");
    while (ticket) {
        temp[size++] = atoi(ticket); // save str to int
        ticket = strtok(NULL, " ");
    }
    dyn_block *block = alloc_dyn_block(size);
    if (block) {
        for (size_t i = 0; i < size; i++) {
            block->data[i] = temp[i];
        }
    }
    return block;
}

// function to make dynamic arr and read file
dyn_block** read_file_lines(const char *filename, size_t *block_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    char line[2048];
    size_t count = 0;
    dyn_block **blocks = malloc(2048 * sizeof(dyn_block *));

    while (fgets(line, sizeof(line), file)) {
        blocks[count++] = store_line_in_block(line);
    }

    fclose(file);
    *block_count = count;
    return blocks;
}

// function to free memory
void free_blocks(dyn_block **blocks, size_t block_count) {
    for (size_t i = 0; i < block_count; i++) {
        free(blocks[i]->data);
        free(blocks[i]);
    }
    free(blocks);
}

// Test
int main() {
    const char *filename = "blocks.data";
    size_t block_count = 0;

    dyn_block **blocks = read_file_lines(filename, &block_count);
    if (!blocks) return -1;

    // print data
    printf("Reading %zu from the file:\n", block_count);
    for (size_t i = 0; i < block_count; i++) {
        printf("Block %zu: ", i + 1);
        for (size_t j = 0; j < blocks[i]->size; j++) {
            printf("%d ", blocks[i]->data[j]);
        }
        printf("\n");
    }

    // free memory
    free_blocks(blocks, block_count);
    return 0;
}
