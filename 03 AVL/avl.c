#include "avl.h"

TABB * inicializa(){
    return NULL;
}

TABB * ins(TABB * arv, int x){
    if (!arv) {
        TABB *novo = (TABB *)malloc(sizeof(TABB));
        novo->info = x;
        novo->esq = NULL;
        novo->dir = NULL;
    }
}