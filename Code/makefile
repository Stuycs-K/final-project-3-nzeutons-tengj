compile: algorithm.c methods.c methods.h
	@gcc -c algorithm.c methods.c
	@gcc -o out algorithm.o methods.o -lm

run: out
	@./out

out:
	@gcc -c algorithm.c methods.c
	@gcc -o out algorithm.o methods.o -lm