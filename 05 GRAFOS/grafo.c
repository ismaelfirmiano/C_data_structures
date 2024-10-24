#include "grafo.h"

TG * inicializar(void)
    return NULL;

void impViz(TVIZ * v){
    if(v){
        printf("%d ", v->idViz);
        impViz(v->proxViz);
    }
}

void imp(TG * g){
    if(g){
        printf("%d - ", g->idNo);
        impViz(g->priViz);
        printf("\n");
        imp(g->proxNo);
    }
}



TVIZ * busViz(TVIZ * v, int y){
    if(!v || (v->idViz == y))
        return v;
    return busViz(v->proxViz);
}

TG * busAresta(TG * g, int x, int y){
    TG * no = busNo(g, x);
    if(!no)
        return NULL;
    return busViz(no->priViz, y);
}

// LISTA DE NÓS DESORDENADOS
TG * busNo(TG * g, int x){
    if(!g || (g->idNo == x))
        return g;
    return busNo(g->proxNo)
}

/* CONSIDERANDO LISTA DE NÓS ORDENADOS
TG * busNo(TG * g, int x){
    if(g){
        if(g->idNo == x)
            return g;
        if(g->idNo < x)
            return busNo(g->proxNo);
    }
    return NULL;
} */

