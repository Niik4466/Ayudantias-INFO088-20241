/* 
Se tiene un árbol binario de la siguiente forma:
Cada nodo tiene un puntero al padre.
Los nodos de este arbol fueron guardados en un arreglo de manera aleatorea,
realicen un algoritmo que en base a estos nodos cree el arbol binario con puntero a sus hijos
*/

#include <cstdio>
#include <random>

#define N 7
#define MAX 50

using namespace std;

//estructura del hijo al padre
struct nodoF{
    nodoF* father;
    int val;
};

//estructura del árbol binario
struct nodoQ{
    nodoQ* izq;
    nodoQ* der;
    int val;
};

//Función que crea el arreglo de nodos
void makeArray(nodoF** nodoArray);

//Función que imprime el arreglo nodoArray
void printArray(nodoF** nodoArray);

//Función que en base a un arreglo de nodos con puntero al padre crea un árbol binario
void toBinaryTree(nodoF** nodoArray, nodoQ** root);

int main(int argc, char** argv){
    nodoF** nodoArray = new nodoF*[N];
    makeArray(nodoArray);
    printArray(nodoArray);
    nodoQ* root = nullptr;

}

void toBinaryTree(nodoF** nodoArray, nodoQ** root){
    //podemos armarlo desde arriba hacia abajo recursivamente para cada sub arbol

}

void makeArray(nodoF **nodoArray){
    nodoF* q;
    
    //Creamos los nodos del arreglo nodoArray
    for (int i = 0; i < N; ++i){
        q = new nodoF();
        q->val = rand() % MAX;
        nodoArray[i] = q;
    }

    //Creamos las uniones a mano (quería hacerlo random pero no tuve tiempo para implementarlo bien:c)
    //Imaginemos esto:
    // Al principio tenemos un bósque con muchos árboles los cuales sólo contienen raíces.
    //Para poder armar un árbol único en base a este bósque, entonces debemos ir agregando padres al nodo
    //verificando que para cada nodo p al que le agregamos un padre q, el nodo p no exista en el árbol de q.
    //Si existe el nodo p en el árbol de q, entonces q se cambia a un nuevo nodo aleatorio y se vuelve a repetir el proceso (UNION-FIND).
    nodoArray[0]->father = nodoArray[1];
    nodoArray[1]->father = nullptr;     //nodo raíz
    nodoArray[2]->father = nodoArray[3];
    nodoArray[3]->father = nodoArray[4];
    nodoArray[4]->father = nodoArray[1];
    nodoArray[5]->father = nodoArray[4];
    nodoArray[6]->father = nodoArray[3];
}

void printArray(nodoF** nodoArray){
    for (int i = 0; i < N; ++i){
        if (nodoArray[i]->father == nullptr)
            printf("null\t");
        else
            printf("%i\t", nodoArray[i]->father->val);
    }
    printf("\n");
    for (int i = 0; i < N; ++i){
        printf("^\t");
    }
    printf("\n");
    for (int i = 0; i < N; ++i){
        printf("|\t");
    }
    printf("\n");
    for (int i = 0; i < N; ++i){
        printf("%i\t", nodoArray[i]->val);
    }
    printf("\n");
}