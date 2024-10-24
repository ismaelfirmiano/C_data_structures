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

TG * inicializar();
TG * liberar(TG * g);
void imp(TG * g);
TG * busNo(TG * g, int x);
TVIZ * busViz(TG * g, inx x, int y);
TG * insNo(TG * g);
TG * insViz(TG * g);
TG * remNo(TG * g);
TG * remViz(TG * g);
