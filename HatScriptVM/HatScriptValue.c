//
// Created by florian on 3/26/21.
//

#include "HatScriptValue.h"

List* createList(VM* vm) {
   List* list = reallocate(NULL , 0, sizeof list, vm);
   if (list != NULL) {
       list->size = 0;
       list->length = 0;
       list->values = NULL;
   }
   return list;
}

int writeToList(VM* vm, List* list, Value value, int index) {
    if (list->length == list->size) {
        Value* tmp = GROW_ARRAY(list->values, list->size, GROW_CAPACITY(list->size), vm);
        if (tmp == NULL)
            return -1;
        list->values = tmp;
    }

    list->values[index] = value;

    return 0;
}
