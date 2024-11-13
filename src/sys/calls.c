#ifndef SYSCALLS
#define SYSCALLS

/*
    THIS FILE NEEDS TO DEFINE:
        - ulong _sys_write(ulong fd, void* buf, ulong len)
        - ulong _sys_time()
*/

#include "../utils/prelude.c"

// this is a template to be followed by all target and/or compilers combinations
// you can be arbitarily specific i.e. add vendor r compiler to specification of syscall
#ifdef SYS_operatingsystem
    #ifdef SYS_machine
        #define SYS_CALLS

        ulong _sys_write(void* buf, ulong len) {
            return 0;
        }

        ulong _sys_time() {
            return 0;
        }
    #endif
#endif

// #define SYS_MACOS
// #define SYS_ARM64

#ifdef SYS_MACOS
    #ifdef SYS_ARM64
        #define SYS_CALLS

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

#ifndef SYS_CALLS
    #include <stdio.h> // all nostd gaurentees are off if target is undefined
    #include "../utils/prelude.c"
    ulong _sys_write(void* buf, ulong len) {
        printf("\nTHIS TARGET IS NOT SUPPORTED.\n");
        printf("%s", nosupport);
        return 1;
    }

    ulong _sys_time() {
        return 0;
    }
#endif

#endif