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
    
}

TABB * alt(TABB *a){
    if(!a) return 0;
    return 1 + maior(alt(a->esq), alt(a->dir));
}

TABB * impAlt(TABB *a){
    if(!a) return 0;
    return 1 + maior(alt(a->esq), alt(a->dir));
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

void imp_form(TABB *a, int n)
{
    if (a)
    {
        imp_form(a->dir, n + 1);
        for (int i = 0; i < n; i++)
            printf("  ");
        printf("%d\n", a->info);
        imp_form(a->esq, n + 1);
    }
}