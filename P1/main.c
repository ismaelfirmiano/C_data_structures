#include "grafo.c"

int mdk(TG * g, int origem, int destino, int k, int * tam_caminho){
    if(!g || k < -1)
        return 999;
    
    
}


int main(void){
    TG * grafo = inicializar();
    int x, y, p;

    int * caminho = (int*)malloc(sizeof(int));

    scanf("%d", &x);
    while(x!= 0){
        if(x > 0)
            grafo = insNo(grafo, x);
        
        else
            switch(x){
                case -1:
                    scanf("%d", &x);
                    grafo = remNo(grafo, x);
                    break;
                case -2:
                    scanf("%d%d%d", &x, &y, &p);
                    insArestaOri(grafo, x, y, p);
                    break;
                
                case -3:
                    scanf("%d%d%d", &x, &y, &p);
                    p = mdk(grafo, x, y, p, caminho);
                    printf("O menor caminho é %d, passando por %d nós.\n", p, *caminho);
                    break;
                
                case -5:
                    imp(grafo);
                    break;
            }
        scanf("%d", &x);
    }

    return 0;
}