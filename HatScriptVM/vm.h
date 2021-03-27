//
// Created by florian on 3/26/21.
//

#ifndef HATSCRIPT_VM_H
#define HATSCRIPT_VM_H

#include <stdlib.h>
#include "HatScriptValue.h"
#include "Chunk.h"
#include "Instructions.h"


typedef struct VM {
    Value* stack;
    Value* registerStart;
    Value* tos;
    Instruction* ip;
    int maxStackSize;
    size_t maxMemory;
    size_t currentMemory;
} VM;

void initVM(VM* vm, size_t maxMemory, int maxStackSize);
void freeVM(VM* vm);

void runVM(VM* vm);

#endif //HATSCRIPT_VM_H