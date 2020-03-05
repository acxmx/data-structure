main: main.o bllist.o
	g++ -o main main.o bllist.o
main.o: main.cc bllist.h
	g++ -g -o main.o -c main.cc
bllist.o: bllist.cc bllist.h
	g++ -g -o bllist.o -c  bllist.cc

clean:
	rm *.o
