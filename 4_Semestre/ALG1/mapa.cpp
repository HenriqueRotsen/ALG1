#include "mapa.hpp"

void Mapa::adicionarLinha(vector<Objeto> v)
{
    mapa.push_back(v);
}

bool Mapa::isValid(vector<vector<bool>> vec, Objeto b)
{
    // Fora dos limites
    if (b.getX() < 0 || b.getY() < 0 || b.getX() >= this->n || b.getY() >= this->m)
        return false;

    // Ja foi visitado
    if (vec[b.getX()][b.getY()])
        return false;

    if (b.getTipo() == "barreira")
        return false;

    // Valido
    return true;
}

vector<int> Mapa::bfs(Objeto b)
{
    vector<vector<bool>> vec;
    vector<int> dist_vec;

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
            dist_vec[mapa[x][y].getId()] = dist;
        }

        q.pop();

        // Vai para as celulas adjacentes
        for (int i = 0; i < 4; i++)
        {
            
            int adjx = x + dRow[i];
            int adjy = y + dCol[i];
            Objeto aux = this->mapa[adjx][adjy];

            if (isValid(vec, aux))
            {
                q.push({{adjx, adjy}, dist + 1}); //########
                vec[adjx][adjy] = true;
            }
        }
    }
    return dist_vec;
}