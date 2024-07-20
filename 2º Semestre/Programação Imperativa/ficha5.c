// Ficha 5 -- Structers e Indices
// Ficheiro globalmente não executável

#include <stdio.h>

// --1
typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
}Aluno;

int main(){    
    struct aluno zeca;

    float testefinal;
    int minitestes = 0;
    float notaf;

    zeca.teste = 10.9;
    zeca.miniT[0] = 2;
    zeca.miniT[1] = 1;
    zeca.miniT[2] = 6;
    zeca.miniT[3] = 1;
    zeca.miniT[4] = 1;
    zeca.miniT[5] = 6;
    testefinal = zeca.teste;

    for(int i = 0; i < 6; i++){
        minitestes += zeca.miniT[i];
    }
    
    notaf = (testefinal*0.7) + (minitestes*0.3);

    if(notaf >= 9.5) printf("Passou, %.2f\n",notaf);
    else printf("Ops\n");
}   

// -- 2
typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
}Aluno;

int main(){
    int num = 98320;
    int tamanho = 4;
    Aluno alunos[] = {{98980, "edu", {2,2,6,2,2,6}, 20.0}, {98940, "maria", {2,2,6,2,2,6}, 20.0},
                       {98123, "ze", {2,2,6,2,2,6}, 20.0}, {98320, "tone", {2,2,6,2,2,6}, 20.0}};

    int res = -1;

    for(int i = 0; i < tamanho; i++){
        if(alunos[i].numero == num) res = i;
    }

    printf("%d\n",res);
}   

// -- 3
typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
}Aluno;

void swap(Aluno *x, Aluno *y) {
    Aluno t = *x;
    *x = *y;
    *y = t;
}

void ordenaPorNum(Aluno t[], int N) {
    int i,j;
    for (i = 0; i < N-1; i++) {
        for (j = i+1; j < N; j++) {
            if (t[j].numero < t[i].numero) swap(t+i, t+j);
        }
    }
}

int main(){
    int tamanho = 4;
    Aluno alunos_de_lcc[] = {{98980, "edu", {2,2,6,2,2,6}, 20.0}, {98940, "maria", {2,2,6,2,2,6}, 20.0},
                       {98123, "ze", {2,2,6,2,2,6}, 20.0}, {98320, "tone", {2,2,6,2,2,6}, 20.0}};

    ordenaPorNum(alunos_de_lcc,tamanho);
  
    for(int k = 0; k < tamanho; k++){
        printf("%d ",alunos_de_lcc[k].numero);
    }
    putchar('\n');
}   */

// -- 4
typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
}Aluno;


void criaIndPorNum(Aluno t [], int N, int ind[]){
    int i = 0, ind_max = 0, j = 0;
    int max = t[i].numero;

    while (1){
        for(i = 0; i < N; i++){
            if(t[i].numero > max){
                max = t[i].numero;
                ind_max = i;
            }
        }
        t[ind_max].numero = 0;
        ind[j] = ind_max;
        j++;
        max = 0;
        if(j == N) break;
    }
}

int main(){
    int tamanho = 4;
    Aluno alunos_de_lcc[] = {{98980,"edu", {2,2,6,2,2,6}, 20.0}, {98940, "mar", {2,2,6,2,2,6}, 20.0},
                       {98123, "zec", {2,2,6,2,2,6}, 20.0}, {98320, "ton", {2,2,6,2,2,6}, 20.0}};
    int ind[] = {0,0,0,0};

    criaIndPorNum(alunos_de_lcc,tamanho,ind);
  
    for(int k = 0; k < tamanho; k++){
        printf("%d ",ind[k]);
    }
    putchar('\n');
} */

// -- 5
typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
}Aluno;


void criaIndPorNum(Aluno t [], int N, int ind[]){
    int i = 0, ind_max = 0, j = 0;
    int max = t[i].numero;

    while (1){
        for(i = 0; i < N; i++){
            if(t[i].numero > max){
                max = t[i].numero;
                ind_max = i;
            }
        }
        t[ind_max].numero = 0;
        ind[j] = ind_max;
        j++;
        max = 0;
        if(j == N) break;
    }
}

imprimeTurma (int ind[], Aluno t[], int N){
    int i = 0, max = ind[i], max_ind = 0, controlo = 0;

    while (1){
        for(i = 0; i < N; i++){
            if(ind[i] > max){
                max = ind[i];
                max_ind = i;
            }
        }
        printf("%d %s %.2f\n", t[max_ind].numero, t[max_ind].nome, t[max_ind].teste);
        ind[max_ind] = -1;
        max = -1;
        controlo++;
        if(controlo == N) break;
    }
}

int main(){
    int tamanho = 4;
    Aluno alunos_de_lcc[] = {{98980,"edu", {2,2,6,2,2,6}, 20.0}, {98940, "mar", {2,2,6,2,2,6}, 20.0},
                       {98123, "zec", {2,2,6,2,2,6}, 20.0}, {98320, "ton", {2,2,6,2,2,6}, 20.0}};
    int ind[] = {0,0,0,0};

    criaIndPorNum(alunos_de_lcc,tamanho,ind);
  
    imprimeTurma (ind, alunos_de_lcc, tamanho);
} 

// ta quase porem a funcao que criei para criar o array dos indices esta a eliminar os valores dos numeros
// dos alunos portanto ao imprimir imprime sempre o nr 0


