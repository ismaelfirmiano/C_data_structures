#include "lista.c"

void inverte(TLSE * l){
    TLSE * pilha = LSE_inicializa();
    TLSE * aux = l;
    while(aux){
        pilha = LSE_add_ini(pilha, aux->info);
        aux = aux->prox;
    }
    while (pilha)
    {
        l->info = pilha->info;
        pilha = pop(pilha);
        l = l->prox;
    }
}

TLSE * inverte2(TLSE * l){
    if(!l)
        return NULL;

    TLSE * aux2;
    TLSE * aux = l->prox;
    l->prox = NULL;

    while(aux){
        aux2 = l;
        l = aux;
        aux = l->prox;
        l->prox = aux2;
    }

    return l;
}


int main(void){

    TLSE * lista = LSE_inicializa();

    int x;
    scanf("%d", &x);

    while (x > 0)
    {
        lista = LSE_add_ord(lista, x);
        scanf("%d", &x);
    }

    LSE_imp(lista);

    lista = inverte2(lista);

    LSE_imp(lista);

    return 0;
}