/*
    THE REAL ENTRY POINT
*/

#ifdef __APPLE__
    #include "../main.c"

    #define def_main
    int main(int argc, char** argv) {
        (void)argc;
        return prog_main(argv);
    }
#endif

#ifdef __linux__
    #include "../main.c"

    #error "BROKEN: will fix later"
    #define def_main
    int _start(int argc, char** argv) {
        (void)argc;
        return prog_main(argv);
    }
#endif

// add more supported compiler (linker) entries

#ifndef def_main
    #error "THIS TARGET'S COMPILER (LINKER) IS NOT SUPPORTED OUT OF THE BOX"
#endif