#include "Nucleo.h"
#include "Cola.h"
#include <iostream>
using namespace std;

Nucleo::Nucleo(int id)
{
    id = id;
    procesoActual = nullptr;
}

Nucleo::Nucleo()
{
    srand(time(0)); // Semilla para garantizar números aleatorios
    id = (rand() % 1000) + 1;
}

Nucleo::~Nucleo()
{
    delete procesoActual;
}

// Obtener el ID del núcleo
int Nucleo::getId()
{
    return id;
}

// Obtener el proceso que se está ejecutando actualmente
Proceso *Nucleo::getProcesoActual()
{
    return procesoActual;
}

// Asignar un proceso para ejecutarse en el núcleo
void Nucleo::setProcesoActual(Proceso *proceso)
{
    procesoActual = proceso;
}

// Añadir un proceso a la cola de espera del núcleo
void Nucleo::añadirEsperaPrioridad(Proceso proceso)
{
    Cola caux;
    while (!colaEspera.esVacia() && colaEspera.frente().getPrioridad() < proceso.getPrioridad())
    {
        caux.encolar(colaEspera.desencolar());
    }
    caux.encolar(proceso);
    while (!colaEspera.esVacia())
    {
        caux.encolar(colaEspera.desencolar());
    }
    colaEspera = caux;
}

// Obtener y eliminar el primer proceso de la cola de espera
Proceso Nucleo::obtenerProcesoDeCola()
{
    return colaEspera.desencolar(); // Se asume que la cola tiene un método `pop`
}

// Consultar si el núcleo está ocupado
bool Nucleo::estaOcupado()
{
    return procesoActual != nullptr; // Está ocupado si hay un proceso asignado
}

// Consultar el número de procesos en la cola de espera
int Nucleo::numeroProcesosEnEspera()
{
    return colaEspera.getLongitud() + estaOcupado() ? 1 : 0;
}

// Mostrar información sobre el núcleo
void Nucleo::mostrarInformacion()
{
    cout << "Nucleo " << id << ": "
         << (estaOcupado() ? "Ocupado" : "Libre") << endl;

    if (estaOcupado())
    {
        cout << "Proceso en ejecución (PID): " << procesoActual->getPID() << endl;
    }

    if (numeroProcesosEnEspera() > 0)
    {
        cout << "Procesos en espera: " << numeroProcesosEnEspera() << endl;
        colaEspera.mostrarCola(); // Asumiendo que Cola tiene un método `mostrarCola()`
    }
    else
    {
        cout << "No hay procesos en espera" << endl;
    }
}

void Nucleo::reducirTiempoVida()
{
    if (procesoActual != nullptr)
    {
        procesoActual->reducirTiempoVida();
    }
}