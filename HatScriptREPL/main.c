//
// Created by florian on 3/26/21.
//

#include <stdio.h>
#include <Instructions.h>
#include <vm.h>

int main() {
    VM vm;
    initVM(&vm, 1324, 12);

    printf("%lu", sizeof(Instruction));

    freeVM(&vm);
    return 0;
}