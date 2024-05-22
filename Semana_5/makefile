CC=g++
CFLAGS=-std=c++23 -Ofast -Wall -Wextra -Wpedantic -Wno-unused-parameter -Wdouble-promotion
BINS=bin/prog
all: clean problema

problema:
	$(CC) $(CFLAGS) -o bin/prog src/Ejercicio1-y-2_resueltos.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
