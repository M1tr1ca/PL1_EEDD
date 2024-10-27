#include "Nucleo.h"
#include "Cola.h"
#include <iostream>
using namespace std;

Nucleo::Nucleo(int id)
{
    ID = id;
    puntProcesoActual = NULL;
    // colaEspera = Cola();
}

Nucleo::Nucleo()
{
    static int pidCounter = 0;
    // srand(time(0)); // Semilla para garantizar números aleatorios
    ID = pidCounter++;
    // ID = (rand() % 1000) + 1;
    puntProcesoActual = NULL;
    colaEspera = Cola();
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
Proceso *Nucleo::getPuntProcesoActual()
{
    return puntProcesoActual;
}

// Asignar un proceso para ejecutarse en el núcleo
void Nucleo::setProcesoActual(Proceso *proceso)
{
    puntProcesoActual = proceso;
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
    while (!caux.esVacia())
    {
        colaEspera.encolar(caux.desencolar());
    }
}

// Obtener y eliminar el primer proceso de la cola de espera
Proceso Nucleo::obtenerProcesoDeCola()
{
    return colaEspera.desencolar(); // Se asume que la cola tiene un método `pop`
}

// Consultar si el núcleo está ocupado
bool Nucleo::estaOcupado()
{
    return puntProcesoActual != NULL; // Está ocupado si hay un proceso asignado
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
        puntProcesoActual->mostrarInformacion();
    }

    if (numeroProcesosEspera() > 0)
    {
        cout << "Procesos en espera: " << numeroProcesosEspera() << endl;
        colaEspera.mostrarCola();
    }
    else
    {
        cout << "No hay procesos en espera" << endl;
    }
}

void Nucleo::reducirTiempoVida()
{
    if (puntProcesoActual != NULL)
    {
        puntProcesoActual->reducirTiempoVida();
    }
}

void Nucleo::terminarProcesoActual()
{
    cout << "Proceso " << puntProcesoActual->getPID() << " terminado en el núcleo " << ID << endl;
    if (colaEspera.esVacia())
    {
        delete puntProcesoActual;
        puntProcesoActual = NULL;
    }
    else
    {
        delete puntProcesoActual;
        puntProcesoActual = new Proceso(colaEspera.desencolar());
        cout << "Proceso " << puntProcesoActual->getPID() << " entró en ejecución en el núcleo " << ID << endl;
    }
}