#!/bin/sh

BIN=$(./build.sh -nostdlib -fno-stack-protector)
sh -c "${BIN} $*"