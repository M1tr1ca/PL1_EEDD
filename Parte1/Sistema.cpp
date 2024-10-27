// Sistema.cpp
#include "Sistema.h"
#include "Proceso.h"
#include "Pila.h"

Sistema::Sistema()
{
    nucleosLibres = TOTAL_NUCLEOS;
    minutos = 0;
    for (int i = 0; i < TOTAL_NUCLEOS; i++)
    {
        nucleos[i] = NULL;
    }
    crearProcesos();
}

void Sistema::crearProcesos()
{
    cout << "Creando 10 procesos..." << endl;
    // Crear 10 procesos manualmente
    nuevoProceso(Proceso(1001, 1, 10, 30, 2, -1));
    nuevoProceso(Proceso(1002, 1, 5, 20, 1, -1));
    nuevoProceso(Proceso(1003, 1, 15, 25, 3, -1));
    nuevoProceso(Proceso(1004, 1, 3, 10, 0, -1));
    nuevoProceso(Proceso(1005, 1, 12, 15, 4, -1));
    nuevoProceso(Proceso(1006, 1, 8, 18, 1, -1));
    nuevoProceso(Proceso(1007, 1, 20, 10, 2, -1));
    nuevoProceso(Proceso(1008, 1, 25, 30, 3, -1));
    nuevoProceso(Proceso(1009, 1, 14, 20, 0, -1));
    nuevoProceso(Proceso(1010, 1, 18, 15, 1, -1));
}

void Sistema::mostrarPila()
{
    if (!pilaProcesos.esVacia())
    {
        cout << "Procesos en la pila:" << endl;
        pilaProcesos.mostrarTodo();
    }
    else
    {
        cout << "La pila está vacía" << endl;
    }
}

void Sistema::borrarPila()
{
    Pila pila;
    pilaProcesos = pila;
    cout << "Pila de procesos borrada.\n";
}

void Sistema::mostrarCola()
{
    if (!colaEspera.esVacia())
    {
        cout << "Procesos en la cola:" << endl;
        // Muestra solo el primer elemento
        colaEspera.mostrarCola();
    }
    else
    {
        cout << "La cola de espera está vacía" << endl;
    }
}

void Sistema::mostrarEjecutando()
{
    if (nucleosLibres == 3)
    {
        cout << "No hay procesos en ejecución" << endl;
    }
    else
    {
        cout << nucleosLibres << " núcleo" << (nucleosLibres == 1 ? "" : "s") << " libre" << (nucleosLibres == 1 ? "" : "s") << "\n"
             << endl;
        cout << "Procesos en ejecución:\n"
             << endl;
        for (int i = 0; i < TOTAL_NUCLEOS; i++)
        {
            if (nucleos[i] != NULL)
            {
                cout << "Núcleo " << i + 1 << ": " << endl;
                nucleos[i]->mostrarInformacion();
                cout << endl;
            }
            else
            {
                cout << "Núcleo " << i + 1 << ": Vacío" << endl;
            }
        }
    }
}

void Sistema::simularMinutos(int n)
{
    // Simular la llegada/salida de procesos
    for (int i = 0; i < n; i++)
    {

        // Simular los procesos en la pila
        cout << "Simulando minuto " << minutos << "..." << endl;
        minutos++;
        if (!pilaProcesos.esVacia())
        {
            pilaProcesos.reducirTiempoInicio();
            while (!pilaProcesos.esVacia() && pilaProcesos.primero().getInicio() == 0)
            {
                Proceso proceso = pilaProcesos.desapilar();
                cout << "Proceso " << proceso.getPID() << " entró en la cola de espera" << endl;
                procesoEntraEspera(proceso);
            }
        }

        // Simular la ejecución de procesos
        for (int j = 0; j < TOTAL_NUCLEOS; j++)
        {
            if (nucleos[j] != NULL)
            {
                nucleos[j]->reducirTiempoVida();
                if (nucleos[j]->getTiempoVida() == 0)
                {
                    cout << "Proceso " << nucleos[j]->getPID() << " terminó de ejecutarse" << endl;
                    delete nucleos[j];
                    nucleos[j] = NULL;
                    nucleosLibres++;
                }
            }
        }

        // Asignar procesos a los núcleos libres
        while ((!colaEspera.esVacia()) && (nucleosLibres > 0))
        {
            Proceso proceso = colaEspera.desencolar();
            for (int k = 0; k < TOTAL_NUCLEOS; k++)
            {
                if (nucleos[k] == NULL)
                {
                    proceso.setNucleo(k + 1);
                    nucleos[k] = new Proceso(proceso);
                    nucleosLibres--;
                    cout << "Proceso " << proceso.getPID() << " asignado al núcleo " << k + 1 << endl;
                    break;
                }
            }
        }
    }
}

void Sistema::ejecutarProcesos()
{
    while (!pilaProcesos.esVacia())
    {
        simularMinutos(1);
    }
    while (!colaEspera.esVacia())
    {
        simularMinutos(1);
    }
    while (nucleosLibres < TOTAL_NUCLEOS)
    {
        simularMinutos(1);
    }
}

void Sistema::nuevoProceso(Proceso p)
{
    Pila paux;
    while (!pilaProcesos.esVacia() && pilaProcesos.primero().getInicio() < p.getInicio())
    {
        paux.apilar(pilaProcesos.desapilar());
    }
    pilaProcesos.apilar(p);

    while (!paux.esVacia())
    {
        pilaProcesos.apilar(paux.desapilar());
    }
}

void Sistema::procesoEntraEspera(Proceso p)
{
    Cola caux;
    while (!colaEspera.esVacia() && colaEspera.frente().getPrioridad() < p.getPrioridad())
    {
        caux.encolar(colaEspera.desencolar());
    }
    caux.encolar(p);
    while (!colaEspera.esVacia())
    {
        caux.encolar(colaEspera.desencolar());
    }
    while (!caux.esVacia())
    {
        colaEspera.encolar(caux.desencolar());
    }
}

int Sistema::getMinutos()
{
    return minutos;
}