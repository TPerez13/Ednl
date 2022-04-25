
#include <iostream>
#include <fstream>
#include <vector>
#include "../Implementacion_Arboles/Abin_busqueda.hpp"
#include "abin_E-S.h"

Abb<t> union(Abb<t> A, Abb<t> B)
{
    vector<t> vec1;
    
    arbol_inorden(A,vec1);
    arbol_inorden(B,vec1);

    vec1.sort();

    Abb<t> uni;
    
    rellenar_B(uni,vec1,min,max);
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