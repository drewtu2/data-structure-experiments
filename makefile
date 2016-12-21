CC = g++

all: main

main:
	$(CC) main.cpp -o build/main
#linkedLists.o: 
#	$(CC) linkedlists.h -o build/linkedLists.o

clean:
	rm build/*
