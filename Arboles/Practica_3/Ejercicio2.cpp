#include <iostream>
#include <fstream>
#include "../Implementacion_Arboles/Agen_enlazado.hpp"

using namespace std;
typedef char t;
const t fin = '#'; // Fin de lectura.

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

}*/

int numHijos(Agen<t>::nodo n,Agen &A)
{
    int cont = 0;
    n = A.hijoIzqdo(n);

    while(n != Agen<t>::NODO_NULO)
    { 
        n = A.hermDrcho(n,A);
        cont++;
    }

    return cont;
}

int profundidadAgen_Rec(Agen<t>::nodo n,Agen<t> &A)
{
    if(n == Agen<t>::NODO_NULO)
    {
        return -1;
    }else
    {
        return 1 + profundidadAgen_Rec(A.padre(n),A);
    }
}

int profundidadAgen(Agen<t> &A)
{
    return gradoAgen_Rec(A.raiz(),A);
}

int main ()
{
    Agen<t> A(16), B(16);

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

    std::cout<<"El grado de este arbol es:"<<gradoAgen(B)<<std::endl;
} 

