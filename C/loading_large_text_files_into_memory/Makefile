all: run test

run: main.o loadfile.o
	clang main.o loadfile.o -o run

main.o: main.c
	clang -c main.c

loadfile.o: loadfile.c
	clang -c loadfile.c

test: test.c
	clang test.c -o test

clean:
	rm *.o run test
