main: main.o lkqueue.o algorithm.o
	g++ -o main main.o lkqueue.o algorithm.o
main.o: main.cc lkqueue.h
	g++ -g -o main.o -c main.cc
lkqueue.o: lkqueue.cc lkqueue.h
	g++ -g -o lkqueue.o -c lkqueue.cc
algorithm.o: algorithm.cc lkqueue.h
	g++ -g -o algorithm.o -c algorithm.cc

clean:
	rm *.o
