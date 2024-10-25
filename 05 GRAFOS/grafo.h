#include <stdio.h>
#include <stdlib.h>

typedef struct viz{
    int idViz;
    struct viz * proxViz;
}TVIZ;

typedef struct no{
    int idNo;
    TVIZ * priViz;
    struct no *proxNo;
}TG;

TG * inicializar(); // OK
TG * liberar(TG * g);
void impNos(TG * g); // OK
void imp(TG * g); // OK
TG * busNo(TG * g, int x); // OK
TVIZ * busAresta(TG * g, int x, int y); // OK
TVIZ * busViz(TVIZ * g, int y); // OK
TG * insNo(TG * g, int x); // OK
void insAresta(TG * g, int x, int y); // OK
TVIZ * insViz(TVIZ * g, int x); // OK

/*
TG * remNo(TG * g);
void remAresta(TG * g);
TVIZ * remViz(TG * g);
*/