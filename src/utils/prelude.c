
#ifndef MISC
#define MISC 

typedef unsigned int uint;
typedef unsigned long int ulong ;

typedef enum _bool {
    true = 1,
    false = !1
} bool;

//nul terminated buffer
ulong buflen(void* buf, ulong element_size) {
    ulong i = 0;
    while (*( (char*) buf + (i*element_size))) i++;
    return i;
}

#endif