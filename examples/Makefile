SAW?=saw
CLANG?=clang
CLANGOPTS?=-c -emit-llvm

CFILES=$(wildcard *.c)
BCFILES=$(patsubst %.c, %.bc, ${CFILES})
LOGFILES=$(patsubst %.saw, %.log, $(wildcard *.saw))

all: deps.mk ${BCFILES}

run: ${LOGFILES}

%.bc: %.c
	clang ${CLANGOPTS} -o $@ $<

%.log: %.saw
	${SAW} $< 2>&1 | tee $@

clean:
	rm -f ${BCFILES} ${LOGFILES}

deps.mk:
	./mkdeps.sh

-include deps.mk
