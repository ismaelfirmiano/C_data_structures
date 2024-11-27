#include "lista.h"

void menu()
{
    printf("--- ESCOLHAR ---\n");
    printf("0 - LIMPAR\n");
    printf("1 - ADD_INI\n");
    printf("2 - ADD_ORD\n");
    printf("3 - ADD_FIM\n");
    printf("4 - REMOVER X\n");
    printf("5 - REMOVER PARES\n");
    printf("OPÇÃO: ");
}

TLSE *LSE_inicializa()
{
    return NULL;
}

TLSE *LSE_add_ini(TLSE *l, int x)
{
    TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
    novo->info = x;
    novo->prox = l;
    return novo;
}

TLSE *LSE_add_ord(TLSE *l, int x)
{
    if (!l || l->info > x)
        return LSE_add_ini(l, x);
    l->prox = LSE_add_ord(l->prox, x);
    return l;
}

TLSE *LSE_add_fim(TLSE *l, int x)
{
    if (!l)
        return LSE_add_ini(l, x);

    l->prox = LSE_add_fim(l->prox, x);
    return l;
}

TLSE *LSE_rem(TLSE *l, int x)
{
    if (!l)
        return NULL;
    if (l->info == x)
    {
        TLSE *aux = l->prox;
        free(l);
        return LSE_rem(aux, x);
    }
    l->prox = LSE_rem(l->prox, x);

    return l;
}

TLSE *pop(TLSE *l)
{
    if (!l)
        return NULL;
    
    TLSE *aux = l->prox;
    free(l);

    return aux;
}

TLSE *LSE_free(TLSE *l)
{
    if (!l)
        return NULL;
    LSE_free(l->prox);
    free(l);
    return NULL;
}

void LSE_imp(TLSE *l)
{
    if (l)
    {
        printf("%d ", l->info);
        LSE_imp(l->prox);
    }
}