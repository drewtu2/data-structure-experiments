CC = g++

all: main

main: linkedLists.o
	$(CC) build/linkedLists.o main.cpp -o build/main
linkedLists.o: 
	$(CC) -c linkedlists.cpp -o build/linkedLists.o

clean:
	rm build/*
