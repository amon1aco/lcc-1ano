/* A mooshak */

/* Recebe 2 valores, e responde o quadrado do maior ou caso sejam iguais responde "IGUAIS" */

#include <stdio.h>

int main(){
    int a,b;
    if(scanf("%d %d",&a,&b) == 2){
        if(a < b){
            printf("%d\n", b*b);
        }
        else if(a > b){
            printf("%d\n", a*a);
        }
        else{
            printf("IGUAIS\n");
        }
    } 
return 0;
}
