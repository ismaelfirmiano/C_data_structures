#include "grafo.c"

void f(void){
    printf("Função: ");
}

int main(void) {
    TG * grafo = inicializar();

    int x;
    int y;
    scanf("%d", &x);

    while (x != 0)
    {   
        if(x<0){
            switch (x)
            {
            
            // INSERIR UMA ARESTA ORIENTADA
            case -1:
                scanf("%d%d", &x, &y);
                while(x!=0){
                    insArestaOri(grafo, x, y);
                    scanf("%d%d", &x, &y);
                }
                f();
                break;

            // INSERIR UMA ARESTA DOIS SENTIDOS
            case -2:
                scanf("%d%d", &x, &y);
                while(x!=0){
                    insAresta(grafo, x, y);
                    scanf("%d%d", &x, &y);
                }
                f();
                break;
            
            // IMPRIMIR VERTICES
            case -4:
                impNos(grafo);
                f();
                break;
            
            // IMPRIMIR GRAFO COMPLETO
            case -5:
                imp(grafo);
                f();
                break;
            
            default:
                printf("OPÇÃO INVÁLIDA\n");
                f();
                break;
            }
        } else {
            grafo = insNo(grafo, x);
        }
        
        
        scanf("%d", &x);
    }

    
}