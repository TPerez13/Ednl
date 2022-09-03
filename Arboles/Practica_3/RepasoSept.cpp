//Ejercicio 1

int calcular_grado_Rec(Agen<tElto>::nodo n,Agen<tElto> &A)
{
    if(n != Agen<tElto>::NODO_NULO)
    {   
        n = A.hijoIzqdo(nodo n);
        int grado = agenHermanos(n,A);

        while(n != Agen<tElto>::NODO_NULO)
        {
            grado = max(grado,calcular_grado_Rec(n,A));
            n = A.hermanoDrcho(n);
            
        }
    }else {
        return 0;
    }
}

int genHermanos(Agen<tElto>::nodo n,Agen<tElto> &A)
{
    int grado = 0;
    while(n != Agen<tElto>::NODO_NULO)
    {
        grado++;
        n = A.hermanoDrcho(n);
    }
    return grado;
}

// Altura agen

int agenAltura_Rec(Agen<tElto>::nodo n,Agen<tElto> &A)
{
    if(n != Agen<tElto>::NODO_NULO)
    {   
        n = A.hijoIzqdo(nodo n);

        int altura = 0;

        while(n != Agen<tElto>::NODO_NULO)
        {
            altura = max(altura,agenAltura_Rec(n,A));
            n = A.hermanoDrcho(n);    
        }

        return 1 + altura;
    }else {
        return -1;
    }
}

//Ejercicio 3

int desequilibrioAgen_Rec(Agen<tElto>::nodo n, Agen<tElto> A)
{
    if(n != Agen<tElto>::NODO_NULO)
    {   
        n = A.hijoIzqdo(nodo n);

        int maxaltura = agenAltura_Rec(n,A);
        int minaltura = 
        int desequilibrio = maxaltura -minaltura;

        while(n != Agen<tElto>::NODO_NULO)
        {
            desequilibrio = max(desequilibrio,desequilibrioAgen_Rec(n,A));
            n = A.hermanoDrcho(n);    
        }

        return desequilibrio;
    }else {
        return 0;
    }
}