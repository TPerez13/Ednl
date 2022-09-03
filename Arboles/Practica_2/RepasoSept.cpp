//Ejercicio 1
bool recorridoPre(Abin<tElto>::nodo n1,Abin<tElto>::nodo n2,Abin<tElto> &A1,Abin<tElto> &A2)
{

    if(n1 != Abion<tElto>::NODO_NULO && n2 != Abion<tElto>::NODO_NULO)
        return true && recorridoPre(A1.hijoIzqdo(n),A2.hijoIzqdo(n),A1,A2) 
                    && recorridoPre(A1.hijoDrcho(n),A2.hijoDrcho(n),A1,A2);
    else if (n1 == Abion<tElto>::NODO_NULO && n2 == Abion<tElto>::NODO_NULO)
        return true ;
    else
        return false;
}


//Ejercicio 2

void arbol_reflejado(Abin<tElto>::nodo n1,Abin<tElto>::nodo n2,Abin<tElto> &A,Abin<tElto> &B)
{

    if(A.hijoDrcho(n1) != Abin<tElto>::NODO_NULO && A.hijoIzqdo(n) != Abin<tElto>::NODO_NULO){
        B.insertarHijoIzqdo(n2,A.elemento(A.hijoDrcho(n1)));
        B.insertarHijoDrcho(n2,A.elemento(A.hijoIzqdo(n1))

        arbol_reflejado(A.hijoIzqdo(n1),B.hijoDrcho(n2),A,B);
        arbol_reflejado(A.hijoIzqdo(n1),B.hijoIzqdo(n2),A,B);

    }else if(A.hijoIzqdo(n) != Abin<tElto>::NODO_NULO){
        B.insertarHijoDrcho(n1,A.elemento(A.hijoDrcho(n1)));        
        
        arbol_reflejado(A.hijoIzqdo(n1),B.hijoDrcho(n2),A,B);
    }else if(A.hijoDrcho(n) != Abin<tElto>::NODO_NULO){
        B.insertarHijoizqdo(n1,A.elemento(A.hijoDrcho(n1)));        
        
        arbol_reflejado(A.HijoDrcho(n1),B.hijoIzqdo(n2),A,B);
    }    
}