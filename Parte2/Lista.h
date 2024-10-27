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
    void resto();//devuelve un nodo lista
    void eult();
    void mostrarTodo();
    void reducirTiempoVida();
    Nucleo *buscarMenosCola();
    Nucleo *buscarMasCola();
    int nucleosLibres();
    void eliminarNucleosVacios();
    int getLongitud();
};

#endif // PILA_H