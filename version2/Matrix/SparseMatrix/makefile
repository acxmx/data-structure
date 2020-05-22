ObjFiles=main.o sparse.o algorithm.o

main: $(ObjFiles)
	g++ -o main $(ObjFiles)
main.o: main.cc sparse.h
	g++ -g -o main.o -c main.cc
sparse.o: sparse.cc sparse.h
	g++ -g -o sparse.o -c sparse.cc
algorithm.o: algorithm.cc sparse.h
	g++ -g -o algorithm.o -c algorithm.cc

clean:
	rm *.o
