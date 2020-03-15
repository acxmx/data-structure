main: main.o sqqueue.o algorithm.o
	g++ -o main main.o sqqueue.o algorithm.o
main.o: main.cc sqqueue.h
	g++ -g -o main.o -c main.cc
sqqueue.o: sqqueue.cc sqqueue.h
	g++ -g -o sqqueue.o -c sqqueue.cc
algorithm.o: algorithm.cc sqqueue.h
	g++ -g -o algorithm.o -c algorithm.cc

clean:
	rm *.o
