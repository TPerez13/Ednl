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
//Hay que dar el recorrido por anchura para hacer este ejercicio
bool calcular_pseudocompletoRec(int altura,int aux,Abin<tElto>::nodo n, Abin<tElto> &A)
{
    if(aux+1==altura)   // Miro si el contador ya esta en el penultimo nivel,
    {
        aux--;        //La unica manera que se me ha ocurrido de copntrolar la altura del aux
        return ((A.hijoIzqdo(n) == Abin<tElto>::NODO_NULO && A.hijoDrcho(n) == Abin<tElto>::NODO_NULO)
                || (A.hijoIzqdo(n) != Abin<tElto>::NODO_NULO && A.hijoDrcho(n) != Abin<tElto>::NODO_NULO)); //condiciones para ver si es 
    }                                                                                                       //pseudocompleto
    else
    {
        return min(calcular_pseudocompletoRec(altura,aux++,A.hijoIzqdo(n)),calcular_pseudocompletoRec(altura,aux++,A.hijoDrcho(n)));
    }       //Hago el min porque si en las condiciones de comprobar si es pseudocompleto el return es 0 entonces algun nodo del penultimo nivel
            //no cumple la condicion por lo que no seria pseudocompleto    
}

bool calcular_pseudocompleto(Abin<tElto> &A)
{
    int altura = int calcular_alturaRec(A.raiz(),A);

    bool sol = calcular_pseudocompletoRec(altura,0,A.raiz(),A);
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

   int pseduocompletoAbin = calcular_desequilibrio(B);

    cout <<"El arbol es pseudocompleto: "<<pseduocompletoAbin <<endl;

    return 0;
    
} 