#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#ifndef RESULTS
#define RESULTS
#define INF 1<<30
#define S 0
#define T 1
#define s 2
#define t 3

class Results
{
	
private:

public:
	Results();
	void print_paths(const pair<int,vector<vector<int> > > &pilots,const vector<vector<int> >&E, const vector<vector<int> >&C, bool all);
};

#endif	