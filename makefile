all: randfile.o
	gcc randfile.o

clear:
	rm *.o

run:
	./a.out

randfile.o: randfile.c
	gcc -c -g randfile.c
