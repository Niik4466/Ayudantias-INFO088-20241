.PHONY = all clean
CC=g++
CFLAGS=-std=c++23 -Ofast -Wall -Wextra -Wconversion -Wdouble-promotion -Wduplicated-cond -Wfatal-errors -Wfloat-equal -Wformat=2 -Wlogical-op -Wpedantic -Wshadow -Wundef -Wno-unused-parameter -Wno-unused-result
BINS=bin/prog

all: clean avl/AVL.o $(BINS)

bin/%: ejercicio1.cpp
	$(CC) $(CFLAGS) -o $@ avl/AVL.o $<

avl/AVL.o: avl/AVL.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS) avl/*.o