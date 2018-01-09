# Airling Scheduling problem [MAX-FLOW]

This project covers the 20% of the evaluation of the subject Algoritmia (FIB - UPC Q1-TARDOR).

Project structure:

* **Folders:**
   * **Benchmark:** some sample input files. You can use any of them to do some tests.
   * **fonts:** the source code of the project.
   * **results:** with some test results.
* **AirShe.pdf:** project statement
* **airSche-docu.pdf:** our own documentation about the project.
* **Makefile:** a Makefile to compile the project and run some test.
* **generate_results.sh:** a script that runs airShe solver using all the files in the Benchmark folde. To run the script you migth a number [1 or 2] depending on the recheable version you want. It saves the results in the result folder. 
* **generate_time_table.sh:** a sccript that computes mean execution time for each instances type. The results are saved into results/times\_table1.txt and results/times\_table2.txt


## Getting Started

git clone https://github.com/josue22almo/airlingScheduling-MaxFlow.git

## Prerequisites

* g++
* git

## Compiling

To compile the source code move to the fonts/ folder and do type make in the terminal. Two executable will be created:

* **airSche**: main program  
* **ctimes**: uses to compute instances type mean execution time.

## Running the tests

Type make test to run the teacher test with v1. 

## Makefile options
* **type:** set the algorithm type of a test. [default = edmodnds]
* **version:** set the recheable version of a test. [default = v1]

## Usage
Usage: running a scheduling airline problem solver.  
The correct usage is:  

		  ./airSche vx max_flow_algorithm ?all  

  where

 * vx is the reacheable version to run, x must be 1 or 2, depending on the reachable version.
 * max_flow_algorithm must be:
 * edmonds: run using Edmonds Karp, using BFS.
     * ford: run using Ford Fulkerson, using DFS.
 * all: is not mandatory, you have to set this param if you want to print all pilots rutes.

## Makefile usage

Main commands:

* **make**: generates the executable, airSche
* **make resultados**: generates results using the generate_results.sh script
* **make test**: runs airSche using the instances with problem of type 10.
