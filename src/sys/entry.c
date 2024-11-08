/*
    THE REAL ENTRY POINT
*/

//#define SYS_ARM64_APPLE_MACOS

// this is a template to be followed by all target triplets
#ifdef SYS_machine_vendor_operatingsystem
    #define SYS_TARGET
    #define SYS_machine
    #define SYS_vendor
    #define SYS_operatingsystem
#endif

#ifdef SYS_ARM64_APPLE_MACOS
    #define SYS_TARGET
    #define SYS_ARM64
    #define SYS_APPLE
    #define SYS_MACOS
#endif

#ifdef SYS_X86_64_GNU_WINDOWS
    #define SYS_TARGET
    #define SYS_X86_64
    #define SYS_GNU
    #define SYS_WINDOWS
#endif

// this is a template to be followed by all compilers
#ifdef __other_compiler__
    #define SYS_CC
    // other_compiler's linker entry point
#endif

#ifdef __clang__
    #define SYS_CC

    #include "../main.c"

    int main(int argc, char** argv) {
        return prog_main(argc, argv);
    }
#endif

#ifdef __GNUC__
    #define SYS_CC

    //todo
#endif


#ifndef SYS_CC // for unsupported compiler
    #include <stdio.h> // all nostd gaurentees are off
    #include "../utils/prelude.c"
    int _main(int argc, char** argv) {
        printf("THIS COMPILER IS NOT SUPPORTED.\n");
        printf("%s", nosupport);
        return 1;
    }
#endif