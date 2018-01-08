all: airSche

version = v1
type = edmonds

airSche: ./fonts/*.cpp
	g++ -c ./fonts/*.cpp
	g++ *.o -o airSche -Wall -W -std=c++11
	rm *.o

resultados: airSche
	./generate_results.sh 1
	./generate_results.sh 2

test: airSche
	./airSche $(version) $(type)  < ./Benchmark/instance_100_10_10.air
	./airSche $(version) $(type) < ./Benchmark/instance_100_10_1.air
	./airSche $(version) $(type) < ./Benchmark/instance_100_10_2.air
	./airSche $(version) $(type) < ./Benchmark/instance_100_10_3.air
	./airSche $(version) $(type) < ./Benchmark/instance_100_10_4.air
	./airSche $(version) $(type) < ./Benchmark/instance_100_10_5.air
	./airSche $(version) $(type) < ./Benchmark/instance_100_10_6.air
	./airSche $(version) $(type) < ./Benchmark/instance_100_10_7.air
	./airSche $(version) $(type) < ./Benchmark/instance_100_10_8.air
	./airSche $(version) $(type) < ./Benchmark/instance_100_10_9.air

clean:
	rm airSche
