main: main.o CirQueue.o
	g++ -o main main.o CirQueue.o
main.o: main.cc CirQueue.h
	g++ -o main.o -c main.cc
CirQueue.o: CirQueue.cc CirQueue.h
	g++ -o CirQueue.o -c CirQueue.cc

clean:
	rm *.o
