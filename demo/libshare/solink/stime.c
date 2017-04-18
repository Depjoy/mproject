#include <stdio.h>
#include <time.h>
#include <stdint.h>

/*
 * get system time without considering user's change
 */
uint64_t micro64(void)
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC,&t);
    return t.tv_sec * 1e+3 + t.tv_nsec / 1000;
}
