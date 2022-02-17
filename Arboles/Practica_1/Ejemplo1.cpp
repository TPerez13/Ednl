#include <iostream>
#include <fstream>
#include "../Implementacion_Arboles/Abin_enlazado.hpp"
#include "abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

int contador(typename Abin<tElto>::nodo n, int iterator)
{
    Abin<tElto>::nodo m = Abin<tElto>::NODO_NULO;

    if (n!=Abin<tElto>::NODO_NULO)
    {
        m = n;

       
        if(m->hizq != Abin<tElto>::NODO_NULO)
        {
            contador(m->hizq,iterator+=1);
        }
        if(m->hder != Abin<tElto>::NODO_NULO)
        {
            contador(m->hder,iterator+=1);
        }
        
    }
     cout<<"El iterador es"<<iterator<<endl;
    return iterator;
}

int contar(typename Abin<tElto>::nodo m)
{
    assert(m != Abin<tElto>::NODO_NULO);
    std::cout<<"Ha llegado";
    int res = contador(m,1);
    return res;
}

int main ()
{
    Abin<tElto> /*A,*/ B;
     /*
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // Desde std::cin

    ofstream fs("abin.dat"); // Abrir fichero de salida.
    imprimirAbin(fs, A, fin); // En fichero.
    fs.close();
    cout << "\n*** Árbol A guardado en fichero abin.dat ***\n";*/

    cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
    ifstream fe("abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, B); // Desde fichero.
    fe.close();

    cout << "\n*** Mostrar árbol binario B ***\n";
    imprimirAbin(B); // En std::cout

    int num_nodos = contar(B.raiz());

    cout <<"El arbol a tiene"<<num_nodos<<"nodos"<<endl;

    return 0;
    
} 
