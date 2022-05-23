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
void podar(GrafoP<T> &G, GrafoP<t>::vertice v)
{
    typedef typename GrafoP<T>::vertice vertice;

    for(size_t i=0;i<G.numVert();i++){
        G[vertice][i] = GrafoP<T>::INFINITO;
        G[i][vertice] = GrafoP<T>::INFINITO;
    }
}

template <typename T>
GrafoP<T> minpath_toZu(GrafoP<T> &G,Lista<GrafoP<T>::vertice> tomado,Lista<GrafoP<T>::aristas> cortadas, vertice cap)
{
    typedef typename GrafoP<T>::vertice vertice;
    typedef typename GrafoP<T>::aristas aristas;
    
    GrafoP<T> g = G;
    Lista<GrafoP<T>::vertice>::iterator it = tomado.begin();
    
    while(it != tomado.end()) 
        podar(g,tomado.elemento(it));
    

    Lista<GrafoP<T>::vertice>::iterastor it2 = cortadas.begin();
    aristas = cortadas.elemento(it2);
    
    while (it2 != tomado.end())
        Grafo[arista.orig][arista.dest] = GrafoP<T>::INFINITO;
    

    
    
    vector<vertice> aux_vert;
    vector<T> aux,aux2;

    aux = DijkstraInv(g,cap,aux_vert);

    aux2 = Dijkstra(g,cap,aux_vert);

    matriz<tCoste> mCostes;

    for(size_t i = 0; i<g.numVert();i++)
        for(size_t j = 0; j<g.numVert();j++)
        {
            if(i == j)
                mCostes[i][j] == GrafoP<tCoste>::INFINITO;
            else
                mCostes[i][j] = aux[i] + aux2[j];
        }

    return mCostes;
}