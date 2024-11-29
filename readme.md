# cinsults
Writes insult(s) to stdout. Written in the C programming language without stdlib (or any other lib).

> heavy WIP

## building
right now only clang is supported however gcc support is on the way.  
i recommend passing `CC="zig cc"` to `make` as well because it makes cross compiling insanely easy.  

### arm64 macos
```bash
    make build BA="-target aarch64-macos"
```
### x86_64 macos
```bash
    make build BA="-target x86_64-macos"
```
### arm64 linux
wip
### x86_64 linux
wip
### x86_64 windows
wip

## more targets
add support for more targets and compilers (+linkers) at `src/sys/calls` and `src/sys/entry`

## please help add more insults
to `src/insults.c`
just add more insults at the end of the char* array[].
make sure to update the patch insult version (the third number in the version string of INSULTS).