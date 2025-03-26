/*******************************************
Fecha: 26 marzo 2025
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
// #include <bits/stdc++.h>  // Comentado porque es innecesario en este contexto.
#include "arbol.h"  // Incluye la definición de la clase Arbol.

using namespace std;

int main() {
    // Crea un árbol de enteros con la raíz en el nodo 5.
    Arbol<int> arbol(5);

    // Inserta nodos en el árbol.
    // Se agrega 6, 7 y 8 como hijos del nodo 5.
    arbol.insertarNodo(5, 6);
    arbol.insertarNodo(5, 7);
    arbol.insertarNodo(5, 8);

    // Se agregan nodos secundarios:
    // - 9 y 10 como hijos del nodo 6.
    // - 11 como hijo del nodo 7.
    arbol.insertarNodo(6, 9);
    arbol.insertarNodo(6, 10);
    arbol.insertarNodo(7, 11);

    // Imprime el recorrido en preorden del árbol.
    arbol.preOrden();

    return 0;
}
