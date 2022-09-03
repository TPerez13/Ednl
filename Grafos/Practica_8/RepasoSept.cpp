//Ejercicio 1 
struct Ciudades
{
    int x;
    int y;
}

GrafoP<T> coste_min(Matriz<bool> conexiones, List<Ciudades> Ciudades)
{
    GrafoP<T> Grafo_costes(conexiones.size());
    
    List<Ciudades>::iterator it_ciudades1 = Ciudades.begin();
    List<Ciudades>::iterator it_ciudades2 = Ciudades.begin();

    while(it_ciudades1 != Ciudades.end())
    {   
        it_ciudades2 = Ciudades.begin();
        while(it_ciudades2 != Ciudades.end())
        {
            Grafo_costes[it_ciudades1][it_ciudades2] =
                sqrt(pow(it_ciudades2.x - it_ciudades1.x) + pow(it_ciudades2.y - it_ciudades1.y));
            
            it_ciudades2++;
        }
        it_ciudades1++;
    }

    for(int i=0;i<conexiones.size();i++)
        for(int j=0;j<conexiones.size();j++)
            if(Conexiones[i][j] == false)
                Grafo_costes[i][j] = GrafoP<T>::INFINITO;

    
    GrafoP<T> Costes_min(conexiones.size());
    std::vector<GrafoP<T>::vertice> ver_floyd
    Costes_min = floyd(Grafo_costes,ver_floyd);

    return Costes_min;
}

//Ejercicio 2

std::vector<aristas> costes_min(Matriz<bool> conexiones, List<Ciudades> Ciudades)
{
    GrafoP<T> Grafo_costes1(conexiones.size());
    
    List<Ciudades>::iterator it_ciudades1 = Ciudades.begin();
    List<Ciudades>::iterator it_ciudades2 = Ciudades.begin();
    
    int i= 0;
    int j= 0;
    while(it_ciudades1 != Ciudades.end())
    {   
        j=0;
        it_ciudades2 = Ciudades.begin();
        while(it_ciudades2 != Ciudades.end())
        {
            Grafo_costes1[i][j] =
                sqrt(pow(it_ciudades2.x - it_ciudades1.x) + pow(it_ciudades2.y - it_ciudades1.y));
            
            it_ciudades2++;
            j++
        }
        it_ciudades1++;
        i++
    }

    GrafoP<T> Grafo_costes2(conexiones.size());
    for(i=0;i<conexiones.size();i++)
        for(j=0;j<conexiones.size();j++)
            if(Conexiones[i][j] == false)
                Grafo_costes2[i][j] = GrafoP<T>::INFINITO;
    
    int tamisla1 = contar_ciudades_islas(Grafo_costes2+0);
    int tamisla2 = contar_ciudades_islas(Grafo_costes2+tamisla1);
    int tamisla3 = contar_ciudades_islas(Grafo_costes2+tamisla2);

    int min = 10000;
    GrafoP<T>::arista a;

    for(int i=0;i<tamisla1;i++)
    {
        for(int j=tamisla1;j<tamisla2+tamisla1;j++)
        {
            dis = Grafo_costes1[i][j];

            if(dis<min)
            {
                min = dis;
                a.og = j;
                a.dest = i;
            }
        }   
    }

    min=1000000;
    GrafoP<T>::arista b;
    for(int i=0;i<tamisla1;i++)
    {
        for(int j=tamisla2;j<tamisla2+tamisla1+tamisla3;j++)
        {
            dis = Grafo_costes1[i][j];

            if(dis<min)
            {
                min = dis;
                b.og = j;
                b.dest = i;
            }
        }   
    }

    min = 100000;
    GrafoP<T>::arista c;
    for(int i=0;i<tamisla1;i++)
    {
        for(int j=0;j<tamisla2;j++)
        {
            dis = Grafo_costes1[i][j];

            if(dis<min)
            {
                min = dis;
                c.og = j;
                c.dest = i;
            }
        }   
    }

    std::vector<GrafoP<T>::aristas> vec_solucion;

    vec_solucion.push_back(a);
    vec_solucion.push_back(b);
    vec_solucion.push_back(c);

    return vec_solucion;

}

int contar_ciudades_islas(GrafoP<T> G,int N)
{
    matriz<bool> matriz_adyacencia(G.numvert());
    matriz_adyacencia = Warshall(G);
    
    bool bandera = true;
    for(int i=0;i<conexiones.size() && bandera;i++)
        for(int j=0;j<conexiones.size() && bandera;j++)
            if(G[i][j] == GrafoP<T>::INFINITO)
                bandera == false;

    return j+N;
}


//
void Archipielago(Grafo<T> Fobos, Grafo<T> Deimos, List<GrafoP<T>::vertice> Fobos_costera,
List<GrafoP<T>::vertice> Deimos_costera)
{
    GrafoP<T> PrimFobos;
    GrafoP<T> PrimDeimos;

    List<GrafoP<T>::vertice>::iterator it_fobos_cos = Fobos_costera.primera();
    List<GrafoP<T>::vertice>::iterator it_deimos_cos = Deimos_costera.primera();

    int menor = GrafoP<T>::INFINITO;

    while(it_fobos_cos != Fobos_costera.fin()){
        p2 = Deimos_costera.primera();
        while(it_deimos_cos != Deimos_costera.fin()){
            
            if(distancia < menor){
                
            }

            p2 = costa2.siguiente(p2);
        }

        p1 = costa1.siguiente(p1);
    }
}


