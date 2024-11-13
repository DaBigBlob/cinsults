
#ifndef INSULTS
#define INSULTS "0.1.0"

#include "./utils/prelude.c"

static const char* insults[] = {
    "You're not even worthy of my insult.",
    "Skibidi.",
    "Rizz.",
    "Slut.",
    (char*) (long) 0 // end sentinel (add new insult before this)
};

ulong insult_count() BUFLEN(insults, char*, (char*) (long) 0)

#endif