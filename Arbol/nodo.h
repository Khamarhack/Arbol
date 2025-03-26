/*******************************************
Fecha: 26 marzo 2025
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
#ifndef __NODO__H__   // Verifica si el archivo ya ha sido incluido para evitar múltiples inclusiones
#define __NODO__H__

using namespace std;

template<class T>
class Nodo {
  protected:
    T dato;  // Dato almacenado en el nodo
    vector<Nodo<T>> hijos;  // Lista de nodos hijos (estructura de árbol general)

  public:
    // Constructores
    Nodo();  // Constructor por defecto
    Nodo(T valor);  // Constructor que inicializa el nodo con un valor

    // Métodos de análisis del árbol
    int altura();  // Retorna la altura del subárbol con raíz en este nodo
    int tamano();  // Retorna el número total de nodos en el subárbol

    // Métodos de manipulación de datos
    T& obtenerDato();  // Devuelve una referencia al dato del nodo
    void fijarDato(T& val);  // Modifica el dato almacenado en el nodo

    // Métodos de manipulación del árbol
    void limpiarLista();  // Elimina todos los nodos en el subárbol
    void adicionarDesc(T& val);  // Agrega un nodo hijo con el valor dado
    bool eliminarDesc(T& val);  // Elimina un nodo hijo con el valor dado

    // Métodos de recorrido del árbol
    void preOrden();  // Recorre el árbol en preorden (nodo -> hijos)
    void posOrden();  // Recorre el árbol en posorden (hijos -> nodo)
    void nivelOrden();  // Recorre el árbol por niveles

    // Búsqueda en el árbol
    Nodo* buscar(T val);  // Busca un nodo con el valor especificado
};

#include "nodo.hxx"  // Incluye la implementación de la clase
#endif  // Cierre del `#ifndef`

