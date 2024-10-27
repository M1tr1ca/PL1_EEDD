#include <iostream>
#include "NodoPila.h"
#include "Proceso.h"

using namespace std;

NodoPila::NodoPila()
{
    // valor = Proceso();
    siguiente = NULL;
}

NodoPila::NodoPila(Proceso p, NodoPila *sig)
{
    valor = p;
    siguiente = sig;
}

NodoPila::~NodoPila()
{
    // Destructor
}
