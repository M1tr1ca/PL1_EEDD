#include "NodoCola.h"
#include "Cola.h"
#include "Proceso.h"

NodoCola::NodoCola()
{
    siguiente = NULL;
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
