#include "grafo.c"

void f(void){
    printf("Função: ");
}

void opcoes(void){
    printf("NÚMERO POSITIVO : ADICIONAR VERTICE\n");
    printf("-0 : PARAR O PROGRAMA\n");
    printf("-1 : INSERIR ARESTA ORIENTADA\n");
    printf("-2 : INSERIR ARESTA DOIS SENTIDOS\n");
    printf("-3 : BUSCAR ARESTA\n");
    printf("-4 : IMPRIMIR VÉRTICES\n");
    printf("-5 : IMPRIMIR GRAFO\n");
    printf("-6 : REMOVER ARESTA ORIENTADA\n");
    printf("-7 : REMOVER ARESTA\n");
    printf("-8 : REMOVER NO\n");
}

int main(void) {
    TG * grafo = inicializar();

    opcoes();

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
                scanf(" %d %d", &x, &y);
                while(x!=0){
                    insAresta(grafo, x, y);
                    scanf(" %d %d", &x, &y);
                }
                f();
                break;
            
            // BUSCAR UMA ARESTA
            case -3:
                scanf("%d%d", &x, &y);
                TVIZ * v = busAresta(grafo, x, y);
                if(v)
                    printf("A aresta existe\n");
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
            
            // REMOVER ARESTA ORIENTADA
            case -6:
                scanf("%d%d", &x, &y);
                while(x!=0){
                    remArestaOri(grafo, x, y);
                    scanf("%d%d", &x, &y);
                }
                f();
                break;

            // REMOVER ARESTA NÃO ORIENTADA
            case -7:
                scanf("%d%d", &x, &y);
                while(x!=0){
                    remAresta(grafo, x, y);
                    scanf("%d%d", &x, &y);
                }
                f();
                break;
            
            case -8:
                scanf("%d", &x);
                while(x!=0){
                    remNo(grafo, x);
                    scanf("%d", &x);
                }
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