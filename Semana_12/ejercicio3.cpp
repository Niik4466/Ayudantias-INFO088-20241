/*
Se sabe que un arbol binario puede representarse en un arreglo BT[1..n] de la siguiente manera
sea un nodo almacenado en el espacio i del arreglo, sus hijos seran BT[i*2+1] y BT[i*2+2]

Dado un árbol binario de búsqueda (BST) deben transformarlo a un Array de la manera antes descrita

Luego, codifiquen la función "void sumBSA(vector<int> Array)" la cual opera con suma si se va al nodo izquierdo y reste si se va al nodo derecho
en postorder.
*/

#include <vector>
#include <random>

#define MAX 100
#define N 5

using namespace std;

struct node{
    node* izq;
    node* der;
    int val;
};

// Función para agregar un elemento al BST
void llenaBST(node **root, int elem){
    if (root == nullptr){
        (*root) = new node();
        (*root)->val = elem;
    }
    else if ((*root)->val < elem){
        llenaBST(&(*root)->izq, elem);
    }else
        llenaBST(&(*root)->der, elem);
}

// Función que transforma un BST a un Array
void transformaArray(node* root, vector<int> BSA /*más argumentos que necesiten*/);

// Función que suma si se mueve a la izquierda y reste si se mueve a la derecha
void sumBSA(vector<int> BSA /*más argumentos que necesiten*/);

int main() {

    node* root = nullptr;
    
    //Poblamos el BST con elementos aleatorios
    for (int i = 0; i < N; ++i) {
        llenaBST(&root, rand()%MAX);
    }

    // Calculamos el tamaño del Array
    int max=0;
    for (int i = 0; i<N; i/2) {
        max = max*2+2;
    }

    vector<int> BSA(max, -1);
}

void transformaArray(node* root, vector<int> BSA) {
    return;
}

void sumBSA(vector<int> BSA) {
    return;
}