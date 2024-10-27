# Estructura general:

El proyecto se organiza en varios archivos .cpp y .h que definen y manipulan las siguientes clases y componentes:

Cola-> Implementa una cola para la gestión de procesos en el orden en que fueron añadidos (FIFO).

Pila-> Implementa una pila que permite gestionar los procesos en orden LIFO.

NodoCola y NodoPila-> Representan los nodos utilizados en las estructuras de Cola y Pila respectivamente.

Proceso-> Define las características y atributos de cada proceso.

Sistema: Controla y administra el sistema completo, proporcionando la lógica mediante los métodos que interacciona con las estructuras

# Consideraciones a tomar en cuenta:

Se crean 10 procesos una vez se inicia el sistema , y si estos se acaban o se eliminan al crear nuevos procesos se añaden los mismos 10 procesos

# Ejecución:

Para compilar el programa, usa el siguiente comando:

g++ \*.cpp -o main
./main.exe
