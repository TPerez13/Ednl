//Ejercicio1

bool similar_Rec(Abin<tElto>::nodo n1,Abin<tElto>::nodo n2,Abin<tElto> &A1,Abin<tElto> &A2)
{
    if(n1 == Abin<tElto>::NODO_NULO && n2 == NODO_NULO)
    {
        return true;
    }
    else
    {
        if(n1 != Abin<tElto>::NODO_NULO || n2 != Abin<tElto>::NODO_NULO)
        {
            return false;
        }
        else
        {
            return (similar_Rec(A1.hijoIzqdo(n),A2.hijoIzqdo(n),A1,A2) &&
                    similar_Rec(A1.hijoDrcho(n),A2.hijoDrcho(n),A1,A2))
        }
    }
}


//Ejercicio 2: Copiar espejo

void arbolespejo_Rec(Abin<tElto>::nodo n1,Abin<tElto>::nodo n2,Abin<tElto> &A1,Abin<tElto> &A2)
{
    if(A1.padre(n1) == NODO_NULO)
    {
        A2.insertarRaiz(A1.elemento(n1));
        arbolespejo_Rec(A1.hijoIzqdo(n1),A2.hijoDrcho(n2),A1,A2);
    }
    else
    {
        if(A1.hijoIzqo(n1) != Abin<tElto>::NODO_NULO)
        {
            A2.insertarHijoDrcho(A2.hijoDrcho(n2),A1.elemento(A1.HijoIzqo(n1));)
            arbolespejo_Rec(A1.hijoIzqdo(n1),A2.hijoDrcho(n2));
        }
        else if(A1.hijoIzqdo(n1) != Abin<tElto>::NODO_NULO)
        {
            A2.insertarHijoIzqdo(A2.hijoIzqdo(n2),A1.elemento(A1.hijoDrcho(n1)))
            arbolespejo_Rec(A1.hijoDrcho(n1),A2.hijoIzqdo(n2));
        } 
        
        
    }
}

//Ejercicio3: