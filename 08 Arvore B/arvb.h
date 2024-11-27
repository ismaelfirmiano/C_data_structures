#include <stdio.h>
#include <stdlib.h>

typedef struct arvb {
    int nchaves;
    int folha;
    int * chaves;
    struct arvb ** filhos;
} TARVB;

TARVB * inicializa();
TARVB * cria(int t);
TARVB * bus(TARVB * no, int x);
TARVB * ins(TARVB * no, int x);
TARVB * rem(TARVB * no, int x);
void lib(TARVB * no);