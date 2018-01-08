#include "results.hh"
#include "iostream"
using namespace std;

Results::Results(){};

void Results::print_paths(const pair<int,vector<vector<int> > > &pilots,const vector<vector<int> >&E, const vector<vector<int> >&C, bool all){
	cout << pilots.first << endl;

	if (all){
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
}

