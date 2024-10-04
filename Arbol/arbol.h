/******************************************
Fecha: 1 octubre 2024
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
#ifndef __ARBOL__H__
#define __ARBOL__H__

#include "nodo.h"

using namespace std;

template<class T>
class Arbol {
	protected:
    	Nodo<T> *raiz;
	public:
		Arbol();
		Arbol(T val);
	    bool esVacio();
   	 	T obtenerRaiz();
   	 	void fijarRaiz(Nodo<T>* root);
   	 	bool insertarNodo(T padre, T val);
    	int altura();
	    int tamano();
   		void insertar(T& val);
    	bool eliminar(T& val);
    	Nodo<T>*  buscar(T val);
    	void preOrden();
    	void inOrden();
    	void posOrden();
    	void nivelOrden();
};

#include "arbol.hxx"
#endif
