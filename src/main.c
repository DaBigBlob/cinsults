
#ifndef MAIN
#define MAIN "0.1.5"

// #define DBG

#include "./sys/calls.c"
#include "./utils/str.c"
#include "./utils/argopt.c"
#include "./utils/int.c"
#include "./insults.c"

int cmd_version(char* stric) {
    strwrite("C Insult v");
    strwrite(MAIN);
    strwrite(" (list v");
    strwrite(INSULTS);
    strwrite(" with ");
    strwrite(stric);
    strwrite(" insults)" nl);
    return 0;
}

int cmd_help(char* stric, char* self) {
    cmd_version(stric);
    strwrite(
        "Author: Hman <hman@hman.io>" nl
        nl
        "Writes insult(s) to stdout. Written in the C programming language without stdlib." nl
        nl
        "USAGE" nl
    );
    strwrite(self);
    strwrite(
        "[OPTIONS...]" nl
        nl
        "RANK\tOPTIONS\t\tDESCRIPTION" nl
        "0" "\t-h --help"     "\tPrint this message to stdout" nl
        "1" "\t-v --version"  "\tPrint the version text" nl
        "2" "\t-n --no-delim" "\tDon't print delimiter (dafault: newline) after insult" nl
        "3" "\t-d --delim"    "\tDelimiter between (or after) insults (default: newline)" nl
        "4" "\t-a --all"      "\tPrint all insults, one on each line" nl
        "5" "\t-i --index"    "\tIndex (mod "
    );
    strwrite(stric);
    strwrite(
        ") of the insult to print (default: random)" nl
        nl
        "Unknown options are ignored." nl
        nl
        "OPTION CONFLICT" nl
        "Option with least rank number takes presidence if in conflict with nother option." nl
    );
    return 0;
}

int cmd_all(char* dlim) {
    ulong i = 0;
    for (; *(insults+i); i++) {
        strwrite((void *) insults[i]);
        strwrite(dlim);
    }
    return 0;
}

int prog_main(int argc, char** argv) {
    ulong ic = insult_count();
    char __ULONG_MAX_CHARS[] = "4294967295\0";
    char* stric = str_from_ulong(ic, __ULONG_MAX_CHARS, 11);

    if (arg_of_opt(argv, "-h") || arg_of_opt(argv, "--help")) return cmd_help(stric, argv[0]);
    if (arg_of_opt(argv, "-v") || arg_of_opt(argv, "--version")) return cmd_version(stric);

    char* d = nl;
    {
        if(arg_of_opt(argv, "-n") || arg_of_opt(argv, "--no-delim")) d = "";
        else {
            char* dd = arg_of_opt(argv, "-d");
            if (!dd) dd = arg_of_opt(argv, "--delim");
            if (dd) d = dd;
        }
    }

    if (arg_of_opt(argv, "-a") || arg_of_opt(argv, "--all")) return cmd_all(d);

    ulong i = 0;
    {
        char* ii = arg_of_opt(argv, "-i");
        if (!ii) ii = arg_of_opt(argv, "--index");
        if (ii) i = parse_ulong(ii)%ic;
        else i = _sys_time()%ic;
    }

    strwrite((void *) insults[i]);
    strwrite(d);

    return 0;
}

#endif