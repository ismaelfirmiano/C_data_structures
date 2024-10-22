#include "avl.c"

int main(void){
    TAVL * arv = inicializa();
    int x;

    printf("Adicionar: ");
    scanf("%d", &x);
    while(x > 0){
        arv = ins(arv, x);
        scanf("%d", &x);
    }

    imp_form(arv, 0);

    printf("Remover: ");
    scanf("%d", &x);
    while(x > 0){
        arv = rem(arv, x);
        scanf("%d", &x);
    }

    imp_form(arv, 0);
    
    return 0;
}
