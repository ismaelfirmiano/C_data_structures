#include <stdio.h>
#include <stdlib.h>

typedef struct ABB{
    int info;
    struct ABB *esq, *dir;
}TABB;

typedef struct listaEncadeada
{
    int info;
    struct listaEncadeada *prox;
} TLSE;

TABB * inicializa();
TABB * ins(TABB * a, int x);
TABB * rem(TABB * a, int x);
TABB * copiar(TABB * a);
TABB * liberar(TABB * a);
TABB * espelhar(TABB * a);
int* mN(TABB*a, int N, int *tam);
int zz(TABB*a);

void imp(TABB *a);
void impForm(TABB *a, int n);