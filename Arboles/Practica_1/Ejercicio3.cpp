int calcular_altura(typename Abin<tElto>::nodo n,int aux)
{
    if(n == Abin<tElto>::NODO_NULO)
    {
        return 0;
    }else
    {
        if(m->hizq != Abin<tElto>::NODO_NULO)
        {
            
            calcular_altura(m->hizq, aux);
        }else if(m->hizq == Abin<tElto>::NODO_NULO)
        {
           if(altura<aux)
           {
               altura=aux;
           } 
            aux--;
        }        
        
        if(m->hder != Abin<tElto>::NODO_NULO)
        {
            aux++
            calcular_altura(m->hder, aux);
        }else if(m->hder == Abin<tElto>::NODO_NULO)
        {
            if(altura<aux)
           {
               altura=aux;
           } 
            aux--;
        }
        
        return 0;
    }

}
