/*
Nota. Algunas funciones en string que son muy útiles:
        strcpy(a, b);
        copia el contenido del string 'b' a la variable string 'a'
También se puede usar como:
        strcpy(a, "Nuevo valor");

Además con:
        strcat(a, b);  , o con: 
        strcat(a, "se aniade al final");
        el contenido del segundo argumento se aniade al final de la variable string 'a'
*/

/*
Ejercicio 1:
Teniendo un arreglo de Alum[0..n-1] llamado "Alumnos", cree la función quickSortId(vector<Alum> &Alumno, const int l, const int r)
que ordena el arreglo de alumnos ascendentemente utilizando el campo id.
Luego de ordenar el arreglo, intente buscar una id aleatoria utilizando binarySearchId(vector<Alum> &Alumno, const int l, const int r).

Ejercicio 2:
Siguiendo el enunciado del ejercicio anterior, cree la función insertionSortNombre(vector<Alum> &Alumno, int l, int r)
¿De que manera puede ordenarse según el nombre, considerando que son caracteres y un nombre puede ser igual a otro?
Adicionalmente implemente un binarySearchNombre(vector<Alum> &Alumno, const int l, const int r) el cual, despues de ordenarlo con su insertionSort,
busque un nombre en el arreglo.
*/

#include <iostream>
#include <cstring>
#include <random>
#include <vector>
#include <array>
using namespace std;

#define N_CAR 3
#define N_NOM 5
#define N_APEL 10
#define MIN_EDAD 17
#define MAX_EDAD 49

const array<char[10], N_NOM>  ellos = {"Pedro", "Juan", "Manuel", "Diego", "Agustin"};
const array<char[10], N_NOM> ellas = {"Maria", "Claudia", "Josefina", "Paola", "Linda"};
const array<char[10], N_APEL> apel = {"Torres", "Flores", "Campos", "Acosta", "Aguirre", "Molina", "Silva", "Rojas", "Rios", "Castillo"};

struct {
   char id;
   char nombre[20];
} const Carrera[N_CAR] = {{'B', "Bachillerato"},{'I', "Ingenieria"},{'M', "Magister"}};

struct Alum{
	int id;		// cree un entero alearotio positivo
	char nombres[21];	// 2 nombres (separados por un espacio en blanco), 
	char apellidos[21];	// 2 apellidos provenientes de apel (separados por un espacio en blanco)
	bool masc;		// true: masculino, false: femenino
	char idCarrera; 	// 'B', 'I' o 'M'
	int edad;		// IN [MIN_EDAD..MAX_EDAD]
};

void genAlumnos(vector<Alum> &Alumno, const int n);
void print_alumnos(vector<Alum> &Alumno, const int n);
void quickSortId(vector<Alum> &Alumno, const int l, const int r);
int partitionId(vector<Alum> &Alumno, const int l ,const int r);
int binarySearchId(vector<Alum> &Alumno, const int l, const int r);
void insertionSortNombre(vector<Alum> &Alumno, int l, int r);
int binarySearchNombre(vector<Alum> &Alumno, const int l, const int r);

// A esta definición del main(), se le pueden pasar argumentos
int main(int argc, char **argv) {
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./alum n" << endl;
		exit(EXIT_FAILURE);
	}

    const int n=atoi(argv[1]);
	vector<Alum> Alumno(n);	// ESTO ES MEMORIA DINAMICA --> no sabe el compilador cuantos bytes son

	genAlumnos(Alumno, n);

	print_alumnos(Alumno, n);

	return EXIT_SUCCESS;
}

// generar n alumnos con dos nombres y 2 apellidos aleatorios desde los arreglos globales
void genAlumnos(vector<Alum> &Alumno, const int n) {
	int i, a, b;

	for(i=0; i<n; ++i){
		Alumno.at(i).id = rand();
		strcpy(Alumno.at(i).apellidos, apel.at(rand()%N_APEL)); // primer apellido
		strcat(Alumno.at(i).apellidos, " ");
		strcat(Alumno.at(i).apellidos, apel.at(rand()%N_APEL));

        a = b = rand()%N_NOM;
            while (a==b)
				b = rand()%N_NOM;
		
		if(rand()%2 == 0){
			Alumno.at(i).masc = false;
            
			strcpy(Alumno.at(i).nombres, ellas.at(a));
			strcat(Alumno.at(i).nombres, " ");
			strcat(Alumno.at(i).nombres, ellas.at(b));
		}else{
			Alumno.at(i).masc = true;
            
			strcpy(Alumno.at(i).nombres, ellos.at(a));
			strcat(Alumno.at(i).nombres, " ");
			strcat(Alumno.at(i).nombres, ellos.at(b));
		}

		Alumno.at(i).edad = MIN_EDAD + rand()%(MAX_EDAD-MIN_EDAD+1);
		Alumno.at(i).idCarrera = Carrera[rand()%N_CAR].id;
	}
}

void print_alumnos(vector<Alum> &Alumno, const int n) {
    printf("Lista de Alumnos:\n");
	for (int i=0; i<n; i++){
		printf("Id        : %d\n", Alumno.at(i).id);

		if (Alumno.at(i).masc)
			fputs_unlocked("Sexo      : Masculino \n", stdout);
		else
			fputs_unlocked("Sexo      : Femenino \n", stdout);

		printf("Nombres   : %s\n", Alumno.at(i).nombres);
		printf("Apellidos : %s\n", Alumno.at(i).apellidos);
		fputs_unlocked("Carreara  : ",stdout);
		switch (Alumno.at(i).idCarrera) {
			case 'B':
				printf("%s\n",Carrera[0].nombre);
				break;
			case 'I':
				printf("%s\n",Carrera[1].nombre);
				break;
			case 'M':
				printf("%s\n",Carrera[2].nombre);
				break;
			default:
				fputs_unlocked(" NO DEFINIDA !! \n", stdout);
				break;
		}
		printf("Edad      : %d\n\n", Alumno.at(i).edad);
	}
}

void quickSortId(vector<Alum> &Alumno, const int l, const int r) {

}

int partitionId(vector<Alum> &Alumno, const int l ,const int r) {
    return 0;
}

int binarySearchId(vector<Alum> &Alumno, const int l, const int r) {
    return 0;
}

void insertionSortNombre(vector<Alum> &Alumno, int l, int r) {

}

int binarySearchNombre(vector<Alum> &Alumno, const int l, const int r) {
    return 0;
}