#!/bin/sh

BIN=$(./build.sh -nostdlib -O3 -fno-stack-protector)
sh -c "${BIN} $*"