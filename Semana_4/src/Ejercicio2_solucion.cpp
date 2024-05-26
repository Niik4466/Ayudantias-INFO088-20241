#include <random>
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

int main() {

    char** A = new char*[M];
    for (int i = 0; i < M; ++i)
        A[i] = new char[N];
    llenaMatriz(A);
    fputs_unlocked("La matriz es: \n", stdout);
    imprimeMatriz(A);
    fputs_unlocked("Encontrando la palabra...\n", stdout);
    if (encuentraPalabra(A))
        fputs_unlocked("Palabra encontrada jeje\n", stdout);
        
    else
        fputs_unlocked("Palabra no encontrada :(\n", stdout);

    fputs_unlocked("La matriz final es: \n", stdout);
    imprimeMatriz(A);

    for (int i = 0; i < M; ++i){
        delete [] A[i];
    }

    delete [] A;
}

void llenaMatriz(char** A){
    for (int i = 0; i < M; ++i)
        for(int j = 0; j < N; ++j)
            A[i][j] = (char)(MIN + rand()%(MAX-MIN));
}

void imprimeMatriz(char** A){
    for (int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j)
            printf("%c ", A[i][j]);
        fputc_unlocked('\n', stdout);
    }
}

bool encuentraPalabra(char** A){
    //for que recorre el arreglo "palabra"
    int i, j, k,t,cont;
    i=t=cont=0;
    for (; i < 5; ++i){
        t=0;
        //Se detiene si llega a M o si se encontro la letra que se estaba buscando en la iteracion
        for (j = 0; j < M && t==0; ++j) {
            // Esta estructura es un 'if ternario' que tiene el formato condicion ? accion1 sino(:) accion2
            // El if comun es if(condicion) accion1; sino(else) accion2
            j == 0 ? k = i : k = 0;
            //Se detiene si llega a N o si se encontro la letra que se estaba buscando en la iteracion
            for (; k < N && t==0; ++k){
                //Si encuentra una letra de la palabra la coloca en su posicion
                if (palabra[i] == A[j][k]){
                    intercambiaMatriz(A, 0, i, j, k);
                    t=1;
                    ++cont;
                }
            }
        }
    }
    //Revisa si la palabra fue encontrada
    if (cont == N) return 1;
    else return 0;
}

void intercambiaMatriz(char** A, int filaA, int columnaA, int filaB, int columnaB){
    char aux = A[filaA][columnaA];
    A[filaA][columnaA] = A[filaB][columnaB];
    A[filaB][columnaB] = aux;
}