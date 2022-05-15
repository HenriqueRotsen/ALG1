#include "mapa.hpp"

vector<bool> vec;

void Mapa::adicionarLinha(vector<Objeto> v)
{
    mapa.push_back(v);
}










void Mapa::edge(int a, Objeto b)
{
    mapa[a].push_back(b);
  
    // for undirected graph add this line
    // g[b].push_back(a);
}
  
/*void Mapa::bfs(Objeto u)
{
    queue<Objeto> q;
  
    q.push(u);
    v[u] = true;
  
    while (!q.empty()) {
  
        int f = q.front();
        q.pop();
  
        cout << f << " ";
  
        // Enqueue all adjacent of f and mark them visited 
        for (auto i = mapa[f].begin(); i != mapa[f].end(); i++) {
            if (!v[*i]) {
                q.push(*i);
                v[*i] = true;
            }
        }
    }
}*/