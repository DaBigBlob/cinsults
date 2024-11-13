#ifndef SYSCALLS
#define SYSCALLS

#include "../utils/prelude.c"


/*
    THIS FILE NEEDS TO DEFINE:
        - ulong _sys_write(ulong fd, void* buf, ulong len)
        - ulong _sys_time()
        - NEWLINE macro
*/

#ifdef __APPLE__
    #define NEWLINE "\n"
    
    #ifdef __arm64__
        /*
            we need:
                - write
                - gettimeofday
            macos -> xnu -> bsd
            (https://github.com/apple-open-source/macos/blob/master/xnu/bsd/kern/syscalls.master)
            https://github.com/apple-open-source/macos/blob/8d328decdf52737f128024f07f5fba4ab39f9cb0/xnu/bsd/kern/syscalls.master#L49
            https://github.com/apple-open-source/macos/blob/8d328decdf52737f128024f07f5fba4ab39f9cb0/xnu/bsd/kern/syscalls.master#L190
            we see:
                - write is sycall # 4
                - gettimeofday is syscall # 116
        */

        #include <unistd.h>  // temporary till i write the syscalls

        ulong _sys_write(void* buf, ulong len) {
            return syscall(4, 1, buf, len);
        }


        ulong _sys_time() {
            struct timeval tv;
            syscall(116, &tv, 0);
            return tv.tv_sec;
        }
    #endif
#endif

// add more supported targets

#endif