/*bool similarRec(n1 nodo,n2 nodo, A1 arbol,A2 arbol)
{
	si n != nodo_nulo && n2 = nodo_nulo
		devolver true
	sino
		si n1 = nodo_nulo || n2 = nodo_nulo
			devolver false
		sino
}
*/

#include <iostream>
#include <fstream>
#include "../Implementacion_Arboles/Abin_enlazado.hpp"
#include "abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

bool similarRec(Abin<tElto>::nodo n1,Abin<tElto>::nodo n2,Abin<tElto> &A1,Abin<tElto> &A2)
{

    if (n1 != Abin<tElto>::NODO_NULO && n2 != Abin<tElto>::NODO_NULO)        
    {
		return true;
	}
	else
	{
		if(A1.hijoIzqdo(n1) == Abin<tElto>::NODO_NULO || A2.hijoIzqdo(n2)==Abin<tElto>::NODO_NULO)
		{
			return false;
		}
		else
		{	
			return (similarRec(A1.hijoIzqdo(n1),A2.hijoIzqdo(n2),A1,A2)
			   		|| similarRec(A1.hijoDrcho(n1),A2.hijoDrcho(n2),A1,A2));
		}
	}
}
bool similar(Abin<tElto> &A1, Abin<tElto> &A2)
{
	bool similitud = similarRec(A1.raiz(),A2.raiz(),A1,A2);
    return similitud;
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

    cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
    ifstream fe1("abin1.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe1, C); // Desde fichero.
    fe1.close();

    cout << "\n*** Mostrar árbol binario B ***\n";
    imprimirAbin(C); // En std::cout
	
	bool simil = similar(B,C);


    cout <<"El arbol es similar: "<<similar<<endl;

    return 0;
    
} 



