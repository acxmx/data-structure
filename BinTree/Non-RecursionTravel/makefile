main: main.o BLList.o SqStack.o
	g++ -o main main.o BLList.o SqStack.o
main.o: main.cc BLList.h
	g++ -g -o main.o -c main.cc
BLList.o: BLList.cc SqStack.cc BLList.h 
	g++ -g -o BLList.o -c BLList.cc 
SqStack.o: SqStack.cc SqStack.h
	g++ -g -o SqStack.o -c SqStack.cc


