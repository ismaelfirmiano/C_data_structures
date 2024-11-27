#include "avl.c"

int main(void){
    TAVL * arv = inicializa();
    int x;

    menu();
    scanf("%d", &x);

    while (x != 0)
    {   
        if(x<=0){
            switch (x)
            {
            
            // REMOVER UM ELEMENTO
            case -1:
                scanf("%d", &x);
                arv = rem(arv, x);
                break;
            
            // REMOVER VÁRIOS ELEMENTOS
            case -2:
                scanf("%d", &x);
                while(x > 0){
                    arv = rem(arv, x);
                    scanf("%d", &x);
                }
                break;
            
            // LIBERAR ARVORE
            case -3:
                //arv = liberar(arv);
                break;
            
            // IMPRIMIR ARVORE
            case -5:
                impForm(arv, 0);
                break;
            
            // IMPRIMIR ELEMENTOS
            case -4:
                imp(arv);
                printf("\n");
                break;
            
            // COPIAR ARV
            case -6:
                impAlt(arv, 0);
                break;
            
            /*
            case -7:
                impFB(arv, 0);
                break;
            
            */
           
            default:
                printf("OPÇÃO INVÁLIDA");
                break;
            }
        } else {
            arv = ins(arv, x);
        }
        scanf("%d", &x);
    }
    

    return 0;
}