/*******************************************
Fecha: 26 marzo 2025
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
#include <iostream>
#include "nodo.h"

using namespace std;

template<class T>
Nodo<T>::Nodo() {
    // Constructor por defecto
}

template<class T>
Nodo<T>::Nodo(T valor) {
    // Constructor que inicializa el nodo con un valor
    this->dato = valor;
}

template<class T>
T& Nodo<T>::obtenerDato() {
    return this->dato;
}

template<class T>
void Nodo<T>::fijarDato(T& val) {
    this->dato = val;
}

template<class T>
int Nodo<T>::altura() {
    // Calcula la altura del nodo dentro del árbol.
    if (hijos.empty()) {
        return 0; // Un nodo sin hijos tiene altura 0.
    }

    int maximo = 0;
    for (auto& hijo : hijos) {
        maximo = max(maximo, hijo.altura());
    }
    return maximo + 1; // Se suma 1 para contar el nodo actual.
}

template<class T>
int Nodo<T>::tamano() {
    // Calcula el número total de nodos en el subárbol a partir de este nodo.
    int conta = 1; // Cuenta el nodo actual
    for (auto& hijo : hijos) {
        conta += hijo.tamano(); // Suma el tamaño de cada hijo
    }
    return conta;
}

template<class T>
void Nodo<T>::limpiarLista() {
    // Elimina todos los nodos en la lista de hijos de forma recursiva.
    for (auto& hijo : hijos) {
        hijo.limpiarLista();
    }
    hijos.clear(); // Borra todos los hijos de la lista
}

template<class T>
void Nodo<T>::adicionarDesc(T &val) {
    // Agrega un nuevo nodo hijo con el valor proporcionado.
    hijos.emplace_back(val); // Se agrega el nuevo hijo directamente al vector
}

template<class T>
bool Nodo<T>::eliminarDesc(T &val) {
    // Busca y elimina un nodo hijo con el valor especificado.
    for (auto it = hijos.begin(); it != hijos.end(); ++it) {
        if (it->dato == val) {
            hijos.erase(it); // Elimina el nodo encontrado
            return true;
        }
    }
    return false; // Si no se encontró el nodo, retorna falso.
}

template<class T>
Nodo<T>* Nodo<T>::buscar(T val) {
    // Busca un nodo con el valor especificado en el subárbol.
    if (this->dato == val) {
        return this;
    }

    for (auto& hijo : hijos) {
        Nodo<T>* resultado = hijo.buscar(val);
        if (resultado != nullptr) {
            return resultado;
        }
    }
    return nullptr;
}

template<class T>
void Nodo<T>::preOrden() {
    // Recorre el árbol en preorden (nodo actual -> hijos).
    cout << "\t" << this->obtenerDato() << endl;
    for (auto& hijo : hijos) {
        hijo.preOrden();
    }
}

template<class T>
void Nodo<T>::posOrden() {
    // Recorre el árbol en posorden (hijos -> nodo actual).
    for (auto& hijo : hijos) {
        hijo.posOrden();
    }
    cout << "\t" << this->obtenerDato() << endl; // Ahora sí se imprime correctamente después de recorrer los hijos
}

template<class T>
void Nodo<T>::nivelOrden(std::queue<Nodo<T>*>& cola) {
    // Recorre el árbol en orden por niveles usando una cola.
    cola.push(this);
    for (auto& hijo : hijos) {
        cola.push(&hijo); // Se encolan los hijos correctamente
    }
}


	

