#include <hash.h>

void ini(THASH tab, int n){
    for(int i = 0; i<n; i++)
        tab[i]=NULL;
}

TA * aloca(int mat, float cr){
    TA * al = (TA *)malloc(sizeof(TA));
    al->mat = mat;
    al->cr = cr;
    al->prox = NULL;
    return al;
}

int hash(int mat, int n){
    return mat%n;
}

void lib(THASH tab, int n){
    
}