Esta parte  amplía el sistema de gestión de procesos básico, integrando estructuras de datos adicionales para una administración más compleja de procesos. La implementación incluye estructuras de pila, cola y lista (sustityendo el array de la parte anterior), así como una nueva clase Núcleo que proporciona una capa adicional de procesamiento

Estructura de la parte 2:

El proyecto está dividido en varios archivos de cabecera (.h) y de implementación (.cpp) que definen y manipulan las siguientes clases:

Cola-> Implementación de una cola (FIFO) para la administración de procesos en el orden de llegada.
Pila-> Implementación de una pila (LIFO) para gestionar los procesos de manera inversa a su orden de ingreso.
Lista-> Introduce una lista enlazada para un manejo más flexible y accesible de los procesos.
NodoCola, NodoPila y NodoLista-> Representan los nodos en cada estructura correspondiente.
Núcleo-> Clase adicional que ofrece un nivel superior de gestión, permitiendo la centralización y el procesamiento avanzado de los procesos.
Proceso-> Define las características de los procesos administrados.
Sistema-> Encapsula la lógica de control de todas las estructuras y permite la interacción completa del sistema de gestión.


Consideraciones a tomar en cuenta:

Se crean 10 procesos una vez se inicia el sistema , y si estos se acaban o se eliminan al crear nuevos procesos se añaden los mismos 10 procesos
 



Ejecución:

Para compilar el programa, usa el siguiente comando:

g++ *.cpp -o main
./main.exe