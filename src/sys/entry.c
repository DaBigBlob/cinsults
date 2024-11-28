/*
    THE REAL ENTRY POINT
*/

#ifdef __clang__
    #include "../main.c"

    #define def_main
    int main(int argc, char** argv) {
        return prog_main(argc, argv);
    }
#endif

// add more supported compiler (linker) entries

#ifndef def_main
    #error "THIS COMPILER (LINKER) IS NOT SUPPORTED OUT OF THE BOX"
#endif