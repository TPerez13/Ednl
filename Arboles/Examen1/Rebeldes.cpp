int nodos_rebeldes(Abin<bool> A,Abin<bool>::nodo n)
{
    if(n == NODO_NULO)
    {
        return 0;
    }else
    {
        return contar_nodos_verdes(A,n) + nodos_rebeldes(A,A.hijoIzqdo(n)) + nodos_rebeldes(A,A.hijoDrcho(n));
    }
}

int contar_nodos_verdes(Abin<bool> A,Abin<bool>::nodo n1)
{
    int cont1=0,cont2=0;
    Abin<bool>::nodo n2 = n1;

    while(n2 != NODO_NULO)
    {
        cont1++;
        if(A.elemento(n1)!=A.padre(n2))
        {
            cont2++;
            n2 = A.padre(n2);
        }
    }
    
    if(cont2 > (cont1/2))
        return 1;
    else
        return 0;
}
/***********************************************************************************/

int nodos_abueletes(Abin<bool> A,Abin<bool>::nodo n)
{
    if(n == NODO_NULO)
    {
        return 0;
    }else
    {   
        return contar_nodos_verdes(A,n) + nodos_abueletes(A,A.hijoIzqdo(n)) + nodos_abueletes(A,A.hijoDrcho(n));
    }
}

int contar_nodos_verdes(Abin<bool> A,Abin<bool>::nodo n1)
{
    if(contar_nodos_verdes_Rec(A,n1,n1) == 3)
        return 1;
    else
        return 0;
}

int contar_nodos_verdes_Rec(Abin<bool> A,Abin<bool>::nodo n1,Abin<bool>::nodo n2)
{
    if(n2 == NODO_NULO)
    {
        return 0;
    }
    else{
        if(profundidad(n2)<profundidad(n1)+2)
            return contar_nodos_verdes_Rec(A,n1,A.hijoIzqdo(n2)) + contar_nodos_verdes_Rec(A,n1,A.hijoDrcho(n2));
        else if(profundidad(n1)+2 == profundidad(n2));
            return 1;
        else
            return 0;
    }
}
    