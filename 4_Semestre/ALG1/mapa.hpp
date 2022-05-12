#include <iostream>
#include <string.h>

using namespace std;

class Objeto
{
private:
    int x;
    int y;
public:
    Objeto(int linha, int coluna): x(linha), y(coluna){}
    virtual ~Objeto() {}
    virtual void setX(int x) const = 0;
    virtual int getX() const {
        return x;
    }
    
    virtual void sety(int y) const = 0;
    virtual int gety() const {
        return y;
    }

};

class Visitante: public Objeto
{   
private:
    int id;
public:
    Visitante(/* args */);
    ~Visitante();
};

Visitante::Visitante(/* args */)
{
}

Visitante::~Visitante()
{
}


class Mapa
{
private:
    Objeto ob*;
public:
    Mapa(/* args */);
    ~Mapa();
};
