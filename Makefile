CC = g++
CFLAGS = -Wall -Wextra

all: build

build: integral.cpp main.cpp lagrange_impl.cpp lagrange.py
	$(CC) $(CFLAGS) integral.cpp main.cpp -o main
	$(CC) -shared -o lagrange.so -fPIC lagrange_impl.cpp
	./main
	python3 lagrange.py
	rm lagrange.so 
	rm ./main