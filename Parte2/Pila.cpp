#include <iostream>
#include "Pila.h"
#include "Proceso.h"
#include "NodoPila.h"

using namespace std;

Pila::Pila()
{
    cima = NULL;
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
    return cima == NULL;
}

void Pila::apilar(Proceso p)
{
    cima = new NodoPila(p, cima);
}

Proceso Pila::desapilar()
{
    if (cima)
    {
        Proceso elemento = cima->valor;
        NodoPila *aux = cima;
        cima = cima->siguiente;
        delete aux;
        return elemento;
    }
    else
    {
        throw runtime_error("La pila está vacía");
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
    while (actual != NULL)
    {
        actual->valor.mostrarInformacion(); // Asumiendo que 'Proceso' tiene sobrecargado el operador '<<'
        actual = actual->siguiente;
    }
}

void Pila::reducirTiempoInicio()
{
    pnodo actual = cima;
    while (actual != NULL)
    {
        actual->valor.reducirTiempoInicio();
        actual = actual->siguiente;
    }
}
