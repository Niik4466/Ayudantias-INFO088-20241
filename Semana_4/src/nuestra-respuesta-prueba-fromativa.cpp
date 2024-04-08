r#include <iostream>
#include <string.h>
#include <cstdlib>
#include <math.h>
using namespace std;	// uso del espacio de nombre std

#define N 30		// cantidad de puntos a crear
#define Q 50		// debe crear puntos flotantes en el rango [-Q, Q]
#define REP 30		// Repeticiones

void genPoints(float X[N], float Y[N]);
float euclideanDistance(float X[N], float Y[N], int u, int v);
int manhattanDistance(float X[N], float Y[N], int u, int v);
float porcentajeDiferencia(float X[N], float Y[N]);
void centroide(float X[N], float Y[N]);
//agregada la función imprimeArray(int X[n])
void imprimeArray(float X[N], float Y[N]);

int main(){

	float X[N], Y[N], porcentaje;
	
	genPoints(X, Y);
	
	fputs_unlocked("Coordenadas: \n", stdout);
	imprimeArray(X, Y);
	
	porcentaje = porcentajeDiferencia(X, Y);
	
    // \% es para que el printf tomo el caracter de % como caracter enves de instruccion
	printf("\nEl porcentaje de diferencia es de: %f\% \n", porcentaje);
	
	return EXIT_SUCCESS;
}

void genPoints(float X[N], float Y[N]){
	for (int i = 0; i < N; i++){
		X[i] = (Q-1) - rand()%(Q+Q) + rand()/(float)RAND_MAX;
		Y[i] = (Q-1) - rand()%(Q+Q) + rand()/(float)RAND_MAX;
	}
}


float porcentajeDiferencia(float X[N], float Y[N]){
	float porcentaje = 0;
	int v, u;
	float mDistance, eDistance;
	for (int i = 0; i < REP; i++){
		u = rand()%N; v = rand()%N;
		mDistance = manhattanDistance (X, Y, u , v);
		eDistance = euclideanDistance(X, Y, u, v) ;
		porcentaje += (mDistance - eDistance) / eDistance;
	}
	return porcentaje/REP;
}

float euclideanDistance(float X[N], float Y[N], int u, int v){
	float distancia_x = abs(X[u] - X[v]);
	float distancia_y = abs(Y[u] - Y[v]);																									
	return (sqrt(distancia_x*distancia_x + distancia_y*distancia_y));
}

int manhattanDistance(float X[N], float Y[N], int u, int v){
	float distancia_x = abs(X[u] - X[v]);
	float distancia_y = abs(Y[u] - Y[v]);
	return (distancia_x + distancia_y);
}

void imprimeArray(float X[N], float Y[N]){
	for (int i = 0; i < N; i++){
        //el 0.3f indica que imprimira 3 digitos despues de la coma de un flotante 
		printf("(%0.3f, %0.3f) ", X[i], Y[i]);
	}
    // fputc es como el fputs pero para char (put charater vs put string)
	fputc_unlocked('\n', stdout);
}
	

/*
SI DESEA PROFUNDIZAR, RESUELVA:
===============================

Cree el procedimiento void losMasCercanos(float X[N], float Y[N], int q, int *p_manh, int *p_real)
que encuentra, utilizando la distancia de Manhattan, cuales son los indices p_manh y p_eucl de los 
puntos más cercanos a (X[q],Y[q]), según la distancia euclideana y de manhattan respectivamente.
*/

// calcula e imprime el centroide correspondientes a los N puntos
void centroide(float X[N], float Y[N]){

}
