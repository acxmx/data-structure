main: main.o BLList.o
	g++ -o main main.o BLList.o
main.o: main.cc BLList.h
	g++ -g -o main.o -c main.cc
BLList.o: BLList.cc BLList.h
	g++ -g -o BLList.o -c  BLList.cc

clean:
	rm *.o
