#ifndef __UTEST_H__
#define __UTEST_H__

#include <stdio.h>
#include <stdlib.h>

static unsigned int ntest;
static unsigned int npass;

static int fast_fail = 0;
#define FF_NONE 0
#define FF_ALWAYS 1

#define init_test(flag)   \
    do {                  \
        ntest = 0;        \
        npass = 0;        \
        fast_fail = flag; \
    } while (0)

#define add_test(expr)                                                                    \
    do {                                                                                  \
        ntest++;                                                                          \
        if (expr) {                                                                       \
            npass++;                                                                      \
        } else {                                                                          \
            fprintf(stdout, "[❌ %s] failed at line %u: %s\n", __FILE__, __LINE__, #expr); \
            if (fast_fail) return EXIT_FAILURE;                                           \
        }                                                                                 \
    } while (0)

#define end_test()                                                                    \
    do {                                                                              \
        if (ntest == npass) {                                                         \
            fprintf(stdout, "[✅ %s] passed %u / %u cases\n", __FILE__, npass, ntest); \
        } else {                                                                      \
            fprintf(stdout, "[❌ %s] passed %u / %u cases\n", __FILE__, npass, ntest); \
        }                                                                             \
    } while (0)

#endif  //__UTEST_H__
