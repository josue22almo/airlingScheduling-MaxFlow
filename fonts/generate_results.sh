#!/bin/sh

echo > Resultados$1.txt
for i in `ls -v ../Benchmark/*.air`; do 
	./airSche v$1 edmonds  < $i >> Resultados$1.txt
done;

