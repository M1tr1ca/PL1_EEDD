#include <iostream>
#include "Pila.h"
#include "Proceso.h"
#include "NodoPila.h"

using namespace std;

Pila::Pila()
{
    cima = nullptr;
}

Pila::~Pila()
{
    while (cima)
    {
        pnodo temp = cima;
        cima = cima->siguiente;
        delete temp;
    }
}

bool Pila::esVacia()
{
    return cima == nullptr;
}

void Pila::apilar(Proceso p)
{
    cima = new NodoPila(p, cima);
}

void Pila::desapilar()
{
    if (cima)
    {
        pnodo temp = cima;
        cima = cima->siguiente;
        delete temp;
    }
}

Proceso Pila::primero()
{
    if (esVacia())
    {
        throw runtime_error("La pila está vacía");
    }
    return cima->valor; // Retorna el valor en la cima de la pila
}

void Pila::mostrarTodo()
{
    if (esVacia())
    {
        throw runtime_error("La pila está vacía");
    }

    pnodo actual = cima;
    while (actual != nullptr)
    {
        cout << actual->valor.getPID() << endl; // Asumiendo que 'Proceso' tiene sobrecargado el operador '<<'
        actual = actual->siguiente;
    }
}
