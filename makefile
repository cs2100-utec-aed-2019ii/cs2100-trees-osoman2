run: compile
	./trees.o

compile:
	clang++ -o trees.o main.cpp

clear:
	rm trees.o
