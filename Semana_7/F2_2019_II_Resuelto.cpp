#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

#define MAX 30

struct Lista{
	int ID;		// un correlativo que parte de 0
	int num;	// aleatorio en el rango [1..MAX]
	struct Lista *next;
};
typedef struct Lista nodoL;

void genDatos(nodoL **L, int *A, int n);
void sortA(nodoL *l, int *A, int n);
void printList(nodoL *l);
void printArray(int *A, int n);
nodoL *buscaNodoId(nodoL *l, int id);

int main(int argc, char **argv){
	if(argc != 2) {
		cout << "Error. Debe ejecutarse como ./arrayLisst n" << endl;
		exit(EXIT_FAILURE);
	}
	
	int n=atoi(argv[1]);
	if(n==0)
		return EXIT_FAILURE;

	int *A = new int[n];
	nodoL *l = NULL;

	// creación de datos aleatorios
	genDatos(&l, A, n);

	printList(l);
	printArray(A, n);

    sortA(l, A, n);
    fputs_unlocked("\nArreglo ordenado:\n",stdout);
    printArray(A, n);
}

void genDatos(nodoL **l, int *A, int n){
	int i, cont=0;

	if(*l == nullptr) {
		*l = new nodoL;
		(*l)->ID = 0;
		(*l)->num = rand()%MAX;
	}
	nodoL *initl = *l;

	A[0] = -1;
	for(i = 1; i<n ; ++i) {
		nodoL *p = new nodoL;
		p->ID = i;
		p->num = rand()%MAX;
		(*l)->next =  p;
		*l = (*l)->next;

		A[i] = -1;
	}
	*l = initl;
 
	while(cont<n) {
		i = rand()%n;
		if(A[i]==-1) {
			A[i] = cont;
			++cont;
		}
	}
	
}

void sortA(nodoL *l, int *A, int n) {
    int i,j,key;
    nodoL *p = nullptr;
    for(i=1; i<n; ++i) {
        p = buscaNodoId(l, A[i]);
        key = A[i];
        j = i-1;
        while (j>=0 && buscaNodoId(l, A[j])->num > p->num) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

void printList(nodoL *l){
	nodoL *p = l;
	cout << "Lista = ID(num)..." << endl;
	while (p != nullptr){
		cout << "(" << p->ID << ")" << p->num << " ";
		p = p->next;
	}
	cout << endl;
}

void printArray(int *A, int n){
	cout << "Array A..." << endl;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
}

// buscar en l el nodo *p con p->ID==id y lo retorna
nodoL *buscaNodoId(nodoL *l, int id){
	nodoL *p=l;
	p = l;
	while(p!=nullptr && p->ID!=id)
		p=p->next;
	return p;
	}

// este método le servirá para guiarse en la codificación de sortA()
void insertionSort(int* A, int n){
	int i,j,key;

	for(i=1; i<n; i++){
		key = A[i];
		j = i-1;
		while (j>=0 && A[j]>key){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}
