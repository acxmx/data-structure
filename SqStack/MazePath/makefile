main: main.o maze.o
	g++ -o main main.o maze.o
main.o: main.cc maze.h
	g++ -o main.o -c main.cc
maze.o: maze.cc maze.h
	g++ -o maze.o -c maze.cc

clean:
	rm *.o

gdb:
	g++ -g -o main main.cc maze.cc
