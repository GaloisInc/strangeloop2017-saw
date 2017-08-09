SAW?=saw

run: salsa20.bc
	${SAW} salsa.saw

%.bc: %.c
	clang -c -g -emit-llvm $<

clean:
	rm -f *.bc
