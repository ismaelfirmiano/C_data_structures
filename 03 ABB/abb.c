#include "abb.h"

TABB * inicializa(){
    return NULL;
}

TABB * cria(int x, TABB * e, TABB * d){
    TABB * novo = (TABB *)malloc(sizeof(TABB));
    novo->info = x;
    novo->esq = e;
    novo->dir = d;
    return novo;
}

TABB * ins(TABB *a, int x){
    if (!a)
        return cria(x, NULL, NULL);
    if (a->info > x)
        a->esq = ins(a->esq, x);
    else if (a->info < x)
        a->dir = ins(a->dir, x);
    return a;
}

int maior(int a, int b){
    if(a>b)
        return a;
    return b;
}

TABB * rem(TABB *a, int x){
    if(a){
        if(a->info > x)
            a->esq = rem(a->esq, x);
        else if(a->info < x)
            a->dir = rem(a->dir, x);
        if(a->info == x){
            if(!a->dir && !a->esq){
                free(a);
                return NULL;
            }
            else if(a->esq && a->dir){
                TABB * aux = a->esq;
                while (aux->dir){
                    aux = aux->dir;
                }
                a->info = aux->info;
                a->esq = rem(a->esq, a->info);
                return a;
            }
            else {
                TABB* aux = (a->esq) ? a->esq : a->dir;
                free(a);
                return aux;
            }
        }
    }
    return a;
    
}

TABB * copiar(TABB * a){
    if(!a) return NULL;
    TABB * c = (TABB *)malloc(sizeof(TABB));
    c->info = a->info;
    c->esq = copiar(a->esq);
    c->dir = copiar(a->dir);
    return c;
}

TABB * liberar(TABB * a){
    if(a){
        liberar(a->esq);
        liberar(a->dir);
        free(a);
    }
    return NULL;
}

TABB * espelhar(TABB * a){
    if(a){
        TABB * aux = a->esq;
        a->esq = espelhar(a->dir);
        a->dir = espelhar(aux);
    }
    return a;
}

int alt(TABB *a){
    if(!a) return 0;
    return 1 + maior(alt(a->esq), alt(a->dir));
}

TABB * impAlt(TABB *a, int n){
    if (a)
    {
        impAlt(a->dir, n + 1);
        for (int i = 0; i < n; i++)
            printf("  ");
        printf("%d\n", alt(a));
        impAlt(a->esq, n + 1);
    }
}

void imp(TABB *a)
{
    if (a)
    {
        imp(a->esq);
        printf("%d ", a->info);
        imp(a->dir);
    }
}

void impForm(TABB *a, int n)
{
    if (a)
    {
        impForm(a->dir, n + 1);
        for (int i = 0; i < n; i++)
            printf("  ");
        printf("%d\n", a->info);
        impForm(a->esq, n + 1);
    }
}