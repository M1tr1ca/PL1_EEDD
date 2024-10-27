#ifndef NODOPILA_H
#define NODOPILA_H
#include "Proceso.h"
#include <iostream>

class NodoPila
{
private:
    Proceso valor;
    NodoPila *siguiente;
    friend class Pila;

public:
    NodoPila();
    NodoPila(Proceso valor, NodoPila *sig = NULL);
    ~NodoPila();
};
typedef NodoPila *pnodo;

#endif // NODOPILA_H