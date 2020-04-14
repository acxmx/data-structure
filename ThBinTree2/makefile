main: main.o thread.o algorithm.o
	g++ -o main main.o thread.o algorithm.o
main.o: main.cc thread.h
	g++ -g -o main.o -c main.cc
thread.o: thread.cc thread.h
	g++ -g -o thread.o -c thread.cc
algorithm.o: algorithm.cc thread.h
	g++ -g -o algorithm.o -c algorithm.cc

clean:
	rm *.o
