#include <vector>
#include <queue>
#include <iostream>
#include "load.hh"
using namespace std;

#ifndef LOADV2
#define LOADV2

class LoadV2: public Load{
	
private:
	void load_recheable_v2(vector<vector<int> > &E, vector<vector<int> > &C, const vector<Trip> &trips);
	vector<int> BFSReach(vector<vector<int> > &E, int i);

public:
	LoadV2();

	virtual pair< vector<vector<int>>,vector<vector<int>> > load(){
		vector<Trip> trips(4);

	    int o, d, h1, h2;
	    int num_trips = 0;
	    while(cin >> o >> d >> h1 >> h2){
	        trips.push_back(Trip(o,h1,true));
	        trips.push_back(Trip(d,h2,false));
	        ++num_trips;
	    }

	    int n = trips.size();
	    vector<vector<int> > C(n, vector<int>(n, 0));
	    vector<vector<int> > E(n);

	    load_recheable_v2(E, C, trips);

	    return make_pair(C, E);
	}
};

#endif	