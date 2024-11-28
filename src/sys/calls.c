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
            macos -> xnu -> bsd
            (https://github.com/apple-open-source/macos/blob/master/xnu/bsd/kern/syscalls.master)
            https://github.com/apple-open-source/macos/blob/8d328decdf52737f128024f07f5fba4ab39f9cb0/xnu/bsd/kern/syscalls.master#L49
            https://github.com/apple-open-source/macos/blob/8d328decdf52737f128024f07f5fba4ab39f9cb0/xnu/bsd/kern/syscalls.master#L190
        */
        #define def_syscall4
        void* syscall4(void* a1, void* a2, void* a3, void* a4) {
            void* _ret = 0;
            __asm__ volatile (
                "mov x16, %1\n"
                "mov x0, %2\n"
                "mov x1, %3\n"
                "mov x2, %4\n"
                "svc #0x80\n"
                "mov %0, x0\n"
                : "=r" (_ret)   // output operands
                : "r" (a1), "r" (a2), "r" (a3), "r" (a4) // input operands
                : "x3", "x4"  // clobbers
            );
            return _ret;
        }
    #endif

    #ifdef def_syscall4
        #define def_sys_write
        ulong _sys_write(void* buf, ulong len) {
            return (ulong) syscall4((void*)4, (void*)1, buf, (void*)len);
        }

        #define def_sys_time
        ulong _sys_time() {
            ulong tt[2];
            syscall4((void*)116, &tt, 0, 0);
            return *tt;
        }
    #endif
    
#endif

// add more supported targets

#ifndef def_sys_write
    #error "NO IMPLEMENTATION FOR write SYSCALL FOR THIS TARGET"
#endif
#ifndef def_sys_time
    #error "NO IMPLEMENTATION FOR time SYSCALL FOR THIS TARGET"
#endif
#endif