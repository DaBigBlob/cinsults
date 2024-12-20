
BIN = ./bin
NAME = cinsult
SRC = ./src
ENTRY = sys/entry.c

CC = clang
CFLAGS = -nostdlib -O3 -Wall -Wextra -Wfatal-errors -fno-stack-protector -fno-unwind-tables -fno-exceptions

build: ${SRC}/${ENTRY}
	@mkdir -p ${BIN}
	${CC} ${SRC}/${ENTRY} ${BA} -o ${BIN}/${NAME} ${CFLAGS}
	@printf "built to: %s\n" ${BIN}/${NAME}

clean: ${BIN}/
	@rm -r "${BIN}"

test: build
	@printf "running: "
	${BIN}/${NAME} ${TA}

