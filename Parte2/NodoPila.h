#ifndef NODOPILA_H
#define NODOPILA_H
#include "Proceso.h"
#include <iostream>

class NodoPila
{
private:
    Proceso valor;
    NodoPila *siguiente;
    friend class Pila; // Accede a los atributos privados de Nodo pila
public:
    NodoPila(); // Constructor por defecto
    NodoPila(Proceso valor, NodoPila *sig = NULL);
    ~NodoPila(); // destructor de la clase para eliberar espacio de la memoria.
};
typedef NodoPila *pnodo; // aquí establece un alias a Nodo pila para simplicar el código

#endif // NODOPILA_H