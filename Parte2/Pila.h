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

    void reducirTiempoInicio();
    void mostrarTodo(); // No es correcto, se implementa para ver que está creada correctamente
};

#endif // PILA_H