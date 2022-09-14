CC=g++
# CFLAGS=-std=c++11 -Wall
CFLAGS=-g
# CFLAGS=-g -funsigned-char

all: main

main: main.o Huffman.o 
	${CC} ${CFLAGS} main.o Huffman.o

main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp

Huffman.o: Huffman.h Huffman.cpp
	${CC} ${CFLAGS} -c Huffman.cpp

clean:
	rm -f main *.o *.txt *.out arquivos/decodificado.txt arquivos/saida.dat

encode: 
	valgrind --leak-check=full ./a.out c arquivos/original.txt arquivos/saida.dat

decode: 
	valgrind --leak-check=full ./a.out d arquivos/saida.dat arquivos/decodificado.txt