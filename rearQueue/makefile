main: main.o rqueue.o algorithm.o
	g++ -o main main.o rqueue.o algorithm.o
main.o: main.cc rqueue.h
	g++ -g -o main.o -c main.cc
rqueue.o: rqueue.cc rqueue.h
	g++ -g -o rqueue.o -c rqueue.cc
algorithm.o: algorithm.cc rqueue.h
	g++ -g -o algorithm.o -c algorithm.cc

clean:
	rm *.o
