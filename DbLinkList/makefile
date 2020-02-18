main: main.o DbLinkList.o
	g++ -o main main.o DbLinkList.o
main.o: main.cc DbLinkList.h
	g++ -c main.cc -o main.o
DbLinkList.o: DbLinkList.cc DbLinkList.h
	g++ -c DbLinkList.cc -o DbLinkList.o
clean:
	rm *.o
