/*El archipielago Grecoland esta formado por 2 islas, con N1 y N2 ciudades, de las cuales C1 y C2 son costeras.
Se dispone de los grafos de matrices de adyacencia, distancia euclidea entre ciudades
Hay que construir 
*/
struct Puente
{
    Ciudades og;
    Ciudades dest;
};

struct Ciudades
{
    float x;
    float y;
};

tCoste distancia(Ciudades c1, Ciudades c2){return sqrt(pow(c2.x-c1.x)+pow(c2.y-c1.y));}

Puente minimizar_costes(Matriz<bool> Fobos,Matriz<bool> Deimos,std::vector<Ciudades> Fobos_coordenadas,std::vector<Ciudades> Deimos_coordenadas,List<Ciudades> Fobos_costera,List<Ciudades> Deimos_costera)
{
    GrafoP<tCoste> Archipielago_distancias(Fobos.size()+Deimos.size());

    for(int i=0;i<Fobos.size();i++)
        for(int j=0;Fobos.size();j++)
            if(Fobos[i][j])
                Archipielago_distancias[i][j] = distancia(Fobos_coordenadas[i],Fobos_coordenadas[j]);


    for(int i=0;i<Deimos.size();i++)        
        for(int j=0;Deimos.size();j++)
            if(Deimos[i][j])
                Archipielago_distancias[i+Fobos.size()][j+Fobos.size()] = distancia(Deimos_coordenadas[i],Deimos_coordenadas[j]);
           
    
    return mejor_puente(Archipielago_distancias, Fobos.size(),Deimos.size())
}

float sumatorio(std::vector<Grafo<tCoste>::vertices> vec_ver,int tam_d,int tam_f)
{
    int sumatorio=0;
    for(int i= tam_ini;i<tam_f+tam_d;i++)
        sumatorio +=vec_ver[i];

    return sumatorio;
}

Puente mejor_puente(GrafoP<tCoste> Archipielago, int tam_f,int tam_d,List<Ciudades> Fobos_costera,List<Ciudades> Deimos_costera)
{

    std::vector<Grafo<tCoste>::vertices> vec_ver;
    std::vector<tCoste> vec_Dijk;
    
    float min1 = Grafo<tCoste>::INFINITO-1;

    float sumatorio;
    Puente p;

    std::List<Ciudades>::iterator it_fob_cost = Fobos_costera.begin();

    int i=0;
    while(it_fob_cost != Fobos.end())
    {
        vec_Dijk=Dijkstra(Archipielago,vec_ver);
        sumatorio = sumatorio(vec_Dijk,0,tam_d)
        if(sumatorio < min1)
        {
            min1 = sumatorio;
            c1 = i;
        }
        i++;
    }

    std::List<Ciudades>::iterator it_fob_cost = Deimos.begin();

    int j=0;
    while(it_fob_cost != Deimos.end())
    {
        vec_Dijk=Dijkstra(Archipielago,vec_ver);
        sumatorio = sumatorio(vec_Dijk,tam_f,tam_d)
        if(sumatorio < min1)
        {
            min1 = sumatorio;
            c2 = j;
        }
        j++;
    }

    Puente p;
    p.x = i; p.y = j;

    return p;
}


