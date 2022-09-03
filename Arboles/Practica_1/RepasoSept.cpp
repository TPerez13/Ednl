#include <iostream>
#include <fstream>
#include <algorithm>
#include "../Implementacion_Arboles/Abin_enlazado.hpp"
#include "abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.
/*
int numNodos_Rec(Abin<tElto>::nodo n, Abin<tElto> &A)
{
    if(n == Abin<tElto>::NODO_NULO){
        return 0;        
    }else
    {
        return 1 + numNodos_Rec(A.hijoIzqdo(n),A) + numNodos_Rec(A.hijoDrcho(n),A);
    }
}

int numNodos(Abin<tElto> &A)
{
    assert(A.raiz() != Abin<tElto>::NODO_NULO);
    int sol = 0;
    sol = numNodos_Rec(A.raiz(),A);
    
    return sol;
}


int main ()
{
    Abin<tElto> /*A,*/// B;
     /*
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // Desde std::cin

    ofstream fs("abin.dat"); // Abrir fichero de salida.
    imprimirAbin(fs, A, fin); // En fichero.
    fs.close();
    cout << "\n*** Árbol A guardado en fichero abin.dat ***\n";*/
    /*
    cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
    ifstream fe("abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, B); // Desde fichero.
    fe.close();

    cout << "\n*** Mostrar árbol binario B ***\n";
    imprimirAbin(B); // En std::cout

    //int num_nodos = contar(B.raiz());
    int num_nodos = numNodos(B);
    cout <<"El arbol a tiene "<<num_nodos<<" nodos"<<endl;

    return 0;
    
} */


//*******************************************************************************************************//

int altura_Rec(Abin<tElto>::nodo n, Abin<tElto> A)
{
    if(n == Abin<tElto>::NODO_NULO)
    {
        return -1;
    }else{
        return 1 + max(altura_Rec(A.hijoIzqdo(n),A),altura_Rec(A.hijoDrcho(n),A));
    }
}

int calcular_altura(Abin<tElto> &A)
{
    assert(!A.arbolVacio());
    int sol;
    sol = altura_Rec(A.raiz(),A);
    return sol;
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

   int alturaAbin = calcular_altura(B);

    cout <<"El arbol a tiene una altura de "<<alturaAbin <<endl;

    return 0;
    
} 