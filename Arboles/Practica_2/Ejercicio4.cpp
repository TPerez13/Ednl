 //busqueda dicotomica
//Ejercicio 4

//Vector de posiciones relativas
template <typename T>
class Abin
{
	public:
		Abin();
		void insertarRaiz(const T& e);
		void insertarHijoIzqdo(Abin<T>::nodo n, const T& e);
		Abin<T>::nodo padre(Abin<T>::nodo n) const;
		
		
		
	private:
		int alturaAbin(const Abin<T>& A);
		int alturaAbin_rec(const Abin<T>& A, Abin<T>::nodo n);
		
		int H = -1;
		int N = pow(2,H+1) - 1;
		Nodo[N] vec;

}



template <typename T>
inline int Abin::alturaAbin(const Abin<T>& A)
{
	return alturaAbin_rec(A,A.raiz());
}



template <typename T>
inline int Abin::alturaAbin(const Abin<T>& A, Abin<T>::nodo n)
{
	if(n == Abin<T>::NODO_NULO)
		return -1;
	else
		return 1 + max(alturaAbin(A,A.hijoIzqdo(n)), alturaAbin(A,A.hijoDrcho(n)));
}


template <typename T>
inline Abin::Abin(){}



template <typename T>
inline void Abin::insertarRaiz(const T& e)
{
	vec[0] = e;
}


template <typename T>
inline void Abin::insertarHijoIzqdo(Abin<T>::nodo n, const T& e)
{
	vec[n - pow(2,alturaAbin_rec(A,n)-1)] = e;
}


template <typename T>
inline Abin<T>::nodo Abin::padre(Abin<T>:: nodo n) const
{
	if(n % pow(2,alturaAbin_rec(A,n)+2) == pow(2,alturaAbin_rec(A,n))-1)
		return (n + pow(2,alturaAbin_rec(A,n)));
	else
		return (n - pow(2,alturaAbin_rec(A,n)));
}



/*
int Altura_Rec(Abin<tElto>::nodo n, Abin<tElto> &A)
{
    if(n == Abinz<tElto>::NODO_NULO)
    {
       return -1;
    }
    else
    {
       if(n < A.raiz())
       {
           return 1 + max(Altura_Rec(n/2,A),Altura_Rec((n+((n/2)+1));
       }
       else if(n > A.raiz())
    }
}*/