#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#ifndef RESULTS
#define RESULTS

class Results
{
	
private:

public:
	Results();
	void print_paths(const pair<int,vector<vector<int> > > &pilots,const vector<vector<int> >&E, const vector<vector<int> >&C, bool all);
};

#endif	