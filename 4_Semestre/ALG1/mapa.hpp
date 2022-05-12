#include <iostream>
#include <string.h>
#include <vector>


#ifndef MAPA_H
#define MAPA_H

using namespace std;

class Objeto
{
protected:
    int x;
    int y;
public:
    Objeto(){x = -1; y = -1;}
    virtual void setX(int x){this->x=x;};
    virtual int getX(){return x;};
    virtual void setY(int y){this->y=y;};
    virtual int getY(){return y;};
};

class Visitante: public Objeto
{   
private:
    int id;
public:
    Visitante() : Objeto() {};
    void setId(int id){this->id=id;};
    int getId(){return id;};
};


/*struct Objeto
{
    int x;
    int y;
    int id;
    string tipo;

    int getX();
    void setX(int x);

    int getY();
    void setY(int y);  

    int getId();
    void setId(int id);

    string getTipo();
    void setTipo(string tipo);
};*/




class Mapa
{
private:
    int n;
    int m;
    vector<vector<Objeto>> mapa;
public:
    Mapa(){
        mapa.resize(n,vector<Objeto>(m));
    };
    
};

#endif