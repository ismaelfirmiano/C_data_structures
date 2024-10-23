#include <stdio.h>
#include <stdlib.h>

typedef struct ABB{
    int info;
    struct ABB *esq, *dir;
}TABB;

TABB * inicializa();
TABB * ins(TABB * a, int x);
TABB * rem(TABB * a, int x);
TABB * copiar(TABB * a);
TABB * liberar(TABB * a);
TABB * espelhar(TABB * a);

void imp(TABB *a);
void impForm(TABB *a, int n);