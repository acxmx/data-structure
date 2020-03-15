main: main.o dlklist.o algorithm.o
	g++ -o main main.o dlklist.o algorithm.o
main.o: main.cc dlklist.h
	g++ -g -o main.o -c main.cc
dlklist.o: dlklist.cc dlklist.h
	g++ -g -o dlklist.o -c dlklist.cc
algorithm.o: algorithm.cc dlklist.h
	g++ -g -o algorithm.o -c algorithm.cc

clean:
	rm *.o
