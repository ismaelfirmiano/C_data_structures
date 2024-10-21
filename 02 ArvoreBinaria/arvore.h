#include <stdio.h>
#include <stdlib.h>

typedef struct ArvoreBinaria
{
    int info;
    struct ArvoreBinaria *esq, *dir;
} TAB;

TAB *vet2ab(int *vet, int ini, int fim);

void imp(TAB *a);
void imp_form(TAB *a, int n);