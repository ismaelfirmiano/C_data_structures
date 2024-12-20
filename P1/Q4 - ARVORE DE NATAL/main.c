#include "TAB.c"

int teste(TAB * a){
    int folha = -1;

    return testePar(a, &folha, 0);
}

int testePar(TAB * a, int * f, int nivel){
    if (a->esq && a->dir){
        return testeImpar(a->esq, f, nivel+1, 0) && testeImpar(a->dir, f, nivel+1, 1);
    }
    if(a->esq || a->dir)
        return 0;
    
    if(*f == -1)
        *f = nivel;
    else if(*f != nivel)
        return 0;
    return 1;
}

int testeImpar(TAB * a, int *f, int nivel, int lado){
    if(!lado){
        if(!a->esq || a->dir)
            return 0;
        return testePar(a->esq, f, nivel+1);
    }
    if(a->esq || !a->dir)
        return 0;
    return testePar(a->dir, f, nivel+1);
}

int main(void){
    TAB * arvore = inicializa();
    int x;
    scanf("%d", &x);

    while (x>0)
    {
        arvore = ins(arvore, x);
        scanf("%d", &x);
    }

    impForm(arvore, 0);
    
    if(teste(arvore))
        printf("\n[1] é uma arvore de natal\n");
    else
        printf("\n[0] NÃO é uma arvore de natal\n");

    return 0;
}