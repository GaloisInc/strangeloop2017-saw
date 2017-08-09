SAW?=saw
CLANG?=clang
CLANGOPTS?=-c -emit-llvm

CFILES=add-comm.c direct-swap.c xor-swap.c xor-swap-bug.c ffs.c
BCFILES=$(patsubst %.c, %.bc, ${CFILES})
LOGFILES=$(patsubst %.saw, %.log, $(wildcard *.saw))

all: ${BCFILES}

run: ${LOGFILES}

%.bc: %.c
	clang ${CLANGOPTS} -o $@ $<

%.log: %.saw
	${SAW} $< 2>&1 | tee $@

clean:
	rm -f ${BCFILES} ${LOGFILES}

ffs_bug.log: ffs.bc
ffs_bug_fail.log: ffs.bc
ffs_eq.log: ffs.bc
ffs_sat.log: ffs.bc
swap.log: xor-swap.bc
swap.log: xor-swap-bug.bc
swap.log: direct-swap.bc
