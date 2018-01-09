#!/bin/sh

echo 'Generating problem type mean time for version v'$1
cd ./Benchmark/
for tipo in {2..30}
do
    s=0.0
    echo > results
    for i in {1..10}
    do
        ../airSche v$1 edmonds  < 'instance_100_'$tipo'_'$i'.air' > result
        tail -n 1 result | egrep -o '[0-9]+.[0-9]+' >> results
    done
    ../ctimes < results > result
    r=$(cat result)  
    echo 'instance_100_'$tipo' '$r >> ../results/times_table$1.txt
done
echo 'Done! The results has been saved into results/times_table'$1'.txt'
rm result results

