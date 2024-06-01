CC=g++
CFLAGS=-std=c++23 -Ofast -Wall -Wextra -Wshadow -Wfloat-equal -Wconversion -Wduplicated-cond -Wundef -Wformat=2 -Wdouble-promotion -Wno-unused-parameter 
BINS=bin/prog
all: clean problema

problema:
	$(CC) $(CFLAGS) -o bin/prog src/ejercicio1.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)