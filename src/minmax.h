#ifndef __MINMAX_H__
#define __MINMAX_H__

/*
 * min() macro returns the smaller of two values of same type, while max() is the opposite.

using gcc extensions
    https://gcc.gnu.org/onlinedocs/gcc/Typeof.html#Typeof
    https://gcc.gnu.org/onlinedocs/gcc/Statement-Exprs.html#Statement-Exprs
*/

#define min(a, b)           \
    ({                      \
        typeof(a) _a = (a); \
        typeof(b) _b = (b); \
        (void)(&_a == &_b); \
        _a < _b ? _a : _b;  \
    })

#define max(a, b)           \
    ({                      \
        typeof(a) _a = (a); \
        typeof(b) _b = (b); \
        (void)(&_a == &_b); \
        _a > _b ? _a : _b;  \
    })

#endif  // __MINMAX_H__
