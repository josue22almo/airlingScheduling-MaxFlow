#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1<<30
#define S 0
#define T 1
#define s 2
#define t 3

// void imprimir_E(vector<vector<int> > &v, vector<vector<int> > &C){
//     for (int i = 0; i < v.size(); ++i)
//     {
//         for (int j = 0; j < v[i].size(); ++j)
//         {
//             cout << "(" << i << ", " << v[i][j] << ") con C " << C[i][v[i][j]]<< endl;
//         }
//     }
// }

// void print_vector(const vector<int>& v){
//     for (int i = 0; i< v.size(); ++i){
//         cout << v[i] << ", ";
//     }
//     cout << endl;
// }

void print_edmonds(pair<int, vector<vector<int> >> &edmonds, const vector<vector<int> >&v,
    const vector<vector<int> >&C){
    cout << "Max flow is " << edmonds.first << endl;

    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            cout << "(" << i << ", " << v[i][j] << ") con F " << edmonds.second[i][v[i][j]]<< " con C " << C[i][v[i][j]]<< endl;
        }
    }
    cout << "================================" << endl;
    cout << "================================" << endl;
    cout << "================================" << endl;
}


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

bool reachable_v1(const Trip &t1, const Trip &t2){
    return t2.origen and t1.airport == t2.airport and t2.time - t1.time >= 15;
}

void load_trips(vector<vector<int> > &E, vector<vector<int> > &C, const vector<Trip> &trips){
    int n = trips.size();
    E[S].push_back(s);
    E[t].push_back(T);
    
    for (int i = 4; i < n; i+=2){
        C[s][i] = C[i][T] = 1;
        E[s].push_back(i);
        E[i].push_back(T);

        C[i+1][t] = C[S][i+1] = 1;
        E[i+1].push_back(t);
        E[S].push_back(i+1);
    }

    for (int i = 4; i < n; ++i){
        if(!trips[i].origen){
            for (int j = 4; j < n; ++j){
                if (reachable_v1(trips[i], trips[j])){
                    E[i].push_back(j);
                    C[i][j] = 1;
                }
            }            
        }
    }
    E[s].push_back(t);
}

pair<int, vector<int> > BFS(const vector<vector<int> >&C, const vector<vector<int> >&E, 
    const vector<vector<int> >&F){
    int n = C[0].size();
    vector<int> P(n, -1);
    P[S] = -2; // para asegurarnos de que no volvemos a S
    vector<int> M(n, INF);

    queue<int> Q;
    Q.push(S);

    // cout << "=======================" << endl;
    // cout << "Imprimiendo flows" << endl;

    // for (int i = 0; i < F.size(); ++i){
    //     for(int j = 0; j < F.size() ; ++j){
    //         cout << F[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    while(!Q.empty()){
        int u = Q.front();
        for(int i = 0; i < E[u].size(); ++i){
            int v = E[u][i];
            if (C[u][v] - F[u][v] > 0 and P[v] == -1){
                  P[v] = u;
                M[v] = min(M[u], C[u][v] - F[u][v]);
                if (v != T)
                    Q.push(v);
                else
                    return make_pair(M[T], P);
            }
        }
        Q.pop();
    }
    return make_pair(0, P);
}


pair<int, vector<vector<int> >> edmonds_karp(vector<vector<int> >&C, const vector<vector<int> >&E, int k, vector<vector<int> > &paths){
    int f = 0;
    int n = C[0].size();
    vector<vector<int> > F(n, vector<int>(n, 0));
    C[S][s] = C[t][T] = C[s][t] = k;
    // C[S][s] = C[t][T] = k;

    while(true){
        pair<int, vector<int> > bfs = BFS(C, E, F);

        if (bfs.first == 0)
            break;
        
        f += bfs.first;
        int v = T;

        vector<int> auxP;
        auxP.push_back(T);
        while(v != S){
            int u = bfs.second[v];
            auxP.push_back(u);
            F[u][v] += bfs.first;
            F[v][u] -= bfs.first;
            v = u;
        }

        
        cout << "paths is ";
        for(int j = auxP.size()-1; j >= 0 ; --j){
            cout << auxP[j] << " ";
        }
        cout << endl << "=======================" << endl;
        paths.push_back(auxP);
    }
    return make_pair(f, F);
}

int compute_min_pilots(vector<vector<int> >&C, const vector<vector<int> >&E, int num_trips){
    bool troved = false;
    int k = 0;
    vector<vector<int> > paths;
    while(!troved){
        ++k;
        vector<vector<int> > aux_paths;
        pair<int, vector<vector<int> >> edmonds = edmonds_karp(C, E, k, aux_paths);
        print_edmonds(edmonds, E, C);
        paths = aux_paths;
        troved = (edmonds.first == num_trips + k);
    }
    for (int i = 0; i < paths.size(); ++i){
        for(int j = paths[i].size()-1; j >= 0 ; --j){
            cout << paths[i][j] << " ";
        }
        cout << endl;
    }
    return k;
}

int main(){
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

    load_trips(E, C, trips);   
    int pilots = compute_min_pilots(C, E, num_trips);
    cout << "min pilots is " << pilots << endl;
}
