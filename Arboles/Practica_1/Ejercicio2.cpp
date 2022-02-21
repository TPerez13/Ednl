#include <iostream>
#include <fstream>
#include "../Implementacion_Arboles/Abin_enlazado.hpp"
#include "abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

static int altura = 0;

int calcular_altura(typename Abin<tElto>::nodo n,int aux)
{
     Abin<tElto>::nodo m = Abin<tElto>::NODO_NULO;

    if(n == Abin<tElto>::NODO_NULO)
    {
        return 0;
    }else
    {   
        m = n;
        
        if(m->hizq != Abin<tElto>::NODO_NULO)
        {
            calcular_altura(m->hizq, aux);
        }else if(m->hizq == Abin<tElto>::NODO_NULO)
        {
           if(altura<aux)
           {
               altura=aux;
           } 
            aux--;
        }        
        
        if(m->hder != Abin<tElto>::NODO_NULO)
        {
            aux++;
            calcular_altura(m->hder, aux);
        }else if(m->hder == Abin<tElto>::NODO_NULO)
        {
            if(altura<aux)
           {
               altura=aux;
           } 
            aux--;
        }
        
        return 0;
    }

}

void alturabin(typename Abin<tElto>::nodo m)
{
    assert(m != Abin<tElto>::NODO_NULO);
    std::cout<<"Ha llegado";
    //int res =
    calcular_altura(m,1);
    //return res;
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

   //int num_nodos = 
    alturabin(B.raiz());

    cout <<"El arbol a tiene una altura de "<<altura <<endl;

    return 0;
    
} 