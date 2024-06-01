CC=g++
CFLAGS=-std=c++23 -Ofast -Wall -Wextra -Wconversion -Wdouble-promotion -Wduplicated-cond -Wfatal-errors -Wfloat-equal -Wformat=2 -Wlogical-op -Wpedantic -Wshadow -Wundef -Wno-unused-parameter
BINS=arrayList
all: clean problema

problema:
	$(CC) $(CFLAGS) -o arrayList F2_2019_II_resuelto.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
