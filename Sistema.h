
#ifndef SISTEMA_H
#endif // SISTEMA_H
#define SISTEMA_H

#include "Proceso.h"
#include "Cola.h"
#include "Pila.h"
#include <iostream>

using namespace std;

class Sistema
{
private:
    Pila pilaProcesos; // Pila de procesos ordenados por inicio
    Cola colaEspera;   // Por orden de prioridad
    int nucleosLibres; // salen los núcleos libres q hay
    const int TOTAL_NUCLEOS = 3;
    Proceso *nucleos[3]; // Núcleos del sistema

public:
    Sistema();
    void crearProcesos();       // Punto 1, se CREA la PILA DE PROCESOS en el sistema, asi creas tu los datos manual
    void mostrarPila();         // Punto 2, se MUESTRA la PILA DE PROCESOS que se inician en el SO
    void borrarPila();          // Punto 3, se BORRA la PILA DE PROCESOS del SO
    void mostrarColaEspera();   // Punto 4, MUESTRA la COLA DE ESPERA
    void mostrarEjecutando();   // Punto 5, MUESTRA los PROCESOS EN EJECUCI´NO
    void simularMinutos(int n); // Punto 6, la n viene por teclado y procesos que pasan
    void ejecutarProcesos();    // Punto 7, salen todos los procesos al finalizarse, los en espera también
    void mostrarEstado();
    void nuevoProceso(Proceso proceso);
    void procesoEntraEspera(Proceso proceso);
    void eliminarProcesoPila(Proceso p);
    void eliminarProcesoCola(Proceso p);
};
