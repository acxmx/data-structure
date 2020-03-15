main: main.o sqlist.o algorithm.o
	g++ main.o sqlist.o algorithm.o -o main
main.o: main.cc sqlist.h
	g++ -g -o main.o -c main.cc
sqlist.o: sqlist.cc sqlist.h
	g++ -g -o sqlist.o -c sqlist.cc
algorithm.o: algorithm.cc sqlist.h
	g++ -g -o algorithm.o -c algorithm.cc
clean:
	rm *.o
