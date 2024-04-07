CC=g++
CFLAGS=-std=c++23 -Ofast -Wall -Wextra -Wno-unused-parameter #-Wdouble-promotion
BINS=bin/prog
all: clean problema

problema:
	$(CC) $(CFLAGS) -o bin/prog src/nuestra-respuesta-prueba-fromativa.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
