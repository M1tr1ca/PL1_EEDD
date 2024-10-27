#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Nucleo.h"
#include <iostream>

class NodoLista
{
private:
    Nucleo valor;
    NodoLista *siguiente;
    friend class Lista;

public:
    NodoLista(Nucleo valor, NodoLista *sig = NULL);
    NodoLista();
    ~NodoLista();
};
typedef NodoLista *lnodo;

#endif // NODOPILA_H