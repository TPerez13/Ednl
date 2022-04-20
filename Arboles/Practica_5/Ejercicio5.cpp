struct Pixel{
    size_t coorx,coory,coorfx,coorfy;
    bool color;

}

void pintar(matriz<char> &m,Pixel p)
{
    for(int i=p.coorx; i< p.coorfx; i++){
        for(int j=p.coory;i<p.coordy;j++){
            m[i][j] = p.color;
        }
    }
}


void dibujar_figura_Rec(nodo n,Agen<Pixel> &A,matriz<char> &M)
{
    nodo hijo = A.hijoIzqdo(n);

    if(hijo == nODO_NULO)
    {
        pintar(&M,A.elemento(n));
    }else
    {
        while(hijo != NODO_NULO){
            dibujar_figura_Rec(hijo,A,M);
            hijo = A.HermanoDrcho();
        }
    }         
}


matriz<char> figura_asociada()
{
    matriz<char> dibujo(pow(2,altura(A)-1),'N'); // N de "negro"
    
    dibujar_figura_Rec();
    
    return dibujo();
}