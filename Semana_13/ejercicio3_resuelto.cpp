/*
    Se sabe que un árbol binario puede ser transformado a un vector de la siguiente forma
    para un nodo x ubicado en algún indice i del vector A[1..n] 
    el hijo izquierdo del nodo x estará ubicado en el indice i*2+1
    y el hijo derecho en el indice i*2+2

    Dada esta información y un AVL
    codifique la función void creaAvlVector(nodoAVL* root, int i, vector<int> &vectorAVL)
    ¿Por qué cuesta menos espacio (celdas) transformar un AVL a un vector que un BST a un vector?

    Además codifique la función "void printVectorInorder(vector<int> &vectorAVL, int i)" para imprimir inorder los elementos del vector.
    El resultado de avl.printInorder y printVectorInorder deberían ser el mismo.

    Por último implemente las funciones del ejercicio1.cpp "void imprimeCeldas(nodoAVL* root, int val);"
    y del ejercicio2.cpp "void imprimeAltura(nodo* t, int h);" en su versión vector

    PD: pueden modificar los argumentos de las funciones a conveniencia
*/

#include "avl/AVL.h"
#include <vector>
#include <random>

#define MAX 100

using namespace std;

void creaAvlVector(nodoAVL* root, int pos, vector<int> &vectorAVL);
void imprimeCeldas(vector<int> &vectorAVL, int val);
int findMaxHeight(vector <int> &vectorAVL);
void imprimeAltura(vector<int> &vectorAVL, int h, int pos);

int main(int argc, char** argv){
    if (argc != 2){
        printf("Se debe ejecutar como './prog n'\n");
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);

    AVL avl;

    for (int i = 0; i < n; ++i){
        avl.insert(&(avl.root), rand()%MAX);
    }

    avl.printInorder(avl.root);
    printf("\n");

    int h = static_cast<int>(floor(log2(n)))+1;
    vector<int> vectorAVL(static_cast<int>(pow(2, h)), -1);
    creaAvlVector(avl.root, 0, vectorAVL);
    imprimeCeldas(vectorAVL, 35);
    imprimeAltura(vectorAVL, rand()%h, 0);
    printf("\n");

    return EXIT_SUCCESS;
}

void creaAvlVector(nodoAVL* root, int pos, vector<int> &vectorAVL) {
    if (root == nullptr || pos >= static_cast<int>(vectorAVL.size()))
        return;
    
    vectorAVL.at(pos) = root->key;
    creaAvlVector(root->izq, pos*2+1, vectorAVL);
    creaAvlVector(root->der, pos*2+2, vectorAVL);
}

void imprimeCeldas(vector<int> &vectorAVL, int val) {
    int posIzq = 0;
    int posDer = 2;
    while (posIzq < static_cast<int>(vectorAVL.size()) && posDer < static_cast<int>(vectorAVL.size())) {
        if(vectorAVL.at(posIzq) != -1 && vectorAVL.at(posIzq) == val && vectorAVL.at(posIzq*2+1) != -1 && vectorAVL.at((posIzq*2+1)*2 + 2) != -1) {
            printf("Nodo: %i\nHijo derecho: %i\nHijo derecho del nulo izquierdo %i\n", vectorAVL.at(posIzq), vectorAVL.at(posIzq*2+1), vectorAVL.at((posIzq*2+1)*2 + 2));
            return;
        } else {
            posIzq = posIzq*2+1;
        }
        if (vectorAVL.at(posDer) != -1 && vectorAVL.at(posDer) == val && vectorAVL.at(posDer*2+1) != -1 && vectorAVL.at((posDer*2+1)*2 + 2) != -1) {
            printf("Nodo: %i\nHijo derecho: %i\nHijo derecho del nulo izquierdo %i\n", vectorAVL.at(posDer), vectorAVL.at(posDer*2+1), vectorAVL.at((posDer*2+1)*2 + 2));
            return;
        } else {
            posDer = posDer*2+2;
        }
        
    }
}

int findMaxHeight(vector <int> &vectorAVL) {
    return static_cast<int>(floor(log2(vectorAVL.size())));
}

void imprimeAltura(vector<int> &vectorAVL, int h, int pos) {
    if (pos >= static_cast<int>(vectorAVL.size()) || vectorAVL.at(pos) == -1)
        return;
    
    imprimeAltura(vectorAVL, h, pos*2+1);
    if (static_cast<int>(floor(log2(pos))) == h)
        printf("%i ", vectorAVL.at(pos));
    imprimeAltura(vectorAVL, h, pos*2+2);
}