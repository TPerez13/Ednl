#include <iostream>
#include <fstream>
#include "../Implementacion_Arboles/Abin_enlazado.hpp"
#include "abin_E-S.h"

using namespace std;

static int cont;

int main()
{
   
    Abin a();

    int num_nodos = contar(a);
    

}

int contar(Nodo m)
{
    assert(m != NODO_NULO);
    res = contador(m,0);
    return res;
}

int contador(nodo n, int iterator)
{
    nodo m = NODO_NULO;

    if (n!=NODO_NULO)
    {
        m = new celda(n->elto);
        iterator++;

        if(m->hizq != NODO_NULO)
        {
            contador(m->hizq,contador(m,iterator));
        }
        if(m->hder != NODO_NULO)
        {
            contador(m->hder,iterator);
        }
    }

    return iterator;
}