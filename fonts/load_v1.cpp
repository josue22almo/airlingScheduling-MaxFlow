#include "load_v1.hh"

LoadV1::LoadV1(){}

bool LoadV1::reachable_v1(const Trip &t1, const Trip &t2){
    return t2.origen and t1.airport == t2.airport and t2.time - t1.time >= 15;
}

void LoadV1::load_recheable_v1(vector<vector<int> > &E, vector<vector<int> > &C, const vector<Trip> &trips){
    int n = trips.size();
    E[t].push_back(T);

    for (int i = 4; i < n; ++i){
        if(!trips[i].origen){
            for (int j = 4; j < n; ++j){
                if (reachable_v1(trips[i], trips[j])){
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

pair< vector<vector<int>>,vector<vector<int>> > LoadV1::load_v1(){
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

    load_recheable_v1(E, C, trips);

    return make_pair(C, E);
}
