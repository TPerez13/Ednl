//Ejercicio1 Contar numeros de nodos de un arbol

int numnodos_Rec(Abin<tElto>::nodo n, Abin<tElto> &A)
{
    if(n == Abin<tElto>::NODO_NULO)
    {
        return 0 ;
    }
    else
    {
        return 1+ numnodos_Rec(A.hijoIzqdo(n),A) + numnodos_Rec(A.hijoDrcho(n));
    }
}

//Ejercicio2 Calcular la altura de un arbol del


int altura_Rec(Abin<tElto>::nodo n, Abin<tElto> &A)
{
    if(n == Abin<tElto>::NODO_NULO)
    {
        return -1;
    }else
    {
        return 1 + max(altura_Rec(A.hijoIzqdo(n),A),altura_Rec(A.hijoDrcho(n),A));
    }
}

//Ejercicio3 Determine prof del arbol de

int profundidad_iterativa(Abin<tElto>::nodo n, Abin<tElto> &A)
{
    int contador=0;
    for(n; A.padre(n) !=Abin<tElto>::NODO_NULO;n = A.padre(n))
        contador++;

    return contador;
}

//Ejercicio6 Desequilibrio de un arbol, como el maximo desequilibrio de todos sus nodos

int numdesequilibrio_Rec(Abin<tElto>::nodo n, Abin<tElto> &A)
{
    if(n == Abin<tElto>::NODO_NULO)
    {
        return -1
    }else
    {
        return std::max(std::abs(altura_Rec(A.hijoIzqdo(n),A)-altura_Rec(A.hijoDrcho(n))),
                            std::max(numdesequilibrio_Rec(A.hijoIzqdo(n),A),numdesequilibrio_Rec(A.hijoDrcho(n),A)))
    }
}

//Ejercicio7 Pseudocompleto

bool pseudocompleto_Rec(Abin<tElto>::nodo n, Abin<tElto> &A)
{
    if(altura_Rec(n)==1)
    {
        return (A.hijoIzqdo(n) != Abin<tElto>::NODO_NULO && A.hijoDrcho(n) != Abin<tElto>::NODO_NULO) //Comprobamos que tiene 2 hijos
    }else                                                                                      //Puesto que para que sea pseudocompleto_Rec
    {                                                                                        //el arbol necesita que al menos 1 nodo del penultimo nivel tenga  2 hijos
        if(altura_Rec(A.hijoIzqdo(n),A)>altura_rec(A.hijoDrcho(n)))
        {
            return psuedocompleto_Rec(A.hijoIzqdo(n),A);
        }
        else if(altura_Rec(A.hijoIzqdo(n),A)<altura_rec(A.hijoDrcho(n)))
        {
            return psuedocompleto_Rec(A.hijoDrcho(n),A);
        }
        else
        {
            return (pseudocompleto_Rec(A.hijoIzqdo(n),A) && psuedocompleto_Rec(A.hijoDrcho(n),A));
        }
    }
}