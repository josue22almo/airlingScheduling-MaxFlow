#include <vector>
#include <queue>
#include "edmonds_karp.hh"
#include "load_v1.hh"
#include "results.hh"

int main(int argc, char *argv[]){
    LoadV1 load;

    pair< vector<vector<int>>,vector<vector<int>> > load_result =  load.load_v1();

    EdmondsKarp ed(load_result.first, load_result.second, INF);
    pair <int, vector<vector<int> > > pilots = ed.max_flow();
    Results re;
    re.print_paths(pilots, load_result.first, load_result.second, false);
}
