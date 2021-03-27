//
// Created by florian on 3/26/21.
//

#ifndef HATSCRIPT_INSTRUCTIONS_H
#define HATSCRIPT_INSTRUCTIONS_H

#include <stdint.h>

typedef enum{
    STOP,
    LOAD_CONSTANT,
    NEG,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD
} OpCode;

typedef struct {
    OpCode opCode:8;
    uint8_t op1_8bit;
    union {
        struct {
            uint8_t op2_8bit;
            uint8_t op3_8bit;
        };
        struct {
            uint16_t op16_bit;
        };
    };

} Instruction;

#endif //HATSCRIPT_INSTRUCTIONS_H