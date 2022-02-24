#include <iostream>
#include <fstream>
#include "../Implementacion_Arboles/Abin_enlazado.hpp"
#include "abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

int calcular_profundidad(Abin<tElto> &A,typename Abin<tElto>::nodo n)
{
    int prof = -1;

    for(n; n != Abin<tElto>::NODO_NULO; n = A.padre(n))
    {
        prof++;
    }
    
    return prof;    
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

    int num_nodos = calcular_profundidad(B,B.hijoIzqdo(B.hijoIzqdo(B.hijoIzqdo(B.raiz()))));

    cout <<"El arbol a tiene una profundidad de "<<num_nodos<<" nodos"<<endl;

    return 0;
    
} 
