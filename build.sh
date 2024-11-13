#!/bin/sh

MAIN="./src/sys/entry.c"
BUILDS="./bin"
NAME="cinsult"

mkdir -p $BUILDS

clang $MAIN "$@" -o "${BUILDS}/${NAME}" -nostdlib -fno-stack-protector -fno-unwind-tables -fno-asynchronous-unwind-tables

printf "%s" "${BUILDS}/${NAME}"