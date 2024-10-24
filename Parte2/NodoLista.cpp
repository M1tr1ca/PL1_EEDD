#include <iostream>
#include "NodoLista.h"

using namespace std;

NodoLista::NodoLista()
{
    valor = Nucleo();
    siguiente = NULL;
}

NodoLista::NodoLista(Nucleo p, NodoLista *sig)
{
    valor = p;
    siguiente = sig;
}

NodoLista::~NodoLista()
{
    // Destructor
}