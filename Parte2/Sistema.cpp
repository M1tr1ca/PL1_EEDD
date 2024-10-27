// Sistema.cpp
#include "Sistema.h"
#include "Proceso.h"
#include "Pila.h"
#include "Lista.h"
#include "Nucleo.h"

Sistema::Sistema()
{
    // pilaProcesos = Pila();
    // nucleos = Lista();
    minutos = 0;
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

void Sistema::mostrarEjecutando()
{
    cout << "Estado de los núcleos:" << endl;
    mostrarNumNucleos();
    nucleos.mostrarTodo();
}

void Sistema::simularMinutos(int n)
{
    // Simular la llegada/salida de procesos
    for (int i = 0; i < n; i++)
    {
        // Simular los procesos en la pila
        cout << "Simulando minuto " << minutos << "..." << endl;
        minutos++;

        // Simular los procesos en ejecución
        nucleos.reducirTiempoVida();

        if (!pilaProcesos.esVacia())
        {
            pilaProcesos.reducirTiempoInicio();
            while (!pilaProcesos.esVacia() && pilaProcesos.primero().getInicio() == 0)
            {
                Proceso proceso = pilaProcesos.desapilar();
                procesoEntraEspera(new Proceso(proceso));
            }
        }

        // Elimina nucleos que han terminado de ejecutar
        if (nucleos.nucleosLibres() >= 2)
        {
            nucleos.eliminarNucleosVacios();
        }
    }
}

void Sistema::ejecutarProcesos()
{
    while (!pilaProcesos.esVacia())
    {
        simularMinutos(1);
    }

    while (nucleos.buscarMasCola()->numeroProcesosTotales() > 0)
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

void Sistema::procesoEntraEspera(Proceso *p)
{
    Nucleo *n = nucleos.buscarMenosCola();
    if (n->numeroProcesosTotales() >= 3) // El proceso ejecutándose también cuenta
    {
        Nucleo nuevoNucleo;
        p->setNucleo(nuevoNucleo.getId());
        nuevoNucleo.setProcesoActual(p);
        nucleos.izquierda(nuevoNucleo);
        cout << "Proceso " << p->getPID() << " entró en ejecución en el núcleo " << nuevoNucleo.getId() << endl;
    }
    else if (n->numeroProcesosTotales() == 0)
    {
        p->setNucleo(n->getId());
        n->setProcesoActual(p);
        cout << "Proceso " << p->getPID() << " entró en ejecución en el núcleo " << n->getId() << endl;
    }
    else
    {
        p->setNucleo(n->getId());
        n->añadirEsperaPrioridad(*p);
        cout << "Proceso " << p->getPID() << " entró en la cola de espera del núcleo " << n->getId() << endl;
        delete p;
    }
}

void Sistema::mostrarMasMenos()
{
    Nucleo *n = nucleos.buscarMasCola();
    Nucleo *n2 = nucleos.buscarMenosCola();
    cout << "Núcleo con más procesos en espera: " << n->getId() << endl
         << "Tiene: " << n->numeroProcesosTotales() << endl;
    cout << "Núcleo con menos procesos en espera: " << n2->getId() << endl
         << "Tiene: " << n2->numeroProcesosTotales() << endl;
}

void Sistema::mostrarNumNucleos()
{
    int n = nucleos.getLongitud();
    cout << "Hay " << n << " nucleo" << (n == 1 ? "" : "s") << endl;
}

int Sistema::getMinutos()
{
    return minutos;
}