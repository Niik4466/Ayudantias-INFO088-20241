/*
Dada una Matriz dinamica A de caracteres, de tamaño MxN (M filas y N columnas) y un arreglo de 5 caracteres "palabra".
Creen un algoritmo que: dada la Matriz de carácteres aleatorios, busque una palabra y la almacene en su primera fila (A[0])

Para esto, primero deben inicializar su matriz y llenarla de carácteres aleatorios. Esto se hace utilizando código ascii y una transformación de entero a carácter
https://elcodigoascii.com.ar

Luego deben codificar la función booleana encuentraPalabra(char** A)
Esta función debe recorrer cada caracter del arreglo "palabra" y comprobar si existe en el arreglo,
De ser ese el caso, va a mover ese caracter a su posición correspondiente en la primera fila de la Matriz.
Simultaneamente, la función debe retornar verdadero si encuentra la palabra o falso si no la encontró.

*/

#include <iostream>
using namespace std;

#define MIN 97  //valor mínimo que pueden tomar los carácteres
#define MAX 123 //valor máximo que pueden tomar los carácteres

#define N 5  //columnas del arreglo
#define M 10 //filas del arreglo

const char palabra[5] = {'z', 'o', 'r', 'r', 'o'}; //palabra a buscar

void intercambiaMatriz(char** A, int filaA, int columnaA, int filaB, int columnaB);
void llenaMatriz(char** A);
void imprimeMatriz(char** A);
bool encuentraPalabra(char** A);

int main(){

}