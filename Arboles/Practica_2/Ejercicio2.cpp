/*abin rellenarabin(A abin)
{
	Abin b

	si arbolvacio(a)
		devolver b
	sino
		insertarraiz(raiz(a),b)
		reflex	
}
*/

#include <iostream>
#include <fstream>
#include "../Implementacion_Arboles/Abin_enlazado.hpp"
#include "abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

int contar_nodosRec(Abin<tElto> &A,typename Abin<tElto>::nodo n)
{
    if( n = Abin<tElto>::NODO_NULO)  //La igualdad es algo natural el distinto no
    {
        return 0;
    }else
        return 1 + (contar_nodosRec(A,A.hijoIzqdo(n)) + contar_nodosRec(A,A.hijoDrcho(n)));
}

int global =0;

void abinreflejadoRec(Abin<tElto>::nodo n1,Abin<tElto>::nodo n2,Abin<tElto> &A1,Abin<tElto> &A2)
{
	if(contar_nodosRec(A1,A1.raiz()) != contar_nodosRec(A2,A2.raiz()))
	{
		if(A2.raiz() == Abin<tElto>::NODO_NULO)
		{
			A2.insertarRaiz(A1.elemento(n1));
			abinreflejadoRec(n1,n2,A1,A2);
		}
		else
		{
			if(A1.hijoIzqdo(n1) != Abin<tElto>::NODO_NULO)
			{
				A2.insertarHijoDrcho(n2,A1.elemento(A1.hijoIzqdo(n1)));
				abinreflejadoRec(A1.hijoIzqdo(n1),A2.hijoDrcho(n2),A1,A2);
			}
			else
			{
				if(A1.hijoDrcho(n1) != Abin<tElto>::NODO_NULO)
				{
					A2.insertarHijoIzqdo(n2,A1.elemento(A1.hijoDrcho(n1)));
					abinreflejadoRec(A1.hijoDrcho(n1),A2.hijoIzqdo(n2),A1,A2);
				}
			}
		}
	}
}

Abin<tElto> abinreflejado(Abin<tElto> &A1)
{
	Abin<tElto> A2;

	abinreflejadoRec(A1.raiz(),A2.raiz(),A1,A2);

	return A2;
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
	
	Abin<tElto> A;

	A = abinreflejado(B);

	imprimirAbin(A);
    
} 



