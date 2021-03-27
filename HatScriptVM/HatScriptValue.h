//
// Created by florian on 3/26/21.
//

#ifndef HATSCRIPT_HATSCRIPTVALUE_H
#define HATSCRIPT_HATSCRIPTVALUE_H


#include <stdbool.h>

#define IS_INT(value) value.type == INT
#define IS_DOUBLE(value) value.type == DOUBLE
#define IS_BOOL(value) value.type == BOOL
#define IS_OBJECT(value) value.type == OBJECT

#define IS_STRING(object)


#define NUMBER_VAL(value) \
    ((Value){DOUBLE, {.d = (double) value}})

#define AS_NUMBER(value) \
    (value).d

typedef enum {
  DOUBLE,
  INT,
  BOOL,
  OBJECT
} Type;

typedef struct {
    Type type;
    union {
        double d;
        int i;
        bool b;
    };
} Value;

typedef enum {
    STRING,
    CLASS,
    LIST,
    MAP,
    INSTANCE,
    FUNCTION,
    CLOSURE,
    NATIVE,
} ObjType;

#endif //HATSCRIPT_HATSCRIPTVALUE_H