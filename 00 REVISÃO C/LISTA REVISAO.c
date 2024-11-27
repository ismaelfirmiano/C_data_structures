#include <stdio.h>

int isPrimo(int x){
    for(int i = 2; i < x; i++)
        if(x%i==0)
            return 0;
    return 1;
}


int mmc(int x, int y){
    int maior = x>y?x:y;
    int menor = x>y?y:x;    
    int valor = menor;
    while ((maior%valor != 0) || (menor%valor != 0))
    {
        valor-=1;
    }
    return valor;
}


int main(void){
    
    int x;
    printf("QUESTÃO 1: IMPRIMIR N PRIMEIROS PRIMOS\n");
    scanf("%d", &x);
    while (x > 0)
    {
    int y = 1;

    while(x > 0){
        while(!isPrimo(y)){
            y++;
        }
        printf("%d ", y);
        y++;
        x--;
    }

    printf("\n");
    scanf("%d", &x);
    }
    
    
    printf("Q2: imprimir N primos depois de N\n");

    scanf("%d", &x);
    while (x > 0)
    {
        int y = x+1;

        while(x > 0){
            while(!isPrimo(y)){
                y++;
            }
            printf("%d ", y);
            y++;
            x--;
        }
    }

    printf("\n");
    scanf("%d", &x);

    
    
    int v[4];

    printf("Q3: horas de sono\n");
    for(int i = 0; i<4; i++){
        scanf(" %d", &v[i]);
    }

    while (v[0] || v[1] || v[2] || v[3])
    {
        int h = v[2]-v[0];
        int m = v[3]-v[1];
        if(h < 0)
            h += 24;
        h *= 60;
        int t = h+m;
        if(t < 0)
            t += 1440;
        printf("%d\n", t);
        for(int i = 0; i<4; i++){
            scanf(" %d", &v[i]);
        }
    }
    
    printf("Q4: MMC\n");
    int n, y;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &x, &y);
        printf("%d\n", mmc(x, y));
    }

    return 0;
}