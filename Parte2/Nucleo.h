#ifndef NUCLEO_H
#define NUCLEO_H

#include "Proceso.h"
#include "Cola.h"
#include <iostream>

class Nucleo
{
private:
    int id;                 // Identificador del núcleo
    Proceso *procesoActual; // Proceso actualmente en ejecución en el núcleo
    Cola colaEspera;        // Cola de procesos en espera

public:
    // Constructor que recibe un ID
    Nucleo(int id);
    // Constructor vacío
    Nucleo();
    // Destructor
    ~Nucleo();

    // Getter
    int getId();

    // Getter y setter para el proceso en ejecución
    Proceso *getProcesoActual();
    void setProcesoActual(Proceso *proceso);

    // Operaciones sobre la cola de espera
    void añadirEsperaPrioridad(Proceso proceso);
    Proceso obtenerProcesoDeCola();

    // Consultas sobre el estado del núcleo
    bool estaOcupado();           // Retorna true si hay un proceso ejecutándose
    int numeroProcesosEnEspera(); // Número de procesos en la cola

    // Mostrar información del núcleo
    void mostrarInformacion();
    void reducirTiempoVida(); // Reduce el tiempo restante del proceso actual
};

#endif // NUCLEO_H
