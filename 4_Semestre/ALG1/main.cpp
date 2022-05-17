#include "mapa.hpp"
#include <assert.h>
#include <string.h>

int main()
{
    int v, n, m, valor;
    string input;

    Objeto ob;

    cout << "Entrar com numero de vititantes/bicicletas: ";
    cin >> v;
    assert(1 <= v && v <= 10);
    cout << "Entrar com numero de linhas do mapa: ";
    cin >> n;
    assert(1 <= n && n <= 1000);
    cout << "Entrar com numero de colunas do mapa: ";
    cin >> m;
    assert(1 <= m && m <= 1000);

    Objeto bic_vet[v];
    Mapa map(v, n, m);

    for (int i = 0; i < n; i++)
    {
        cin >> input; // le a configuracao da linha
        ob.setX(i);

        for (int j = 0; j < m; j++)
        {
            ob.setId(-1);
            ob.setY(j);

            if (input.at(j) == '*')
            {
                ob.setTipo("vazio");
            }
            else if (input.at(j) == '-')
            {
                ob.setTipo("barreira");
            }
            else if ('a' <= input.at(j) && input.at(j) <= 'j')
            {
                valor = (int)input.at(j) - 96;
                ob.setId(valor);
                ob.setTipo("visitante");
            }
            else if ('0' <= input.at(j) && input.at(j) <= '9')
            {
                valor = input.at(j) - '0';
                ob.setId(valor + 1);
                ob.setTipo("bicicleta");
                bic_vet[valor] = ob;
            }
            else
            {
                cout << "\nERRO: Entrada invalida\n";
                break;
            }
            map.adicionarObjeto(ob, i, j);
        }
    }

    int auxV[v][v];
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

    int auxB[v][v];
    for (int i = 0; i < v; i++)
    {
        vector<int> temp = map.bfs(bic_vet[i]);
        for (int j = 0; j < v; j++)
        {
            auxB[i][j] = temp[j];
        }
    }

    int pref_bic[v][v];
    int menor;
    for (int i = 0; i < v; i++) // para cada bicicleta...
    {
        for (int j = 0; j < v; j++) // para cada aluno...
        {
            pref_bic[i][j] = j + 1;
            menor = auxB[i][j];

            for (int k = 0; k < v; k++) // compare as distancias
            {
                if (auxB[i][k] < menor)
                {
                    ctrl = k;
                    menor = auxB[i][k];
                    pref_bic[i][j] = k + 1; // adiciona o id do visitante de menor distancia
                }
            }
            auxB[i][ctrl] = 100;
        }
    }
}