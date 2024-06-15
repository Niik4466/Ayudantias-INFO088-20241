/*
Ejercicio 1

Crear los metodos "isEmpty()", "Pop()", "Push()", "Top()".
de la clase "Pila" en el archivo pila.h, la cual almacena caracteres y se comporta como una pila

en el Main() se proporciona una prueba simple para corroborar que los métodos sean correctos
*/

#include "pila/Pila.h"
using namespace std;

int main(int argc, char** argv) {

    printf("Generando la Pila...\n");
    Pila miPila;
    printf("Listo!!!\n");

    printf("\nIngresando datos a la Pila...\n");
    miPila.push('d');
    miPila.push('l');
    miPila.push('r');
    miPila.push('o');
    miPila.push('w');
    miPila.push(' ');
    miPila.push('o');
    miPila.push('l');
    miPila.push('l');
    miPila.push('l');
    miPila.push('e');
    miPila.push('h');
    printf("\nListo!!!\n");

    printf("\nQuitando e imprimiendo los elementos de la pila...\n\n");
    fflush(stdout);
    while (!miPila.isEmpty())
        printf("%c\t%c\n" , miPila.pop(), miPila.top()); 

    printf("\nListo!!!\n");

    return EXIT_SUCCESS;
}