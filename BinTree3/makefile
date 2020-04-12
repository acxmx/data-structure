ObjFiles=main.o btree.o algorithm.o
main: main.o btree.o algorithm.o
	gcc -o main main.o btree.o algorithm.o
main.o: main.c btree.h
	gcc -g -o main.o -c main.c
btree.o: btree.c btree.h
	gcc -g -o btree.o -c btree.c
algorithm.o: algorithm.c btree.h
	gcc -g -o algorithm.o -c algorithm.c

clean:
	rm *.o
