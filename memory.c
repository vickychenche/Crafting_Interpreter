#include <stdlib.h>

#include "memory.h"

void * reallocate(void * pointer, size_t oldSize, size_t newSize) {
    if (newSize == 0) { //free allocation
        free(pointer);
        return NULL;
    }

    //uses C standard library
    //when oldSize = 0 equivallent to calling malloc()
    //when both are not 0, it simply updates size of the block and return 
    //the same pointer
    void* result = realloc(pointer, newSize);
    //allocation can fail if there isn't enough memory 
    if (result == NULL) exit(1);
    return result;
}