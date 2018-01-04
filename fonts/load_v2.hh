#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#ifndef LOADV2
#define LOADV2
#define INF 1<<30
#define S 0
#define T 1
#define s 2
#define t 3

class LoadV2{
	
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

	bool reachable_v2(const Trip &t1, const Trip &t2);
	void load_recheable_v2(vector<vector<int> > &E, vector<vector<int> > &C, const vector<Trip> &trips);
	vector<int> BFSReach(vector<vector<int> > &E, int i);

public:
	LoadV2();
	pair< vector<vector<int>>,vector<vector<int>> > load_v2();
};

#endif	