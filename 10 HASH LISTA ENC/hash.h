#define TAM_TAB_HASH 101

typedef struct aluno{
    int mat;
    float cr;
    struct aluno * prox;
}TA;

typedef TA * THASH[TAM_TAB_HASH];

