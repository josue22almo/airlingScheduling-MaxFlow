all: program

test =
program: airSche.cpp
	g++ -o airSche airSche.cpp

test: program
	./airSche < $(test)