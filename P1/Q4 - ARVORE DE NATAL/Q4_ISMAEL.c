#include <string.h>
#include "TAB.c"

int testeImpar(TAB * a, int *f, int nivel, int lado){
  if(!lado){
    if(!a->esq || a->dir)
      return 0;
    return testePar(a->esq, f, nivel+1);
  }
  if(a->esq || !a->dir)
    return 0;
  return testePar(a->dir, f, nivel+1);
}


int testePar(TAB * a, int * f, int nivel){
  if (a->esq && a->dir){
    return testeImpar(a->esq, f, nivel+1, 0) && testeImpar(a->dir, f, nivel+1, 1);
  }
  if(a->esq || a->dir)
    return 0;
  
  if(*f == -1)
    *f = nivel;
  else if(*f != nivel)
    return 0;
  return 1;
}


int teste(TAB * a){
  if(!a)
    return 0;
  int folha = -1;

  return testePar(a, &folha, 0);
}


int main(void){
  int no, pai;
  printf("Digite a raiz da arvore... ");
  scanf("%d", &no);
  TAB *a = TAB_cria(no, NULL, NULL), *resp;
  char repete;
  do{
    char lado[2];
    printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);
    if((repete == 'N') || (repete == 'n')) break;
    printf("Digite o pai (que deve existir), o filho a ser inserido e a posição E(ESQ) ou D(DIR)... ");
    scanf("%d%d%s", &pai, &no, lado);
    resp = TAB_busca(a, pai);
    if(!resp){
      TAB_libera(a);
      return 0;
    }
    if(strcmp(lado, "E") == 0) resp->esq = TAB_cria(no, NULL, NULL);
    else resp->dir = TAB_cria(no, NULL, NULL);
  }while(1);
  TAB_imp_ident(a);
  printf("\n");
  
  printf("Segue o padrao? %d\n", teste(a));
  TAB_libera(a);
  return 0;
}
