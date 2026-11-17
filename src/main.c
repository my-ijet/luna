#include "base.h"
#include <stc/coption.h>

#include <stdio.h>

int main(int argc, char *argv[]) {
    defer { printf("Bye!\n"); };

    coption_long longopts[] = {
        {"help", coption_no_argument, 'h'},
        {"name", coption_required_argument, 'n'},
        {0}
    };
    const char *optstr = "hn:";

    coption opt = coption_init();
    int c;
    while ((c = coption_get(&opt, argc, argv, optstr, longopts)) != -1) {
        switch (c) {
            case 'h':
                printf("Usage: %s [-h] [-n NAME]\n", argv[0]);
            break;
            case 'n':
                printf("Hello, %s!\n", opt.arg);
            break;
            case '?':
                printf("Unknown option: %s\n", opt.optstr);
            break;
            case ':':
                printf("Missing argument for %s\n", opt.optstr);
            break;
        }
    }

    return 0;
}