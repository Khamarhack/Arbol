/*******************************************
Fecha: 26 marzo 2025
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
#ifndef __ARBOL__H__  // Verifica si el archivo ya ha sido incluido para evitar duplicaciones
#define __ARBOL__H__

#include "nodo.h"  // Inclusión de la clase Nodo

using namespace std;

template<class T>
class Arbol {
	protected:
    	Nodo<T> *raiz;  // Puntero a la raíz del árbol

	public:
		// Constructores
		Arbol();  // Constructor por defecto (árbol vacío)
		Arbol(T val);  // Constructor que inicializa el árbol con un valor en la raíz

	    // Métodos de verificación
	    bool esVacio();  // Devuelve true si el árbol está vacío

   	 	// Métodos de acceso a la raíz
   	 	T obtenerRaiz();  // Retorna el valor de la raíz del árbol
   	 	void fijarRaiz(Nodo<T>* root);  // Establece un nuevo nodo como raíz

   	 	// Métodos de modificación del árbol
   	 	bool insertarNodo(T padre, T val);  // Inserta un nodo con valor `val` como hijo de `padre`
    	int altura();  // Retorna la altura del árbol
	    int tamano();  // Retorna el número total de nodos en el árbol
   		void insertar(T& val);  // Inserta un nuevo nodo en el árbol (método por implementar)
    	bool eliminar(T& val);  // Elimina un nodo con el valor `val`

    	// Métodos de búsqueda
    	Nodo<T>* buscar(T val);  // Busca un nodo con el valor `val` y lo retorna

    	// Métodos de recorrido del árbol
    	void preOrden();  // Recorre el árbol en preorden
    	void inOrden();  // Recorre el árbol en inorden (pendiente de implementación)
    	void posOrden();  // Recorre el árbol en posorden
    	void nivelOrden();  // Recorre el árbol por niveles
};

#include "arbol.hxx"  // Se incluye la implementación de la clase
#endif  // Fin de la directiva de preprocesador
