#include <iostream>
#include "Lista.h"
#include "NodoLista.h"
#include "Nucleo.h"

using namespace std;

Lista::Lista()
{
    cima = nullptr;
    longitud = 0;
}

Lista::~Lista()
{
    while (cima)
    {
        lnodo temp = cima;
        cima = cima->siguiente;
        delete temp;
    }
}

bool Lista::esVacia()
{
    return cima == nullptr;
}

void Lista::izquierda(Nucleo p)
{
    lnodo nuevo = new NodoLista(p, cima);
    cima = nuevo;
    longitud++;
}

void Lista::derecha(Nucleo p)
{
    lnodo nuevo = new NodoLista(p, nullptr);

    if (esVacia())
    {
        cima = nuevo;
    }
    else
    {
        lnodo actual = cima;
        while (actual->siguiente != nullptr)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }

    longitud++;
}

Nucleo Lista::prim()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    return cima->valor;
}

Nucleo Lista::ult()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    lnodo actual = cima;
    while (actual->siguiente != nullptr)
    {
        actual = actual->siguiente;
    }

    return actual->valor;
}

void Lista::resto()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    lnodo temp = cima;
    cima = cima->siguiente;
    delete temp;
    longitud--;
}

void Lista::mostrarTodo()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    lnodo actual = cima;
    while (actual != nullptr)
    {
        cima->valor.mostrarInformacion();
        actual = actual->siguiente;
    }
    cout << endl;
}

void Lista::eult()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    Nucleo valor;

    if (cima->siguiente == nullptr)
    {
        valor = cima->valor;
        delete cima;
        cima = nullptr;
    }
    else
    {
        lnodo actual = cima;
        while (actual->siguiente->siguiente != nullptr)
        {
            actual = actual->siguiente;
        }

        delete actual->siguiente;
        actual->siguiente = nullptr;
    }

    longitud--;
}

void Lista::reducirTiempoVida()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    lnodo actual = cima;
    while (actual != nullptr)
    {
        actual->valor.reducirTiempoVida();
        actual = actual->siguiente;
    }
}

Nucleo *Lista::buscarMenosCola()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    lnodo actual = cima;
    lnodo menor = cima;
    while (actual != nullptr)
    {
        if (actual->valor.numeroProcesosEnEspera() < menor->valor.numeroProcesosEnEspera())
        {
            menor = actual;
        }
        actual = actual->siguiente;
    }

    return &menor->valor;
}

Nucleo *Lista::buscarMasCola()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    lnodo actual = cima;
    lnodo mayor = cima;
    while (actual != nullptr)
    {
        if (actual->valor.numeroProcesosEnEspera() > mayor->valor.numeroProcesosEnEspera())
        {
            mayor = actual;
        }
        actual = actual->siguiente;
    }

    return &mayor->valor;
}

int Lista::nucleosLibres()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    int libres = 0;
    lnodo actual = cima;
    while (actual != nullptr)
    {
        if (!actual->valor.estaOcupado())
        {
            libres++;
        }
        actual = actual->siguiente;
    }

    return libres;
}

void Lista::eliminarNucleosVacios()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    lnodo actual = cima;
    while (!actual->valor.estaOcupado())
    {
        lnodo temp = actual;
        cima = actual->siguiente;
        actual = actual->siguiente;
        delete temp;
    }

    while (actual->siguiente != nullptr)
    {
        if (!actual->siguiente->valor.estaOcupado())
        {
            lnodo temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;
        }
        actual = actual->siguiente;
    }
}

int Lista::getLongitud()
{
    return longitud;
}