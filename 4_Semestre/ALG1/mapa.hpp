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
    string tipo;

public:
    Objeto()
    {
        x = -1;
        y = -1;
        tipo = "vazio";
    }
    virtual void setX(int x) { this->x = x; };
    virtual int getX() { return x; };
    virtual void setY(int y) { this->y = y; };
    virtual int getY() { return y; };
    virtual void setTipo(string t) { this->tipo = t;};
    virtual string getTipo() { return tipo; };
};

class Visitante : public Objeto
{
private:
    int id;
    vector<int> pref;
public:
    Visitante() : Objeto(){};
    void setId(int id) { this->id = id; };
    int getId() { return id; };
    void lerPreferencias(int id, int v);
};

class Bicicleta : public Objeto
{
private:
    int id;
    vector<int> pref;
public:
    Bicicleta() : Objeto(){};
    void setId(int id) { this->id = id; };
    int getId() { return id; };
};

class Mapa
{
private:
    int n;
    int m;
    vector<vector<Objeto>> mapa;

public:
    Mapa() {};

    void adicionarLinha(vector<Objeto> v);
    void edge(int a, Objeto b);
    void bfs(Objeto u);

    Objeto getObjeto(int id);

};

//        mapa.resize(n, vector<Objeto>(m));

#endif