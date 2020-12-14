#ifndef __UTEST_H__
#define __UTEST_H__

#include <stdio.h>
#include <stdlib.h>

static int ntest;

#define init_test() \
    do {            \
        ntest = 0;  \
    } while (0)

#define add_test(expr)                                                \
    do {                                                              \
        if (expr) {                                                   \
            ntest++;                                                  \
        } else {                                                      \
            fprintf(stdout, "Failed at case %d: %s\n", ntest, #expr); \
            return EXIT_FAILURE;                                      \
        }                                                             \
    } while (0)

#define end_test()                                        \
    do {                                                  \
        fprintf(stdout, "All %d cases passed!\n", ntest); \
    } while (0)

#endif  //__UTEST_H__
