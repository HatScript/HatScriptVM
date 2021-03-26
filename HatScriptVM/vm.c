//
// Created by florian on 3/26/21.
//

#include "vm.h"

void initVM(VM* vm, size_t maxMemory, int maxStackSize) {
    vm->currentMemory = 0;
    vm->maxMemory = maxMemory;
    vm->maxStackSize = maxStackSize;
    vm->Stack = NULL;
}

void freeVM(VM* vm) {
    free(vm->Stack);
}