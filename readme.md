# cinsults
Writes insult(s) to stdout. Written in the C programming language without stdlib.

> heavy WIP

## building
right now only clang is supported however gcc support is on the way
### arm64 macos
```bash
    ./build.sh -DSYS_ARM64_APPLE_MACOS
```
you'll find builds in the builds/ directory
### x86_64 macos
wip
### arm64 linux
wip
### x86_64 linux
wip
### x86_64 windows
wip

## please help add more insults
to `src/insults.c`
just add more insults at the end of the char* array[].
make sure to update the patch insult version (the third number in the version string of INSULTS).