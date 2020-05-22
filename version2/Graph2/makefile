main: main.o graph.o algorithm.o
	g++ -o main main.o graph.o algorithm.o
main.o: main.cc graph.h
	g++ -g -o main.o -c main.cc
graph.o: graph.cc graph.h
	g++ -g -o graph.o -c graph.cc
algorithm.o: algorithm.cc graph.h
	g++ -g -o algorithm.o -c algorithm.cc

clean:
	rm *.o
