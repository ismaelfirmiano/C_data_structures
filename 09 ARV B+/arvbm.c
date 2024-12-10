#include "arvbm.h"

TARVBM * cria(int t){
    TARVBM * novo = (TARVBM *)malloc(sizeof(TARVBM));
    novo->chave = (int *)malloc(sizeof(int)*((2*t)-1));
    novo->folha = 1;
    novo->filho = (TARVBM **)malloc(sizeof(TARVBM*)*(2*t));
    for(int i = 0; i < (2*t); i++)
        novo->filho[i] = NULL;
    novo->prox = NULL;
    return novo;
}

TARVBM * bus(TARVBM * a, int x){
    if(!a)
        return NULL;
    int i = 0;
    while((i<a->nchaves) && (a->chave[i]<x))
        i++;
    if((a->folha) && (i<a->nchaves) && (a->chave[i]==x))
        return a;
    if((i<a->nchaves) && (a->chave[i]==x))
        i++;
    return bus(a->chave[i], x);
}

TARVBM * ins(TARVBM * a, int x){
    
}