#!/bin/sh

MAIN="./src/sys/entry.c"
BUILDS="./builds"
NAME="cinsult"

mkdir -p $BUILDS

clang $MAIN "$@" -o "${BUILDS}/${NAME}-dbg"
clang $MAIN "$@" -O3 -o "${BUILDS}/${NAME}"

printf "%s" "${BUILDS}/${NAME}-dbg"