#include <stdio.h>
#include <stdlib.h>

typedef struct arvbm{
    int * chave, folha, nchaves;
    struct arvbm **filho, *prox;
}TARVBM;

TARVBM * cria(int t);
TARVBM * bus(TARVBM * a, int x);
TARVBM * ins(TARVBM * a, int x);