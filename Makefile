all: program

test =
program: airSche.cpp
	g++ -o airSche airSche.cpp

test: program
	./airSche < $(test)

profe_test: program
	./airSche < Benchmark/instance_100_10_10.air
	./airSche < Benchmark/instance_100_10_1.air
	./airSche < Benchmark/instance_100_10_2.air
	./airSche < Benchmark/instance_100_10_3.air
	./airSche < Benchmark/instance_100_10_4.air
	./airSche < Benchmark/instance_100_10_5.air
	./airSche < Benchmark/instance_100_10_6.air
	./airSche < Benchmark/instance_100_10_7.air
	./airSche < Benchmark/instance_100_10_8.air
	./airSche < Benchmark/instance_100_10_9.air
