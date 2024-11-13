#!/bin/sh

MAIN="./src/sys/entry.c"
BUILDS="./bin"
NAME="cinsult"

mkdir -p $BUILDS

clang $MAIN "$@" -o "${BUILDS}/${NAME}" -nostdlib -fno-stack-protector -fno-unwind-tables -fno-exceptions -Wl,-no_compact_unwind

printf "%s" "${BUILDS}/${NAME}"