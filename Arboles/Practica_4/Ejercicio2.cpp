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
#include <vector>
#include "../Implementacion_Arboles/Abin_busqueda.hpp"
#include "abin_E-S.h"

using namespace std;
typedef int t;
const t fin = '#'; // Fin de lectura.

void recorrerABB_Rec(vector<t> v,Abb<t> &hijo,Abb<t> &A)
{
    if(n!=NODO_NULO)
    {
        hijo = A.izqdo(n);

        while( n != nullptr )
        {
            recorrerABB_Rec(n,A);
            Abb<t> = A.drcho(n);
        }
    }
}

bool equilibrarABB_Rec(Abb<t> hijo,Abb<t> &A)
{
    //Recorrer arboles
    vector<t> v;
    v = recorrerABB_Rec(n,A)
}

bool equilibrarABB(Abb<tElto> &A)
{
	equilibrarABB_Rec(A.raiz(),A);
}

int main ()
{
    Abb<t> /*A,*/ B;
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

    equilibrarABB(B);

    return 0;
    
} 

//Ejercicio de repaso

void equilibrio(Abb<t> &A)
{
    Abb B();

    if(!A.vacio())
    {
        vector<t> vec;
        arbol_inorden(A,vec);
        rellenar_B(B,vec,0,vec.size()-1);
    }  
    
    A = B;
}

void arbol_inorden(Abb<t> &A,int &vec)
{
    if(!A.vacio())
    {
        arbol_inorden(A.izqdo(),vec);
        vec.push_back(A.elemento());
        arbol_inorden(A.drcho(),vec);
    }
}

void rellenar_B(Abb <t> &A, int &vec,int min, int max)
{
     int elemAInsertar= (max+min)/2;
    A.insertar(v[elemAInsertar]);
    if (min != max)             //(si min == max, entonces no tenemos que hacer más recursiones)
    {
        rellenar_B(A,vec, min, elemAInsertar);
        rellenar_B(A,vec, elemAInsertar+1, max);
    }
    
}


