main: main.o equijoin.o
	g++ -o main main.o equijoin.o
main.o: main.cc equijoin.h
	g++ -o main.o -c main.cc
equijoin.o: equijoin.cc equijoin.h
	g++ -o equijoin.o -c equijoin.cc

clean:
	rm *.o

gdb:
	g++ -g -o main main.cc equijoin.cc
