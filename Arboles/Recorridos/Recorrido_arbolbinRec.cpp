//Recorrido de arboles binarios de manera recurisvo

template <typename T>
void preordenAbin (typename Abin<T>::nodo n, const Abin<T>& A, void (*procesar)(typename Abin<T>::nodo, const Abin<T>&))
// Recorrido en preorden del subárbol cuya raíz
// es el nodo n perteneciente al árbol binario A.
// Cada nodo visitado se procesa mediante la
// función procesar().
{
if (n != Abin<T>::NODO_NULO)
{
procesar(n, A);
preordenAbin(A.hijoIzqdo(n), A, procesar);
preordenAbin(A.hijoDrcho(n), A, procesar);
}
}

template <typename T>
void preordenAbin (typename Abin<T>::nodo n, const Abin<T>& A, void (*procesar)(typename Abin<T>::nodo, const Abin<T>&))
{
    do
    {
        if(n != Abin<T>::NODO_NULO)
        {
            procesar(n,A);
            if(A.hijoDrcho(n) != Abin<T>::NODO_NULO)
            {
                P.push(A.hijoDrcho(n));
            }
            n = A.hijoIzqdo(n);
        }else if(!P.vacia())
        {
            n = P.tope();
            P.pop();
        }
    } while (!(n == Abin<T>::NODO_NULO && P.vacia()));
    
}

template <typename T>
void postodenAbin (typename Abin<T>::nodo n, const Abin<T>& A, void (*procesar)(typename Abin<T>::nodo, const Abin<T>&))// Recorrido en preorden del subárbol cuya raíz
// es el nodo n perteneciente al árbol binario A.
// Cada nodo visitado se procesa mediante la
// función procesar().
{
    if (n != Abin<T>::NODO_NULO)
    {
        preordenAbin(A.hijoIzqdo(n), A, procesar);
        procesar(n, A);
        preordenAbin(A.hijoDrcho(n), A, procesar);
    }
}


template <typename T>
void preordenAbin (typename Abin<T>::nodo n, const Abin<T>& A, void (*procesar)(typename Abin<T>::nodo, const Abin<T>&))// Recorrido en preorden del subárbol cuya raíz
// es el nodo n perteneciente al árbol binario A.
// Cada nodo visitado se procesa mediante la
// función procesar().
{
    if (n != Abin<T>::NODO_NULO)
    {
        preordenAbin(A.hijoIzqdo(n), A, procesar);
        preordenAbin(A.hijoDrcho(n), A, procesar);
        procesar(n, A);
    }
}

template <typename T>
void recNivelesAbin (typename Abin<T>::nodo n, const Abin<T>& A,void (*procesar)(typename Abin<T>::nodo, const Abin<T>&))// Recorrido por niveles del subárbol cuya raíz es el nodo n
// perteneciente al árbol binario A. Cada nodo visitado se
// procesa mediante la función procesar().
{ // Algoritmo mejorado
    Cola<typename Abin<T>::nodo> C; // Cola de nodos de árbol binario.if (n != Abin<T>::NODO_NULO)
    if(n != Abin<T>::NODO_NULO){
        do {
            if (!C.vacia())
            {
                n = C.frente();
                C.pop();
            }
            procesar(n, A);

            if (A.hijoIzqdo(n) != Abin<T>::NODO_NULO)
                C.push(A.hijoIzqdo(n));
            if (A.hijoDrcho(n) != Abin<T>::NODO_NULO)
                C.push(A.hijoDrcho(n));
                
        } while (!C.vacia());
    }
}
