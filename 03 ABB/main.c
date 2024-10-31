#include "abb.c"

int main(void){
    TABB * arv = inicializa();
    TABB * arv2 = inicializa();
    TLSE * lista;
    int * vet;
    int t = 0;
    int * tamanho = &t;
    int x;

    scanf("%d", &x);

    while (x != 0)
    {   
        if(x<0){
            switch (x)
            {

            // ENCERRAR
            case 0:
                printf("FIM\n");
                break;
            
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
                arv = liberar(arv);
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
            
            // IMPRIMIR ALTURA DOS NÓS
            case -6:
                impAlt(arv, 0);
                break;
            
            // CRIAR CÓPIA DA ARVORE
            case -7:
                arv2 = copiar(arv);
                break;

            // IMPRIMIR ARVORE 2
            case -8:
                impForm(arv2, 0);
                break;
            
            // IMPRIMIR ARVORE 2
            case -9:
                arv = espelhar(arv);
                break;
            
            case -10:
                scanf("%d", &x);
                vet = mN(arv, x, tamanho);
                impVet(vet, tamanho);
                printf("\n");
                break;
            
            case -11:
                printf("ZZ: %d\n", zz(arv));
                break;
            
            case -12:
                scanf("%d", &x);
                lista = ancestrais(arv, x);
                impLista(lista);
                printf("\n");
                break;

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