/*******************************************
Fecha: 26 marzo 2025
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
#include <iostream>
#include <queue>
#include "arbol.h"

using namespace std;

template<class T>
Arbol<T>::Arbol() {
    // Inicializa el árbol con una raíz nula (árbol vacío)
    this->raiz = nullptr;
}

template<class T>
Arbol<T>::Arbol(T val) {
    // Crea un árbol con un nodo raíz que contiene el valor `val`
    this->raiz = new Nodo<T>(val);
}

template<class T>
bool Arbol<T>::esVacio() {
    // Verifica si el árbol está vacío (si la raíz es nula)
    return this->raiz == nullptr;
}

template<class T>
T Arbol<T>::obtenerRaiz() {
    // Devuelve el valor almacenado en la raíz del árbol
    if (this->raiz != nullptr) {
        return this->raiz->obtenerDato();
    }
    throw runtime_error("El árbol está vacío, no tiene raíz.");
}

template<class T>
void Arbol<T>::fijarRaiz(Nodo<T>* root) {
    // Asigna una nueva raíz al árbol
    this->raiz = root;
}

template<class T>
int Arbol<T>::altura() {
    // Retorna la altura del árbol desde la raíz
    return this->raiz ? this->raiz->altura() : 0;
}

template<class T>
int Arbol<T>::tamano() {
    // Retorna el número total de nodos en el árbol
    return this->raiz ? this->raiz->tamano() : 0;
}

template<class T>
bool Arbol<T>::insertarNodo(T padre, T val) {
    // Busca el nodo padre y le agrega un nuevo hijo con el valor `val`
    Nodo<T>* aux = this->raiz ? this->raiz->buscar(padre) : nullptr;
    if (aux == nullptr)
        return false;
    aux->adicionarDesc(val);
    return true;
}

template<class T>
bool Arbol<T>::eliminar(T val) {
    // Elimina un nodo con el valor `val` si existe
    return this->raiz ? this->raiz->eliminarDesc(val) : false;
}

template<class T>
Nodo<T>* Arbol<T>::buscar(T val) {
    // Busca y retorna el nodo con el valor `val`, si existe
    return this->raiz ? this->raiz->buscar(val) : nullptr;
}

template<class T>
void Arbol<T>::preOrden() {
    // Realiza un recorrido en preorden del árbol
    if (this->raiz) this->raiz->preOrden();
}

template<class T>
void Arbol<T>::posOrden() {
    // Realiza un recorrido en posorden del árbol
    if (this->raiz) this->raiz->posOrden();
}

template<class T>
void Arbol<T>::nivelOrden() {
    // Realiza un recorrido por niveles del árbol
    if (this->raiz) {
        queue<Nodo<T>*> cola;
        this->raiz->nivelOrden(cola);
        
        while (!cola.empty()) {
            Nodo<T>* nodo = cola.front();
            cola.pop();
            cout << nodo->obtenerDato() << " ";
        }
        cout << endl;
    }
}

