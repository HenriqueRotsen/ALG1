#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <iterator>

#ifndef MAPA_H
#define MAPA_H

using namespace std;

class Objeto
{
protected:
    int x;
    int y;
    int id;
    string tipo;

public:
    Objeto()
    {
        x = -1;
        y = -1;
        tipo = "vazio";
    }
    void setId(int id) { this->id = id; };
    int getId() { return id; };
    void setX(int x) { this->x = x; };
    int getX() { return x; };
    void setY(int y) { this->y = y; };
    int getY() { return y; };
    void setTipo(string t) { this->tipo = t; };
    string getTipo() { return tipo; };
};

class Mapa
{
private:
    int n;
    int m;
    vector<vector<Objeto>> mapa;

public:
    Mapa(int n, int m) { mapa.resize(n, vector<Objeto>(m)); };

    void adicionarLinha(vector<Objeto> v);
    bool isValid(vector<vector<bool>> v, Objeto b);
    vector<int> bfs(Objeto b);
};

#endif