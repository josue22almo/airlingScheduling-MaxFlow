all: program

program: airSche.cpp
	g++ -o airSche airSche.cpp

test: program
	./airSche < test2