CC=g++
CFLAGS=-std=c++23 -Ofast -Wall -Wextra -Wshadow -Wpedantic -Wfloat-equal -Wconversion -Wduplicated-cond -Wundef -Wformat=2 -Wdouble-promotion -Wno-unused-parameter
BINS=problema
all: clean problema

problema:
	$(CC) $(CFLAGS) -o problema C1_2020.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
