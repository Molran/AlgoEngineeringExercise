CC=gcc -g

default: Fibonacci

Fibonacci.o :Fibonacci.c
	gcc Fibonacci.c -c

Fibonacci: Fibonacci.o
	$(CC) Fibonacci.o -o Fibonacci

clean:
	rm Fibonacci.o Fibonacci