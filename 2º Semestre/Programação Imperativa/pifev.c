/* Programações de fevereiro, Introdução á linguagem C */
// Ficheiro globalmente não executável.

/* As linguagens imperativas (Como o C) basicamente "dizem como se faz" e as declarativas "dizem o que faz" 
Em haskell via-se o tipo (x :: int), em C é (int x), C tem varios tipos mas não tem em concreto os bools, porque
consideram tudo um bool.
O bloco "main" é sempre executado
Quando o "main" retorna 0 quer dizer que correu tudo bem
Temos de dar include stdio.h, sendo o stdio.h um ficheiro que tem várias defenições como o tipo do "printf"
*/

#include <stdio.h> 

int main () {
printf ("Hello \n");
return 0;
}
//
#include <stdio.h> 

int main () {
printf ("Ab %d cD %f \n",7,4.0);
return 0;
}
//
#include <stdio.h>
int main () {
int x = 42;
x = x + 4; 
printf ("%d\n",x);
}
//A função funciona perfeitamente porque o "=" simboliza uma atribuição e n uma equação" 


#include <stdio.h> 
int main () {
int x = 74;
if (x > 10) x = x * 5; 
else x = x + 5;
printf("%d\n",x);
}

/* A função scanf funciona como o input do python, basicamente ao contrário do print que escreve no ecrâ
a função scan lê o que escrevemos no ecrâ */

/* Programa que lê 2 inteiros e escreve o maior dos dois */

#include <stdio.h> 
int main () {
int x, y;
scanf ("%d",&x);
scanf ("%d",&y);
if (x > y ) printf ("%d\n",x);
else printf ("%d\n",y);
return 0;
}


/* Programa que lê 2 inteiros e escreve todos os numeros entre os mesmos */

#include <stdio.h>
void imprime (int a,int b);
main(){
int a,b;
printf("Digite dois valores: \n");
scanf ("%d",&a);
scanf ("%d",&b);
if (b>a) imprime (a,b);
else imprime (b,a);
return 0;
}

void imprime (int a,int b) {
int n;
n = a; 
printf("Aqui estão os numeros entre os valores que digitou: \n");
while (n <= b){
    printf ("%d, ",n);
    n=n+1;
   }
printf("\n");
}


/* No modelo de memória utilizada pelos computadores, os argumentos que o main recebe estão no topo da hierarquia
e não podem ser alterados por funções, cada vez que uma função é chamada é criado um subespaço abaixo de memoria 
com os novos valores gerados, isto é importante de entender para saber como criar programas mais eficientes e leves
em termos de memória */

/* Construtores repetitivos: 
- while condição comando // enquanto a condição se aplicar executa-se o comando
- for (init, condição, inc) comando // o init é executado e caso a condição seja verdadeira aplica-se o comando,
seguidamente o inc e volta de novo para a condição em loop.

Exemplo anterior com "for": */

#include <stdio.h>
void imprime (int a,int b);
main(){
int a,b;
printf("Digite dois valores: \n");
scanf ("%d",&a);
scanf ("%d",&b);
if (b>a) imprime (a,b);
else imprime (b,a);
return 0;
}

void imprime (int a, int b) {
int n;
printf("Aqui estão os numeros entre os valores que digitou: ");
for (n=a; n <= b; n=n+1){
    printf("%d ,",n);
  }
printf("\n");
}


/* Também é possivel criar uma função recursiva para resolver o mesmo problema, sem utilizar ciclos-fortes
porém as funções recursivas são muito pouco eficientes e gastam muita memoria devido ao inumero sub-espaços de
memória criados para guardar os valores novos das variaveis. 
Assim seria a função recursivamente: 

(...)
if (x>y) printf("\n")
else { printf("%d",x);
    imprime (x+1,y);
    }
*/

/* Programa que recebe um número e digita no ecrâ os seus divisores primos */

#include <stdio.h> 

int main() {
  int x;
  scanf("%d",&x);
  aux(x);
  return 0;
}

void aux(int x){
  int d;
  d = 2;
  while (x!=1){
    if (x%d == 0){
      printf("%d",d);
      x = x/d;
    }
    else d+=1;
  } 
  printf("\n");
}

input: 200  
output: 22255   

/* Agora o mesmo exercicio mas com o seguinte output: 2^3 5^2 */
#include <stdio.h> 

int main() {
  int x;
  scanf("%d",&x);
  aux(x);
  return 0;
} */

void aux(int x){
  int d=2;
  int conta; 
  while(x!=1){
    conta = 0;
    while(x%d==0){
      conta += 1;
      x /= d; 
    }
  if(conta != 0)
  printf("%d^%d ",d,conta);
  d += 1;
  }
} 

// A mesma coisa mas com "for"
void aux(int x){
  int d, conta; 
  for (d=2; x!=1; d += 1){ 
    for (conta = 0; x%d == 0; conta += 1)
    x /= d;
    if (conta > 1)
    printf("%d^%d ",d,conta);
    if (conta == 1)
    printf("%d ",d);
  }
}   
