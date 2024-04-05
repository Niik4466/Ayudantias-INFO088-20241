#include <iostream>
#include <random>
using namespace std;

#define MIN 10  //Valor minimo de los números aleatorios
#define MAX 101 //Valor máximo de los números aleatorios

void imprimeArray(int *Vec, const int n);
void intercambiar(int *Vec, const int a, const int b);
void mediana(int *Vec, const int n);

int main() {
    //declaramos las variables
    int i=0, n;

    //validamos que n no sea menor o igual que 0
    cout << "Ingrese n: "; cin >> n;
    while(n < 1){
        cout << "Error! numero ingresado menor o igual a 0, ingrese un numero positivo: "; cin >> n;
    }

    //inicialisamos valores
    int *Vec = new int[n];
    for(; i<n; ++i ){
        Vec[i] = rand()%(MAX-MIN) + MIN;
    }
    fputs_unlocked("\nArray inicial\n", stdout);
    imprimeArray(Vec, n);

    mediana(Vec, n);

    fputs_unlocked("\nArray con la mediana centrada\n", stdout);
    imprimeArray(Vec, n);
    printf("\nLa mediana es aproximadamente %d\n", Vec[(n-1)/2]);

    //eliminamos el Array de memoria
    delete[] Vec;
}

//Coloca nuestra aproximacion de mediana al centro del arreglo
void mediana(int *Vec, const int n) {
    int mid = (n-1)/2;
    if(Vec[0] < Vec[mid]) 
        intercambiar(Vec, 0, mid);

    if(Vec[mid] < Vec[n-1])
        intercambiar(Vec, mid, n-1);
        
    if(Vec[0]<Vec[mid])
        intercambiar(Vec, 0, mid);
}

//Intercambia dos posiciones en un arreglo
void intercambiar(int *Vec, const int a, const int b) {
    int temp = Vec[a];
    Vec[a] = Vec[b];
    Vec[b] = temp;
}


void imprimeArray(int *Vec, const int n) {
    int i=0;
    for(;i<n; ++i){
        printf("%d ", Vec[i]); //printf es pirnt format, osea que imprime el texto dado con un formato (osea que el texto puede recibir instrucxiones)
        // %d le indica al formato que ahi va un integer. Para mas info https://www.simplilearn.com/tutorials/cpp-tutorial/cpp-printf
    }
    fputs_unlocked("\n", stdout); // coloca el string entregado en stdout (la consola) de manera directa. Mas info en https://refspecs.linuxbase.org/LSB_5.0.0/LSB-Core-generic/LSB-Core-generic/baselib-fputs-unlocked-1.html, https://cplusplus.com/reference/cstdio/fputs/
}