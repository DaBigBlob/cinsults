#!/bin/sh

MAIN="./src/sys/entry.c"
BUILDS="./builds"
NAME="cinsult"

mkdir -p $BUILDS

clang $MAIN "$@" -o "${BUILDS}/${NAME}-dbg" -Wno-deprecated-declarations
clang $MAIN "$@" -O3 -o "${BUILDS}/${NAME}" -Wno-deprecated-declarations

printf "%s" "${BUILDS}/${NAME}-dbg"