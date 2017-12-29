#include <iostream>
#include <vector>
using namespace std;

#define INF 1<<30
#define S 0
#define T 1
#define s 2
#define t 3

struct Arista{
    int capacity;
    int flow;
    
    Arista(){}
    
    Arista(int capacity){
        this->capacity = capacity;
        this->flow = 0;
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



bool edmonds_karp(vector< Nodo >& G){
    return true;
}

void resetFlow(vector< Nodo >& G){
    
}


bool reachable_v1(const Nodo& i, const Nodo& j){
    return j.origen and i.airport == j.airport and j.time-i.time >= 15;
} 

int main(){
    int o, d, h1, h2;
    
    
    vector< Nodo > G(4);
    
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
    
//     cout << G[326].conexiones[0].first << endl << endl;
//     
//         for(int i = 0; i < G.size(); ++i){
//         for(int j = 0; j < G[i].conexiones.size(); ++j){
//             cout << G[i].conexiones[j].first << " "; 
//         }
//         cout << endl;
//     }
    
    for(int i = 4; i < G.size(); ++i){
        if(!G[i].origen){
            for(int j = 4; j < G.size(); ++j){
                if(reachable_v1(G[i], G[j])){
                    G[i].conexiones.push_back(make_pair(j, cap1));
                }
            }
        }
    }
    
    bool factible = false;
    int k = 1;
    
    while(not factible){
        G[S].conexiones[0].second.capacity = k;
        G[t].conexiones[0].second.capacity = k;
        
        factible = edmonds_karp(G);
        
        if(not factible){
            resetFlow(G);
        }
        ++k;
    }
    
    //Aqui tenemos el G correcto
    
}
