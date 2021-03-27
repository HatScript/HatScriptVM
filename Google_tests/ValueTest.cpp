//
// Created by florian on 3/27/21.
//
#include "gtest/gtest.h"

extern "C" {
    #include "HatScriptValue.h"
};


TEST(Value, NumberConversion) {
    ASSERT_EQ(AS_NUMBER(NUMBER_VAL(1)),1);
}