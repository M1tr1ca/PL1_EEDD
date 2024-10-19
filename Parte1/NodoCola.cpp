#include "NodoCola.h"
#include "Cola.h"
#include "Proceso.h"

NodoCola::NodoCola()
{
    elemento = Proceso();
    siguiente = NULL;
    // Constructor por defecto
}

NodoCola::NodoCola(Proceso e, NodoCola *sig)
{
    elemento = e;
    siguiente = sig;
}

NodoCola::~NodoCola()
{
    // dtor
}
