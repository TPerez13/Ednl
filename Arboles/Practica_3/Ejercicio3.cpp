#include <iostream>
#include <fstream>
#include "../Implementacion_Arboles/Agen_enlazado.hpp"

using namespace std;
typedef char t;
const t fin = '#'; // Fin de lectura.

int desequilibrioAgen_Rec(Agen<t>::nodo n,Agen<t> &A)
{
    if(n == Agen<t>::NODO_NULO)
    {
        return 0;
    }else
    {
        Agen<t>::nodo n = A.hijoIzqdo(n);
        
        int max;
        int resultado;

        while(n != Agen<t>::NODO_NULO)
        {
            max = maxAltura(n, A);
            min = minAltura(n, A);
            
            resultado = max(max-min,desequilibrioAgen_Rec(n,A));
            
            n1 = A.hermDrcho(n1,A);
        }
        return grado;
    }
}

int desequilibrioAgen(Agen<t> &A)
{
    return desequilibrioAgen_Rec(A.raiz(),A);
}

int main ()
{
    Agen<tElto> A(16), B(16);

    /*cout << "*** Lectura del árbol A ***\n";
    rellenarAgen(A, fin); // Desde std::cin
    ofstream fs(“agen.dat”); // Abrir fichero de salida.
    imprimirAgen(fs, A, fin); // En fichero.
    fs.close();
    cout << "\n*** Árbol A guardado en fichero agen.dat ***\n";
*/
    cout << "\n*** Lectura de árbol B de agen.dat ***\n";
    ifstream fe(“agen.dat”); // Abrir fichero de entrada.
    rellenarAgen(fe, B); // Desde fichero.
    fe.close();

    cout << "\n*** Mostrar árbol B ***\n";
    imprimirAgen(B); // En std::cout

    std::cout<<"El grado de este arbol es:"<<gradoAgen(B)<<std::endl;
} 

