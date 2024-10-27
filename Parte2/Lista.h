#ifndef LISTA_H
#define LISTA_H
#include "NodoLista.h"
#include "Proceso.h"
#include "Nucleo.h"

class Lista
{
private:
    NodoLista *cima;
    int longitud;

public:
    Lista();
    ~Lista();

    bool esVacia();
    void izquierda(Nucleo p);
    void derecha(Nucleo p);
    Nucleo prim();
    Nucleo ult();
    void resto();
    void eult();
    int nucleosLibres();
    int getLongitud();
    
    void mostrarTodo();
    void reducirTiempoVida();
    Nucleo *buscarMenosCola();
    Nucleo *buscarMasCola();
    void eliminarNucleosVacios();
};

#endif // PILA_H