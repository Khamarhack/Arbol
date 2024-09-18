#ifndef __NODO__H__
#define __NODO__H__

using namespace std;

template< class T >
class Nodo{
  protected:
    T dato;
    vector<Nodo <T> > hijos;

  public:
  	Nodo();
  	Nodo(T valor);
  	int altura();
  	int tamano();
    T& obtenerDato();
    void fijarDato(T& val);
    void limpiarLista();
    void adicionarDesc(T& val);
    bool eliminarDesc(T &val);
    void preOrden();
    void posOrden();
    void nivelOrden();
    Nodo* buscar(T val);
};

#include "nodo.hxx"
#endif
