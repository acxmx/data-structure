main: main.o SqStack.o
	g++ -o main main.o SqStack.o
main.o: main.cc SqStack.h
	g++ -o main.o -c main.cc
SqStack.o: SqStack.cc SqStack.h
	g++ -o SqStack.o -c SqStack.cc

clean:
	rm *.o

gdb:
	g++ -g -o main main.cc SqStack.cc
