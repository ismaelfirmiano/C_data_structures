#include "heap.h"

// FUNÇÕES AUXILIARES
int pai(int x){
    return x<=0?-1:(x-1)/2;
}
int esq(int x){
    return x*2+1;
}
int dir(int x){
    return x*2+2;
}

// RESTAURA A PROPRIEDADE DE HEAP
void maxheapfy(int * vet, int n, int pos){
    int maior = pos, e, d;
    e = esq(pos);
    d = dir(pos);
    if(e<n & vet[e]>vet[maior])
        maior = e;
    if(d<n & vet[d]>vet[maior])
        maior = d;
    if(maior != pos){
        int tmp = vet[pos];
        vet[pos] = vet[maior];
        vet[maior] = tmp;
        maxheapfy (vet, n, maior);
    }
}

// TRANSFORMA UM VETOR QUALQUER EM HEAP
void buildmaxheap(int * vet, int n){
    int ultpai = pai(n-1);
    for(int i = ultpai; i>=0; i--)
        maxheapfy(vet, n, i);
}

// ORDENA O VETOR (É HEAP E AO MESMO TEMPO ORDENADO)
void heapsort(int *vet, int n){
    buildmaxheap(vet, n);
    int i;
    for(i = n-1; i>0; i--){
        int tmp = vet[0];
        vet[0] = vet[i];
        vet[i] = tmp;
        maxheapfy(vet, i, 0);
    }
}

