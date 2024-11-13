
#ifndef PRELUDE
#define PRELUDE 

typedef unsigned int uint;
typedef unsigned long int ulong ;

typedef enum _bool {
    true = 1,
    false = !1
} bool;

#define BUFLEN(buf, type, dlim) { ulong i = 0; while (*( (type*) buf + i) != dlim) i++; return i; }

#endif