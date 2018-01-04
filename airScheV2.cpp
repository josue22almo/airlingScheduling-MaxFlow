#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1<<30
#define S 0
#define T 1
#define s 2
#define t 3

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

void print_edmonds(pair<int,vector<vector<int> > > &edmonds, const vector<vector<int> >&v,
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

void print_paths(const pair<int,vector<vector<int> > > &pilots,const vector<vector<int> >&E,
    const vector<vector<int> >&C) {
    vector<bool> done((E.size()-4)/2,false); //numero de viajes totales
    //act es el numero de nodo en el que estoy
    //viajeaux es el indice auxiliar para comprobar los viajes visitados
    
    int act = 5; // 4 para saltarme STst y 1 para apuntar destino
    int viajeaux = 0;
    
    for (int i=0; i < pilots.first; ++i){
        cout << viajeaux+1; //+1 porque los vuelos empiezan por el 1
        while (pilots.second[act][t] != 1){ 
            for (int j=0; j < E[act].size(); ++j){
                if (pilots.second[act][j] == 1){
                    done[(act-4)/2] = true;
                    cout << ' ' << (j-4)/2+1;
                    act = j+1; //act apunta al nodo destino del reacheble encontrado
                    j = E[act].size();
                }
            }
        }
        cout << endl;

        done[(act-4)/2] = true;
        while (i != pilots.first-1 and done[viajeaux]){
            ++viajeaux;
        }
        act = viajeaux*2+5; //act apunta al primer nodo destino no visitado
    }    
}

bool reachable_v1(const Trip &t1, const Trip &t2){
    return t2.origen and t1.airport == t2.airport and t2.time - t1.time >= 15;
}

vector<int> BFSReach(vector<vector<int> > &E, int i){
    //cout << "hola" << endl;
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

void load_trips(vector<vector<int> > &E, vector<vector<int> > &C, const vector<Trip> &trips){
    int n = trips.size();
    

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
//                  E[i].push_back(j);
                    C[i][j] = 1;
                }
            }            
        }
    }
    
    for(int i = 5; i < n; i+=2){
        vector<int> reachables = BFSReach(E, i);
        cout << i << ": ";
        for(int j = 0; j < reachables.size(); ++j){
            bool found = false;
            for(int k = 0; k < E[i].size() and !found; ++k){
                if(E[i][k] == reachables[j]) found = true;
            }
            if(!found){
             ///////////////////////////////////////////////////////
             ///// INSERTAR ARISTA DESDE I HASTA reachables[j] /////
             ///////////////////////////////////////////////////////
                

                
            }
            cout << reachables[j] << ", ";
        }
        cout << endl;
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

pair<int, vector<int> > BFS(const vector<vector<int> >&C, const vector<vector<int> >&E, const vector<vector<int> >&F){
    int n = C[0].size();
    vector<int> P(n, -1);
    P[S] = -2; // para asegurarnos de que no volvemos a S
    vector<int> M(n, INF);

    queue<int> Q;
    Q.push(S);

    while(!Q.empty()){
        int u = Q.front();
        for(int i = 0; i < E[u].size(); ++i){
            int v = E[u][i];
            if (C[u][v] - F[u][v] > 0 and P[v] == -1){
                P[v] = u;
                M[v] = min(M[u], C[u][v] - F[u][v]);
                if (v != T) Q.push(v);
            else
                return make_pair(M[T], P);
            }
        }
        Q.pop();
    }
    return make_pair(0, P);
}


pair<int, vector<vector<int> > > edmonds_karp(vector<vector<int> >&C, const vector<vector<int> >&E, int k){
    int f = 0;
    int n = C[0].size();
    vector<vector<int> > F(n, vector<int>(n, 0));
    C[S][s] = C[t][T] = C[s][t] = k;

    while(true){
        pair<int, vector<int> > bfs = BFS(C, E, F);

        if (bfs.first == 0)
            break;
        
        f += bfs.first;
        int v = T;

        while(v != S){
            int u = bfs.second[v];
            F[u][v] += bfs.first;
            F[v][u] -= bfs.first;
            v = u;
        }
    }
    return make_pair(f, F);
}

pair <int, vector<vector<int> > > compute_min_pilots(vector<vector<int> >&C, const vector<vector<int> >&E, int num_trips){
    bool troved = false;
    int k = INF;
    pair<int, vector<vector<int> > > edmonds;
    edmonds = edmonds_karp(C, E, k);
    // print_edmonds(edmonds, E, C);
//     while(!troved){
//         ++k;
//         edmonds = edmonds_karp(C, E, k);
// //         print_edmonds(edmonds, E, C);
//         troved = (edmonds.first == num_trips + k);
//     }
    // cout << "k = " << k << endl;
    edmonds.first = k - edmonds.second[s][t];
    // edmonds.first = k;
    return edmonds;
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
    pair <int, vector<vector<int> > > pilots = compute_min_pilots(C, E, num_trips);
    cout << "min pilots is " << pilots.first << endl;
     print_paths(pilots, C, E);
}
