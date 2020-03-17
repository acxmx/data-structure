main: main.o hfman.o
	g++ -o main main.o hfman.o
main.o: main.cc hfman.h
	g++ -g -o main.o -c main.cc
hfman.o: hfman.cc hfman.h
	g++ -g -o hfman.o -c hfman.cc

clean:
	rm *.o
