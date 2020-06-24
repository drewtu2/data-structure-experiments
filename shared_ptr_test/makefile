CC = g++

all: main

main:
	$(CC) -pg --std=c++11 main.cpp -o build/main
run: main
	build/main ptr && gprof build/main > output-ptr.txt &&\
	build/main ref && gprof build/main > output-reference.txt
clean:
	rm -rf build/* &&\
	rm -f gmon.out &&\
	rm -f output-*.txt
