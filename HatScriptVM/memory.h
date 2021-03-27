//
// Created by florian on 3/26/21.
//

#ifndef HATSCRIPT_MEMORY_H
#define HATSCRIPT_MEMORY_H

#include <stdlib.h>
#include "vm.h"

typedef struct VM VM;

#define FREE(pointer, oldSize, vm) \
    reallocate(pointer, oldSize, 0, vm)

#define FREE_ARRAY(pointer, oldCount, vm) \
    reallocate(pointer, sizeof(*pointer) * (oldCount), 0, vm); \
    (pointer) = NULL;

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(pointer, oldCount, newCount, vm) \
    (typeof(pointer)) reallocate(pointer, sizeof(*pointer) * (oldCount), sizeof(*pointer) * (newCount), vm)

void* reallocate(void* pointer, size_t oldSize, size_t newSize, VM* vm);

#endif //HATSCRIPT_MEMORY_H
