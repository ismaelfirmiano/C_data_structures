#include "arquivo.c"

int main(void){
    char * arq = "arq";
    int x;
    criaArqBin(arq);
    printf("ARQUIVO CRIADO.\nBUSCAR: ");
    scanf("%d", &x);
    int ele = busBinArq(arq, x);
    printf("%d\n", ele);
    return 0;
}
