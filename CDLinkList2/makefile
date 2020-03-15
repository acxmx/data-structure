main: main.o cdlklist.o algorithm.o
	g++ -o main main.o cdlklist.o algorithm.o
main.o: main.cc cdlklist.h
	g++ -g -o main.o -c main.cc
cdlklist.o: cdlklist.cc cdlklist.h
	g++ -g -o cdlklist.o -c cdlklist.cc
algorithm.o: algorithm.cc cdlklist.h
	g++ -g -o algorithm.o -c algorithm.cc

clean:
	rm *.o
