//
// Created by florian on 3/26/21.
//

#include "memory.h"


void* reallocate(void* pointer, size_t oldSize, size_t newSize, VM* vm) {
    if (vm->currentMemory + newSize - oldSize > vm->maxMemory) {
        return NULL;
    }

    vm->currentMemory += newSize - oldSize;

    void* ptr = realloc(pointer, newSize);
    return ptr;
}