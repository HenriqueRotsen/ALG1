#include "mapa.hpp"
#include <assert.h>
#include <string.h>
#include <map>
#include <list>

int main()
{
    int v, n, m, valor;
    string input;

    Objeto ob;

    // cout << "Entrar com numero de vititantes/bicicletas: ";
    cin >> v;
    assert(1 <= v && v <= 10);
    // cout << "Entrar com numero de linhas do mapa: ";
    cin >> n;
    assert(1 <= n && n <= 1000);
    // cout << "Entrar com numero de colunas do mapa: ";
    cin >> m;
    assert(1 <= m && m <= 1000);

    Objeto bic_vet[v];
    Mapa lagoa(v, n, m);

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
            lagoa.adicionarObjeto(ob, i, j);
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

    int maior, ctrl = 0;
    int pref_vist[v][v];
    for (int i = 0; i < v; i++) // para cada visitante...
    {
        for (int j = 0; j < v; j++) // para cada preferencia...
        {
            maior = auxV[i][j];
            ctrl = j;
            for (int k = 0; k < v; k++) // compare as preferencias
            {
                if (auxV[i][k] > maior)
                {
                    ctrl = k;
                    maior = auxV[i][k];
                }
            }
            pref_vist[i][j] = ctrl; // adiciona o id da bicicleta de maior preferencia
            auxV[i][ctrl] = 0;
        }
    }

    int auxB[v][v];
    for (int i = 0; i < v; i++)
    {
        vector<int> temp = lagoa.bfs(bic_vet[i]);
        for (int j = 0; j < v; j++)
        {
            auxB[i][j] = temp[j];
        }
    }

    list<int> freeVis; // vistantes sem match
    int i, current_bic, current_vis;
    int next[v];    // qual bicicleta sera proposta para cada visitante
    int matches[v]; // o atual casamento de cada bicileta
    int ex_vis;
    
    for (i = 0; i < v; i++)
    {
        freeVis.push_back(i);
        next[i] = 0;
        matches[i] = -1;
    }

    while (!freeVis.empty())
    {
        current_vis = freeVis.front();
        current_bic = pref_vist[current_vis][next[current_vis]];

        if (matches[current_bic] == -1) // se esta vazio
        {
            matches[current_bic] = current_vis;
            freeVis.pop_front();
        }
        else if (auxB[current_bic][current_vis] < auxB[current_bic][matches[current_bic]]) // compara as distancias
        {
            ex_vis = matches[current_bic];
            freeVis.pop_front();
            matches[current_bic] = current_vis;
            freeVis.push_front(ex_vis);
        }
        else if (auxB[current_bic][current_vis] == auxB[current_bic][matches[current_bic]]) // distancias iguais
        {
            if (current_vis < matches[current_bic]) // se o id de quem esta oferecendo for menor
            {
                ex_vis = matches[current_bic];
                freeVis.pop_front();
                matches[current_bic] = current_vis;
                freeVis.push_front(ex_vis);
            }
        }

        next[current_vis]++;
    }

    map<string, int> resp;
    string c;
    for (i = 0; i < v; i++)
    {
        c = matches[i] + 97;
        resp[c] = i;
    }
    for (map<string, int>::iterator it = resp.begin(); it != resp.end(); it++)
        cout << it->first << " " << it->second << endl;
}

