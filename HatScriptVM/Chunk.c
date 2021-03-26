//
// Created by florian on 3/26/21.
//

#include "Chunk.h"
#include "Instructions.h"

void initChunk(Chunk* chunk) {
    chunk->maxSize = 0;
    chunk->size = 0;
    chunk->instructions = NULL;
}

int writeChunk(VM* vm, Chunk* chunk, Instruction instruction) {
    if (chunk->size == chunk->maxSize) {
        Instruction* tmp = GROW_ARRAY(chunk->instructions, chunk->maxSize, GROW_CAPACITY(chunk->maxSize), vm);
        if (tmp == NULL)
            return -1;
        chunk->instructions = tmp;
    }

    chunk->instructions[++chunk->size] = instruction;

    return 0;
}

void freeChunk(VM* vm, Chunk* chunk) {
    FREE_ARRAY(chunk->instructions, chunk->maxSize, vm);
    FREE(chunk, sizeof(Chunk), vm);
}