#include "arq.h"

void criarArq(char * nomeArq){
    
    FILE * f = fopen(nomeArq, "w");

    int x;
    scanf("%d", &x);
    while(x>0){
        fprintf(f, "%d ", x);
        scanf("%d", &x);
    }

    fclose(f);
}

void lerArq(char * nomeArq){
    
    FILE * f = fopen(nomeArq, "r");

    int x, r;
    r = fscanf(f, "%d", &x);
    while(r != EOF){
        printf("%d\n", x);
        r = fscanf(f, "%d", &x);
    }
    
    fclose(f);
}

void criarPart(char * nomeArq, int tamanho){
    
}