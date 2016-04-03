CC=g++

CFLAGS=-Wall

all: main.cpp
	$(CC) $(FLAGS) main.cpp graph.cpp -o main

test: test.cpp
	$(CC) $(FLAGS) test.cpp graph.cpp -o test
