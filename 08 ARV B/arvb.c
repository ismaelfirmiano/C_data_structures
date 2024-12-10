#include "arvb.h"

TARVB * inicializa(){
    return NULL;
}

TARVB * cria(int t){
    TARVB * novo = (TARVB *)malloc(sizeof(TARVB));
    novo->nchaves = 0;
    novo->folha = 1;
    novo->chaves = (int *)malloc(sizeof(int) * (2*t-1));
    novo->filhos = (TARVB **)malloc(sizeof(TARVB *)*2*t);
    
    for(int i = 0; i<(2*t); i++){
        novo->filhos[i] = NULL;
    }
    return novo;
}

TARVB * bus(TARVB * no, int x){
    if(!no)
        return NULL;
    int i = 0;
    while(i<no->nchaves && no->chaves[i]<x){
        i++;
    }
    if((i<no->nchaves) && (no->chaves[i]==x)){
        return a;
    }
    return bus(no->filhos[i], x);
}

TARVB * ins(TARVB * no, int a){

}

TARVB * rem(TARVB * no, int a){

}

void lib(TARVB * a){
    if(a){
        if(!a->folha) for(int i=0; i<=a->nchaves; i++) lib(a->filhos[i]);
        free(a->filhos);
        free(a->chaves);
        free(a);
    }
}