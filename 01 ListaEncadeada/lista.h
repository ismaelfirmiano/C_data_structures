#include <stdio.h>
#include <stdlib.h>

typedef struct listaEncadeada
{
    int info;
    struct listaEncadeada *prox;
} TLSE;

void menu();
TLSE *LSE_inicializa();
TLSE *LSE_add_ini(TLSE *l, int x);
TLSE *LSE_add_fim(TLSE *l, int x);
TLSE *LSE_add_ord(TLSE *l, int x);
TLSE *LSE_rem(TLSE *l, int x);
TLSE *pop(TLSE *l);
TLSE *LSE_free(TLSE *l);
void LSE_imp(TLSE *l);