CC=g++
CFLAGS=-std=c++11 -Wall

all: main

main: main.o cliente.o clientepf.o clientepj.o funcionario.o vendedor.o gerente.o veiculo.o carro.o moto.o estoque.o venda.o
	${CC} ${CFLAGS} main.o cliente.o clientepf.o clientepj.o funcionario.o vendedor.o gerente.o veiculo.o carro.o moto.o estoque.o venda.o -o main

main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp

cliente.o: cliente.h cliente.cpp
	${CC} ${CFLAGS} -c cliente.cpp

clientepf.o: clientepf.h clientepf.cpp
	${CC} ${CFLAGS} -c clientepf.cpp

clientepj.o: clientepj.h clientepj.cpp
	${CC} ${CFLAGS} -c clientepj.cpp

funcionario.o: funcionario.h funcionario.cpp
	${CC} ${CFLAGS} -c funcionario.cpp

vendedor.o: vendedor.h vendedor.cpp
	${CC} ${CFLAGS} -c vendedor.cpp

gerente.o: gerente.h gerente.cpp
	${CC} ${CFLAGS} -c gerente.cpp

veiculo.o: veiculo.h veiculo.cpp
	${CC} ${CFLAGS} -c veiculo.cpp

carro.o: carro.h carro.cpp
	${CC} ${CFLAGS} -c carro.cpp

moto.o: moto.h moto.cpp
	${CC} ${CFLAGS} -c moto.cpp

estoque.o: estoque.h estoque.cpp
	${CC} ${CFLAGS} -c estoque.cpp

venda.o: venda.h venda.cpp
	${CC} ${CFLAGS} -c venda.cpp

clean:
	rm -f main *.o *.txt

run: 
	./main