#include "Nucleo.h"
#include "Cola.h"
#include <iostream>
using namespace std;

Nucleo::Nucleo(int id)
{
    ID = id;
    procesoActual = Proceso();
}

Nucleo::Nucleo()
{
    srand(time(0)); // Semilla para garantizar números aleatorios
    ID = (rand() % 1000) + 1;
    procesoActual = Proceso();
}

Nucleo::~Nucleo()
{
    // Destructor
}

// Obtener el ID del núcleo
int Nucleo::getId()
{
    return ID;
}

// Obtener el proceso que se está ejecutando actualmente
Proceso Nucleo::getProcesoActual()
{
    return procesoActual;
}

// Asignar un proceso para ejecutarse en el núcleo
void Nucleo::setProcesoActual(Proceso proceso)
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
    this->colaEspera = caux;
}

// Obtener y eliminar el primer proceso de la cola de espera
Proceso Nucleo::obtenerProcesoDeCola()
{
    return colaEspera.desencolar(); // Se asume que la cola tiene un método `pop`
}

// Consultar si el núcleo está ocupado
bool Nucleo::estaOcupado()
{
    return procesoActual.getPID() != 0; // Está ocupado si hay un proceso asignado
}

// Consultar el número de procesos en la cola de espera
int Nucleo::numeroProcesosEspera()
{
    return colaEspera.getLongitud();
}

// Consultar el número de procesos en el núcleo
int Nucleo::numeroProcesosTotales()
{
    return colaEspera.getLongitud() + (estaOcupado() ? 1 : 0);
}

// Mostrar información sobre el núcleo
void Nucleo::mostrarInformacion()
{
    cout << "Nucleo " << ID << ": "
         << (estaOcupado() ? "Ocupado" : "Libre") << endl;

    if (estaOcupado())
    {
        cout << "Proceso en ejecución (PID): " << procesoActual.getPID() << endl;
    }

    if (numeroProcesosEspera() > 0)
    {
        cout << "Procesos en espera: " << numeroProcesosEspera() << endl;
        colaEspera.mostrarCola(); // Asumiendo que Cola tiene un método `mostrarCola()`
    }
    else
    {
        cout << "No hay procesos en espera" << endl;
    }
}

void Nucleo::reducirTiempoVida()
{
    if (procesoActual.getPID() != 0)
    {
        procesoActual.reducirTiempoVida();
    }
}