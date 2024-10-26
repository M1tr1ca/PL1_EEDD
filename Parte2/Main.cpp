// main.cpp
#include <iostream>
#include "Sistema.h"

using namespace std;

void mostrarMenu(int minutos)
{
    int horas = minutos / 60 % 24;
    int min = minutos % 60;
    cout << "+----------------------------------------------------------------+" << endl;
    cout << "|                      +--------------------+                    |" << endl;
    cout << "|                      |     * " << (horas >= 10 ? "" : "0") << horas << ":" << (min >= 10 ? "" : "0") << min << " *      |                    |" << endl;
    cout << "|                      +--------------------+                    |" << endl;
    cout << "|                                                                |" << endl;
    cout << "|     +----------------------------------------------------+     |" << endl;
    cout << "|     |                   SYSTEM MENU                      |     |" << endl;
    cout << "|     +----------------------------------------------------+     |" << endl;
    cout << "|     |  1. Crear la pila de procesos                      |     |" << endl;
    cout << "|     |  2. Mostrar procesos en la pila                    |     |" << endl;
    cout << "|     |  3. Borrar pila de procesos                        |     |" << endl;
    cout << "|     |  4. Simular el paso de N minutos                   |     |" << endl;
    cout << "|     |  5. Mostrar datos lista nucleos                    |     |" << endl;
    cout << "|     |  6. Consultar núcleos con más y menos procesos     |     |" << endl;
    cout << "|     |  7. Consultar número de nucleos operativos         |     |" << endl;
    cout << "|     |  8. Ejecutar todos los procesos                    |     |" << endl;
    cout << "|     |  0. Salir                                          |     |" << endl;
    cout << "|     +----------------------------------------------------+     |" << endl;
    cout << "|                                                                |" << endl;
    cout << "|          +------------------------------------------+          |" << endl;
    cout << "|          |  Selecciona una opcion y presiona Enter  |          |" << endl;
    cout << "|          +------------------------------------------+          |" << endl;
    cout << "+----------------------------------------------------------------+" << endl;
}

int main()
{
    Sistema sistema;
    int opcion;

    cout << "\n===================================================================" << endl;
    cout << "ADVERTENCIA: Ya se han creado 10 procesos en la pila de procesos." << endl;
    cout << "Crear la pila de procesos añadirá los mismos 10 procesos a la pila.\n"
         << endl;

    do
    {
        mostrarMenu(sistema.getMinutos());
        cout << "           +------------------------------------------+          " << endl;
        cout << "                Selecciona una opcion: ";
        cin >> opcion;
        cout << "           +------------------------------------------+          " << endl;

        switch (opcion)
        {
        case 1:
            sistema.crearProcesos();
            break;
        case 2:
            sistema.mostrarPila();
            break;
        case 3:
            sistema.borrarPila();
            break;
        case 4:
            int n;
            cout << "Introduce N minutos: ";
            cin >> n;
            sistema.simularMinutos(n);
            break;
        case 5:
            sistema.mostrarEjecutando();
            break;
        case 6:
            sistema.mostrarMasMenos();
            break;
        case 7:
            sistema.mostrarNumNucleos();
            break;
        case 8:
            sistema.ejecutarProcesos();
            break;
        case 0:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opción no válida. Inténtalo de nuevo.\n";
        }
    } while (opcion != 0);

    return 0;
}
