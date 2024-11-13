#!/bin/sh

MAIN="./src/sys/entry.c"
BUILDS="./bin"
NAME="cinsult"

mkdir -p $BUILDS

clang $MAIN "$@" -o "${BUILDS}/${NAME}"

printf "%s" "${BUILDS}/${NAME}"