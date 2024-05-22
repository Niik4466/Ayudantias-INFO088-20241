CC=g++
CFLAGS=-std=c++23 -Ofast -Wall -Wextra -Werror -Wpedantic -Wno-unused-parameter -Wdouble-promotion
BINS=bin/prog1 bin/prog2 bin/prog3 bin/prog4 bin/prog5
all: clean problema

problema: pila ejercicio1 ejercicio2 ejercicio3 ejercicio4 ejercicio5

pila:
	$(CC) $(CFLAGS) -c Pila.cpp

ejercicio1: pila
	$(CC) $(CFLAGS) -o bin/prog1 Pila.o ejercicio1.cpp

ejercicio2: pila
	$(CC) $(CFLAGS) -o bin/prog2 Pila.o ejercicio2_resuelto.cpp

ejercicio3: pila
	$(CC) $(CFLAGS) -o bin/prog3 Pila.o ejercicio3_resuelto.cpp

ejercicio4: pila
	$(CC) $(CFLAGS) -o bin/prog4 Pila.o ejercicio4_resuelto.cpp

ejercicio5: pila
	$(CC) $(CFLAGS) -o bin/prog5 Pila.o ejercicio5_resuelto.cpp



clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
