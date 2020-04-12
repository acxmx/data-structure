ObjFiles=main.c sort.c
main: main.c sort.o
	gcc -o main $(ObjFiles)
main.o: main.c sort.h
	gcc -o main.o -c main.c
sort.o: sort.c sort.h
	gcc -o sort.o -c sort.c

clean:
	rm *.o
