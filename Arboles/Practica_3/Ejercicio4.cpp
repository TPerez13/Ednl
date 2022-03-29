#include <iostream>
#include <fstream>
#include "../Implementacion_Arboles/Agen_enlazado.hpp"
#include "agen_E-S.h"

using namespace std;
typedef char t;
const t fin = '#'; // Fin de lectura.

void podaAgen_Rec(Agen<t>::nodo n,Agen<t> &A,int x)
{
    if(n!= Agen<t>::NODO_NULO)
    {
        if(A.elemento(n) == x)
        {
            eliminDesc_Rec();
        }
        else
        {   
            n = A.hijoIzqdo(n);

            while(n!=Agen<t>::NODO_NULO)
            {
                podaAgen_Rec(n);
                n = A.hermDrcho(n);
            }
        }
    }
}

void eliminDesc_Rec(Agen<t>::nodo n, Agen<t> &A)
{
    if(n != Agen<t>::NODO_NULO)
    {
        n = A.hijoIzqdo(n);

        while(n!= Agen<t>::NODO_NULO)
        {            
            eliminarDesc_Rec(n, A);
            n = A.Hermanodrcho(n);
        }
        A.eliminarHijoIzqdo(n);
    }
}


void podaAgen(Agen<t> &A,int x)
{
    podaAgen_Rec(A.raiz(),A);
}


int main ()
{
    Agen<t> A, B;

    /*cout << "*** Lectura del árbol A ***\n";
    rellenarAgen(A, fin); // Desde std::cin
    ofstream fs(“agen.dat”); // Abrir fichero de salida.
    imprimirAgen(fs, A, fin); // En fichero.
    fs.close();
    cout << "\n*** Árbol A guardado en fichero agen.dat ***\n";
    */
    cout << "\n*** Lectura de árbol B de agen.dat ***\n";
    ifstream fe(“agen.dat”); // Abrir fichero de entrada.
    rellenarAgen(fe, B); // Desde fichero.
    fe.close();
    
    cout << "\n*** Mostrar árbol B ***\n";
    imprimirAgen(B); // En std::cout

    std::cout<<"El grado de este arbol es:"<<gradoAgen(B)<<std::endl;
} 

