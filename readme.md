# cinsults
Writes insult(s) to stdout. Written in the C programming language without stdlib (or any other lib).

> heavy WIP

## building
right now only clang is supported however gcc support is on the way.  

### arm64 macos
```bash
    ./build.sh
```
you'll find builds in the bin/ directory
### x86_64 macos
wip
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

# note (for now)
dont try to use automatic optimizer i.e. `-O`. 
it will fuck things up.