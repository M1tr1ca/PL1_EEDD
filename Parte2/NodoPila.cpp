#include <iostream>
#include "NodoPila.h"
#include "Proceso.h"

using namespace std;

NodoPila::NodoPila()
{
    siguiente = NULL;
}

NodoPila::NodoPila(Proceso p, NodoPila *sig)
{
    valor = p;
    siguiente = sig;
}

NodoPila::~NodoPila()
{
    // dtor
}
