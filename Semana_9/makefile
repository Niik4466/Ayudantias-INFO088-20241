.PHONY = all clean
CC=g++
CFLAGS=-std=c++23 -Ofast -Wall -Wextra -Wconversion -Wdouble-promotion -Wduplicated-cond -Wfatal-errors -Wfloat-equal -Wformat=2 -Wlogical-op -Wpedantic -Wshadow -Wundef -Wno-unused-parameter
SRCS:=$(wildcard *.cpp)
BINS:=$(SRCS:%.cpp=bin/%)
all: pila/Pila ${BINS}

pila/Pila: pila/Pila.cpp
	echo $(BINS)
	$(CC) $(CFLAGS) -c $<

bin/%: %.cpp
	$(CC) $(CFLAGS) -o $@ Pila.o $<

clean:
	@echo " [CLN] Removing binary files"
	@rm -f ${BINS} *.o