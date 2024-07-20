// Problema D versão Totalmente autónoma com cotação de 90 pontos

#include <stdio.h>
#include <math.h>
#include <stdbool.h>


int contatriangulares (int z[],int w);
int contaprimos (int z[],int w);

// Recebe uma linha com dois valores inteiros separados por espaço e imprime uma linha 
// com a quantidade de numeros triangulares e a quantidade de primos separados por um espaço

int main(){
    int x, y, i, acc;
    if(scanf("%d %d", &x, &y) == 2){
        acc = x;
        int z[(y-x+1)];
        for(i = 0; i <= (y-x); i++){
            z[i] = acc;
            acc++;
        }
        printf("%d %d\n",contatriangulares (z,(y-x+1)),contaprimos (z,(y-x+1)));   
    }       
return 0;
}     

// Conta nrs triangulares n==(n*(n+1))/2, mas esta forma não é otimizada não vai passar nos testes todos

int contatriangulares (int z[],int w){
    int j, acc = 0, valor;
    float flt;
    int in; 
        for(j = 0; j < w; j++){
            valor = z[j];
            flt = sqrt(8 * valor + 1);
            in = sqrt(8 * valor + 1);
            if(flt-in == 0) acc++;
        }
  //  printf("%d ",acc);
return acc;
}

// Conta nrs primos 

int contaprimos (int z[],int w){
    int k, l, valor2, primo = 0, acc2;
    for (k = 0; k < w ; k++){
        valor2 = z[k];
        acc2 = 0;
            for(l = 2; l <= sqrt(valor2); l++){
                if(valor2 % l == 0) acc2++;
                }    
        if(acc2 == 0 && valor2 != 1) primo++;
    }
  //  printf("%d\n",primo);
return primo;
}