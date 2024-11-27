#include <stdio.h>
int main(void){
    
    for(int a = -1; a != 0; a = a<<1)
        printf("%d\n", a);
    return 0;
}