bool hayPedidos(std::vector Pedidos)
{
    int sumatorio;
    
    for(int i = 0;i<Pedidos.size();i++)
        sumatorio += Pedidos[i];

    return sumatorio != 0; // Si el sumatorio es distinto de 0 entonces hay pedidos
}

Grafo<tCoste>::nodo min_Dijkstra_pedido(GrafoP<tCoste> mClientes,std::vector<int> Pedidos,Grafo<tCoste>::nodo cliente_actual)
{
        std::vector<tCoste> vec_Dijk;
        std::vector<GrafoP<tCoste>::vertice> vec_ver;
        Grafo<tCoste>::nodo siguiente_cliente;

        vec_Dijk = Dijkstra(mClientes,cliente_actual,vec_ver);

        float min = GrafoP<tCoste>::INFINITO-1;

        for(int i=0;i<vec_Dij.size();i++)
            if(vec[i] < min && Pedidos[i] != 0)
                siguiente_cliente = i;
    

    return siguiente_cliente;
}

float distancia_total(GrafoP<tCoste> matriz_Clientes,size_t capacidad)
{
    std::vector<int> Pedidos(mClientes.size(),-1);
    size_t aux_cap = capacidad;
    float sumatorio = 0;
    
    matriz<tCoste> mCliente = Floyd(matriz_Clientes);
    
    Grafo<tCoste>::nodo actual_cliente = 0; 
    int i=0;    

    while(hayPedidos(Pedidos))
    {   
        siguiente_cliente = min_Dijkstra_pedido(matriz_Clientes,Pedidos,actual_cliente);
        sumatorio += mCliente[actual_cliente][siguiente_cliente];

        if(aux_cap <= Pedido(siguiente_cliente,aux_cap))
        {
            sumatorio += mClientes[n][0];
            actual_cliente = 0;
            aux_cap = capacidad;
        }else{
            aux_cap -= Pedidos(siguiente_cliente,aux_cap);
            pedidos[siguiente_cliente] = 0;
            actual_cliente = siguiente_cliente;
        }
    }

    return sumatorio;
}

///Estaria mal, lo suyo hace floyd y en min_Dijkstra_pedido hacer buscar el min pero sin hacer dijstra