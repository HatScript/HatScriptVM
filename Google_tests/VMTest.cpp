//
// Created by florian on 3/27/21.
//
#include "gtest/gtest.h"

extern "C" {
#include "vm.h"
};


TEST(VM, AddTwoIntegers) {
    VM vm;

    Chunk chunk;
    initVM(&vm, 8192, 16);
    initChunk(&chunk);

    Instruction add = {.opCode = ADD, .op1_8bit = 0, {{.op2_8bit = 0, .op3_8bit = 1}}};
    Instruction load_11 = (Instruction) {LOAD_CONSTANT, 1, {.op16_bit = 11}};
    Instruction load_10 = (Instruction) {LOAD_CONSTANT, 0, {.op16_bit = 10}};
    Instruction stop = (Instruction) {STOP};

    writeChunk(&vm, &chunk, load_11);
    writeChunk(&vm, &chunk, load_10);
    writeChunk(&vm, &chunk, add);
    writeChunk(&vm, &chunk, stop);

    vm.ip = chunk.instructions;

    runVM(&vm);

    ASSERT_EQ(AS_NUMBER(vm.registerStart[0]), (double)21);

    freeVM(&vm);
}