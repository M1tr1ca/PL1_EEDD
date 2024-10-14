#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"
#include "Proceso.h"

class Cola
{
private:
    NodoCola *primero;
    NodoCola *ultimo;
    int longitud;

public:
    Cola();
    ~Cola();
    void encolar(Proceso p);
    Proceso inicio();
    Proceso fin();
    Proceso desencolar();
    int getLongitud();
    bool esVacia();
    Proceso frente();   // frente
    void mostrarCola(); // No es correcto , se implementa para ver que está creada correctamente
};

#endif // COLA_H