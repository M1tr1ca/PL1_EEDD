# PL1

## ℹ️ About
Este proyecto en C++ implementa un sistema para crear y gestionar distintos tipos de procesos de manera organizada, simulando el flujo de estos procesos a través de la CPU. El sistema incluye una cola de espera que prioriza los procesos según su importancia y una pila que mantiene todos los procesos ordenados por su tiempo de ejecución. Además, se gestionan núcleos que se activan o desactivan según la demanda, y estos se almacenan en una lista. A través de diversas funciones, el proyecto ofrece al usuario la capacidad de:

* Almacenar y organizar datos en estructuras específicas, como listas , pilas y colas de manera que se puedan añadir, eliminar, y acceder a los elementos fácilmente.
* Ejecutar operaciones básicas y avanzadas sobre estos datos, como ordenarlos, buscarlos o modificarlos según necesidades específicas.
* Gestionar datos dinámicamente, permitiendo que los programas ajusten su uso de memoria según los datos almacenados en cada momento.
  
En conjunto, el proyecto actúa como una herramienta práctica para aprender a construir sistemas que organizan y manipulan datos en C++, proporcionando ejemplos claros de cómo estructurar y gestionar información de manera eficiente y ordenada.


## 📸 Screenshots
<div align="center">
    <img src="https://github.com/user-attachments/assets/04bfcdde-f031-490b-9f46-56c8c0633ffa" width="500">
</div>


## ⚠️ Consideraciones antes de ejecutar el programa

Al iniciar el programa ya se crean 10 procesos.
Estos están creados manualmente dentro del código.
La opción de crear la pila de procesos añadirá esos mismos 10 procesos a la pila.

## 🚀 Ejecución
(Dentro de sus respectivas carpetas)

El programa se puede compilar con:
```bash
  g++ \*.cpp -o main
```
Y ejecutar con:
```bash
  ./main.exe
```

O usando el Makefile:
```bash
make release
make debug
make valgrind
make valgrind-summary
make clean
```

## 👥 Autores

- [Javier Macías](https://github.com/Jala3400)
- [David Mitrică](https://github.com/M1tr1ca)
