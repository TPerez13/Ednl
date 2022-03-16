#include <iostream>
#include <fstream>
#include "../Implementacion_Arboles/Agen_enlazado"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

/*
entero GradoAgen(A Abin)
{
    devolver GradoAgen_Rec(Raiz(A),A)
}

entero GradoAgen_Rec(n nodo, A agen)
{
    si n = Nodo_nulo
        devolver 0
    sino
        gr = numhijos(n,A)

        Hijo = Hijoizqdo(n,A)

        mientras(hijo != nODO_NULO)
            gr = max(gr, gradoAgen_rec(hijo,A))
            hijo = Hermanodrcho(Hijo,A)
        F mientras
            devolver gr


       /* int n = 1;
        if(HijoIzq(n) != NODO_NULO)
        {
            while(n!= NODO_NULO,n=HemanoDrcho)
            {
                n++;
            }
        }else{
            n--
        }
        devolver max(n)*/

}
*/




int main ()
{
    Agen<tElto> A(16), B(16);

    cout << "*** Lectura del árbol A ***\n";
    rellenarAgen(A, fin); // Desde std::cin
    ofstream fs(“agen.dat”); // Abrir fichero de salida.
    imprimirAgen(fs, A, fin); // En fichero.
    fs.close();
    cout << "\n*** Árbol A guardado en fichero agen.dat ***\n";

    cout << "\n*** Lectura de árbol B de agen.dat ***\n";
    ifstream fe(“agen.dat”); // Abrir fichero de entrada.
    rellenarAgen(fe, B); // Desde fichero.
    fe.close();
    
    cout << "\n*** Mostrar árbol B ***\n";
    imprimirAgen(B); // En std::cout
} 

