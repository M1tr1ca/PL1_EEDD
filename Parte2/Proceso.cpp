#include "Proceso.h"
#include <iostream>
using namespace std;

// Constructor con cositas dentro
Proceso::Proceso(int pid, int ppid, int ini, int vida, int pri, int nuc)
{
    PID = pid,
    PPID = ppid,
    inicio = ini,
    tiempoVida = vida,
    prioridad = pri,
    nucleo = nuc;
}

// Constructor vacío
Proceso::Proceso()
{
    PID = -1;
    PPID = -1;
    inicio = -1;
    tiempoVida = -1;
    prioridad = -1;
    nucleo = -1;
}

Proceso::~Proceso()
{
}

/*  int PID;        // Identificador del proceso
    int PPID;      // Identificador del proceso padre
    int inicio;     // Inicio del proceso (en minutos desde las 00:00)
    int tiempoVida; // Tiempo de vida (en minutos)
    int prioridad;  // Prioridad del proceso (0-9)
    int nucleo;     // Núcleo asignado para la ejecución */


void Proceso::mostrarInformacion()
{
    cout << "PID: " << PID << endl
        << "PPID: " << PPID << endl
        << "Minutos hasta inicio: " << inicio << " minutos " << endl
        << "Tiempo de vida: " << tiempoVida << " minutos" << endl
        << "Prioridad: " << prioridad << endl
        << "Núcleo: " << nucleo << endl;
}

// Getters
int Proceso::getPID()
{
    return PID;
}

int Proceso::getPPID()
{
    return PPID;
}

int Proceso::getInicio()
{
    return inicio;
}

int Proceso::getTiempoVida()
{
    return tiempoVida;
}

int Proceso::getPrioridad()
{
    return prioridad;
}

int Proceso::getNucleo()
{
    return nucleo;
}

// Setters
void Proceso::setPID(int pid)
{
    PID = pid;
}

void Proceso::setPPID(int ppid)
{
    PPID = ppid;
}

void Proceso::setInicio(int ini)
{
    inicio = ini;
}

void Proceso::setTiempoVida(int vida)
{
    tiempoVida = vida;
}

void Proceso::setPrioridad(int pri)
{
    prioridad = pri;
}

void Proceso::setNucleo(int nuc)
{
    nucleo = nuc;
}

void Proceso::reducirTiempoInicio()
{
    inicio--;
}

void Proceso::reducirTiempoVida()
{
    tiempoVida--;
}