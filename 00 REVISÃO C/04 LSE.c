#include <stdio.h>
#include <stdlib.h>

//LISTA SIMPLESMENTE ENCADEADA

typedef struct No{
    int num;
    struct No * prox;
}NO;

NO * insIni (NO * no, int x){
    NO * novo = (NO *)malloc(sizeof(NO));
    novo->num = x;
    novo->prox = no;
    return novo;
}

NO * insOrd (NO * no, int x){
    
}

NO * insFim (NO * no, int x){
    if(!no)
        return insIni(no, x);
    no->prox = insFim(no->prox, x);
    return no;
}

void imp(NO * no){
    if(!no)
        printf("FIM\n");
    printf("%d ", no->num);
    imp(no->prox);
}

int main(void){
    NO * l1 = NULL;
    NO * l2 = NULL;
    NO * l3 = NULL;
    int x;
    scanf("%d", &x);
    while(x > 0){
        l1 = insIni(l1, x);
        //l2 = insOrd(l2, x);
        l3 = insFim(l3, x);
        scanf("%d", &x);
    }

    imp(l1);
    //imp(l2);
    imp(l3);

    return 0;
}
