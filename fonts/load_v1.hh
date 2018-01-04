#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#ifndef LOADV1
#define LOADV1
#define INF 1<<30
#define S 0
#define T 1
#define s 2
#define t 3


class LoadV1{
	
private:
	struct Trip{
	    int airport;
	    int time;
	    bool origen;

	    Trip(){}
	    Trip(int airport, int time, bool origen){
	        this->airport = airport;
	        this->origen = origen;
	        this->time = time;
	    }
	};

	bool reachable_v1(const Trip &t1, const Trip &t2);
	void load_recheable_v1(vector<vector<int> > &E, vector<vector<int> > &C, const vector<Trip> &trips);

public:
	LoadV1();
	pair< vector<vector<int>>,vector<vector<int>> > load_v1();
};

#endif	