#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <cmath>
using namespace std;

#ifndef FORD_FULKERSON
#define FORD_FULKERSON
#define INF 1<<30
#define S 0
#define T 1
#define s 2
#define t 3

class FordFulkerson
{
	
private:
	vector<vector<int> >C;
	vector<vector<int> >E;
	vector<vector<int> > F;
	int n;
	vector<bool> visited;
	int k;
	bool is_path(int _s, int _t);
	
public:
	FordFulkerson();
	FordFulkerson(const vector<vector<int> > &C, const vector<vector<int> > &E);
	pair<int, vector<vector<int> > > max_flow();
};

#endif	