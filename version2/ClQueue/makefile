main: main.o clqueue.o algorithm.o
	g++ -o main main.o clqueue.o algorithm.o
main.o: main.cc clqueue.h
	g++ -g -o main.o -c main.cc
clqueue.o: clqueue.cc clqueue.h
	g++ -g -o clqueue.o -c clqueue.cc
algorithm.o: algorithm.cc clqueue.h
	g++ -g -o algorithm.o -c algorithm.cc

clean:
	rm *.o
