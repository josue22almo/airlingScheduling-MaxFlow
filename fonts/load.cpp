#include "load.hh"

Load::Load(){}

bool Load::reachable(const Trip &t1, const Trip &t2){
    return t2.origen and t1.airport == t2.airport and t2.time - t1.time >= 15;
}

int Load::usage(){
    cout << "Usage:" << endl;
    cout << "   Your are trying to run a scheduling airline problem solver." << endl;
    cout << "   The correct usage is:" << endl;
    cout << "   ./airSche vx max_flow_algorithm ?all" << endl;
    cout << "   where" << endl;
    cout << "       - vx is the reacheable version to run, x must be 1 or 2, depending on the reachable version." << endl;
    cout << "       - max_flow_algorithm must be:" << endl;
    cout << "       - edmonds: run using Edmonds Karp, using BFS." << endl;
    cout << "           - ford: run using Ford Fulkerson, using DFS." << endl;
    cout << "       - all: is not mandatory, you have to set this param if you want to print all pilots rutes." << endl;
    return 0;
}
