#include "arvore.c"

int main(void)
{
    int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TAB *arvore = vet2ab(vet, 0, 10);
    imp(arvore, 0);
}