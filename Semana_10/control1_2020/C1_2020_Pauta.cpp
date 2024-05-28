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
void creaLista(Datos S, nodo **l);
bool esPrimo(int num, int divisor);
void datosRecursivos(Datos S, nodo **L);

void appendToListL(nodo **l, int num);		// añade un nodo al inicio de la lista 
void appendToListR(nodo **l, int num);		// añade un nodo al final de la lista 
void imprimeEstructura(Datos S);				// imprime todo lo que S tiene
void printList(nodo *l);						// imprime la lista l

int main(int argc, char **argv){
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./problema n" << endl;
		exit(EXIT_FAILURE);
	}
	Datos S;
	S.n = atoi(argv[1]);
	S.A = new int[S.n];
	S.C = new int[S.n];

	llenaEstructura(S);
	imprimeEstructura(S);
	nodo *L = NULL;
	
	creaLista(S, &L);
	printList(L);

	nodo *P = NULL;
	cout << "Lista enlazada P con 1 o 0, si S.A[i] es o no primo" << endl;
	datosRecursivos(S, &P);
	printList(P);

	cout << "Fin Control 1" << endl;
	return EXIT_SUCCESS;
}

// devuelve la cantidad de dígitos de x
int cantDigitos(int x){
	int c=1;
	while(x>=10){
		x = x/10;
		c++;		
	}

	return c;
}

// 2 Pts.
void llenaEstructura(Datos S){
	for (int i=0; i<S.n; i++){
		S.A[i] = rand()%(max+1);
		S.C[i] = cantDigitos(S.A[i]);
	}
}

// 2 Pts.
void creaLista(Datos S, nodo **l){
	int i, j, x;
	for (i=S.n-1; i>=0; i--){
		x = S.A[i];
		for (j=0; j<S.C[i]; j++){
			appendToListR(l, x%10);
			x = x/10;
		}
	}
}

bool esPrimo(int num, int divisor){
	if(divisor > num/2)
		return true;
	if(num%divisor == 0)
		return false;
	return esPrimo(num,divisor+1); 
}

void datosRecursivos(Datos S, nodo **L){
// crea una lista enlazada con valores 1 o 0, dependiendo
// si el A[i] es primo o no
	for(int i = 0; i < S.n; i++){
		if(esPrimo(S.A[i],2))
			appendToListR(L,1);
		else
			appendToListR(L,0);
	}
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