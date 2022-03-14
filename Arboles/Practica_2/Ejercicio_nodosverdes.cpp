#include <iostream>
#include <fstream>
#include "../Implementacion_Arboles/Abin_enlazado.hpp"
#include "abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

void contar_nodosRec(Abin<tElto> &A,typename Abin<tElto>::nodo n)
{
    if(n == NODO_NULO)  //La igualdad es algo natural el distinto no
    {
        return 0;
    }else
        return 1 + contar_nodoRec(A,A.hizq(n)) + contar_nodoRec(A,A.hder(n));
}
//Hay que comtemplarse el caso limite

int contar_nodosverdesRec(Abin<tElto>::nodo n,Abin<tElto> &A)
{
    if(A.hijoIzqdo(n) != Abin<tElto>::NODO_NULO && A.hijoDrcho(n) != Abin<tElto>::NODO_NULO)
    {
        if (
            ((contar_nodosRec(A.hijoIzqdo(n),A) + contar_nodosRec(A.hijoDrcho(n),A))-
            (contar_nodosRec(A.hijoIzqdo(A.hijoIzqdo(n)),A) + contar_nodosRec(A.hijoIzqdo(A.hijoDrcho(n)),A)
            contar_nodosRec(A.hijoDrcho(A.hijoIzqdo(n)),A) + contar_nodosRec(A.hijoDrcho(A.hijoDrcho(n)),A)) 
            == 3)
            )
        {
            return 1 + contar_nodosverdesRec(A.hijoIzqdo(n),A) + contar_nodosverdesRec(A.hijoDrcho(n),A);
        }
    }else
    {
        return 0 + contar_nodosverdesRec(A.hijoIzqdo(n),A) + contar_nodosverdesRec(A.hijoDrcho(n),A);
    }
}


int contar_nodosverdes(Abin<tElto> &A)
{
    int sol;

    sol = contar_nodosverdesRec(A.raiz(),A);
    
    return sol;
}

int main ()
{
    Abin<tElto> /*A,*/ B,C;
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

    cout << "\n*** Lectura de árbol binario C de abin1.dat ***\n";
    ifstream fe1("abin1.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe1, C); // Desde fichero.
    fe1.close();

    cout << "\n*** Mostrar árbol binario C ***\n";
    imprimirAbin(C); // En std::cout
	
	int numnodosverdes = contar_nodosverdes(B);

    cout<<"Numero de nodos verdes: "<<numnodosverdes<<endl;

    return 0;
    
} 



