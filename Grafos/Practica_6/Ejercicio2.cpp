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
/*
Lista<Grafo::vertice> Profundidad2(const Grafo& G, Grafo::vertice u)
{
    typedef Grafo::vertice vertice;
    const size_t n = G.numVert();

    vector<visitas> marcas(n, NO_VISITADO);
    Pila<vertice> P;
    Lista<vertice> Lv;
    vertice i = u;
    
    do {
        if (marcas[i] == NO_VISITADO) {
            P.push(i);
            do {
                vertice v = P.tope(); P.pop();
                if (marcas[v] == NO_VISITADO) {
                    marcas[v] = VISITADO;
                    Lv.insertar(v, Lv.fin());
                    // Meter en la pila los adyacentes no visitados
                    for (vertice w = n; w > 0; w--)
                        if (G[v][w-1] && marcas[w-1] == NO_VISITADO)
                            P.push(w-1);
                }
            } while (!P.vacia());
        }
        i = (i+1) % n;
    } while (i != u);
    return Lv;
}*/
//MAIN---------------------------------

template<typename T>
typename GrafoP<T>::tCoste longitud(GrafoP<T> &G)
{
    typedef typename GrafoP<T>::vertice vertice;

    vertice pseudocentro,v;

    size_t numVert = G.numVert();
    
    vector<T> aux;
    vector<vertice> aux_vert;

    int sumatorio = 10000;

    for(v=0;v<numVert;v++)
    {
        aux = Dijkstra(G,v,aux_vert);

        sort(aux.begin(),aux.end());

        cout << aux[numVert-2]<<"||||"<<aux[numVert-1]<<endl;
        if(aux[numVert-2]+aux[numVert-1] < sumatorio)
        {
            pseudocentro = v;
            sumatorio = aux[numVert-2]+aux[numVert-1];   
        }
    }

    return sumatorio;

}

int main()
{
    GrafoP<unsigned int> G("gNoDiri.txt");

    cout << "--- Grafo G ---" <<endl;
    cout << G << endl;

    cout << "--- Longitud Grafo G ---" <<endl;
    cout << longitud(G) << endl;


    return 0;
}