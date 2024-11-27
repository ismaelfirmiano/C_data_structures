typedef struct ELEMENTO{
    void * info;
    struct ELEMENTO * prox;
}Elemento;

Elemento * inserir(void * e, int t){
    Elemento * novo = malloc(sizeof(Elemento));
    if(t)
    novo->info = e;

}

int main(void)
{
    
    return 0;
}
