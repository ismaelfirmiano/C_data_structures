#include <stdio.h>
#include <stdlib.h>

typedef struct ABB{
    int info;
    struct ABB *esq, *dir;
}TABB;

TABB * inicializa();
TABB * ins(TABB * a, int x);
TABB * rem(TABB * a, int x);

void imp(TABB *a);
void imp_form(TABB *a, int n);