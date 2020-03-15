main: main.o lklist.o algorithm.o
	g++ -o main main.o lklist.o algorithm.o
main.o: main.cc lklist.h
	g++ -g -o main.o -c main.cc
lklist.o: lklist.cc lklist.h
	g++ -g -o lklist.o -c lklist.cc
algorithm.o: algorithm.cc lklist.h
	g++ -g -o algorithm.o -c algorithm.cc

clean:
	rm *.o
