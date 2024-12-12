#include "hash.c"

int main(void){
    THASH tabela = ini();
    int x;

    scanf("%d", &x);
    while(x > 0){
        
        add("hash", "arquivo", x);

        scanf("%d", &x);
    }
}