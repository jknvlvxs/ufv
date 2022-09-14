CC=g++
CFLAGS=-std=c++11 -Wall

all: main

main: main.o alunos.o
	${CC} ${CFLAGS} main.o alunos.o -o main

main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp

alunos.o: alunos.h alunos.cpp
	${CC} ${CFLAGS} -c alunos.cpp

clean:
	rm -f main *.o 