// main.cpp
#include <iostream>
#include "Sistema.h"
using namespace std;

void mostrarMenu(int minutos)
{
    int horas = minutos / 60 % 24;
    int min = minutos % 60;

    cout << "                                      ggg                      " << endl;
    cout << "                               _gg___g@@@__  __                " << endl;
    cout << "                               %@@@@@@&&@@@g@@@y               " << endl;
    cout << "                               _@@@*`     *@@@\"                +----------------------------------------------------------------+" << endl;
    cout << "             ____           ,gg@@@          Q@g                |                    +-------------------+                       |" << endl;
    cout << "            J@@@@      g_   g@@@@[          ]@@@@@             |                    |     * " << (horas >= 10 ? "" : "0") << horas << ":" << (min >= 10 ? "" : "0") << min << " *     |                       |" << endl;
    cout << "            _@@@@gg,__@@@@y   `@@g          g@@MMF             |                    +-------------------+                       |" << endl;
    cout << "     _gg__,g@@@@@@@@@@@@@F     ]@@g_      _g@@`                |                                                                |" << endl;
    cout << "    .@@@@@@@@M*\"``\"*M@@@@g    g@@@@@@gggg@@@@@_                |     +----------------------------------------------------+     |" << endl;
    cout << "     \"M@@@@M          \"@@@g__,,%M` \"M@@@M*\"\"0@*                |     |                   SYSTEM MENU                      |     |" << endl;
    cout << "      q@@@F             @@@@@@@      @@@ gggg,                 |     +----------------------------------------------------+     |" << endl;
    cout << "      g@@@              ]@@@@MM`_        @@@@$                 |     |  1. Crear la pila de procesos                      |     |" << endl;
    cout << "   @@@@@@@              g@@@  _g@@_  __,g@@@@g_     __         |     |  2. Mostrar procesos en la pila                    |     |" << endl;
    cout << "   $@@@@@@g            ,@@@F *@@@@@@@@@@@@@@@@@@g__g@@g_       |     |  3. Borrar pila de procesos                        |     |" << endl;
    cout << "    `  \"@@@g_        _g@@@@@g_ %@@@@@@@MMMMMN@@@@@@@@@@@       |     |  4. Mostrar la cola de espera                      |     |" << endl;
    cout << "        '@@@@@gggggg@@@@@@@@@F g@@@@M`        `M@@@@@P`        |     |  5. Mostrar procesos en ejecucion                  |     |" << endl;
    cout << "        g@@@@@@@@@@@@@M\"  \"*`_@@@@P              %@@@g         |     |  6. Simular el paso de N minutos m                 |     |" << endl;
    cout << "        N@@@` `\"\"0@@@[   g@@@@@@@@                $@@@_        |     |  7. Ejecutar todos los procesos                    |     |" << endl;
    cout << "          \"      J@@@&   @@@@@@@@L                ]@@@@gggg    |     |  0. Salir                                          |     |" << endl;
    cout << "                         \"**M@@@@L                ]@@@@@@@@    |     |                                                    |     |" << endl;
    cout << "                             ]@@@@               _@@@@MMN&F    |     +----------------------------------------------------+     |" << endl;
    cout << "                              %@@@@_            ,@@@@F         |          +------------------------------------------+          |" << endl;
    cout << "                             ,@@@@@@gg__    __g@@@@@F          |          |  Selecciona una opcion y presiona Enter  |          |" << endl;
    cout << "                            @@@@@@@@@@@@@@@@@@@@@@@@g_         |          +------------------------------------------+          |" << endl;
    cout << "                             %@@*``*&@@@@@@@@@&MN@@@@@         +----------------------------------------------------------------+" << endl;
    cout << "                                      $@@@@M`    '0@*          " << endl;
    cout << "                                      @@@@@                    " << endl;
    cout << "                                      \"\"\"*\"" << endl;
}

int main()
{
    Sistema sistema;
    int opcion;

    cout << R"(
 _______  ___      _______  __    _  ___   _______  ___   _______  _______  ______   _______  _______  
|       ||   |    |   _   ||  |  | ||   | |       ||   | |   ____||   _   ||      | |       ||    _  |  
|    _  ||   |    |  |_|  ||   |_| ||   | |    ___||   | |  |     |  |_|  ||  _    ||   _   ||   | | |  
|   |_| ||   |    |       ||       ||   | |   |___ |   | |  |     |       || | |   ||  | |  ||   |_| | 
|    ___||   |___ |       ||  _    ||   | |    ___||   | |  |     |       || |_|   ||  |_|  ||    __  |
|   |    |       ||   _   || | |   ||   | |   |    |   | |  |____ |   _   ||       ||       ||   |  | |
|___|    |_______||__| |__||_|  |__||___| |___|    |___| |_______||__| |__||______| |_______||___|  |_|

    )" << endl;

    cout << "\n====================================================================" << endl;
    cout << "ADVERTENCIA: Ya se han creado 10 procesos en la pila de procesos." << endl;
    cout << "Los procesos que se crean son siempre los mismos." << endl;
    cout << "Crear la pila de procesos añadirá los mismos 10 procesos a la pila."
         << endl;
    cout << "====================================================================\n"
         << endl;

    do
    {
        mostrarMenu(sistema.getMinutos());
        cout << "       +------------------------------------------+          " << endl;
        cout << "                Selecciona una opcion: ";
        cin >> opcion;
        cout << "       +------------------------------------------+          " << endl;
        cout << "=================================================================================================================================\n"
             << endl;

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
            sistema.mostrarCola();
            break;
        case 5:
            sistema.mostrarEjecutando();
            break;
        case 6:
            int n;
            cout << "Introduce N minutos: ";
            cin >> n;
            sistema.simularMinutos(n);
            break;
        case 7:
            sistema.ejecutarProcesos();
            cout << endl;
            cout << sistema.getMedia() << " minutos vivos en promedio." << endl;
            break;
        case 0:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opción no válida. Inténtalo de nuevo.\n";
        }
        cout << "\n=================================================================================================================================" << endl;
    } while (opcion != 0);

    return 0;
}