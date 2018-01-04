#include "edmonds_karp.hh"

EdmondsKarp::EdmondsKarp(){}

EdmondsKarp::EdmondsKarp(const vector<vector<int> > &C, const vector<vector<int> > &E, int k){
	this->C = C;
	this->E = E;
	this->k = k;
}

pair<int, vector<int> > EdmondsKarp::BFS(const vector<vector<int> > &C, const vector<vector<int> > &E, const vector<vector<int>> &F)
{
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

pair<int, vector<vector<int> > > EdmondsKarp::max_flow(){

	int f = 0;
    int n = C[0].size();
    vector<vector<int> > F(n, vector<int>(n, 0));
    C[S][s] = C[t][T] = C[s][t] = k;

    while(true){
        pair<int, vector<int> > bfs = BFS(C,E,F);

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
    return make_pair(k-F[s][t], F);
}
