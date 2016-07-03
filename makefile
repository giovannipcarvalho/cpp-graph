CC=g++

CFLAGS=-std=c++11#-Wall

all: main.cpp
	$(CC) $(CFLAGS) graph.cpp main.cpp -o main

test: test.cpp
	$(CC) $(CFLAGS) graph.cpp test.cpp -o test
	$(CC) $(CFLAGS) graph.cpp test2.cpp -o test2
	$(CC) $(CFLAGS) graph.cpp test_utils.cpp -o test_utils
	@echo "===Testing core:"
	@./test
	@echo "===Testing Utils"
	@./test_utils
	@echo "===Testing VA2:"
	@./test2

MCP: 
	$(CC) $(CFLAGS) graph.cpp MCP.cpp -o MCP && ./MCP

MST:
	$(CC) $(CFLAGS) graph.cpp MST.cpp -o MST && ./MST

.PHONY: clean
clean:
	rm main test test2 test_utils
