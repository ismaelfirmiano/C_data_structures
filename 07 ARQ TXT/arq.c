#include "arq.h"

void criarArq(char * nomeArq){
    
    FILE * f = fopen(nomeArq, "wb");
    int x;
    scanf("%d", &x);
    while(x>0){
        fprintf(f, "%d ", x);
        scanf("%d", &x);
    }
    fclose(f);
}

void selNat(char * nomeArq, int tamanho){
    FILE * res = fopen("reservatorio.txt", "w");
    FILE * f = fopen(nomeArq, "r");
    int vetor[tamanho];
    int qtdRes = 0;
    int elem;

    while(fgets(elem, sizeof(int), f)){
        while(qtdRes < tamanho){

        }
    }

}

void selSub(char * nomeArq, int tamanho){
    
}