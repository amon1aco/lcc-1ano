/* Problema E

O programa deve receber uma linha com uma sequência. A sequência em causa tem no máximo 10000 posições.
E deve imprimir o tamanho da maior subsequência que se lê de igual forma da direita para a esquerda como 
da esquerda para a direita (capicua).

Exemplos: 
    Input: ABCD
    Output: 1

    Input: ABACBBCDEDTTDEDCBBCABA
    Output: 4       */

// if (inverte(x) == x) { /* capicua */ } else { /* não capicua */ }

// usar fgets (lê conjuntos de strings com espaços numa só string) invéz de scanf
// >>fgets(variavel,tamanho,nome do ficheiro q vou ler e como vou ler a linha de comandos por "stdin")

/* Algoritmo: 
        string lenght para saber o tamanho da string 
        2 ciclos -- dividir a string em 2 e verificar se os membros do lado sao iguais, se n forem
salta para o proximo "meio" da lista, se forem adiciona 2 ... */

#include <stdio.h>
#include <string.h> 

int main(){
    int n=10000;
    char string[10000];
    
    if(fgets(string, n, stdin)){
    
    int acc = 1;
    int resultado = 1;
    char centro;
    int i;
    char charAnterior;
    char charPosterior;
    int menos;
    int mais;
    char centroMais;
    char centroMenos;

    int tamanho = strlen(string);


    for(i=1; i<tamanho-2;i++){ // Este for escolhe o centro
        centro = string[i];
        centroMais = string[i+1];
        centroMenos = string[i-1];


                if(centroMenos == centroMais){   // Caso seja do tipo "ABA"
                    resultado = 3;
                    charAnterior = string[i-2];
                    charPosterior = string[i+2];
                    menos = 2; 
                    mais = 2;
                while(charAnterior == charPosterior){  // Enquanto os valores externos forem iguais conta +2 
                    resultado += 2;
                    menos++; 
                    mais++;
                    charAnterior = string[i-menos];
                    charPosterior = string[i+mais];      
            }
        if(acc < resultado) acc = resultado;
        }      


                if(centro == centroMais){ // Caso seja do tipo "ABBA"
                    resultado = 2;
                    charAnterior = string[i-1];
                    charPosterior = string[i+2];
                    menos = 1; 
                    mais = 2;
                while(charAnterior == charPosterior){ // Enquanto os valores externos forem iguais conta +2
                    resultado += 2;
                    menos++; 
                    mais++;
                    charAnterior = string[i-menos];
                    charPosterior = string[i+mais]; 
            }
        if(acc < resultado) acc = resultado;
        } 
    }
    printf("%d\n",acc);
}
}


