#include <iostream>
#include <fstream>
#include "../Implementacion_Arboles/Abin_enlazado.hpp"
#include "abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

//Arbol en mayus, nodo en minus y el contador lo primero que se pone
void contar_nodosRec(int* aux, Abin<tElto> &A,typename Abin<tElto>::nodo n)
{
    
    if(n != Abin<tElto>::NODO_NULO)
    {
        Abin<tElto>::nodo m = n; 
        *aux += 1;
        contar_nodosRec(aux,A,A.hijoIzqdo(n));
        contar_nodosRec(aux,A,A.hijoDrcho(n));
    }
}

/*Solucion dlh
void contar_nodosRec(Abin<tElto> &A,typename Abin<tElto>::nodo n)
{
    if( n = NODO_NULO)  //La igualdad es algo natural el distinto no
    {
        return 0;
    }else
        return 1 + contar_nodoRec(A,A.hizq(n)) + contar_nodoRec(A,A.hder(n));
    }
//Hay que comtemplarse el caso limite
*/

//NO EXISTE NINGUN NODO VACIO
int contar_nodos(Abin<tElto> &A)
{
    assert(A.raiz() != Abin<tElto>::NODO_NULO);
    int sol = 0;
    int* sol_pointer = &sol;
    contar_nodosRec(sol_pointer,A,A.raiz());
    
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

    //int num_nodos = contar(B.raiz());
    int num_nodos = contar_nodos(B);
    cout <<"El arbol a tiene "<<num_nodos<<" nodos"<<endl;

    return 0;
    
} 