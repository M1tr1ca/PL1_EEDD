#ifndef NODOCOLA_H
#define NODOCOLA_H
#include <iostream>
#include "Proceso.h"

class NodoCola
{
private:
    Proceso elemento;
    NodoCola *siguiente;
    friend class Cola;

public:
    NodoCola();
    NodoCola(Proceso elemento, NodoCola *sig = NULL);
    ~NodoCola();
};
typedef NodoCola *cnodo;

#endif // NODOCOLA_H
