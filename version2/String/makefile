ObjFiles=main.o string.o algorithm.o

main: $(ObjFiles)
	g++ -o main $(ObjFiles)
main.o: main.cc string.h
	g++ -o main.o -c main.cc
string.o: string.cc string.h
	g++ -o string.o -c string.cc
algorithm.o: algorithm.cc string.h
	g++ -o algorithm.o -c algorithm.cc

clean:
	rm *.o
