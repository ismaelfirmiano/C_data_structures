#include <stdio.h>
#include <stdlib.h>

typedef struct AVL {
    int info, altura;
    struct AVL *esq, *dir;
}TAVL;

/*
TAVL * cria(int x, TAVL * e, TAVL * d);
TAVL * fator(TAVL * a);
TAVL * altura(TAVL * a);

TAVL * rse(TAVL * a);
TAVL * rsd(TAVL * a);
TAVL * rde(TAVL * a);
TAVL * red(TAVL * a);
*/

TAVL * ins(TAVL * arv, int x);
TAVL * rem(TAVL * arv, int x);

void imp(TAVL *a);
void impForm(TAVL *a, int n);
void impAlt(TAVL *a, int n);
