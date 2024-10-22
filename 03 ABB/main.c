#include "abb.c"

int main(void){
    TABB * arv = inicializa();
    int x;

    scanf("%d", &x);

    while (x != -9)
    {   
        if(x < 0){
            switch (x)
            {
            
            // IMPRIMIR ELEMENTOS
            case -1:
                imp(arv);
                break;

            // IMPRIMIR ARVORE
            case -2:
                imp_form(arv, 0);
                break;
            
            // REMOVER ELEMENTO
            case -3:
                scanf("%d", &x);
                arv = rem(arv, x);
                break;
            
            // IMPRIMIR ALTURA DOS NÓS
            case -4:
                alt(arv, 0);
                break;
            
            default:
                printf("OPÇÃO INVÁLIDA");
                break;
            }
        }
        arv = ins(arv, x);
        scanf("%d", &x);
    }

    imp_form(arv, 0);
    

    return 0;
}