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
        printf(" [%d - %d]", v->idViz, v->peso);
        impViz(v->proxViz);
    }
}

// IMPRIME COMPLETO
void imp(TG * g){
    if(g){
        printf("%d ->", g->idNo);
        impViz(g->priViz);
        printf("\n");
        imp(g->proxNo);
    }
}

// IMPRIMIR VÉRTICES
void impNos(TG * g){
    if(g){
        printf("%d ", g->idNo);
        impNos(g->proxNo);
    } else printf("\n");
}

// BUSCAR VIZINHO
TVIZ * busViz(TVIZ * v, int y){
    if(!v || (v->idViz == y))
        return v;
    return busViz(v->proxViz, y);
}

// BUSCAR ARESTA
TVIZ * busAresta(TG * g, int x, int y){
    TG * no = busNo(g, x);
    if(!no)
        return NULL;
    return busViz(no->priViz, y);
}

// INSERIR VIZ NO INICIO
TVIZ * insViz(TVIZ * v, int x, int p){
    if(!busViz(v, x)){
        TVIZ * novoViz = (TVIZ *)malloc(sizeof(TVIZ));
        novoViz->idViz = x;
        novoViz->proxViz = v;
        novoViz->peso = p;
        return novoViz;
    }
    return NULL;
}

// INSERIR ARESTA ORIENTADA
void insArestaOri(TG * g, int x, int y, int p){
    TG * no = busNo(g, x);
    if(no && busNo(g, y))
        no->priViz = insViz(no->priViz, y, p);
}

// INSERIR ARESTA NÃO ORIENTADA
void insAresta(TG * g, int x, int y, int p){
    TG * no1 = busNo(g, x);
    TG * no2 = busNo(g, y);
    if(no1 && no2){
        no1->priViz = insViz(no1->priViz, y, p);
        no2->priViz = insViz(no2->priViz, x, p);
    }
        
}

TVIZ * remViz(TVIZ * v, int x){
    if(v){
        if(v->idViz == x){
            TVIZ * aux = v->proxViz;
            free(v);
            return aux;
        }
        v->proxViz = remViz(v->proxViz, x);
    }
    return v;
}

// REMOVER ARESTA
void remArestaOri(TG * g, int x, int y){
    TG * no = busNo(g, x);
    if(no)
        remViz(no->priViz, y);
}

// REMOVER ARESTA NÃO ORIENTADA
void remAresta(TG * g, int x, int y){
    remArestaOri(g, x, y);
    remArestaOri(g, y, x);
}

// REMOVER NÓ
TG * remNo(TG * no, int x){
    if(no){
        if (no->idNo == x) {
            libViz(no->priViz);
            TG * aux = no;
            no = no->proxNo;
            free(aux);
            if(no)
                remViz(no->priViz, x);
        }
        if(no && no->idNo != x){
            no->priViz = remViz(no->priViz, x);
            no->proxNo = remNo(no->proxNo, x);
        }
    }
    return no;
}

// BUSCAR NÓ
TG * busNo(TG * g, int x){
    if(!g || (g->idNo == x))
        return g;
    return busNo(g->proxNo, x);
}

// INSERIR NO NO INICIO
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