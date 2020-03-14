main: main.o graph.o
	g++ -o main main.o graph.o
main.o: main.cc graph.h
	g++ -g -o main.o -c main.cc
graph.o: graph.cc graph.h
	g++ -g -o graph.o -c graph.cc

clean:
	rm *.o
