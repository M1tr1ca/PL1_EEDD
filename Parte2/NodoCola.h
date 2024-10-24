#ifndef NODOCOLA_H
#define NODOCOLA_H
#include <iostream>
#include "Proceso.h"

class NodoCola
{
    friend class Cola;

private:
    NodoCola *siguiente;
    Proceso elemento;

public:
    NodoCola();
    NodoCola(Proceso elemento, NodoCola *sig = NULL);
    ~NodoCola();
};
typedef NodoCola *cnodo;

#endif // NODOCOLA_H
