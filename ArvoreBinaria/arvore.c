#include "arvore.h"

TAB *novoNo(int x)
{
    TAB *novo = (TAB *)malloc(sizeof(TAB));
    novo->info = x;
    novo->dir = novo->esq = NULL;
    return novo;
}

TAB *vet2ab(int *v, int ini, int fim)
{
    if (ini >= fim)
        return NULL;

    int meio = ini + (fim - ini) / 2;

    TAB *no = novoNo(v[meio]);

    no->esq = vet2ab(v, ini, meio);
    no->dir = vet2ab(v, meio + 1, fim);

    return no;
}

void imp(TAB *a, int n)
{
    if (a)
    {
        imp(a->dir, n + 1);
        for (int i = 0; i < n; i++)
            printf("  ");
        printf("%d\n", a->info);
        imp(a->esq, n + 1);
    }
}