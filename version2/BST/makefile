ObjFiles=main.o bst.o algorithm.o

main: $(ObjFiles)
	g++ -o main $(ObjFiles)
main.o: main.cc bst.h
	g++ -g -o main.o -c main.cc
bst.o: bst.cc bst.h
	g++ -g -o bst.o -c bst.cc
algorithm.o: algorithm.cc bst.h
	g++ -g -o algorithm.o -c algorithm.cc

clean: 
	rm *.o
