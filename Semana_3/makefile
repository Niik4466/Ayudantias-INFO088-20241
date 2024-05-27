CC=g++
CFLAGS=-std=c++23 -Ofast -Wall -Wextra -Wshadow -Wfloat-equal -Wconversion -Wduplicated-cond -Wundef -Wformat=2 -Wdouble-promotion -Wno-unused-parameter -Wno-unused-result
BINS=bin/prog
all: clean problema

problema:
	$(CC) $(CFLAGS) -o bin/prog src/Ejercicio1_resuelto.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
