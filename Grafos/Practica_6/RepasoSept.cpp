#include "../Implementacion_grafos/grafoPMC.h"
#include "../Implementacion_grafos/matriz.h"
#include "../Implementacion_grafos/grafoPMC.h"
#include "../Implementacion_grafos/alg_grafoPMC.h"
#include "../Implementacion_grafos/listaenla.h"
#include "../Implementacion_grafos/pilaenla.h"

#include <iostream>
#include <limits>
#include <algorithm>    // std::sort

//Ejercicio 2

size_t diametro(GrafoP<T> &G)
{
    std::vector<GrafoP<T>::vertice> vec_ver_Dij;
    T sum_distancias_minimas;
    T longitud_min = 1000000;

    for(int i = 0;i<G.numVert()-1)
    {
        sum_distancias_minimas = 0;
        vec_ver_Dij = Dijkstra(G,G[i][j]);

        sort(vec_ver_Dij.begin(),vec_ver_Dij.end());

        sum_distancias_minimas = vec_ver_Dij[G.numVert()-1]+vec_ver_Dij[G.numVert()-2]
        
        if(sum_distancias_minimas < longitud_min)
            longitud_min = sum_distancias_minimas;
    }

    return longitud_min;
}


//Ejercicio 3 --- ES ACICLICO?

bool esAciclico(GrafoP<T> &G)
{
    Grafo<T> g = G;

    std::vector<bool> Podas = {false};

    for(int i=0;i<g.numvert()-1;g++)
    {
        if(esHoja(g,i) && Podas[i])
        {
            podar(g,i);
            Podas[i] = true;
            i=0;
            cont++;
        }
    }

    if(g.numVert() > 0)
        return false;
    else 
        return true;
}

void esHoja(GrafoP<T> &G, GrafoP<T>::vertice)
{
    bool bandera = true;

    for(int i=0 ; i<G.numVert() && bandera; i++)
    {
        if(G[vertice][i] != GrafoP<T>::INFINITO)
            bandera = false;
    }
}

void podar(GrafoP<T> &G, GrafoP<T>::vertice ver)
{
    for(int i=0 ; i<G.numVert(); i++)
        G[i][ver] = GrafoP<T>::INFINITO;
}


// Ejercicio 4

GrafoP<T> costes_min(GrafoP<T> G,List<Grafo<T>::vertice> ciudades_tomadas(),List<Grafo<T>::aristas> carreteras_cortadas
,Grafo<T>::vertice cap )
{
    List<Grafo<T>::vertice>::iterator it = ciudades_tomadas.begin();
    List<Grafo<T>::aristas>::iterator it2 = carreteras_cortadas.begin();
    
    
    while(it != ciudades_tomadas)
    {
        for(int i=0;i<g.numVert();i++)
            G[i][it] =  GrafoP<T>::INFINITO;

        it++;
    }

    while(it2 != carreteras_cortadas)
    {
        G[it.og][it.dest] == GrafoP<T>::INFINITO; 
        it2++;
    }

    std::vector<T> vec_Dij(G.numVert);
    std::vector<T> vec_DijInv(G.numVert);
    
    std::vector<GrafoP<T>::vertice>> vec_aux
    
    vec_Dij = Dijkstra(G,cap,P);
    vec_Dij_Inv = DijsktraInverso(G,cap,P);

    for(i=0;i<g.numVert;i++)
        for(j=0;j<g.numVert;j++)
            if(i != j)
                g[i][j] = g[i][cap] + g[cap][j];
            else
                g[i][j] = GrafoP<tCoste>::INFINITO;




}