
BIN = ./bin
NAME = cinsult
SRC = ./src
ENTRY = sys/entry.c

CC = clang
CFLAGS = -nostdlib -fno-stack-protector -fno-unwind-tables -fno-exceptions #-Wl,-no_compact_unwind

clean: ${BIN}
	rm -d "${BIN}/*"

build: ${SRC}/${ENTRY}
	mkdir -p ${BIN}
	${CC} ${SRC}/${ENTRY} ${BARGS} -o ${BIN}/${NAME} ${CFLAGS}

test: build
	${BIN}/${NAME} ${TARGS}