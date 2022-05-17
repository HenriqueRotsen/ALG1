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
private:
    int x;
    int y;
    int id;
    string tipo;

public:
    Objeto()
    {
        x = -1;
        y = -1;
        id = -1;
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
    int v;
    int n;
    int m;
    vector<vector<Objeto>> mapa;

public:
    Mapa(int v, int n, int m) {
        this->v = v;
        this->n = n;
        this->m = m;
        mapa.resize(n, vector<Objeto>(m)); 
    };

    void setV(int v) { this->v = v; };
    int getV() { return v; };
    void adicionarObjeto(Objeto, int x, int y);
    bool isValid(vector<vector<bool>> v, int x, int y);
    vector<int> bfs(Objeto b);
};

#endif