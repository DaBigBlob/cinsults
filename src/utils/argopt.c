
#ifndef ARGOPT
#define ARGOPT

#include "./str.c"

// whole parsing opt is O(n(n+1)/2) i.e. O(n^2) but i dont care and avg(max(n)) = 6 anyways
char* arg_of_opt(char** argv, char* opt) {
    for (; *argv; argv++) {
        char* argmm = *argv, * optmm = opt;
        // dbg("*argv: \"%s\", opt: \"%s\"\n", *argv, opt);
        first_str_mismatch(&argmm, &optmm);
        if (*optmm) continue; // more opt left to match -> try next argv
        else {
            if (*argmm) { // complete opt match but not argv
                if (*argmm == '-' && *(argmm+1) && *(argmm+1) != '-') continue; // opt of format: --ab-cd -> try next
                else return argmm;  // else -> rest of argv is cmd arg [never null]
            }
            else return (*(++argv)) ? *argv : ""; // complete argv - opt match -> next argv is cmd arg
                                //^ special case: if ++argv is end, return self [for: semant: null -> opt DNE]
        }
    }
    return *argv; // always null <- end of argv array [semant: opt DNE]
}

#endif