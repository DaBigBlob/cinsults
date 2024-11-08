#!/bin/sh

BIN=$(./build.sh -DSYS_ARM64_APPLE_MACOS)
sh -c "${BIN} $*"