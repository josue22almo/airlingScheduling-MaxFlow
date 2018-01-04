#include "load_v2.hh"

LoadV2::LoadV2(){}

bool LoadV2::reachable_v2(const Trip &t1, const Trip &t2){
    return t2.origen and t1.airport == t2.airport and t2.time - t1.time >= 15;
}

vector<int> LoadV2::BFSReach(vector<vector<int> > &E, int i){
    vector<int> result;
    vector<bool> visited(E.size(), false);
    queue<int> Q;
    
    visited[i] = true;
    
    Q.push(i);

    while(!Q.empty()){
        int u = Q.front();
        
        
        if(u%2 == 0){
            result.push_back(u);
            Q.push(u+1);
        }
        else{
            
            for(int k = 0; k < E[u].size(); ++k){
                int v = E[u][k];
                if(!visited[v]){
                    visited[v] = true;
                    Q.push(v);
                }
            }
            
        }
        Q.pop();
    }
    return result;
}

void LoadV2::load_recheable_v2(vector<vector<int> > &E, vector<vector<int> > &C, const vector<Trip> &trips){
    int n = trips.size();
    

    for (int i = 4; i < n; ++i){
        if(!trips[i].origen){
            for (int j = 4; j < n; ++j){
                if (reachable_v2(trips[i], trips[j])){
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
    
    for(int i = 5; i < n; i+=2){
        vector<int> reachables = BFSReach(E, i);
        for(int j = 0; j < reachables.size(); ++j){
            bool found = false;
            for(int k = 0; k < E[i].size() and !found; ++k){
                if(E[i][k] == reachables[j]) found = true;
            }
            if(!found){
               
                vector<int>::iterator it = E[i].begin();
                    int itrips = 0;
                    bool inserit = false;
                    
                    while (it != E[i].end() and !inserit){
                        if(trips[reachables[j]].time <= trips[E[i][itrips]].time){
                            E[i].insert(it,reachables[j]);
                            inserit = true;
                        }
                        else{
                            ++itrips;
                            ++it;
                        }
                    }
                    
                    if (!inserit) E[i].insert(it,reachables[j]);
                    C[i][reachables[j]] = 1;
                
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
    
    E[t].push_back(T);
    E[S].push_back(s);
    E[s].push_back(t);
}

pair< vector<vector<int>>,vector<vector<int>> > LoadV2::load_v2(){
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


