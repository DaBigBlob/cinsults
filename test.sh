#!/bin/sh

BIN=$(./build.sh -nostdlib -O3)
sh -c "${BIN} $*"