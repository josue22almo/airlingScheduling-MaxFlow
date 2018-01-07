#include "load_v1.hh"

LoadV1::LoadV1(){}

void LoadV1::load_recheable_v1(vector<vector<int> > &E, vector<vector<int> > &C, const vector<Trip> &trips){
    int n = trips.size();
    E[t].push_back(T);

    for (int i = 4; i < n; ++i){
        if(!trips[i].origen){
            for (int j = 4; j < n; ++j){
                if (reachable(trips[i], trips[j])){
                    vector<int>::iterator it = E[i].begin();
                    int itrips = 0;
                    bool inserit = false;
                    while (it != E[i].end() and !inserit){
                        if(trips[j].time <= trips[E[i][itrips]].time){
                            E[i].insert(it,j);
                            inserit = true;
                        }
                        else{
                            ++itrips;
                            ++it;
                        }
                    }
                    if (!inserit) E[i].insert(it,j);
                    C[i][j] = 1;
                }
            }            
        }
    }

    for (int i = 4; i < n; i+=2){
        C[s][i] = C[i][T] = 1;
        E[s].push_back(i);
        E[i].push_back(T);

        C[i+1][t] = C[S][i+1] = 1;
        E[i+1].push_back(t);
        E[S].push_back(i+1);
    }

    E[S].push_back(s);
    E[s].push_back(t);
}
