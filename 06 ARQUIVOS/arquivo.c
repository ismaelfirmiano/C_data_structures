#include <stdio.h>
#include <stdlib.h>


void criaArqBin (char * nome_arq){
    FILE * fp = fopen(nome_arq, "wb");
    if(!fp) exit(1);
    int atual, ant;
    printf("Digite valores positivos, caso contrário, pare a gravação\n");
    scanf("%d", &atual);

    while (atual > 0)
    {
        fwrite(&atual, sizeof(int), 1, fp);
        scanf("%d", &atual);
    }

    fclose(fp);
    
}

int busBin(int * vet, int n, int x) {
    int ini=0, fim = n-1, meio;
    while (ini <= fim)
    {
        meio = (ini+fim)/2;
        if(vet[meio] == x) return meio;
        if(vet[meio] > x) fim = meio-1;
        else ini = meio+1;
    }
    return -1;
    
}

int busBinArq(char * arq, int x){
    FILE * fp = fopen(arq, "rb");
    if(!fp) exit(1);
    int ini, fim, meio, elem;
    ini = 0;
    fseek(fp, 0, SEEK_END);
    fim = ftell(fp) - sizeof(int);

    while (ini <= fim)
    {
        meio = (((fim-ini)/sizeof(int))/2)*sizeof(int);
        fseek(fp, meio, SEEK_SET);
        fread(&elem, sizeof(int), 1, fp);
        if(elem == x){
            fclose(fp);
            return meio;
        }
        if(elem > x)
            fim = meio - sizeof(int);
        else
            ini = meio + sizeof(int);
    }

    fclose(fp);
    return -1;
    
}

void junta(char * arq1, char * arq2, char * saida){
    FILE    * fp1 = fopen(arq1, "r"),
            * fp2 = fopen(arq2, "r"),
            * fps = fopen(saida, "r");
    if ((!fp1) || (!fp2) || (!fps)) exit(1);
}

/* LEITURA DE DADOS
int fread(void *ptr, int tam_cada_elemento, int nelem, FILE *fp);



*/ 

