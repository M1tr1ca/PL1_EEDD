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
    // Crear 10 procesos manualmente
    nuevoProceso(Proceso(1001, 1, 10, 30, 2, 1));
    nuevoProceso(Proceso(1002, 1, 5, 20, 1, 2));
    nuevoProceso(Proceso(1003, 1, 15, 25, 3, 1));
    nuevoProceso(Proceso(1004, 1, 3, 10, 0, 1));
    nuevoProceso(Proceso(1005, 1, 12, 15, 4, 2));
    nuevoProceso(Proceso(1006, 1, 8, 18, 1, 2));
    nuevoProceso(Proceso(1007, 1, 20, 10, 2, 1));
    nuevoProceso(Proceso(1008, 1, 25, 30, 3, 2));
    nuevoProceso(Proceso(1009, 1, 14, 20, 0, 1));
    nuevoProceso(Proceso(1010, 1, 18, 15, 1, 1));
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
    cout << "Estdo de los núcleos:" << endl;
    cout << "Hay " << nucleos.getLongitud() << " núcleos" << endl;
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
        nuevoNucleo.setProcesoActual(p);
        nucleos.izquierda(nuevoNucleo);
        cout << "Proceso " << p->getPID() << " entró en ejecución en el núcleo " << nuevoNucleo.getId() << endl;
    }
    else if (n->numeroProcesosTotales() == 0)
    {
        n->setProcesoActual(p);
        cout << "Proceso " << p->getPID() << " entró en ejecución en el núcleo " << n->getId() << endl;
    }
    else
    {
        n->añadirEsperaPrioridad(*p);
        cout << "Proceso " << p->getPID() << " entró en la cola de espera del núcleo " << n->getId() << endl;
    }
}

void Sistema::mostrarEstado()
{
    nucleos.mostrarTodo();
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
    cout << "Número de núcleos: " << nucleos.getLongitud() << endl;
}

int Sistema::getMinutos()
{
    return minutos;
}