//
// Created by florian on 3/26/21.
//

#include <math.h>
#include "vm.h"

void initVM(VM* vm, size_t maxMemory, int maxStackSize) {
    vm->currentMemory = 0;
    vm->maxMemory = maxMemory;
    vm->maxStackSize = maxStackSize;
    vm->stack = malloc(sizeof *vm->stack * maxStackSize);
    vm->registerStart = vm->stack;
}

void freeVM(VM* vm) {
    free(vm->stack);
}

void runVM(VM* vm) {


    for (;;) {

        Instruction instruction = *vm->ip++;


#define RESULT_REGISTER vm->registerStart[instruction.op1_8bit]
#define FIRST_REGISTER vm->registerStart[instruction.op2_8bit]
#define SECOND_REGISTER vm->registerStart[instruction.op3_8bit]
#define BINARY_NUMBER_OPERATION(op) RESULT_REGISTER = NUMBER_VAL(AS_NUMBER(FIRST_REGISTER) op AS_NUMBER(SECOND_REGISTER));
#define TWO_BYTE_OPERAND

        switch (instruction.opCode) {
            case STOP:
                return;
            case LOAD_CONSTANT:
                vm->registerStart[instruction.op1_8bit] = NUMBER_VAL(instruction.op16_bit);
                break;
            case NEG:
                BINARY_NUMBER_OPERATION(-)
                break;
            case ADD:
                BINARY_NUMBER_OPERATION(+)
                break;
            case SUB:
                BINARY_NUMBER_OPERATION(-)
                break;
            case MUL:
                BINARY_NUMBER_OPERATION(*)
                break;
            case DIV:
                BINARY_NUMBER_OPERATION(/)
                break;
            case MOD:
                RESULT_REGISTER = NUMBER_VAL(fmod(AS_NUMBER(FIRST_REGISTER),AS_NUMBER(SECOND_REGISTER)));
        }
    }
}