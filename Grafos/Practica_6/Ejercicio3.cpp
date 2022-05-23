#include "../Implementacion_grafos/grafoPMC.h"
#include "../Implementacion_grafos/matriz.h"
#include "../Implementacion_grafos/grafoPMC.h"
#include "../Implementacion_grafos/alg_grafoPMC.h"
#include "../Implementacion_grafos/listaenla.h"
#include "../Implementacion_grafos/pilaenla.h"

#include <iostream>
#include <limits>
#include <algorithm>    // std::sort

using namespace std;

template <typename T>
bool esHoja(GrafoP<T> &G,GrafoP<t>::vertice v)
{
    typedef typename GrafoP<T>::vertice vertice;
    
    bool bandera = true;
    for(size_t i=0;i<G.numVert() && bandera;i++)
    {
        if(!G[vertice][i] == GrafoP<T>::INFINITO)
            bandera = false;
    }
}

template <typename T>
void podar(GrafoP<T> &G, GrafoP<t>::vertice v)
{
    typedef typename GrafoP<T>::vertice vertice;

    for(size_t i=0;i<G.numVert();i++)
        G[vertice][i] == GrafoP<T>::INFINITO)
}

bool aciclico(GrafoP<T> &G)
{
    typedef typename GrafoP<T>::vertice vertice;

    Grafo<T> g = G;

    vertice v = 0;
    size_t cont = 0;

    bool vPodado[G.numVert()] = {false};
    for(v=0;v<G.numVert();v++)
    {
        if(esHoja(g,v) && !vPodado[v])
        {
            podar(g,v);
            cont++;
            v = -1
            vPodado[v] = true;
        }
    }
    return cont == G.numVert();
}