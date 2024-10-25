#include "grafo.h"

TG * inicializar(void){
    return NULL;
}

TVIZ * libViz(TVIZ * v){
    if(v){
        libViz(v->proxViz);
        free(v);
    }
    return NULL;
}

// LIBERA O GRAFO
TG * lib(TG * g){
    if(g){
        libViz(g->priViz);
        lib(g->proxNo);
        // DEPOIS QUE EXECUTAR OS DOIS CONTINUAR
        free(g);
    }
    return NULL;
}


// IMPRIME VIZINHOS
void impViz(TVIZ * v){
    if(v){
        printf("%d ", v->idViz);
        impViz(v->proxViz);
    }
}

// IMPRIME COMPLETO
void imp(TG * g){
    if(g){
        printf("%d - ", g->idNo);
        impViz(g->priViz);
        printf("\n");
        imp(g->proxNo);
    }
}

// Imprimir Vértices
void impNos(TG * g){
    if(g){
        printf("%d ", g->idNo);
        impNos(g->proxNo);
    } else printf("\n");
}


TVIZ * busViz(TVIZ * v, int y){
    if(!v || (v->idViz == y))
        return v;
    return busViz(v->proxViz, y);
}

TVIZ * busAresta(TG * g, int x, int y){
    TG * no = busNo(g, x);
    if(!no)
        return NULL;
    return busViz(no->priViz, y);
}

// INSERIR VIZ NO INICIO
TVIZ * insViz(TVIZ * v, int x){
    if(!busViz(v, x)){
        TVIZ * novoViz = (TVIZ *)malloc(sizeof(TVIZ));
        novoViz->idViz = x;
        novoViz->proxViz = v;
        return novoViz;
    }
    return NULL;
}

// INSERIR ARESTA ORIENTADA
void insArestaOri(TG * g, int x, int y){
    TG * no = busNo(g, x);
    if(no && busNo(g, y))
        no->priViz = insViz(no->priViz, y);
}

// INSERIR ARESTA
void insAresta(TG * g, int x, int y){
    TG * no1 = busNo(g, x);
    TG * no2 = busNo(g, y);
    if(no1 && no2){
        no1->priViz = insViz(no1->priViz, y);
        no2->priViz = insViz(no2->priViz, x);
    }
        
}

// NÓS DESORDENADOS
TG * busNo(TG * g, int x){
    if(!g || (g->idNo == x))
        return g;
    return busNo(g->proxNo, x);
}

// INSERIR NO INICIO
TG * insNo(TG * g, int x){
    if(!busNo(g, x)){
        TG * aux = g;
        g = (TG *)malloc(sizeof(TG));
        g->idNo = x;
        g->proxNo = aux;
        g->priViz = NULL;
    }
    return g;
}

/* BUSCAR NÓS ORDENADOS
TG * busNo(TG * g, int x){
    if(g){
        if(g->idNo == x)
            return g;
        if(g->idNo < x)
            return busNo(g->proxNo);
    }
    return NULL;
} */

