main: main.o sqstack.o algorithm.o
	gcc -o main main.o sqstack.o algorithm.o
main.o: main.c sqstack.h
	gcc -g -o main.o -c main.c
sqstack.o: sqstack.c sqstack.h
	gcc -g -o sqstack.o -c sqstack.c
algorithm.o: algorithm.c sqstack.h
	gcc -g -o algorithm.o -c algorithm.c

clean:
	rm *.o
