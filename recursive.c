// #include "clz2.h"
#include "clz.h"
#if defined(recursive)
static const int mask8[] = {0, 2};//0, 0+2
static const int mask16[] = {0, 4, 6};//0, 0+4, 0+4+2
static const int mask32[] =  { 0, 8, 12,14 };
static const int mask64[] = {0, 16, 24, 28, 30};

// static const int magic8[] = {};
// static const int magic16[] = {};
static const int magic[] = { 2, 1,  0, 0 };
// static const int magic64[] = {};

/*
unsigned clz2(uint32_t x,int c)
{
    if (!x && !c) return 32;

    uint32_t upper = (x >> (16 >> c));
    uint32_t lower = (x & (0xFFFF >> mask[c]));
    if (c == 3) return upper ? magic[upper] : 2 + magic[lower];
    return upper ? clz2(upper, c + 1) : (16 >> (c)) + clz2(lower, c + 1);
}
*/

unsigned clz_uint8_rec(uint8_t x, int c)
{
    if (!x && !c) return 8;

    uint8_t upper = (x >> (4 >> c));
    uint8_t lower = (x & (0xF >> mask8[c]));
    if (c == 1) return upper ? magic[upper] : 2 + magic[lower];
    return upper ? clz_uint8_rec(upper, c + 1) : (4 >> (c)) + clz_uint8_rec(lower, c + 1);
}

unsigned clz_uint16_rec(uint16_t x, int c)
{
    if (!x && !c) return 16;

    uint16_t upper = (x >> (8 >> c));
    uint16_t lower = (x & (0xFF >> mask16[c]));
    if (c == 2) return upper ? magic[upper] : 2 + magic[lower];
    return upper ? clz_uint16_rec(upper, c + 1) : (8 >> (c)) + clz_uint16_rec(lower, c + 1);
}

unsigned clz_uint32_rec(uint32_t x, int c)
{
    if (!x && !c) return 32;

    uint32_t upper = (x >> (16 >> c));
    uint32_t lower = (x & (0xFFFF >> mask32[c]));
    if (c == 3) return upper ? magic[upper] : 2 + magic[lower];
    return upper ? clz_uint32_rec(upper, c + 1) : (16 >> (c)) + clz_uint32_rec(lower, c + 1);
}

unsigned clz_uint64_rec(uint64_t x, int c)
{
    if (!x && !c) return 64;

    uint64_t upper = (x >> (32 >> c));
    uint64_t lower = (x & (0xFFFFFFFF >> mask64[c]));
    if (c == 4) return upper ? magic[upper] : 2 + magic[lower];
    return upper ? clz_uint64_rec(upper, c + 1) : (32 >> (c)) + clz_uint64_rec(lower, c + 1);
}

#endif