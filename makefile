CC=g++

CFLAGS=-std=c++11#-Wall

all: main.cpp
	$(CC) $(CFLAGS) main.cpp graph.cpp -o main

test: test.cpp
	$(CC) $(CFLAGS) test.cpp graph.cpp -o test

test_utils: test_utils.cpp
	$(CC) $(CFLAGS) test_utils.cpp graph.cpp -o test_utils

.PHONY: clean
clean:
	rm main test test_utils