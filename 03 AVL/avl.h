#include <stdio.h>
#include <stdlib.h>

typedef struct ABB {
    int info, altura;
    struct ABB *esq, *dir;
}TABB;

TABB * ins(TABB * arv, int x);
TABB * rem(TABB * arv, int x);
void imp(TABB *a);
void imp_form(TABB *a, int n);