#include <iostream>
#include <string>
/*#include <bits/stdc++.h>*/
#include "arbol.h"

using namespace std;

int main(){
    Arbol<int> arbol(5);
    arbol.insertarNodo(5,6);
    arbol.insertarNodo(5,7);
    arbol.insertarNodo(5,8);

    arbol.insertarNodo(6,9);
    arbol.insertarNodo(6,10);
    arbol.insertarNodo(7,11);

    arbol.preOrden();
}
