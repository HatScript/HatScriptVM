//
// Created by florian on 3/26/21.
//

#include <stdio.h>
#include <Instructions.h>
#include <vm.h>
#include <compiler.h>

int main() {
    VM vm;
    initVM(&vm, 1324, 12);
    Chunk chunk;
    initChunk(&chunk, &vm);
    compile("1 + 1", &vm, &chunk);
    printf("%lu", sizeof(Instruction));

    freeChunk(&vm, &chunk);
    freeVM(&vm);
    return 0;
}