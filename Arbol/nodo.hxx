#include <iostream>
#include "nodo.h"

using namespace std;

template<class T>
Nodo<T>::Nodo()
{

}

template<class T>
Nodo<T>::Nodo(T valor)
{
    this->dato = valor;
}

template<class T>
T& Nodo<T>::obtenerDato()
{
    return this->dato;
}

template<class T>
void Nodo<T>::fijarDato(T& val)
{
    this->dato = val;
    return;
}

template<class T>
int Nodo<T>::altura()
{
	if(hijos.size()==0)
	{
		return 0;
	}
	int maximo = 0, aux_altura;
	for(int i = 0;i<hijos.size() ; i++){
	    aux_altura = hijos[i].altura();
        if(aux_altura> maximo)
            maximo = aux_altura;
	}
	return maximo + 1;
}


template<class T>
int Nodo<T>::tamano()
{
	if(this->hijoIzq==NULL && this->hijoDer == NULL)
	{
		return 1;
	}
	int conta = 0;
	for( int i = 0; i<hijos.size() ; ++i){
        conta+=hijos[i].tamano();
	}
	return conta+1;
}


template<class T>
void Nodo<T>:: limpiarLista()
{
    if(hijos.size()==0){
        delete(this);
        return;

    }

    for(int i=0; i<hijos.size(); i++){
        hijos[i].limpiarLista();
    }

}



template<class T>
void Nodo<T>:: adicionarDesc(T &val)
{
    Nodo* hijo = new Nodo(val);
    hijos.push_back(*hijo);
}


template<class T>
bool Nodo<T>:: eliminarDesc(T &val){
    bool correr=false;
    for(int i=0;i<hijos.size();i++){
        if(correr){
            hijos[i-1]=hijos[i];
        }
        if(hijos[i] == val)
            correr=true;
    }

    if(!correr)
        return false;
    hijos.pop_back();
    return true;
}


template<class T>
Nodo<T>* Nodo<T>:: buscar(T val){
    if(this->dato == val)
        return this;
    if(this->hijos.size() == 0)
        return NULL;
    Nodo* aux;
    for(int i = 0; i<hijos.size() ; i++){
        aux = hijos[i].buscar(val);
        if(aux!=NULL)
            return aux;
    }

    return NULL;

}

template<class T>
void Nodo<T>:: preOrden()
{
	cout << "\t"<<this->obtenerDato() << endl;
	for(int i = 0; i < hijos.size() ; i++){
        hijos[i].preOrden();
	}
	return;
}

template<class T>
void Nodo<T>:: posOrden()
{
	for(int i = 0; i < hijos.size() ; i++){
        hijos[i].preOrden();
	}
	return;

	cout << "\t"<<this->obtenerDato() << endl;
	return;

}

template<class T>
void Nodo<T>:: nivelOrden(std::queue<Nodo*> &cola){
	cola.push(this);
	for(int i=0 ; i<this->hijos->size() ; i++){
        cola.push(this->hijos[i]);
	}
}




