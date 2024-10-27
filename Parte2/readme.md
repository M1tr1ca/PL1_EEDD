# Parte 2

Esta parte amplía la parte 1, siumulando un entorno elástico en la nube. Ya no hay una cola de espera global, sino que cada núcleo tiene su propia cola de espera. Además, los núcleos se añaden o eliminan en tiempo de ejecución cuando no hay ninguno con menos de dos procesos en su cola de espera.

## 🗂️ Estructura de la parte 2

El proyecto está dividido en varios archivos de cabecera (.h) y de implementación (.cpp) que definen y manipulan las siguientes clases:

* Cola :Implementación de una cola (FIFO) para la administración de procesos en el orden de llegada.
* Pila: Implementación de una pila (LIFO) para gestionar los procesos de manera inversa a su orden de ingreso.
* Lista: Introduce una lista enlazada para un manejo más flexible y accesible de los procesos.
* NodoCola, NodoPila y NodoLista: Representan los nodos en cada estructura correspondiente.
* Núcleo: Contiene una cola de espera y el proceso actual.
* Proceso: Define las características de los procesos administrados.
* Sistema: Encapsula la lógica de control de todas las estructuras y permite la interacción del sistema de gestión.


## ⚠️ Consideraciones a tomar en cuenta

Se crean 10 procesos una vez se inicia el sistema, y al crear nuevos procesos se añaden los mismos 10 procesos

Ejecución:

## 🚀 Ejecución

g++ *.cpp -o main
./main.exe

O usando el Makefile