/*
Codifique un programa que lea un entero n positivo y mayor que 0,
con la variable, n cree un arreglo A[0..n-1] y llenelo con datos aleatorios entre MIN y MAX
Con una variabble m guarde el tamaño de su arreglo inicial.

ahora cree una función aumentaCapacidad(int* A, int &n, const int m) que aumente la capacidad de su arreglo en m

Mediante un ciclo for, siga llenando el arreglo hasta 10 veces su capacidad inicial(10*n)

Desafío: probarlo con un n muy grande y medir el tiempo que lleva generar el nuevo arreglo
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