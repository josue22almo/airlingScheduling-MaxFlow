#!/bin/sh

echo 'Generating Resultados'$1'.txt file'
echo > ./results/Resultados$1.txt
cd ./Benchmark/
for i in `ls -v *.air`; do 
	../airSche v$1 edmonds  < $i > result
	r=$(head -n 1 result)
	echo $i" "$r >> ../results/Resultados$1.txt
done;

rm result
echo 'Done! The result has been saved in results folder.'

