/*
    THE REAL ENTRY POINT
*/

#ifdef __clang__
    #include "../main.c"

    int main(int argc, char** argv) {
        return prog_main(argc, argv);
    }
#endif

// add more supported compiler (linker) entries