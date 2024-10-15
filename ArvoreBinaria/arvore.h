#include <stdio.h>
#include <stdlib.h>

typedef struct ArvoreBinaria
{
    int info;
    struct ArvoreBinaria *esq, *dir;
} TAB;

TAB *vet2ab(int *vet, int ini, int fim);

void imp(TAB *a, int n);