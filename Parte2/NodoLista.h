#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Nucleo.h"
#include <iostream>

class NodoLista
{
private:
    Nucleo valor;
    NodoLista *siguiente;
    friend class Lista; // Accede a los atributos privados de Nodo lista
public:
    NodoLista(Nucleo valor, NodoLista *sig = NULL);
    NodoLista(); // Constructor por defecto
    ~NodoLista(); // destructor de la clase para eliberar espacio de la memoria.
};
typedef NodoLista *lnodo; // aquí establece un alias a Nodo lista para simplicar el código

#endif // NODOPILA_H