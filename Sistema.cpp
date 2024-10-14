// Sistema.cpp
#include "Sistema.h"
#include "Proceso.h"
#include "Pila.h"

Sistema::Sistema()
{
    int nucleosLibres = TOTAL_NUCLEOS;
    crearProcesos();
}

void Sistema::crearProcesos()
{
    // Crear 10 procesos manualmente
    pilaProcesos.apilar(Proceso(1001, 1, 10, 30, 2, 1));
    pilaProcesos.apilar(Proceso(1002, 1, 5, 20, 1, 2));
    pilaProcesos.apilar(Proceso(1003, 1, 15, 25, 3, 1));
    pilaProcesos.apilar(Proceso(1004, 1, 3, 10, 0, 1));
    pilaProcesos.apilar(Proceso(1005, 1, 12, 15, 4, 2));
    pilaProcesos.apilar(Proceso(1006, 1, 8, 18, 1, 2));
    pilaProcesos.apilar(Proceso(1007, 1, 20, 10, 2, 1));
    pilaProcesos.apilar(Proceso(1008, 1, 25, 30, 3, 2));
    pilaProcesos.apilar(Proceso(1009, 1, 14, 20, 0, 1));
    pilaProcesos.apilar(Proceso(1010, 1, 18, 15, 1, 1));
}

void Sistema::mostrarPila()
{
    cout << "Procesos en la pila:" << endl;
    if (!pilaProcesos.esVacia())
    {
        Proceso proceso = pilaProcesos.primero();
        proceso.mostrarInformacion();
    }
    else
    {
        cout << "La pila está vacía" << endl;
    }
}

void Sistema::borrarPila()
{
    while (!pilaProcesos.esVacia())
    {
        pilaProcesos.desapilar();
    }
    cout << "Pila de procesos borrada.\n";
}

void Sistema::mostrarColaEspera()
{
    cout << "Cola de espera:" << endl;
    // Muestra solo el primer elemento
    colaEspera.mostrarCola();
}

void Sistema::mostrarEjecutando()
{
    cout << "Procesos en ejecución:" << endl;
    for (int i = 0; i < TOTAL_NUCLEOS; i++)
    {
        if (nucleos[i] != NULL)
        {
            cout << "Núcleo " << i + 1 << ": ";
            nucleos[i]->mostrarInformacion();
            cout << endl;
        }
    }
}

void Sistema::simularMinutos(int n)
{
    // Simular la llegada/salida de procesos
    for (int i = 0; i < n; i++)
    {
        cout << "Simulando minuto " << i << "..." << endl;
        if (!pilaProcesos.esVacia())
        {
            Proceso proceso = pilaProcesos.primero();
            if (proceso.getInicio() == i)
            {
                cout << "Proceso " << proceso.getPID() << "entró en la cola de espera" << endl;
                procesoEntraEspera(proceso);
            }
        }
        // Simular la ejecución de procesos
        for (int j = 0; j < TOTAL_NUCLEOS; j++)
        {
            if (nucleos[j] != NULL)
            {
                if (nucleos[j]->getTiempoVida() == 0)
                {
                    cout << "Proceso " << nucleos[j]->getPID() << "terminó de ejecutarse" << endl;
                    nucleos[j] = NULL;
                    nucleosLibres++;
                }
                else
                {
                    nucleos[j]->reducirTiempoVida();
                }
            }
        }
        // Asignar procesos a los núcleos
        while (!colaEspera.esVacia() && nucleosLibres > 0)
        {
            Proceso proceso = colaEspera.desencolar();
            for (int j = 0; j < TOTAL_NUCLEOS; j++)
            {
                if (nucleos[j] == NULL)
                {
                    nucleos[j] = new Proceso(proceso);
                    nucleosLibres--;
                    cout << "Proceso " << proceso.getPID() << "asignado al núcleo " << j + 1 << endl;
                    break;
                }
            }
        }
    }
}

void Sistema::ejecutarProcesos()
{
    while (!pilaProcesos.esVacia() && !colaEspera.esVacia())
    {
        simularMinutos(1);
    }
}

void Sistema::procesoEntraEspera(Proceso p)
{
    Cola caux;
    while (!colaEspera.esVacia() && colaEspera.frente().getPrioridad() < p.getPrioridad())
    {
        Proceso proceso = colaEspera.desencolar();
        caux.encolar(proceso);
    }
    caux.encolar(p);
    while (!colaEspera.esVacia())
    {
        caux.encolar(colaEspera.desencolar());
    }
    colaEspera = caux;
}

void Sistema::mostrarEstado()
{
    cout << "Estado actual del sistema:\n";
    cout << "Núcleos libres: " << nucleosLibres << endl;
    cout << "Procesos en cola de espera: ";
    colaEspera.mostrarCola();
    cout << endl;
    mostrarEjecutando();
}
