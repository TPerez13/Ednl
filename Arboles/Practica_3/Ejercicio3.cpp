#include <iostream>
#include <fstream>
#include "../Implementacion_Arboles/Agen_enlazado.hpp"

using namespace std;
typedef char t;
const t fin = '#'; // Fin de lectura.

int desequilibrioAgen_Rec(Agen<t>::nodo n,Agen<t> &A)
{
    if(A.numHijos(n)<2)
    {
        return altura(n,A);
    }else
    {
        Agen<t>::nodo hijo = A.hijoIzqdo(n);
        
        int max,min;
        int resultado;

        while(n != Agen<t>::NODO_NULO)
        {
            max = maxAltura(n, A);
            min = minAltura(n, A);
            
            resultado = max(max-min,desequilibrioAgen_Rec(hijo,A));
            
            hijo = A.hermDrcho(hijo,A);
        }
        return resultado;
    }
}

int desequilibrioAgen(Agen<t> &A)
{
    return desequilibrioAgen_Rec(A.raiz(),A);
}

int main ()
{
    Agen<t> A(16), B(16);

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

