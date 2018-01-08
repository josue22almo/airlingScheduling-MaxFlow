all: airSche

version = v1
type = edmonds

airSche: ./fonts/*.cpp
	g++ -c ./fonts/*.cpp
	g++ *.o -o airSche -Wall -W -std=c++11
	rm *.o

resultados: ./airSche
	./generate_results.sh 1
	./generate_results.sh 2

test: ./airSche
	./airSche $(version) $(type)  < Benchmark/instance_100_10_10.air >> test.txt
	./airSche $(version) $(type) < Benchmark/instance_100_10_1.air >> test.txt
	./airSche $(version) $(type) < Benchmark/instance_100_10_2.air >> test.txt
	./airSche $(version) $(type) < Benchmark/instance_100_10_3.air >> test.txt
	./airSche $(version) $(type) < Benchmark/instance_100_10_4.air >> test.txt
	./airSche $(version) $(type) < Benchmark/instance_100_10_5.air >> test.txt
	./airSche $(version) $(type) < Benchmark/instance_100_10_6.air >> test.txt
	./airSche $(version) $(type) < Benchmark/instance_100_10_7.air >> test.txt
	./airSche $(version) $(type) < Benchmark/instance_100_10_8.air >> test.txt
	./airSche $(version) $(type) < Benchmark/instance_100_10_9.air >> test.txt
	diff test.txt Benchmark/TablaResultadosEjemplo.txt
clean:
	rm airSche
