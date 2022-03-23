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
    if(n!= NODO_NULO)
    {
        eliminar_desc(A.hijoIzqdo(n),A);

        eliminar_desc(A.hijoDrcho(n),A)

        if(A.HijoIzqdo(A.padre(n))!=NODO_NULO)
            A.eliminarHijoIzqdo(A.padre(n));
        if(A.HijoIzqdo(A.padre(n))!=NODO_NULO)
            A.eliminarHijoDrcho(A.padre)
    }
}