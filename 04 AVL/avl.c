#include "avl.h"

void menu()
{
    printf("--- ESCOLHAR ---\n");
    printf("0 - ENCERRAR\n");
    printf("1 - REMOVER UM ELEMENTO\n");
    printf("2 - REMOVER VÁRIOS ELEMENTOS\n");
    printf("3 - LIBERAR ARVORE\n");
    printf("4 - IMPRIMIR ARVORE\n");
    printf("5 - IMPRIMIR ELEMENTOS\n");
    printf("6 - IMPRIMIR ALTURAS\n");
    printf("7 - IMPRIMIR FATOR DE BALANCEAMENTO\n");
    printf("OPÇÃO: ");
}


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
int maior(int x, int y){
    return x>y?x:y;
}

int calAlt(TAVL * a){
    if(!a)
        return -1;
    return 1 + maior(calAlt(a->dir), calAlt(a->esq));
}

TAVL * ins(TAVL * a, int x){
    if(!a) return cria(x, NULL, NULL);
    if(a->info < x){
        a->dir = ins(a->dir, x);
        
    } else if(a->info > x) {
        a->esq = ins(a->esq, x);
    }
    a->altura = calAlt(a);
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

void impForm(TAVL *a, int n)
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

void impAlt(TAVL *a, int n)
{
    if (a)
    {
        impAlt(a->dir, n + 1);
        for (int i = 0; i < n; i++)
            printf("  ");
        printf("%d\n", a->altura);
        impAlt(a->esq, n + 1);
    }
}