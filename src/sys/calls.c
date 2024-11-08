#ifndef SYSCALLS
#define SYSCALLS

/*
    THIS FILE NEEDS TO DEFINE:
        - ulong _sys_write(ulong fd, void* buf, ulong len)
        - ulong _sys_time()
*/

// #define SYS_MACOS
// #define SYS_ARM64

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

#ifdef SYS_MACOS
    #ifdef SYS_ARM64
        #define SYS_CALLS

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
    #include <stdio.h> // all nostd gaurentees are off if target id undefined
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