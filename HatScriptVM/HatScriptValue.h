//
// Created by florian on 3/26/21.
//

#ifndef HATSCRIPT_HATSCRIPTVALUE_H
#define HATSCRIPT_HATSCRIPTVALUE_H


#include <stdbool.h>
#include "vm.h"

#define EQUAL(value1, value2, result) \
    if (value1.type != value2.type) result = BOOL_VAL(false); \
    else if (IS_INT(value1))    result = BOOL_VAL(AS_INT(value1) == AS_INT(value2)) \
    else if (IS_DOUBLE(value1)) result = BOOL_VAL(AS_DOUBLE(value1) == AS_DOUBLE(value2)) \
    else if (IS_BOOL(value1))   result = BOOL_VAL(AS_BOOL(value1) == AS_BOOL(value2))       \
    else if (IS_OBJECT(value1)) result =

#define IS_INT(value) value.type == INT
#define IS_DOUBLE(value) value.type == DOUBLE
#define IS_BOOL(value) value.type == BOOL
#define IS_OBJECT(value) value.type == OBJECT

#define IS_STRING(object)

#define IS_FALSEY(value) \
    false

#define INT_VAL(value) \
    ((Value){INT, {.i = (int) value}})


#define DOUBLE_VAL(value) \
    ((Value){DOUBLE, {.d = (double) value}})

#define BOOL_VAL(value) \
    ((Value){BOOL, {.d = (bool) value}})


#define AS_INT(value) \
    (value).i

#define AS_DOUBLE(value) \
    (value).d

#define AS_BOOL(value) \
    (value).b

typedef enum {
    DOUBLE,
    INT,
    BOOL,
    OBJECT
} Type;

typedef struct {
    Type type;
    union {
        u_int64_t bits;
        double d;
        int32_t i;
        bool b;
    };
} Value;

typedef enum {
    STRING,
    LIST,
    MAP,
    INSTANCE,
    FUNCTION,
    CLOSURE,
    NATIVE,
} ObjType;

typedef struct {
    ObjType type = STRING;

} String;

typedef struct {
    Value* values;
    int length;
    int size;
} List;

typedef struct Instance {
    ObjType type = INSTANCE;
    Instance* klass;
    List fields;
} Instance;

List* createList(VM* vm);
int writeToList(VM* vm, List* list, Value value, int index);
void freeList(List*, VM);

#endif //HATSCRIPT_HATSCRIPTVALUE_H