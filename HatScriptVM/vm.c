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

_Noreturn Result runVM(VM* vm) {


    for (;;) {

        Instruction instruction = *vm->ip++;


#define RESULT_REGISTER vm->registerStart[instruction.op1_8bit]
#define FIRST_REGISTER vm->registerStart[instruction.op2_8bit]
#define SECOND_REGISTER vm->registerStart[instruction.op3_8bit]
#define BINARY_NUMBER_OPERATION(op) {\
        Value op1 = FIRST_REGISTER; \
        Value op2 = SECOND_REGISTER; \
        if (IS_INT(op1)) { \
            if (IS_INT(op2)) \
                RESULT_REGISTER = INT_VAL(AS_INT(op1) op AS_INT(op2)); \
            else if (IS_DOUBLE(op2)) \
                RESULT_REGISTER = DOUBLE_VAL(AS_INT(op1) op AS_DOUBLE(op2)); \
            else \
                return (Result) {TYPE_ERROR} \
        } else if (IS_DOUBLE(op1)) { \
            if (IS_INT(op2)) \
                RESULT_REGISTER = INT_VAL(AS_DOUBLE(op1) op AS_INT(op2)); \
            else if (IS_DOUBLE(op2)) \
                RESULT_REGISTER = DOUBLE_VAL(AS_DOUBLE(op1) op AS_DOUBLE(op2)); \
            else \
                return (Result) {TYPE_ERROR} \
        } else \
            return (Result) {TYPE_ERROR};\
            }



        switch (instruction.opCode) {
            case STOP:
                return (Result) {RESUKLT_OK};
            case LOAD_CONSTANT:
                vm->registerStart[instruction.op1_8bit] = INT_VAL(instruction.op16_bit);
                break;
            case NEG: {
                Value operand = FIRST_REGISTER;
                if (IS_INT(operand))
                    RESULT_REGISTER = INT_VAL(-AS_INT(operand));
                else if (IS_DOUBLE(operand))
                    RESULT_REGISTER = DOUBLE_VAL(-AS_DOUBLE(operand));
                else
                    return (Result) {TYPE_ERROR};
                break;
            }
            case ADD: BINARY_NUMBER_OPERATION(+)
                break;
            case SUB: BINARY_NUMBER_OPERATION(-)
                break;
            case MUL: BINARY_NUMBER_OPERATION(*)
                break;
            case DIV: BINARY_NUMBER_OPERATION(/)
                break;
            case MOD: {
                Value op1 = FIRST_REGISTER;
                Value op2 = SECOND_REGISTER;
                if (IS_INT(op1)) {
                    if (IS_INT(op2))
                        RESULT_REGISTER = INT_VAL(AS_INT(op1) % AS_INT(op2));
                    else if (IS_DOUBLE(op2))
                        RESULT_REGISTER = DOUBLE_VAL(fmod(AS_INT(op1),AS_DOUBLE(op2)));
                    else
                        return (Result) {TYPE_ERROR}
                } else if (IS_DOUBLE(op1)) {
                    if (IS_INT(op2))
                        RESULT_REGISTER = INT_VAL(fmod(AS_DOUBLE(op1),AS_INT(op2)));
                    else if (IS_DOUBLE(op2))
                        RESULT_REGISTER = DOUBLE_VAL(fmod(AS_DOUBLE(op1),AS_DOUBLE(op2)));
                    else
                        return (Result) {TYPE_ERROR}
                } else
                    return (Result) {TYPE_ERROR};
            }
            case NOT: RESULT_REGISTER = BOOL_VAL(IS_FALSEY(FIRST_REGISTER));
                break;
            case EQUAL: {
                Value first = FIRST_REGISTER;
                Value second = SECOND_REGISTER;
                EQUAL(first, second, RESULT_REGISTER);
                break;
            }
            case GREATER:
                break;
            case GREATER_EQUAL:
                break;
            case LESS:
                break;
            case LESS_EQUAL:
                break;
            case NOT_EQUAL:
                break;
        }
    }

#undef RESULT_REGISTER
#undef FIRST_REGISTER
#undef SECOND_REGISTER
#undef BINARY_NUMBER_OPERATION


}