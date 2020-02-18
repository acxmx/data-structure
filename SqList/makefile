main: main.o SqList.o
	g++ main.o SqList.o -o main
main.o: main.cc SqList.h
	g++ -c main.cc -o main.o
SqList.o: SqList.cc SqList.h
	g++ -c SqList.cc -o SqList.o

clean:
	rm *.o

gdb: main.cc SqList.cc SqList.h
	g++ -g -o main main.cc SqList.cc
