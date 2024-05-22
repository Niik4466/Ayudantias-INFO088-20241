CC=g++
CFLAGS=-std=c++23 -Ofast -Wall -Wextra -Wshadow -Wfloat-equal -Wconversion -Wduplicated-cond -Wundef -Wformat=2 -Wno-unused-parameter -Wdouble-promotion
BINS=arrayList
all: clean problema

problema:
	$(CC) $(CFLAGS) -o arrayList F2_2019_II_resuelto.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
