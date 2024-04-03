/*
Con un arreglo dinámico de números enteros aleatorios, A[0..n-1], 
donde n sea leído por consola y los números aleatorios estén entre MIN y MAX.
Realice un algoritmo que encuentre una aproximación de la mediana si el arreglo estuviera ordenado
SIN recorrer el arreglo.

Para lograr esto deben tomar tres elementos del arreglo A y modificarlos.
El primer elemento A[0], el elemento de al medio A[(n-1)/2] y el último elemento A[n-1].

Ejemplo con n=11:

A[0]            A[(n-1)/2]             A[n-1]
 |                   |                   |
 v                   v                   v
[11 ,50 ,65 ,25 ,48 ,83 ,74 ,52 ,73 ,39, 41]
 0   1   2   3   4   5   6   7   8   9   10

Una vez tenemos los tres elementos, mediante intercambio, debemos hacer que el elemento alojado en la posición (n-1)/2 esté
entre los elementos A[0] y A[n-1]. Es decir A[0] <= A[(n-1)/2] <= A[n-1]

Siguiendo el Ejemplo anterior:

Array Original:
[11 ,50 ,65 ,25 ,48 ,83 ,74 ,52 ,73 ,39, 41]
 0   1   2   3   4   5   6   7   8   9   10

Array Modificado:
                     |                   |
                     v                   v
[11 ,50 ,65 ,25 ,48 ,41 ,74 ,52 ,73 ,39, 83]
 0   1   2   3   4   5   6   7   8   9   10

Para lograr esto, podemos validar si el elemento A[(n-1)/2] es menor que A[n-1]. De no ser ese el caso, los intercambiamos
Luego, comprobamos si A[0] es menor que A[n-1]. De no ser ese el caso, los intercambiamos
Posteriormente verificamos si A[0] es menor que A[(n-1)/2]. De no ser ese el caso, los intercambiamos

Una vez hayamos hecho este proceso, el elemento alojado en A[(n-1)/2] será un valor cercano a la mediana
si consideramos que el arreglo está ordenado


PD: la mediana que encontramos es una APROXIMACIÓN, no es el valor exacto.

Desafío: ordenar el Array y verificar que tan alejada estaba la mediana encontrada de la mediana real

*/

#include <iostream>
#include <random>
using namespace std;

#define MIN 10  //Valor minimo de los números aleatorios
#define MAX 101 //Valor máximo de los números aleatorios

void imprimeArray(int* A, int n);
void intercambiar(int* A, int i, int j);
int mediana(int* A, int ini, int med, int fin);

int main(){
    
}