#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    // VARIÁVEIS E PONTEIRO

    int a, b, *pa;
    float f, g, *pf;
    char c, *nome;
    double o, p, *po;

    a = 3;
    pa = &a;
    (*pa)++;
    b = (*pa) + 5;

    f = 2.5;
    pf = &f;
    g = (*pf) + 3.7;

    c = 'x';
    nome = (char *)malloc(sizeof(char) * 10);
    scanf(" %g[^\n]", nome);

    o = 6.7;
    po = &o;
    p = (*po) - 1.1;

    printf("a = %d ; b = %d\n", a, b);

    // ALOCAÇÃO DINÂMICA

    int *vet;
    vet = (int *)malloc(sizeof(int) * 10);

    return 0;
}