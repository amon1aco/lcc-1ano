/* Antes da aula, escrever um programa que leia um inteiro 
(usando o scanf)  e imprima o seu quadrado (usando o printf) */

#import <stdio.h>

int main(){
int x,q;
printf("Digite um valor: \n");
scanf("%d",&x);
q = x * x;
printf("%d \n",q);
}