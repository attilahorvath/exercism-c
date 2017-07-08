#include <stdio.h>
#include <stddef.h>
#include "hello_world.h"

#define BUFFER_LENGTH 128

void hello(char *buffer, const char *name)
{
    if (name == NULL) {
        name = "World";
    }

    snprintf(buffer, BUFFER_LENGTH, "Hello, %s!", name);
}
