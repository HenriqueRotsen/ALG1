#include "mapa.hpp"

void Mapa::adicionarObjeto(Objeto o, int x, int y)
{
    mapa[x][y] = o;
}

bool Mapa::isValid(vector<vector<bool>> vec, int x, int y)
{
    // Fora dos limites
    if (x < 0 || y < 0 || x >= this->n || y >= this->m)
        return false;

    // Ja foi visitado
    if (vec[x][y])
        return false;

    Objeto aux = this->mapa[x][y];
    if (aux.getTipo() == "barreira")
        return false;

    // Valido
    return true;
}

vector<int> Mapa::bfs(Objeto b)
{
    vector<vector<bool>> vec;
    vec.resize(this->n, vector<bool>(this->m));
    vector<int> dist_vec;
    dist_vec.resize(this->v);

    // Possiveis direcoes
    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};

    // Guarda indices e distancia da celula mae
    queue<pair<pair<int, int>, int>> q;

    // Marca a primeira celula como visitada
    // e coloca na fila
    q.push({{b.getX(), b.getY()}, 0});
    vec[b.getX()][b.getY()] = true;

    // Iterate while the queue
    // is not empty
    while (!q.empty())
    {

        pair<pair<int, int>, int> cell = q.front();
        int x = cell.first.first;
        int y = cell.first.second;
        int dist = cell.second;

        if(this->mapa[x][y].getTipo() == "visitante")
        {
            dist_vec[mapa[x][y].getId()-1] = dist;
        }

        q.pop();

        // Vai para as celulas adjacentes
        for (int i = 0; i < 4; i++)
        {
            
            int adjx = x + dRow[i];
            int adjy = y + dCol[i];

            if (isValid(vec, adjx, adjy))
            {
                q.push({{adjx, adjy}, dist+1}); //########
                vec[adjx][adjy] = true;
            }
        }
    }
    return dist_vec;
}

