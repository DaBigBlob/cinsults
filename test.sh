#!/bin/sh

BIN=$(./build.sh)
sh -c "${BIN} $*"