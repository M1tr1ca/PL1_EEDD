#include "Cola.h"
#include <iostream>
#include "Proceso.h"
using namespace std;

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

Cola::~Cola()
{
}

void Cola::encolar(Proceso elemento)
{
    NodoCola *nuevo_nodo = new NodoCola(elemento, NULL);
    if (esVacia())
    {
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    else
    {
        ultimo->siguiente = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    longitud++;
}

Proceso Cola::desencolar()
{
    if (!esVacia())
    {
        Proceso elemento = primero->elemento;
        NodoCola *aux = primero;

        if ((primero == ultimo) && (primero->siguiente == NULL))
        {
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete aux;
        }
        else
        {
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete aux;
        }
        longitud--;
        return elemento;
    }
    else
    {
        throw runtime_error("La cola está vacía");
    }
}

Proceso Cola::fin()
{
    if (!esVacia())
    {
        return ultimo->elemento;
    }
    else
    {
        throw runtime_error("La cola está vacía");
    }
}

int Cola::getLongitud()
{
    return longitud;
}

bool Cola::esVacia()
{
    return ((primero == NULL) && (ultimo == NULL));
}
void Cola::mostrarCola()
{
    NodoCola *aux = primero;
    if (esVacia())
    {
        cout << "La cola está vacía" << endl;
    }
    else
    {
        while (aux)
        {
            cout << aux->elemento.getPID() << endl;
            aux = aux->siguiente;
        }
    }
}

Proceso Cola::frente()
{
    if (esVacia())
    {
        throw runtime_error("La cola está vacía");
    }
    return primero->elemento; // Retorna el valor en la cima de la pila
}