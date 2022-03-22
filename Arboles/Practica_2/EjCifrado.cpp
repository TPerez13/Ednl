/*-Dado una arbol, con el mensaje  "Que me ha dado antes", eeeeh, debnes sacar el mensaje ecrito en el arbol. 
2- Recorrer el mismo arbol en inorden, y sacar el mensaje de recorrerlo en inorden**/

void descifrar_mensaje_Rec(Abin<tElto>::nodo n,Abin &A,)
{
    if(n != Abin<tElto>::NODO_NULO)
    {
        
    }
}

void construir_Arbol(char* cad_cif,Abin<tElto>::nodo n, Abin<tElto> &A,aux)
{
    if(A.raiz() == Abin<tElto>::NODO_NULO)
    {
        A.insertarRaiz(cad_cif[0])
        aux++
        construir_Arbol(cad_cif,A.hijoIzqdo(n),A,aux);
    }
    else
    {
        if(cad_cif[aux] != '/0')
        {
            if(A.profundidad(n) != (log2(cad_cif)))
            {
                A.insertarHijoIzqdo(n,cad_cif[aux]);
                aux++;
                construir_Arbol(cad_cif,A.hijoIzqdo(n),A,aux);
                
                if(numNodos(A) - A.padre(n) - pow(2,(log2(cad_cif) - A.profundidad())
                > (pow(2,((log2(cad_cif) - A.profundidad())-1)) -1)))
                {
                    A.insertrarHijoDrcho(n,cad_cif[aux+pow(2,(log2(cad_cif) - A.profundidad())])
                }
                else
                {
                    A.insetarHijoDrcho()
                }

            }

        }
    }
}


char* descifrar_mensaje(char* cad_cif)
{
    char* cad_descif;
    
    //Para descifrar -> Construir el arbol de caracteres en preorden de y despues recorrerlo por anchura

    Abin<tElto> A;

    construir_Arbol(cad_cif,A);
}
