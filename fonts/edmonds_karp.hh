#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

#ifndef EDMONDS_KARP
#define EDMONDS_KARP
#define INF 1<<30
#define S 0
#define T 1
#define s 2
#define t 3

class EdmondsKarp
{
	
private:
	vector<vector<int> >C;
	vector<vector<int> >E;
	int k;
	pair<int, vector<int> > BFS(const vector<vector<int> > &F);
	
public:
	EdmondsKarp();
	EdmondsKarp(const vector<vector<int> > &C, const vector<vector<int> > &E);
	pair<int, vector<vector<int> > > max_flow();
};

#endif	
