std::vector<camino_minimo(size_t N,List<Paredes> par_lab,Casilla entrada,Casilla salida,T )
{
    GrafoP<T> Laberinto(N*N);

    List<Paredes>::iterator it_paredes = par_lab.begin()

    for(int i=0;i<N;i++)
        for(int j = 0;j<N;j++)
        {  
            Casilla c1(i,i);
            Casilla c2(j,j);

            if(Adyacente(c1,c2)))
            {
                Laberinto[CasillaToNodo(c1)][CasillaToNodo(c2)] = 1;
                Laberinto[CasillaToNodo(c2)][CasillaToNodo(c1)] = 1;
            }
        }

    while(it_paredes != par_lab.end())
    {
        Laberinto[it_paredes.og][it_paredes.dest] == GrafoP<T>::INFINITO;
        Laberinto[it_paredes.dest][it_paredes.og] == GrafoP<T>::INFINITO;
    }

    std::vector<GrafoP<T>::vertice> vec_vertices(N*N);
    T longitud;
    
    std::vector<T> vec_Dij = Dijkstra(Laberinto,entrada,vec_vertices)
    longitud = vec_Dij[salida]; 

    std::vector<GrafoP<T>::vertice> vec_camino(N*N);
    GrafoP<T>::vertice v = salida;
    
    while(v != entrada)
    {
        vec_camino.push_back(vec_vertices[salida])
        v = vec_vertices[salida];
    }


}

bool Adyacente(Casilla c1,Casilla c2)
{
    return (abs(c1.Fila-c2.Fila)+abs(c1.Col-c2.Col));
}

Grafo<T>::vertice CasillaToVertice(Casilla c,size_t N)
{
    Grafo<T>::vertice v = N*c.x+c.y;
    return v;
}

Casilla NodoToCasilla(int i,size_t N)
{
    Casilla c(i/N,(i(i/N)*N))
}



//eJERCICIO 6

GrafoP<T> tarifa_min(GrafoP<T>::vertice viaje_tren,Grafo<T>::vertice viaje_bus,Grafo<T>::vertice ciudad_estaciones_unidas)
{
    GrafoP<T> viaje_tren_bus(viaje_tren.numVert()+viaje_bus.numVert());

    for(int i=0;i<viaje_tren.numVert())
        for(int j=0;j<viaje_bus.numVert();j++)
            if(j<viaje_tren.numVert() && i < viaje_tren.numVert())
                viaje_tren_bus[i][j] = viaje_tren[i][j];
            else if(i == j)
                viaje_tren_bus[i][j] = Grafo<T>::INFINITO;
            else
                viaje_tren_bus[i][j] = viaje_bus[i][j];ç

    viaje_tren_bus[ciudad][ciudad+viaje_tren.numVert()-1] = 0;
    viaje_tren_bus[ciudad+viaje_tren.numVert()-1][ciudad] = 0;

    std::vector<Grafo<T>::vertice> v_floyd;
    GrafoP<T> Grafo_floyd = floyd(viaje_tren_bus,v_floyd);
}
//Ejercicio 7

GrafoP<T> tarifa_min(GrafoP<T>::vertice viaje_tren,Grafo<T>::vertice viaje_bus,Grafo<T>::vertice cambio1,
                    Grafo<T>::vertice cambio2,Grafo<T>::vertice origen,Grafo<T>::vertice destino)
{
    GrafoP<T> viaje_tren_bus(viaje_tren.numVert()+viaje_bus.numVert());

    for(int i=0;i<viaje_tren.numVert())
        for(int j=0;j<viaje_bus.numVert();j++)
            if(j<viaje_tren.numVert() && i < viaje_tren.numVert())
                viaje_tren_bus[i][j] = viaje_tren[i][j];
            
            else if(i == j)
                viaje_tren_bus[i][j] = Grafo<T>::INFINITO;
            else
                viaje_tren_bus[i][j] = viaje_bus[i][j];


    viaje_tren_bus[cambio1][cambio1+viaje_tren.numVert()-1] = 0;
    viaje_tren_bus[cambio1+viaje_tren.numVert()-1][cambio1] = 0;

    viaje_tren_bus[cambio2][cambio2+viaje_tren.numVert()-1] = 0;
    viaje_tren_bus[cambio2+viaje_tren.numVert()-1][cambio2] = 0;

    std::vector<Grafo<T>::vertice> v_floyd;
    GrafoP<T> Grafo_floyd = floyd(viaje_tren_bus,v_floyd);

    return Grafo_floyd[origen][destino];
}
//Siguiente ej 
    if(i+viaje_tren.numVert() =  j)
        viaje_tren_bus[i][j] = viaje_tren[i][j];

//Ejercicio 12


std::pair<GrafoP<T>::vertice> Ciudades_puente(Grafo<T> Fobos, Grafo<T> Deimos, List<GrafoP<T>::vertice> Fobos_costera,
List<GrafoP<T>::vertice> Deimos_costera)
{
    
    GrafoP<T> Archipielago(Deimos.numVert()+Fobos.numVert());
    
    for(int i=0;i<Deimos.numVert())
        for(int j=0;j<Deimos.numVert();j++)
            Archipielago[i][j] = Deimos[i][j];

    for(int i=0;i<Fobos.numVert())
        for(int j=0;j<Fobos.numVert();j++)
            Archipielago[i + Deimos.numVert()][j + Deimos.numVert()] = Deimos[i][j];

    std::List<T>::iterator ccost_fob = Fobos_costera.begin();
    std::List<T>::iterator ccost_dei = Deimos_costera.begin();

    while(ccost_dei != Deimos_costera.end())
    {
        ccost_fob = Fobos_costera.begin();
        while(ccost_fob != Fobos_costera.end())
        {
            Archipielago[ccost_dei][ccost_fob] = 0;
            ccost_fob++;
        }
        ccost_dei++;
    }

    while(ccost_fob != Fobos_costera.end())
    {   
        ccost_dei = Deimos_costera.begin();
        while(ccost_dei != Deimos_costera.end())
        {
            Archipielago[ccost_fob][ccost_dei] = 0;
            ccost_dei++;
        }
        ccost_fob++;
    }

    Archipielago = Kruskal(Archipielago);
    bool bandera = true;
    while(ccost_fob != Fobos_costera.end() && bandera)
    {
        while(ccost_dei != Deimos_costera.end() && bandera)
        {
            if (Archipielago[ccost_fob][ccost_dei] != Grafo<T>::INFINITO)
                bandera = false;
            else 
                ccost_dei++;
        }

        if(bandera)
            ccost_fob++;
    }
    
    return std::pair.insert(make_pair(ccost_fob,ccost_dei));
}



//Ejercicio 6

void canales_Costemin(Matriz<T>& distancia_ciudades,Matriz<T>& Caudales_max,T subvencion, T costekm)
{
    GrafoP<T> costes(distancia_ciudades.size()*distancia_ciudades.size());

    for(int i=0;i<costes.numVert();i++)
        for(int j=0;j<costes.numVert();j++)
            costes[i][j] = (distancia_ciudades[i][j]*costekm - Caudales_max[i][j]*subvencion);

    Grafo<T> canales_minimos = Kruskall(costes);

    for(int i=0;i<costes.numVert();i++)
        for(int j=0;j<costes.numVert();j++)
            if(costes[i][j] == GrafoP<T>INFINITO)
            {
                Caudales_max[i][j] = GrafoP<T>::INFINITO;
                distancias_ciudades[i][j] =  GrafoP<T>::INFINITO;
            }   
}   


//Ejercicio7




