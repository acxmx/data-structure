main: main.o TagBLList.o
	g++ -o main main.o TagBLList.o
main.o: main.cc TagBLList.h
	g++ -g -o main.o -c main.cc
TagBLList.o: TagBLList.cc TagBLList.h
	g++ -g -o TagBLList.o -c TagBLList.cc

clean:
	rm *.o
