#include "TG.c"
#include <limits.h>

int mdk(TG *g, int origem, int destino, int k, int *tam_real_caminho){
  if(k<0)
    return INT_MAX;
  if(origem == destino){
    (*tam_real_caminho) = 0;
    return 0;
  }
  int menor_dis = INT_MAX, dis;
  TG * atual = TG_busca_no(g, origem);

  if(!atual) return INT_MAX; // ESQUECI DE RETORNAR 0, CASO O NÓ NÃO EXISTA O NÓ!!!!

  TVIZ * viz = atual->prim_viz;
  
  while (viz)
  {
    dis = viz->custo + mdk(g, viz->id_viz, destino, k-1, tam_real_caminho);
    if(dis < menor_dis)
      menor_dis = dis;
      printf("Distancia %d %d\n", origem, dis);
    viz = viz->prox_viz; // FALTOU PASSAR PARA O PRÓXIMO VIZINHO
  }
  
  if(menor_dis == INT_MAX)
    *tam_real_caminho = INT_MAX;
  else 
    *tam_real_caminho = (*tam_real_caminho) - k;
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

  int tam_real = k; // NO MEU ALGORÍTMO, O TAM_REAL INICIALIZA COM O K;
  custo = mdk(g, n, m, k, &tam_real);
  printf("no %d alcanca o no %d em %d arestas: %d (%d)\n", n, m, k, custo, tam_real);
  
  TG_libera(g);
  return 0;
}

