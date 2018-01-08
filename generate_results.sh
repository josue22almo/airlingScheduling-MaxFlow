#!/bin/sh

echo > ./results/Resultados$1.txt
cd ./Benchmark/
for i in `ls -v *.air`; do 
	../airSche v$1 edmonds  < $i > result
	r=$(cat result)
	echo $i" "$r >> ../results/Resultados$1.txt
done;

rm result

