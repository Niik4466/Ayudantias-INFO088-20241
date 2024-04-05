/*
Codifique un programa que lea un entero n positivo y mayor que 0,
con la variable n cree un arreglo A[0..n-1] y llenelo con datos aleatorios entre MIN y MAX

ahora cree una función aumentaCapacidad(int* A, int &n) que aumente la capacidad de su arreglo al doble de casillas

Mediante un ciclo for, siga llenando el arreglo hasta 10 veces su capacidad (10*n)
RECOMENDACIÓN: crear una variable auxiliar m que guarde el valor inicial de n

Para hacer la función aumentaCapacidad(int* A, int n), debe copiar todos los elementos de A en un arreglo auxiliar,
luego debemos hacer que nuestro arreglo A, apunte a una nueva sucesión de elementos en memoria.
Además debemos copiar los elementos de nuestro arreglo auxiliar al nuevo arreglo A.
Para finalizar, duplicamos el valor n.
*/

#include <iostream>
#include <random>
using namespace std;

#define MAX 101
#define MIN 10

//inicializamos las funciones
int* aumentaCapacidad(int* A, int &n);
void imprimeArray(int *A, int n);

int main(){
    
}