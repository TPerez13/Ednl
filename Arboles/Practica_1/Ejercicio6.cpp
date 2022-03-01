#include <iostream>
#include <fstream>
#include <algorithm>
#include "../Implementacion_Arboles/Abin_enlazado.hpp"
#include "abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

//**********************************************************************************//
int calcular_alturaRec(Abin<tElto>::nodo n, Abin<tElto> &A)
{
    if(n == Abin<tElto>::NODO_NULO)
    {
        return -1;
    }else
    {
        return 1 +  max(calcular_alturaRec(A.hijoIzqdo(n),A),calcular_alturaRec(A.hijoDrcho(n),A));
    }
}
//Si el arbol esta vacio es = -1, Explicarlo en el examen,

int calcular_desequilibrioRec(Abin<tElto>::nodo n, Abin<tElto> &A)
{
    if(n == Abin<tElto>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        return max(std::abs(calcular_alturaRec(A.hijoIzqdo(n),A) - calcular_alturaRec(A.hijoDrcho(n),A)),
                   max(calcular_desequilibrioRec(A.hijoIzqdo(n),A),calcular_desequilibrioRec(A.hijoDrcho(n),A)));
    }
}

int calcular_desequilibrio(Abin<tElto> &A)
{
    int sol = calcular_desequilibrioRec(A.raiz(),A);
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

   int desquilibrioAbin = calcular_desequilibrio(B);

    cout <<"El desequilibrio del arbol es "<<desquilibrioAbin <<endl;

    return 0;
    
} 