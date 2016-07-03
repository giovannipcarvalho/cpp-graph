CC=g++

CFLAGS=-std=c++11#-Wall

all: main.cpp
	$(CC) $(CFLAGS) graph.cpp main.cpp -o main

test: test.cpp
	$(CC) $(CFLAGS) graph.cpp test.cpp -o test

test_utils: test_utils.cpp
	$(CC) $(CFLAGS) graph.cpp test_utils.cpp -o test_utils

.PHONY: clean
clean:
	rm main test test_utils
