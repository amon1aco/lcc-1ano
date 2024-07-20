// Ficha 3 Programação Imperativa
// Ficheiro globalmente não executável

#include <stdio.h>

// -- 1 a)
Considerando que: 
        y = x - pos na memória de x[0]
        z = x+3 - pos na memória de x[3]

Output: 
1 1 4
2 2 6
3 3 8
4 4 10
5 5 12     

// -- 1 b)
i = 3; j = 5
a = 3; b = 5 (Valores guardados no endereço de memória 42)
i = 4
j = 4 + 5 = 9
b = 4 (porque o i agora é 4)
j = 4 + 9 = 13

Output: 13  

// -- 2
int main(){
    int x = 3, y = 5;
swapM (&x, &y);
printf ("%d %d\n", x, y);
}

void swapM (int *x, int *y){
    int aux;
    aux = *y;
    *y = *x;
    *x = aux;
}   

// -- 4
int main(){
    int v[]={14,23,3,4,5};
    int i,acc=0,n=5; 
    for(i=0;i<n;i++){
        acc += v[i];
    }
    printf("%d\n",acc);
}   

// -- 7 
int main(){
    int v[8]; int n = 8;
    int i, d = 0;
   //   for(i=0;i<n;i++){         Minha versão
   //       v[i] = d*d;
   //       d++;
   //   }
    v[0] = 0;
    for (i=0; i<n-1;i++){
        v[i+1] = v[i] + 2*i+1; // Versão pedida
        }   
    for(i=0;i<n;i++){
        printf("%d ",v[i]);
    }
    putchar('\n');
}   

// -- 8 a)          Por fazer
int main(){
    int v[3];
    int p = 1; int i; int recebe = 3;
    for(i = 0; i < recebe; i++){
   //   v[0] = 1;
   //   v[i] = 2*v[i-1];            Aqui a parte geradora tá complicada!
   //   v[(recebe-1)] = 1;  
    }
    for(i = 0; i < recebe; i++){
        printf("%d ",v[i]);
    }
    putchar('\n');
}   


