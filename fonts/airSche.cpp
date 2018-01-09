#include <vector>
#include <queue>
#include "edmonds_karp.hh"
#include "ford_fulkerson.hh"
#include "load.hh"
#include "load_v1.hh"
#include "load_v2.hh"
#include "results.hh"

int main(int argc, char *argv[]){
    Load *load = new Load(); 
 
    if(argc >= 3 and argc <= 4){
    	if(argv[1] == string("v1"))
    		load = new LoadV1();
	    else if(argv[1] == string("v2"))
	    	load = new LoadV2();
	    else{
	    	return (*load).usage();
	    }


	    pair< vector<vector<int> >,vector<vector<int> > > load_result =  (*load).load();
    	pair <int, vector<vector<int> > > pilots;
    	if (argv[2] == string("edmonds")){
    		EdmondsKarp ed(load_result.first, load_result.second);
    		pilots = ed.max_flow();
    	}
    	else if (argv[2] == string("ford")){
    		FordFulkerson ff(load_result.first, load_result.second);
    		pilots = ff.max_flow();
    	}
    	else{
    		return (*load).usage();
    	}
    	Results re;
	    if(argc == 4){
	    	if(argv[3] == string("all"))
	    		re.print_paths(pilots, load_result.first, load_result.second, true);
	    	else{
	    		return (*load).usage();
	    	}
	    }
	    else
	    	re.print_paths(pilots, load_result.first, load_result.second, false);
    } else{
    	(*load).usage();
    	return 0;
    }
}
