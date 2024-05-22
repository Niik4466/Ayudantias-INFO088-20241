CC=g++
CFLAGS=-std=c++23 -Ofast -Wall -Wextra -Wpedantic -Wno-unused-parameter -Wdouble-promotion
BINS=arrayList
all: clean problema

problema:
	$(CC) $(CFLAGS) -o arrayList F2_2019_II.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
