// Problema D

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

signed long long valorMax = 33554432;
static bool primos [33554432];

int contatriangulares (int x,int y);
int contaprimos (int x, int y);

// Recebe uma linha com dois valores inteiros separados por espaço e imprime uma linha
// com a quantidade de numeros triangulares e a quantidade de primos separados por um espaço

int main(){
    int i,j;
    //preenche a array com numeros, se primos[n] == true entao n é primo
    int raiz = sqrt (valorMax)+1;

    for (i=2; i<=valorMax; i++) {
        primos[i] = true;
    }

    for (i=2; i<=raiz; i++) {
        if (primos[i] == true) {
            for (j= i + i; j<=valorMax; j += i) {
                primos[j] = false;
            }
        }
    }

    int x, y;
    if(scanf("%d %d", &x, &y) == 2){
    printf("%d %d\n", contatriangulares(x,y), contaprimos(x,y));
    }
    return 0;
}

// Se a raiz de 8*n + 1 for raiz perfeita, significa que n é triangular
// Verificamos que é perfeita através de fvar == (int)fvar, pois isso só dá true se nao tiver nenhuma virgula, ou seja, se for um int

int contatriangulares (int x,int y){
    int triangulares = 0;
    int i;
    double fvar;
    for (i = x; i <= y; i++) {
        fvar = sqrt(8*i + 1);
        if (fvar == (int)fvar)
            triangulares++;
    }
    return triangulares;
}

// Conta nrs primos

int contaprimos (int x, int y){
    int primo = 0;
    int i;
    for (i = x; i <= y; i++) {
        if (primos[i] == true)
            primo++;
    }
    return primo;
}