CC=g++
# CFLAGS=-std=c++11 -Wall
CFLAGS=-g

all: main

main: main.o Huffman.o 
	${CC} ${CFLAGS} main.o Huffman.o

main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp

Huffman.o: Huffman.h Huffman.cpp
	${CC} ${CFLAGS} -c Huffman.cpp

clean:
	rm -f main *.o *.txt

encode: 
	./a.out c arquivos/original.html arquivos/saida.dat

decode: 
	./a.out d arquivos/saida.dat arquivos/decodificado.html