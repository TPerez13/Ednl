struct viajes
{
    int og;
    int dest;
    int num;
}

bool km_adicionales(GrafoP<T>::vertice Cap_Zuelandia, GrafoP<T> distancia_ciudades,List<viajes> Viajes_diarios
,int max_km_adicionales,int &km_adicionales)
{
    Grafo<P> Distancias_sin_Capital = G;

    for(int i =0;i<Distancias_sin_Capital.numVert();i++)
        if(i != Cap_Zuelandia)
            Distancias_sin_Capital[i][Cap_Zuelandia] == Grafo<T>::INFINITO;


    matriz<Grafo<T>::vertice> ver_sinCap(Distancias_sin_Capital.numVert());
    matriz<Grafo<T>::vertice> ver_conCap(distancia_ciudades.numVert());

    Matriz<T> floyd_sinCap = floyd(Distancias_sin_Capital,ver_sinCap);
    Matriz<T> floyd_conCap = floyd(distancia_ciudades,ver_conCap);

    List<Grafo<T>::aristas>::iterator it_viajes = Viajes_diarios.begin();
    
    float contador_viajes_sinCap=0;
    float contador_viajes_conCap=0;

    while(it_viajes != Viajes_diarios.end())
    {
        if(it.og != Cap_Zuelandia && it.dest != Cap_Zuelandia)
        {
            contador_viajes_sinCap += (floyd_sinCap[it_viajes.og][it_viajes.dest]*it_viajes.num);
            contador_viajes_conCap += (floyd_conCap[it_viajes.og][it_viajes.dest]*it_viajes.num);
        }
        it_viajes++;
    }
    
    return (contador_viajes_conCap - contador_viajes_sinCap <= max_km_adicionales);
}