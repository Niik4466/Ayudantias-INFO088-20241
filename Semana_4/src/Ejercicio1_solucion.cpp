#include <iostream>
#include <random>
using namespace std;

#define MAX 101 //Valor máximo posible para el random
#define MIN 10 //Valor mínimo posible para el random
#define MULT 10 //Multiplicador del tamaño inicial

//inicializamos las funciones
int* aumentaCapacidad(int* A, int &n, const int m);
void imprimeArray(int *Vec, const int n);

int main(){
    //declaramos las variables
    int n, m, *A;

    //validamos que n no sea menor o igual que 0
    do{
        cout << "Ingrese n: "; cin >> n;
    }while(n < 1);

    m = n;

    //creamos nuestro arreglo dinámico
    A = new int[n];

    cout << "El tamaño del arreglo orignal es: " << n << " y se agregarán " << MULT*m-m << " elementos" << endl;

    //llenamos el arreglo dinámico hasta 10 veces su capacidad
    for (int i = 0; i < MULT*m; i++){
        
        //verificamos si la variable i se pasó de la capacidad
        if (i%n == 0 && i != 0){
            cout << "Aumentando espacio..." << endl;
            aumentaCapacidad(A, n, m);
            cout << "Listo!!" << endl;
        }
        //agregamos un valor aleatorio al arreglo A
        A[i] = MIN + rand()%(MAX-MIN);
    }

    cout << "El tamaño del arreglo final es: " << n << " y se agregaron " << MULT*m-m << " elementos" << endl;

    //eliminamos el Array dinamico que no estará en uso
    delete [] A;

}

//creamos nuestra función aumentaCapacidad
int* aumentaCapacidad(int* A, int &n, const int m){

    //creamos un nuevo puntero, este apuntará a la dirección de memoria apuntada por A
    //en este caso, el array dinamico inicial
    int* B = A;

    //hHacemos que A apunte a un nuevo array dinamico con el doble de memoria
    A = new int[n+m];

    //copiamos los elementos del Array antiguo, al nuevo
    for (int i = 0; i < n; ++i){
        A[i] = B[i];
    }

    //duplicamos el valor n
    n += m;

    //retornamos el arreglo dinámico A
    return (A);
}

void imprimeArray(int *Vec, const int n) {
    int i=0;
    for(;i<n; ++i){
        printf("%d ", Vec[i]);
    }
    fputs_unlocked("\n", stdout);
}