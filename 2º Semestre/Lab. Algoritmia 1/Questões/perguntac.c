// Pergunta C

/* Recebe 3 valores (menores que 2^31 = 2147483648) e imprima a lista ordenada de forma crescente
se o maior valor não for um número fatorial, ou caso contrário imprima FATORIAL. */

/* Primeiro uma função que ordene os 3 digitos recebidos, seguidamente uma que verifique se o ultimo digito 
é fatorial, caso seja printa "FATORIAL", caso não seja retorna a lista ordenada */

#include <stdio.h>

int vfatorial (int x);
int maior(int x,int y,int z);
int ordena(int x,int y,int z);

// Função que verifica se os valores são fatoriais
int vfatorial (int x) {
    int i,f = 1;
    for(i=1;f<x;i++){
        f = f * i;
    }
    if (x==f) {return 2;}
    else {return 1;}
return 0;
}

// Função main

int main(){
    int x,y,z;
    if (scanf("%d %d %d",&x,&y,&z) == 3){
        if (vfatorial(maior(x,y,z)) == 2)
            {
            printf("FATORIAL\n");
            }
        else 
            {
            ordena (x,y,z);
            }
    }
    return 0;
}

// Função que dos 3 valores pega no maior

int maior(int x,int y,int z) {
    int m; 
    if (x > y && x > z && y > z) 
    m = x;
    else if (x < y && x > z)
    m = y;
    else if (x < y && x < z && y > z)
    m = y;
    else if (x < y && x < z && y < z)
    m = z;
    else if (x > y && x < z)
    m = z;
    else m = x;
    return m;
}

// Função que ordena os 3 digitos recebidos caso nenhum seja fatorial

int ordena(int x,int y,int z){
    if (x > y && x > z && y > z) 
    printf("%d %d %d\n",z,y,x);
    else if (x < y && x > z)
    printf("%d %d %d\n",z,x,y);
    else if (x < y && x < z && y > z)
    printf("%d %d %d\n",x,z,y);
    else if (x < y && x < z && y < z)
    printf("%d %d %d\n",x,y,z);
    else if (x > y && x < z)
    printf("%d %d %d\n",y,x,z);
    else printf("%d %d %d\n",y,z,x);
return 0;
}