#ifndef STRING
#define STRING

#include "./prelude.c"
#include "../sys/calls.c" // IWYU pragma: keep

void first_str_mismatch(char** ref_str1, char** ref_str2) {
    char * str1 = *ref_str1, * str2 = *ref_str2;
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    *ref_str1 = str1;
    *ref_str2 = str2; 
}

#define strwrite(str) _sys_write(str, buflen(str, sizeof(char)))

char* str_from_ulong(ulong ul, char str[], ulong str_len) {
    char* cur = str+str_len;
    while (ul > 0) {
        cur--;
        *cur = ul%10 + 0x30;
        ul /= 10;
    }
    return cur;
}

#endif