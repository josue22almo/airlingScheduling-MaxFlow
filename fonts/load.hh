#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

#ifndef LOAD
#define LOAD
#define INF 1<<30
#define S 0
#define T 1
#define s 2
#define t 3


class Load{

protected:
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

	bool reachable(const Trip &t1, const Trip &t2);

public:
	Load();
	int usage();

	virtual pair< vector<vector<int>>,vector<vector<int>> > load(){
	    cout << "load base" << endl;
	    vector<vector<int>> nothing;
	    return make_pair(nothing, nothing);
	}
};

#endif	