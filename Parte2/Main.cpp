// main.cpp
#include <iostream>
#include "Sistema.h"

using namespace std;

void mostrarMenu(int minutos)
{
	int horas = minutos / 60 % 24;
	int min = minutos % 60;

	cout << "                                      ggg                      +----------------------------------------------------------------+" << endl;
	cout << "                               _gg___g@@@__  __                |                      +--------------------+                    |" << endl;
	cout << "                               %@@@@@@&&@@@g@@@y               |                      |     * " << (horas >= 10 ? "" : "0") << horas << ":" << (min >= 10 ? "" : "0") << min << " *      |                    |" << endl;
	cout << "                               _@@@*`     *@@@\"                |                      +--------------------+                    |" << endl;
	cout << "             ____           ,gg@@@          Q@g                |                                                                |" << endl;
	cout << "            J@@@@      g_   g@@@@[          ]@@@@@             |     +----------------------------------------------------+     |" << endl;
	cout << "            _@@@@gg,__@@@@y   `@@g          g@@MMF             |     |                   SYSTEM MENU                      |     |" << endl;
	cout << "     _gg__,g@@@@@@@@@@@@@F     ]@@g_      _g@@`                |     +----------------------------------------------------+     |" << endl;
	cout << "    .@@@@@@@@M*\"``\"*M@@@@g    g@@@@@@gggg@@@@@_                |     |  1. Crear la pila de procesos                      |     |" << endl;
	cout << "     \"M@@@@M          \"@@@g__,,%M` \"M@@@M*\"\"0@*                |     |  2. Mostrar procesos en la pila                    |     |" << endl;
	cout << "      q@@@F             @@@@@@@      @@@ gggg,                 |     |  3. Borrar pila de procesos                        |     |" << endl;
	cout << "      g@@@              ]@@@@MM`_        @@@@$                 |     |  4. Simular el paso de N minutos                         |     |" << endl;
	cout << "   @@@@@@@              g@@@  _g@@_  __,g@@@@g_     __         |     |  5. Mostrar datos lista nucleos                  |     |" << endl;
	cout << "   $@@@@@@g            ,@@@F *@@@@@@@@@@@@@@@@@@g__g@@g_       |     | 6. Consultar núcleos con más y menos procesos                   |     |" << endl;
	cout << "    `  \"@@@g_        _g@@@@@g_ %@@@@@@@MMMMMN@@@@@@@@@@@       |     |  7. Consultar número de nucleos operativos                    |     |" << endl;
	cout << "        '@@@@@gggggg@@@@@@@@@F g@@@@M`        `M@@@@@P`        |     |  8. Ejecutar todos los procesos                                          |     |" << endl;
	cout << "        g@@@@@@@@@@@@@M\"  \"*`_@@@@P              %@@@g         |     |  0. Salir                                                               |      |" << endl;
	cout << "        N@@@` `\"\"0@@@[   g@@@@@@@@                $@@@_        |     +----------------------------------------------------+     |" << endl;
	cout << "          \"      J@@@&   @@@@@@@@L                ]@@@@gggg    |          +------------------------------------------+          |" << endl;
	cout << "                         \"**M@@@@L                ]@@@@@@@@    |          |  Selecciona una opcion y presiona Enter  |          |" << endl;
	cout << "                             ]@@@@               _@@@@MMN&F    |          +------------------------------------------+          |" << endl;
	cout << "                              %@@@@_            ,@@@@F         +----------------------------------------------------------------+" << endl;
	cout << "                             ,@@@@@@gg__    __g@@@@@F          +----------------------------------------------------------------+" << endl;
	cout << "                            @@@@@@@@@@@@@@@@@@@@@@@@g_         +----------------------------------------------------------------+" << endl;
	cout << "                             %@@*``*&@@@@@@@@@&MN@@@@@         +----------------------------------------------------------------+" << endl;
	cout << "                                      $@@@@M`    '0@*          +----------------------------------------------------------------+" << endl;
	cout << "                                      @@@@@                    +----------------------------------------------------------------+" << endl;
	cout << "                                      \"\"\"*\"                    +----------------------------------------------------------------+" << endl;
}

int main()
{
	Sistema sistema;
	int opcion;

	cout << "\n====================================================================" << endl;
	cout << "ADVERTENCIA: Ya se han creado 10 procesos en la pila de procesos." << endl;
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
