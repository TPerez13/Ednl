//Implemente una función que modifique un árbol binario de forma que si
// el árbol tiene nodos con un solo hijo, se elimine toda la descendencia de dichos nodos.
#include <iostream>
#include <fstream>
#include "../Implementacion_Arboles/Abin_enlazado.hpp"
#include "abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.


void eliminar_Descendencia_Rec(Abin<tElto>::nodo n, Abin<tElto> &A)
{
    if(n != Abin<tElto>::NODO_NULO)
    {
        eliminar_Descendencia_Rec(A.hijoIzqdo(n),A);
        eliminar_Descendencia_Rec(A.hijoDrcho(n),A);

        if(A.hijoIzqdo(n) == Abin<tElto>::NODO_NULO &&
            A.hijoDrcho(n) == Abin<tElto>::NODO_NULO)
        {
            A.eliminarHijoIzqdo(A.padre(n));
            A.eliminarHijoDrcho(A.padre(n));
        }
    }
}

void eliminDescUnic_Rec(Abin<tElto>::nodo n, Abin<tElto> &A)
{
    if(n != Abin<tElto>::NODO_NULO)
    {
        if(A.hijoIzqdo(n) == Abin<tElto>::NODO_NULO && A.hijoDrcho(n) != Abin<tElto>::NODO_NULO ||
        A.hijoIzqdo(n) != Abin<tElto>::NODO_NULO && A.hijoDrcho(n) != Abin<tElto>::NODO_NULO)
        {
            if(A.hijoIzqdo(n) != Abin<tElto>::NODO_NULO)
            {
                eliminar_Descendencia_Rec(A.hijoIzqdo(n),A);
            }else
            {
                eliminar_Descendencia_Rec(A.hijoDrcho(n),A);
            }
        }
        else{      
            eliminDescUnic_Rec(A.hijoIzqdo(n),A);
            eliminDescUnic_Rec(A.hijoDrcho(n),A);
        }
    }
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
	
	Abin<tElto> A = B;

	eliminDescUnic_Rec(A.raiz(),A);

    cout << "\n*** Mostrar árbol binario A ***\n";
	imprimirAbin(A);
    
} 