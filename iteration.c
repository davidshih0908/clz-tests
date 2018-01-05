#include "clz.h"

#if defined(iteration)
// static inline __attribute((always_inline))
inline __attribute((always_inline))




/*
unsigned clz(uint32_t x)
{
    int n = 32, c = 16;
    do {
        uint32_t y = x >> c;
        if (y) {
            n -= c;
            x = y;
        }
        c >>= 1;
    } while (c);
    return (n - x);
}
*/



unsigned clz_uint8(uint8_t x)
{
    int n = 8, c = 4;
    do {
        uint8_t y = x >> c;
        if (y) {
            n -= c;
            x = y;
        }
        c >>= 1;
    } while (c);
    return (n - x);
}

unsigned clz_uint16(uint16_t x)
{
    int n = 16, c = 8;
    do {
        uint16_t y = x >> c;
        if (y) {
            n -= c;
            x = y;
        }
        c >>= 1;
    } while (c);
    return (n - x);
}

unsigned clz_uint32(uint32_t x)
{
    int n = 32, c = 16;
    do {
        uint32_t y = x >> c;
        if (y) {
            n -= c;
            x = y;
        }
        c >>= 1;
    } while (c);
    return (n - x);
}

unsigned clz_uint64(uint64_t x)
{
    int n = 64, c = 16;
    do {
        uint64_t y = x >> c;
        if (y) {
            n -= c;
            x = y;
        }
        c >>= 1;
    } while (c);
    return (n - x);
}

#endif