
#ifndef SISTEMA_H
#endif // SISTEMA_H
#define SISTEMA_H

#include "Proceso.h"
#include "Pila.h"
#include "Lista.h"
#include <iostream>

using namespace std;

class Sistema
{
private:
    Pila pilaProcesos; // Pila de procesos ordenados por inicio
    Lista nucleos;     // Lista de procesos en ejecucion
    int minutos;       // Minutos transcurridos

public:
    Sistema();
    void crearProcesos();                      // Punto 1, se CREA la PILA DE PROCESOS en el sistema, asi creas tu los datos manual
    void mostrarPila();                        // Punto 2, se MUESTRA la PILA DE PROCESOS que se inician en el SO
    void borrarPila();                         // Punto 3, se BORRA la PILA DE PROCESOS del SO
    void simularMinutos(int n);                // Punto 4, la n viene por teclado y procesos que pasan
    void mostrarEjecutando();                  // Punto 5, MUESTRA los PROCESOS EN EJECUCIÓN
    void mostrarMasMenos();                    // Punto 6, MUESTRA el PROCESO con MAS y MENOS tiempo de EJECUCIÓN
    void mostrarNumNucleos();                  // Punto 7, MUESTRA el NUMERO de NUCLEOS en EJECUCIÓN
    void ejecutarProcesos();                   // Punto 8, EJECUTA los PROCESOS EN EJECUCIÓN
    void nuevoProceso(Proceso proceso);        // AGREGA un NUEVO PROCESO a la LISTA de PROCESOS en EJECUCIÓN
    void procesoEntraEspera(Proceso *proceso); // Pone un PROCESO en ESPERA en ORDEN de PRIORIDAD
    int getMinutos();
};
