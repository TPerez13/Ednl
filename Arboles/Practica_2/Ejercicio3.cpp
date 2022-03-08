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


float CalculadoraAbinRec(Abin<tElto>::nodo n,Abin<tElto>& A)
{

	if(A.hijoIzqdo(n) != Abin<tElto>::NODO_NULO && A.hijoDrcho(n) !=Abin<tElto>::NODO_NULO )
	{
		switch(A.elemento(n))
		{
			case '*':
				return CalculadoraAbinRec(A.hijoIzqdo(n),A) * CalculadoraAbinRec(A.hijoDrcho(n),A);break;
			case '+':
				return CalculadoraAbinRec(A.hijoIzqdo(n),A) + CalculadoraAbinRec(A.hijoDrcho(n),A);break;
			case '-':
				return CalculadoraAbinRec(A.hijoIzqdo(n),A) - CalculadoraAbinRec(A.hijoDrcho(n),A);break;
			case '/':
				return CalculadoraAbinRec(A.hijoIzqdo(n),A) / CalculadoraAbinRec(A.hijoDrcho(n),A);break;
		}	
		
	}else
	{
		return A.elemento(n);
	}
}

float CalculadoraAbin(Abin<tElto> &A)
{
	float resultado;
	resultado = CalculadoraAbinRec(A.raiz(),A);

	return resultado;
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
    ifstream fe("Exp-aritmetica.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, B); // Desde fichero.
    fe.close();

    cout << "\n*** Mostrar árbol binario B ***\n";
    imprimirAbin(B); // En std::cout
	
	float resultado = CalculadoraAbin(B);

	cout <<"El resultado es: "<<resultado<<endl;
    
} 



