make: sigs.o
	gcc -o sigs sigs.o
sigs.o: sigs.c
	gcc -c sigs.c
