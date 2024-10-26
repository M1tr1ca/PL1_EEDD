#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"
#include "Proceso.h"

class Pila
{
private:
    pnodo cima;

public:
    Pila();
    ~Pila();
    bool esVacia();
    void apilar(Proceso p);
    Proceso primero();
    Proceso desapilar();
    void mostrarTodo();
    void reducirTiempoInicio();
};

#endif // PILA_H