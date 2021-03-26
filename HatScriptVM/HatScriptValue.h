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


typedef enum Type{
  DOUBLE,
  INT,
  BOOL,
  OBJECT
} Type;

typedef struct Value {
    Type type;
    union {
        double d;
        int i;
        bool b;
    };
} Value;

#endif //HATSCRIPT_HATSCRIPTVALUE_H