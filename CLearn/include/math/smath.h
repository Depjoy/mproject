#ifndef _SMATH_H__
#define __SMATH_H__

#define min(x,y) ({ \
    typeof(x) _min1 = (x); \
    typeof(y) _min2 = (y); \
    (void)(&_min1 == &_min2); \
    (_min1 > _min2) ? _min2:_min1; \
})

#define STR(s) #s
#define CONS(a,b) a##b

#endif
