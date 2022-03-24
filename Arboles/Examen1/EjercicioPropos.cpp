

bool calculoExp_Rec(typename Abin<tElto>::nodo n,Abin <tElto>)
{
    if(n!= Abin<tElto>::NODO_NULO)
    {
        if(A.hijoIzqdo(n) != NODO_NULO || A.Hijodrcho(n) != NODO_NULO)
        {
            switch(A.elemento(n))
            {
                case '^': return (calculoExp_Rec(A.hijoIzqdo(n),A) && calculoExp_Rec(A.Hijodrcho(n),A));break;
                case '~': return (calculoExp_Rec(A.HijoIzqdo(n),A) || calculoExp_Rec(A.Hijodrcho(n),A));break;
                case '¬':
                    if(A.hijoIzqdo(n) != NODO_NULO)
                        return !A.elemento(n);
                    if(A.hijoDrcho(n) != NODO_NULO)
                        return !A.elemento(n);
                        
                    break;

            }
        }else
        {
            return A.elemento(n);
        }
    }
}