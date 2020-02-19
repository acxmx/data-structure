main: main.o LinkStack.o
	g++ -o main main.o LinkStack.o
main.o: main.cc LinkStack.h
	g++ -o main.o -c main.cc
LinkStack.o: LinkStack.cc LinkStack.h
	g++ -o LinkStack.o -c LinkStack.cc

clean:
	rm *.o

gdb:
	g++ -g -o main main.cc LinkStack.cc
