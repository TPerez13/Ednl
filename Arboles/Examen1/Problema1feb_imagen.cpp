void transformacionArbol_Rec(Abin<tElto>::nodo n, Abin &A)
{
    if(n != Abin<tElto>::NODO_NULO)
    {   
        transformacionArbol_Rec(A.hijoIzqdo(n),A);
        transformacionArbol_Rec(A.hijoDrcho(n),A);

        if(altura_Rec(n,A) != 0){
            if(minDescendientes(n,A) >= A.elemento(n) >= maxAscendientes(n,A))
            {
                if(A.hijoIzqdo(n) != Abin<tElto>::NODO_NULO)
                {
                    A.eliminarHijoIzqdo(n,A);
                }
                if(A.hijoDrcho(n)!= Abin<tElto>::NODO_NULO)
                {
                    A.eliminarHijoDrcho(n,A);
                }
            }
        }
    }
}

int minDescendientes(Abin<tElto>::nodo n, Abin &A){
    if(n != NODO_NULO)
    {
        return 1000;
    }
    else
    {
        return min(A.elemento(n),min(minDescendientes(A.hijoDrcho(n),A),minDescendientes(A.hijoIzqdo(n),A)));
    }
}

int maxDescendientes(Abin<tElto>::nodo n, Abin &A){
    if(n != NODO_NULO)
    {
        return -1000;
    }
    else
    {
        return max(A.elemento(n),maxDescendientes(A.padre(n),A)));
    }
}