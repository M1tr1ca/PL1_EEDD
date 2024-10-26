#include <iostream>
#include "Lista.h"
#include "NodoLista.h"
#include "Nucleo.h"

using namespace std;

Lista::Lista()
{
    cima = new NodoLista();
    longitud = 1;
}

Lista::~Lista()
{
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
        actual->valor.mostrarInformacion();
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

    // Recorrer la lista y reducir el tiempo de vida de cada núcleo
    lnodo actual = cima;
    while (actual != nullptr)
    {
        actual->valor.reducirTiempoVida();
        actual = actual->siguiente;
    }
    
    // Sacar procesos terminados de ejecutar y meter los de la cola de espera
    actual = cima;
    while (actual != nullptr)
    {
        if (actual->valor.getProcesoActual().getPID()!=0 && actual->valor.getProcesoActual().getTiempoVida() == 0) {
            actual->valor.terminarProcesoActual();
        }
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
        if (actual->valor.numeroProcesosTotales() < menor->valor.numeroProcesosTotales())
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
        if (actual->valor.numeroProcesosTotales() > mayor->valor.numeroProcesosTotales())
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
    lnodo actual = cima;
    while (!esVacia() && !actual->valor.estaOcupado())
    {
        lnodo temp = actual;
        cima = actual->siguiente;
        actual = actual->siguiente;
        longitud--;
        delete temp;
    }

    if (esVacia())
    {
        cima = new NodoLista(Nucleo(), nullptr);
    }
    else
    {

        while (actual->siguiente != nullptr)
        {
            if (!actual->siguiente->valor.estaOcupado())
            {
                lnodo temp = actual->siguiente;
                actual->siguiente = actual->siguiente->siguiente;
                longitud--;
                delete temp;
            }
            actual = actual->siguiente;
        }
    }
}

int Lista::getLongitud()
{
    return longitud;
}