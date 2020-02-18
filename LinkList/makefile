main: main.o LinkList.o
	g++ -o main main.o LinkList.o
main.o: main.cc LinkList.h
	g++ -c main.cc -o main.o
LinkList.o: LinkList.cc LinkList.h
	g++ -c LinkList.cc -o LinkList.o
clean:
	rm *.o
