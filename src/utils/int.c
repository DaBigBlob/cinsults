
#ifndef INTS
#define INTS 

#include "./prelude.c"

static inline bool char_is_int(const char c) {
    return (0x30 < c && c < 0x39);
}

static inline bool safe_ulong(ulong ul) {
    return ul <= ~((ulong) 0);
}

// supports negative integers too
// non-number characters are treated as their (ascii value)-0x30
ulong parse_ulong(char* s) {
    ulong acc = 0, sn = 1;
    if (*s == '-') {
        sn = -1;
        s++;
    }
    while (*s) {
        acc *= 10;
        acc = acc + (*s - 0x30)*sn;
        s++;
    }
    return acc;
}

#endif