CC=g++
CFLAGS=-std=c++23 -Ofast -Wall -Wextra -Wconversion -Wdouble-promotion -Wduplicated-cond -Wfatal-errors -Wfloat-equal -Wformat=2 -Wlogical-op -Wpedantic -Wshadow -Wundef -Wno-unused-parameter
BINS=problema
all: clean problema

problema:
	$(CC) $(CFLAGS) -o problema C1_2020.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
