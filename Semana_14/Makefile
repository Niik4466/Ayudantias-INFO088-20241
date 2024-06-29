CC=g++
CFLAGS=-Wall -std=c++14
BINS=BST_ADN.o problema

all: clean BST_ADN.o
	$(CC) $(CFLAGS) -o problema problema.cpp BST_ADN.o

BST_ADN.o:
	$(CC) $(CFLAGS) -c BST_ADN.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
