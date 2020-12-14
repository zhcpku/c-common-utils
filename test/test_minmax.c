#include <float.h>
#include <limits.h>
#include <stdint.h>
#include "minmax.h"
#include "utest.h"

int main() {
    init_test(FF_ALWAYS);

    // int
    add_test(min(1, 2) == 1);
    add_test(max(1, 2) == 2);

    add_test(min(INT32_MAX, INT32_MIN) == INT32_MIN);
    add_test(max(INT32_MAX, INT32_MIN) == INT32_MAX);

    add_test(min(INT32_MIN, INT32_MIN) == INT32_MIN);
    add_test(max(INT32_MIN, INT32_MIN) == INT32_MIN);

    add_test(min(INT32_MAX, INT32_MAX) == INT32_MAX);
    add_test(max(INT32_MAX, INT32_MAX) == INT32_MAX);

    // long
    add_test(min(1L, 2L) == 1L);
    add_test(max(1L, 2L) == 2L);

    add_test(min(LONG_MAX, LONG_MIN) == LONG_MIN);
    add_test(max(LONG_MAX, LONG_MIN) == LONG_MAX);

    add_test(min(LONG_MIN, LONG_MIN) == LONG_MIN);
    add_test(max(LONG_MIN, LONG_MIN) == LONG_MIN);

    add_test(min(LONG_MAX, LONG_MAX) == LONG_MAX);
    add_test(max(LONG_MAX, LONG_MAX) == LONG_MAX);

    // unsigned long long
#ifndef ULLONG_MIN
#define ULLONG_MIN 0ULL
    add_test(min(1ULL, 2ULL) == 1ULL);
    add_test(max(1ULL, 2ULL) == 2ULL);

    add_test(min(ULLONG_MAX, ULLONG_MIN) == ULLONG_MIN);
    add_test(max(ULLONG_MAX, ULLONG_MIN) == ULLONG_MAX);

    add_test(min(ULLONG_MIN, ULLONG_MIN) == ULLONG_MIN);
    add_test(max(ULLONG_MIN, ULLONG_MIN) == ULLONG_MIN);

    add_test(min(ULLONG_MAX, ULLONG_MAX) == ULLONG_MAX);
    add_test(max(ULLONG_MAX, ULLONG_MAX) == ULLONG_MAX);
#endif  // ULLONG_MIN

    // float
    add_test(min(FLT_MAX, FLT_MIN) == FLT_MIN);
    add_test(max(FLT_MAX, FLT_MIN) == FLT_MAX);

    add_test(min(FLT_MIN, FLT_MIN) == FLT_MIN);
    add_test(max(FLT_MIN, FLT_MIN) == FLT_MIN);

    add_test(min(FLT_MAX, FLT_MAX) == FLT_MAX);
    add_test(max(FLT_MAX, FLT_MAX) == FLT_MAX);

    // double
    add_test(min(1.0, 2.0) == 1.0);
    add_test(max(1.0, 2.0) == 2.0);

    add_test(min(DBL_MAX, DBL_MIN) == DBL_MIN);
    add_test(max(DBL_MAX, DBL_MIN) == DBL_MAX);

    add_test(min(DBL_MIN, DBL_MIN) == DBL_MIN);
    add_test(max(DBL_MIN, DBL_MIN) == DBL_MIN);

    add_test(min(DBL_MAX, DBL_MAX) == DBL_MAX);
    add_test(max(DBL_MAX, DBL_MAX) == DBL_MAX);

    // different type
    add_test(max(INT32_MAX, INT64_MAX) == INT64_MAX);

    // side effect
    int a = 2, b = 3;
    add_test(min(a--, b) == a + 1);
    add_test(max(a--, b++) == b - 1);
    add_test(a == 0);

    end_test();
    return 0;
}
