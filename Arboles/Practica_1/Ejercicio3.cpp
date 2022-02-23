#include <iostream>
#include <fstream>
#include "../Implementacion_Arboles/Abin_enlazado.hpp"
#include "abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

void contador(Abin<tElto>& m,Abin<tElto>::nodo n,int* aux)
{
    
    if(n != Abin<tElto>::NODO_NULO)
    {
        *aux += 1;
        contador(m,m.padre(n),aux);
    }
}
/*
si n = Raiz(A) devolver 0 -> Esto se puede hacer porque en el enunciado dice determina la profundidad de ESTE NODO y si un nodo esta vacio no es nodo
si n= NODO_NULO devolver -1

sino devolver 1 + profundiad(padre(n),a)
no existe la profundidad de un arbol, porque coincidiria con la altura
*/
int contar(Abin<tElto>& m)
{
    assert(m.raiz() != Abin<tElto>::NODO_NULO);
    int sol = 0;
    int* sol_pointer = &sol;
    Abin<tElto>::nodo n = m.hijoIzqdo(m.hijoIzqdo(m.raiz()));
    contador(m,n,sol_pointer);
    
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

    int num_nodos = contar(B);

    cout <<"El arbol a tiene "<<num_nodos<<" nodos"<<endl;

    return 0;
    
} 
