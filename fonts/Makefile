all: v1 v2

test =

compile: *.cpp
	g++ -c *.cpp

v1: compile
	g++ airScheV1.o edmonds_karp.o load_v1.o results.o -o airSche_v1 -Wall -W -std=c++11

v2: compile
	g++ airScheV2.o edmonds_karp.o load_v2.o results.o -o airSche_v2 -Wall -W -std=c++11

test: program
	./airSche < $(test)

profe_test_v1: v1
	./airSche_v1 < ../Benchmark/instance_100_10_10.air
	./airSche_v1 < ../Benchmark/instance_100_10_1.air
	./airSche_v1 < ../Benchmark/instance_100_10_2.air
	./airSche_v1 < ../Benchmark/instance_100_10_3.air
	./airSche_v1 < ../Benchmark/instance_100_10_4.air
	./airSche_v1 < ../Benchmark/instance_100_10_5.air
	./airSche_v1 < ../Benchmark/instance_100_10_6.air
	./airSche_v1 < ../Benchmark/instance_100_10_7.air
	./airSche_v1 < ../Benchmark/instance_100_10_8.air
	./airSche_v1 < ../Benchmark/instance_100_10_9.air

profe_test_v2: v2
	./airSche_v2 < ../Benchmark/instance_100_10_10.air
	./airSche_v2 < ../Benchmark/instance_100_10_1.air
	./airSche_v2 < ../Benchmark/instance_100_10_2.air
	./airSche_v2 < ../Benchmark/instance_100_10_3.air
	./airSche_v2 < ../Benchmark/instance_100_10_4.air
	./airSche_v2 < ../Benchmark/instance_100_10_5.air
	./airSche_v2 < ../Benchmark/instance_100_10_6.air
	./airSche_v2 < ../Benchmark/instance_100_10_7.air
	./airSche_v2 < ../Benchmark/instance_100_10_8.air
	./airSche_v2 < ../Benchmark/instance_100_10_9.air

clean:
	rm airSche_v1 airSche_v2 *.o
