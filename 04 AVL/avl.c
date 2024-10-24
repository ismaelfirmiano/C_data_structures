#include "avl.h"

TAVL * inicializa(){
    return NULL;
}

TAVL * cria(int x, TAVL * e, TAVL * d){
    TAVL * novo = (TAVL *)malloc(sizeof(TAVL));
    novo->info = x;
    novo->esq = e;
    novo->dir = d;
    novo->altura = 0;
    return novo;
}

TAVL * rse (TAVL * a){
    
}

TAVL * rsd (TAVL * a){
    
}

TAVL * red (TAVL * a){
    
}

TAVL * rde (TAVL * a){
    
}

TAVL * ins(TAVL * a, int x){
    if(!a) return cria(x, NULL, NULL);
    if(a->info < x){
        a->dir = ins(a->dir, x);
        if(fator(a)==-2){
            if(x > a->dir->info)
                a = rse(a);
            else
                a = rde(a);
        }
    } else if(a->info > x) {
        a->esq = ins(a->esq, x);
        if(fator(a)==2){
            if(x < a->esq->info)
                a = rsd(a);
            else
                a = red(a);
        }
    }
    //CALCULAR ALTURA
    return a;
}

TAVL * rem(TAVL * a, int x){
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
                TAVL * aux = a->esq;
                while (aux->dir){
                    aux = aux->dir;
                }
                a->info = aux->info;
                a->esq = rem(a->esq, a->info);
                return a;
            }
            else {
                TAVL* aux = (a->esq) ? a->esq : a->dir;
                free(a);
                return aux;
            }
        }
    }
    return a;
}


void imp(TAVL *a)
{
    if (a)
    {
        imp(a->esq);
        printf("%d ", a->info);
        imp(a->dir);
    }
}

void imp_form(TAVL *a, int n)
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