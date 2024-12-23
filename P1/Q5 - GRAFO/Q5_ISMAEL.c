#include "TG.c"
#include <limits.h>

int mdk(TG *g, int origem, int destino, int k, int *tam_real_caminho) {
  if (k < 0) 
    return INT_MAX;

  if (origem == destino) {
    *tam_real_caminho = 0;
    return 0;
  }

  TG *atual = TG_busca_no(g, origem);
  if (!atual)
    return INT_MAX;

  TVIZ *viz = atual->prim_viz;
  int menor_dis = INT_MAX;

  while (viz) {
    int tamanho_parcial = 0;

    // INICIALIZO O DIS COM O RETORNO
    int dis = mdk(g, viz->id_viz, destino, k - 1, &tamanho_parcial);

    // TRATO CASO SEJA DIFERENTE DE INT_MAX
    if (dis != INT_MAX && dis + viz->custo < menor_dis) {
      menor_dis = dis + viz->custo;
      *tam_real_caminho = tamanho_parcial + 1;
    }

    // FALTOU AVANÇAR O VIZINHO
    viz = viz->prox_viz;
  }

  if (menor_dis == INT_MAX) {
    *tam_real_caminho = INT_MAX;
  }

  return menor_dis;
}

int main(void){
  TG *g = TG_inicializa();
  int n;
  do{
    scanf("%d", &n);
    if(n <= 0) break;
    g = TG_ins_no(g, n);
  }while(1);
  
  int m, custo;
  do{
    scanf("%d%d%d", &n, &m, &custo);
    if((n <= 0) || (m <= 0)) break;
    TG_ins_aresta(g, n, m, custo);
  }while(1);
  TG_imprime(g);
  
  int k;
  scanf("%d%d%d", &n, &m, &k);

  int tam_real = 0;
  custo = mdk(g, n, m, k, &tam_real);
  printf("no %d alcanca o no %d em %d arestas: %d (%d)\n", n, m, k, custo, tam_real);
  
  TG_libera(g);
  return 0;
}

