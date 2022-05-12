#include "mapa.hpp"




int main()
{
    Visitante v;
    int a;
    cout << "Entar com valor de x: " << endl;
    cin >> a;
    v.setX(a);
    
    cout << "Entar com valor de x: " << endl;
    cin >> a;
    v.setY(a);

    cout << "x: " << v.getX() <<  endl;
    cout << "y: " << v.getY() <<  endl;
    cout << "id: " << v.getId() <<  endl;
}


/*void Objeto::setX(int x)
{
    this->x = x;
}
int Objeto::getX()
{
    return this->x;
}

void Objeto::setY(int y)
{
    this->y = y;
}
int Objeto::getY()
{
    return this->y;
}

void Objeto::setId(int id)
{
    this->id = id;
}
int Objeto::getId()
{
    return this->id;
}

void Objeto::setTipo(string tipo)
{
    this->tipo = tipo;
}
string Objeto::getTipo()
{
    return this->tipo;
}*/