#include "Pila.h"

//Constructor
Pila::Pila() {
    tope = NULL;
}
Pila::Pila(char caracter) {
    tope = new nodo();
    tope->val = caracter;
}

//Destructor
Pila::~Pila() {
    while (!isEmpty())
        pop();
}

//Método de Pila que retorna true si la pila está vacía y false si no.
bool Pila::isEmpty() {
    return false;
}

//Método que agrega un valor al tope de la pila
void Pila::push(char caracter) {
    return;
}

//Método que quita un valor del tope de la pila y lo retorna
char Pila::pop() {
    return '\0';
}

//Método que retorna el valor en el tope de la pila
char Pila::top() {
    return '\0';
}

//Método que imprime la pila
void printPila() {
    return;
}