//
// Created by florian on 3/27/21.
//

#ifndef HATSCRIPT_CALLFRAME_H
#define HATSCRIPT_CALLFRAME_H

#include "Chunk.h"

typedef struct {
    Instruction* returnAddress;
    Value* registerStart;
} CallFrame;

#endif //HATSCRIPT_CALLFRAME_H
