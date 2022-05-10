#include "../Implementacion_grafos/grafoPMC.h"
#include "../Implementacion_grafos/matriz.h"
#include "../Implementacion_grafos/grafoPMC.h"
#include "../Implementacion_grafos/alg_grafoPMC.h"
#include "../Implementacion_grafos/listaenla.h"
#include "../Implementacion_grafos/pilaenla.h"

#include <iostream>
#include <limits>

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
int main()
{
    GrafoP<unsigned int> G("gNoDiri.txt");

    cout << "--- Grafo G ---" <<endl;
    cout << G << endl;

    //cout << "Búsqueda del pseudocentro: " <<endl;
    //typename GrafoP<unsigned int>::tCoste diam = diametro(G);
    //cout<< "\nDiámetro: "<< diam << endl;

    GrafoP<unsigned int> A("gAciclico.txt");

    cout << "--- Grafo G ---" <<endl;
    cout << A << endl;


    return 0;
}
