#include <iostream>
#include <vector>
using namespace std;

struct InfoArista{
    int capacity;
    int lowerBound;
    int flow;
    
    InfoArista(int capacity, int lowerBound){
        this->capacity = capacity;
        this->lowerBound = lowerBound;
        this->flow = 0;
    }
};

struct Nodo {
    int airport;
    int time;
    int demanda;
    bool origen;
    
    vector< pair <int, InfoArista> > conexiones;
    
    Nodo(){}
    
    Nodo(int airport, int time, bool origen){
        this->airport = airport;
        this->time = time;
        this->origen = origen;
    }
};



int main(){
    int o, d, h1, h2;
    vector< Nodo > G;
    
    
    
    InfoArista vuelo(1,1);
    InfoArista aux(1,0);

    
    Nodo s;
    G.push_back(s);    
    Nodo t;
    G.push_back(t);  
    
    Nodo S;
    G.push_back(S);
    
    Nodo T;
    G.push_back(T);
    
    
    G[2].conexiones.push_back(make_pair(0, aux));
    G[1].conexiones.push_back(make_pair(3, aux));
    
    int numNodo = 4;
    while(cin >> o >> d >> h1 >> h2){
       Nodo origen(o, h1, true);
       G[0].conexiones.push_back(make_pair(numNodo, aux));
       G[2].conexiones.push_back(make_pair(numNodo, aux));
       origen.conexiones.push_back(make_pair(numNodo+1, vuelo));
       G.push_back(origen);
       Nodo destino(d, h2, false);
       destino.conexiones.push_back(make_pair(1, aux));
       G.push_back(destino);
       numNodo += 2;
    }
    
//     cout << G[326].conexiones[0].first << endl << endl;
//     
//         for(int i = 0; i < G.size(); ++i){
//         for(int j = 0; j < G[i].conexiones.size(); ++j){
//             cout << G[i].conexiones[j].first << " "; 
//         }
//         cout << endl;
//     }
    
    for(int i = 0; i < G.size(); ++i){
        if(!G[i].origen){
            for(int j = 0; j < G.size(); ++j){
                if(G[j].origen and G[i].airport == G[j].airport and G[j].time-G[i].time >= 15){
                    
                    G[i].conexiones.push_back(make_pair(j, aux));
                }
            }
        }
    }
    

    
    
    
}
