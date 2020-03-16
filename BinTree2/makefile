main: main.o btree.o algorithm.o
	g++ -o main main.o btree.o algorithm.o
main.o: main.cc btree.h
	g++ -g -o main.o -c main.cc
btree.o: btree.cc btree.h
	g++ -g -o btree.o -c btree.cc
algorithm.o: algorithm.cc btree.h
	g++ -g -o algorithm.o -c algorithm.cc

clean:
	rm *.o
