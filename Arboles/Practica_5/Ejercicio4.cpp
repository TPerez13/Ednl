bool agenTernario_Rec(Agen<T>::nodo n,Agen<t> A)
{
    if(n != NODO_NULO)
    {
        if(numhijos(n,A) == 0 || numhijos(n,A) == 3)
        {
            nodo hijo = A.hijoIzqdo(n);

            while(hijo != NODO_NULO )
            {
                agenTernario_Rec(hijo,A);
                hijo = A.hermDrcho(hijo);   
            }
            
            return true
        }else
            return true;

    }

}

int numhijos(Agen<T>::nodo n,Agen<t> A)
{
    Agen<T>::nodo hijo = A.hijoIzqdo(n);
    
    int i = 0;
    while(n != NODO_NULO)
    {
        i++;
        hijo = A.hermDrcho(hijo);
    }
    
    return i;
}