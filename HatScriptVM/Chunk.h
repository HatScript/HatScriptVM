//
// Created by florian on 3/26/21.
//

#ifndef HATSCRIPT_CHUNK_H
#define HATSCRIPT_CHUNK_H


#include <stdint.h>
#include "memory.h"
#include "Instructions.h"

typedef struct Chunk {
    int size;
    int maxSize;
    Instruction* instructions;
} Chunk;

/// Initializes a Chunk with an maxSize of 0
/// \param chunk Pointer to the Address of the Chunk
void initChunk(Chunk* chunk);

/// Writes an Instruction to the Chunks Instruction List
/// Growing it when needed. Uses memory of the VM,
/// if the vm has not enough memory it to Grow it will return -1
/// \param vm The VM which handles the Memory.
/// \param chunk The Chunk to write the Instruction in.
/// \param instruction The instruction to write.
/// \return 0 if Successful, -1 if Not enough Memory
int writeChunk(VM* vm, Chunk* chunk, Instruction instruction);

/// Frees the Memory the Chunk uses for its Instruction List
/// and resets it to the well defined State it is in after initialization
/// \param vm The VM in which the Memory is freed in.
/// \param chunk The Chunk
void freeChunk(VM* vm, Chunk* chunk);

#endif //HATSCRIPT_CHUNK_H
