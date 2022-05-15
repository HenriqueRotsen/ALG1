#include "mapa.hpp"
#include <assert.h>
#include <string.h>

int main()
{
    int v, n, m, valor;
    string input;
    vector<Objeto> aux;

    Visitante vis;
    Bicicleta bic;
    Objeto ob;

    Mapa map;

    cout << "Entrar com numero de vititantes/bicicletas: ";
    cin >> v;
    assert(1 <= v && v <= 10);
    cout << "Entrar com numero de linhas do mapa: ";
    cin >> n;
    assert(1 <= n && n <= 1000);
    cout << "Entrar com numero de colunas do mapa: ";
    cin >> m;
    assert(1 <= m && m <= 1000);

    for (int i = 0; i < n; i++)
    {
        cin >> input; // le a configuracao da linha
        ob.setX(i);
        bic.setX(i);
        vis.setX(i);

        for (int j = 0; j < m; j++)
        {

            ob.setY(j);
            bic.setY(j);
            vis.setY(j);

            if (input.at(j) == '*')
            {
                ob.setTipo("vazio");
                aux.push_back(ob);
            }
            else if (input.at(j) == '-')
            {
                ob.setTipo("barreira");
                aux.push_back(ob);
            }
            else if ('a' <= input.at(j) && input.at(j) <= 'j')
            {
                valor = (int)input.at(j) - 96;
                vis.setId(valor);
                vis.setTipo("visitante");
                aux.push_back(vis);
            }
            else if ('0' <= input.at(j) && input.at(j) <= '9')
            {
                valor = (int)input.at(j) + 1;
                bic.setId(valor);
                bic.setTipo("bicicleta");
                aux.push_back(bic);
            }
            else
            {
                cout << "\nERRO: Entrada invalida\n";
            }
        }
        map.adicionarLinha(aux);
        aux.clear(); // limpa o vetor aux
    }

    int auxV[v][v];
    int pref_bic[v][v];
    int x;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> x;
            auxV[i][j] = x;
        }
    }

    int maior, ctrl;
    int pref_vist[v][v];
    for (int i = 0; i < v; i++) // para cada visitante...
    {
        for (int j = 0; j < v; j++) // para cada preferencia...
        {
            pref_vist[i][j] = j + 1;
            maior = auxV[i][j];

            for (int k = 0; k < v; k++) // compare as preferencias
            {
                if (auxV[i][k] > maior)
                {
                    ctrl = k;
                    maior = auxV[i][k];
                    pref_vist[i][j] = k + 1; // adiciona o id da bicicleta de maior preferencia
                }
            }
            auxV[i][ctrl] = 0;
        }
    }
}