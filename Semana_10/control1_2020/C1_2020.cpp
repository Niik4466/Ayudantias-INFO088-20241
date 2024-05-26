#include <iostream>
#include <cstdlib>
using namespace std;

#define max 10000

struct Datos{
	int n;	// largo de los arreglos A y C
	int *A;	// arreglo de números aleatorios en [0...MAX]
	int *C;  // arreglo que contiene los largos de los números en A
};

struct nodeList {
	int val;
	nodeList* next;
};
typedef struct nodeList nodo;

void llenaEstructura(Datos S);
void creaLista(Datos S, nodo **L);
void datosRecursivos(Datos S, nodo **P);

void appendToListL(nodo **l, int num);		// añade un nodo al inicio de la lista 
void appendToListR(nodo **l, int num);		// añade un nodo al final de la lista 
void imprimeEstructura(Datos S);				// imprime todo lo que S tiene
void printList(nodo *l);						// imprime la lista l

int main(int argc, char **argv){
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./problema n" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Fin Control 1" << endl;
	return EXIT_SUCCESS;
}

// 2 Pts.
void llenaEstructura(Datos S){

}

// 2 Pts.
void creaLista(Datos S, nodo **L){

}


// 2 Pts.
void datosRecursivos(Datos S, nodo **P){

}

// aniade un nodo al inicio de la lista
void appendToListL(nodo **l, int num){
	nodo *nuevo = new nodo;
	nuevo->val = num;
	nuevo->next = *l;
	*l = nuevo;	
}

// aniade un nodo al final de la lista
void appendToListR(nodo **l, int num){
	nodo *nuevo = new nodo;
	nuevo->val = num;
	nuevo->next = NULL;

	if (*l == nullptr)
		*l = nuevo;
	else{
		nodo *p = *l;
		while (p->next != nullptr)
			p = p->next;

		p->next = nuevo;
	}
}

// imprime todo lo que S tiene
void imprimeEstructura(Datos S){
	cout << "S = (A[i], C[i]) = " << endl;
	for (int i=0; i<S.n; i++)
		cout << "(" << S.A[i] << ", " << S.C[i] << ") ";
	cout << endl;
}

// imprime la lista l
void printList(nodo *l){
	nodo *p = l;
	cout << "Lista = ";
	while (p != nullptr){
		cout << p->val << " ";
		p = p->next;
	}
	cout << "NULL" << endl;
}

