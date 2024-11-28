
BIN = ./bin
NAME = cinsult
SRC = ./src
ENTRY = sys/entry.c

CC = clang
CFLAGS = -nostdlib -Wall -Wextra -fno-stack-protector -fno-unwind-tables -fno-exceptions #-Wl,-no_compact_unwind

build: ${SRC}/${ENTRY}
	@mkdir -p ${BIN}
	${CC} ${SRC}/${ENTRY} ${BA} -o ${BIN}/${NAME} ${CFLAGS}
	@printf "built to: %s\n" ${BIN}/${NAME}

clean: ${BIN}/
	@rm -r "${BIN}"

.SILENT: test
test: build
	@printf "running:\n\n"
	${BIN}/${NAME} ${TA}

