#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1<<30
#define S 0
#define T 1
#define s 2
#define t 3

struct Arista{
    int capacity;
    int flow;
    bool backward;
    
    Arista(){}
    
    Arista(int capacity){
        this->capacity = capacity;
        this->flow = 0;
        this->backward = false;
    }
};

struct Nodo {
    int airport;
    int time;
    //int demanda;
    bool origen;
    
    vector< pair <int, Arista> > conexiones;
    
    Nodo(){}
    
    Nodo(int airport, int time, bool origen){
        this->airport = airport;
        this->time = time;
        this->origen = origen;
        //this->demanda = demanda;
    }
};

void print_flows(vector< Nodo >& G){
    for (int i = 0; i < G.size(); ++i){
        for (int j = 0; j < G[i].conexiones.size(); ++j)
        {
            cout << "(" << i << "-" << G[i].conexiones[j].first << ") -> " << G[i].conexiones[j].second.flow <<  endl;
        }
    }
}

vector<int> BFS(const vector<Nodo>& R){
    queue<int> q;
    q.push(S);
    
    vector<int> dist(R.size(), INF);
    vector<int> path(R.size(), -1);
    
    dist[S] = 0;
    
    vector<int> res;
    
    while(not q.empty()){
        int actual = q.front();
        q.pop();        
        if(actual == T){
            while(actual != S){
                res.push_back(actual);
                actual = path[actual];
            }
            res.push_back(S);
            cout << "acabé el BFS" << endl;
            return res;
        }
        for(int i = 0; i < R[actual].conexiones.size(); ++i){
            int next = R[actual].conexiones[i].first;
            int d = dist[actual] + 1;
            if(d < dist[next]){
                dist[next] = d;
                path[next] = actual;
                q.push(next);
            }
        }
    }
    cout << "acabé el BFS" << endl;
    return res;
}

void print_path(const vector<int> v){
    for (int i = v.size() - 1; i >= 0 ; --i)
    {
        cout << v[i] << " - ";
    }
    cout << endl;
}

bool edmonds_karp(vector<Nodo>& G, int& n){
    
    cout << "edmonds_karp" << endl;
    int f = 0;
    vector<Nodo> R = G;
    cout << "hago el BFS" << endl;
    vector<int> P = BFS(R);
    print_path(P);
    while(P.size() > 0){
        
        //Agument
        for(int i = P.size()-1; i > 0; --i){
            for(int j = 0; j < R[P[i]].conexiones.size(); ++j){
                if(R[P[i]].conexiones[j].first == P[i-1]){
                    if(not R[P[i]].conexiones[j].second.backward){
                        ++G[P[i]].conexiones[j].second.flow;
                    }
                    else --G[P[i]].conexiones[j].second.flow;
                }
            }
        }
        ++n;
        print_flows(G);
        cout << "=============================" << endl;
        P = BFS(R);
        print_path(P);
        cout << "=============================" << endl;
        cout << "=============================" << endl;
        cout << "=============================" << endl;
        //Actualizar residual
    }    
        
    return true;
}

void resetFlow(vector< Nodo >& G){
    for (int i = 0; i < G.size(); ++i){
        for (int j = 0; j < G[i].conexiones.size(); ++j)
        {
            G[i].conexiones[j].second.flow = 0;
        }
    }
}


bool reachable_v1(const Nodo& i, const Nodo& j){
    return j.origen and i.airport == j.airport and j.time-i.time >= 15;
} 

void imprimir_grafo(const vector<Nodo> &G){
    for(int i = 0; i < G.size(); ++i){
        cout << i << " -> ";
        for(int j = 0; j < G[i].conexiones.size(); ++j){
            cout << G[i].conexiones[j].first << " - "; 
        }
        cout << endl;
    }
}

int main(){
    int o, d, h1, h2;
    
    
    vector<Nodo> G(4);
    
    Arista cap1(1);
    G[S].conexiones.push_back(make_pair(s, cap1));
    G[t].conexiones.push_back(make_pair(T, cap1));
    
    /*
     * G[0] = Nodo S
     * G[1] = Nodo T
     * G[2] = Nodo s
     * G[3] = Nodo t
     */
    
    
    int numNodo = 4;
    
    while(cin >> o >> d >> h1 >> h2){
        
       Nodo origen(o, h1, true); //creo origen
       origen.conexiones.push_back(make_pair(T, cap1));
       G.push_back(origen);
       
       G[s].conexiones.push_back(make_pair(numNodo, cap1)); //enlace s a origen
       
       Nodo destino(d, h2, false);
       destino.conexiones.push_back(make_pair(t, cap1));
       G.push_back(destino);
       
       G[S].conexiones.push_back(make_pair(numNodo+1, cap1));
       
       numNodo += 2;
    }
    
    for(int i = 4; i < G.size(); ++i){
        if(!G[i].origen){
            for(int j = 4; j < G.size(); ++j){
                if(reachable_v1(G[i], G[j])){
                    G[i].conexiones.push_back(make_pair(j, cap1));
                }
            }
        }
    }
    // cout << "tengo mi grafo de reachables" << endl;
    // imprimir_grafo(G);
    bool factible = false;
    int k = 1;
    
    while(not factible){
        G[S].conexiones[0].second.capacity = k;
        G[t].conexiones[0].second.capacity = k;
        
        int n=0;
        factible = edmonds_karp(G, n);
        
        if(not factible){
            resetFlow(G);        
            ++k;
        }
    }
}
