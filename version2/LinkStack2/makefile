main: main.o lkstack.o algorithm.o
	g++ -o main main.o lkstack.o algorithm.o
main.o: main.cc lkstack.h
	g++ -g -o main.o -c main.cc
lkstack.o: lkstack.cc lkstack.h
	g++ -g -o lkstack.o -c lkstack.cc
algorithm.o: algorithm.cc lkstack.h
	g++ -g -o algorithm.o -c algorithm.cc

clean:
	rm *.o
