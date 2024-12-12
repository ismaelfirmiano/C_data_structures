#include "hash.h"

void ini(THASH tab, int n){
    for(int i = 0; i<n; i++)
        tab[i]=-1;
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

void add(int x, float cr){
    FILE * fp = fopen("hash", "wb");
    if(!fp) exit(1);

    int pos, n = hash(x, TAM_TAB_HASH);

    fseek(fp, sizeof(int), n);
    fread(&pos, sizeof(int), 1, fp);

    if(pos == -1){
        
    }
}