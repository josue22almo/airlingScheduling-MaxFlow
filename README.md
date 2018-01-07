# Airling Scheduling problem [MAX-FLOW]

This project covers the 20% of the evaluation of the subject Algoritmia (FIB - UPC Q1-TARDOR).

Project structure:

* Folderds:
   * Benchmark: some sample input files. You can use any of them to do some tests.
   * fonts: the source code of the project
* AirShe.pdf: project statement
* airSche-docu.pdf: our own documentation about the project.

## Getting Started

git clone https://github.com/josue22almo/airlingScheduling-MaxFlow.git

### Prerequisites

* g++
* git

### Compiling

To compile the source code move to the fonts/ folder and do type make in the terminal. One executable will be created:
   * airSche

## Running the tests

Type make test to run the teacher test with v1. 

## Makefile options
* type: set the algorithm type of a test. [default = edmodnds]
* version: set the recheable version of a test. [default = v1]

## Usage
Usage: running a scheduling airline problem solver.
  The correct usage is:
    ./airSche vx max_flow_algorithm ?all
    where
       - vx is the reacheable version to run, x must be 1 or 2, depending on the reachable version.
       - max_flow_algorithm must be:
       - edmonds: run using Edmonds Karp, using BFS.
           - ford: run using Ford Fulkerson, using DFS.
       - all: is not mandatory, you have to set this param if you want to print all pilots rutes.

