void podaAbin(int num,Abin<tElto> &A)
{
    return podaAbin_Rec(num,A.raiz(),A);
}

void podaAbin_Rec(int num,Abin<tElto>::nodo n,Abin<tElto> &A)
{
    if(n!= Abin<tElto>::NODO_NULO)
    {
        if(A.elemento(A.hijoIzqdo(n))==num)
        {
            eliminar_desc(A.hijoIzqdo(n),A);
        }



    }
}


void eliminar_desc(Abin<tElto>::nodo n,Abin<tElto> &A)
{
    if(A.hijoIzqdo(n)) != NODO_NULO)
    {
       eliminar_desc(A.hijoIzqdo(n),A);
       A.eliminarHijoIzqdo(n);
    }
    if(A.HijoDrcho(n) != NODO_NULO)
    {
        eliminar_desc(A.HijoDrcho(n),A);
        A.eliminarHijoDrcho(n);
    }
}