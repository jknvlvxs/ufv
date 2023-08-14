#@ title Gerando o código completo % % writefile code.cu
#include "head1.cu"
#define WORK 4
#define GRID 64
#define BLOCO 512
#include "kernel.cu"
// grid 6 = blk 64, work = 2^2 = 4, blk = 64 threads
#define POWER 23
#include "main.cu"