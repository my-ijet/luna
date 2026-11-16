#include "base.h"

#include <stdio.h>


int main(void) {
    arena a = {0};
    defer { arena_release(&a); }

    string greeting = S("Hello, world!");
    printf("[" STR_FMT "]\n", STR_ARG(greeting));

    string upper = string_upper(&a, greeting);
    printf("[" STR_FMT "]\n", STR_ARG(upper));

    return 0;
}
