#include <iostream>
#include <fstream>
#include "../Implementacion_Arboles/Agen_enlazado.hpp"
#include "agen_E-S.h"

using namespace std;
typedef char t;
const t fin = '#'; // Fin de lectura.

/*
entero GradoAgen(A Abin)
{
    devolver GradoAgen_Rec(Raiz(A),A)
}

entero GradoAgen_Rec(n nodo, A agen)
{
    si n = Nodo_nulo
        devolver 0
    sino
        gr = numhijos(n,A)

        Hijo = Hijoizqdo(n,A)

        mientras(hijo != nODO_NULO)
            gr = max(gr, gradoAgen_rec(hijo,A))
            hijo = Hermanodrcho(Hijo,A)
        F mientras
            devolver gr


       /* int n = 1;
        if(HijoIzq(n) != NODO_NULO)
        {
            while(n!= NODO_NULO,n=HemanoDrcho)
            {
                n++;
            }
        }else{
            n--
        }
        devolver max(n)*/


int numHijos(Agen<t>::nodo n,Agen<t> &A)
{
    int cont = 0;
    Agen<t>::nodo n1 = A.hijoIzqdo(n);

    while(n1 != Agen<t>::NODO_NULO)
    {  
        n1 = A.hermDrcho(n1);
        cont++;
    }

    return cont;
}

int gradoAgen_Rec(Agen<t>::nodo n,Agen<t> &A)
{
    if(n == Agen<t>::NODO_NULO)
    {
        return 0;
    }else
    {
        Agen<t>::nodo n1 = A.hijoIzqdo(n);
        int grado = numHijos(n,A);
        
        while(n != Agen<t>::NODO_NULO)
        {
            grado = max(grado, gradoAgen_Rec(n1,A));
            n1 = A.hermDrcho(n1);
        }
        return grado;
    }
}

int gradoAgen(Agen<t> &A)
{
    return gradoAgen_Rec(A.raiz(),A);
}
/* 
  si n = Nodo_nulo
        devolver 0
    sino
        gr = numhijos(n,A)

        Hijo = Hijoizqdo(n,A)

        mientras(hijo != nODO_NULO)
            gr = max(gr, gradoAgen_rec(hijo,A))
            hijo = Hermanodrcho(Hijo,A)
        F mientras
            devolver gr

*/
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

