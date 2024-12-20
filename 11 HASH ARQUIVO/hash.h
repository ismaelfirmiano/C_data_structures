#include <stdio.h>
#include <stdlib.h>

#define TAM_TAB_HASH 10

typedef struct aluno{
    int mat;
    float cr;
    struct aluno * prox;
}TA;

typedef int * THASH[TAM_TAB_HASH];

void add(char * hash, char * arquivo, int x);