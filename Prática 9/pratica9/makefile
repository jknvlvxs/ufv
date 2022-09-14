CC=g++
CFLAGS=-std=c++11 -Wall

all: main

main: main.o soma.o power.o mdc.o
	${CC} ${CFLAGS} main.o soma.o power.o mdc.o -o main

main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp

soma.o: soma.h soma.cpp
	${CC} ${CFLAGS} -c soma.cpp

power.o: power.h power.cpp
	${CC} ${CFLAGS} -c power.cpp

mdc.o: mdc.h mdc.cpp
	${CC} ${CFLAGS} -c mdc.cpp

clean:
	rm -f main *.o 