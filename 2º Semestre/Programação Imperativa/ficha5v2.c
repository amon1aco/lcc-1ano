// ficha 5 -- Structs e ordenacoes

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

#include <stdio.h>
void imprimeAluno (Aluno *a);
int nota (Aluno a);
int procuraNum (int num, Aluno t[], int N);
void ordenaPorNum (Aluno t [], int N);
void swap(Aluno *x, Aluno *y);
void criaIndPorNum(Aluno t [], int N, int ind[]);
void imprimeTurma (int ind[], Aluno t[], int N);


void imprimeAluno (Aluno *a){
    int i;
    printf ("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for(i=1; i<6; i++) printf (", %d", a->miniT[i]);
    printf (") %5.2f %d\n", a->teste, nota(*a));
}

int main() {
    Aluno Turma [7] = {{4444, "André", {2,1,0,2,2,2}, 10.5}
                       ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
                       ,{8888, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{2222, "Joana", {2,0,2,1,0,2},  3.5}
                       ,{7777, "Maria", {2,2,2,2,2,1},  5.5}
                       ,{6666, "Bruna", {2,2,2,1,0,0}, 12.5}
                       ,{5555, "Diogo", {2,2,1,1,1,0},  8.5}
                       } ;
    int indNome [7], indNum [7];
    int i;
    
    for (i=0; i<7; imprimeAluno (Turma + i++));


    int ind[] = {-1,-1,-1,-1,-1,-1,-1};
    criaIndPorNum(Turma, 7, ind);
    for(int k = 0; k < 7; k++) printf("%d ",ind[k]);
    putchar('\n');

    imprimeTurma(ind, Turma, 7);
    
    return 0;
}


int nota (Aluno a){
    int media_minit = 0; int i; int notaf = 0; float teste; float mintfinal = 0; int acc = 0;

    for(i = 0; i < 6; i++){
        media_minit += a.miniT[i];
    }
    acc = media_minit;
    media_minit /= 6;

    media_minit *= 0.3;
    mintfinal = (media_minit * 20) / acc;


    teste = a.teste * 0.7;

    notaf = media_minit + teste;

    return notaf;
}

int procuraNum (int num, Aluno t[], int N){
    int i;
    for(i = 0; i < N; i++){
        if(num == t[i].numero) return i;
    }

    return -1;
}

void ordenaPorNum (Aluno t [], int N){
    int i, maior_numero = t[0].numero, acc = 0;
    Aluno g;

    while(N > 1){
        for(i = 0; i < N; i++){
            if(maior_numero < t[i].numero){ maior_numero = t[i].numero; acc = i; }
        }
        swap(&(t[N-1]), &(t[acc]));
        N--;
        maior_numero = t[0].numero; acc = 0;
    }
}

void swap(Aluno *x, Aluno *y) {
    Aluno t = *x;
    *x = *y;
    *y = t;
}


void criaIndPorNum(Aluno t [], int N, int ind[]){
    int menor = t[0].numero;
    int indice_menor = 0; int j = 0; int i; int control = 0;

    while(j < N){
        for(i = 0; i < N; i++){
            for(int k = 0; k < N; k++){
                if(i == ind[k]) control++;
            }   
            if(control != 0){ control = 0; continue; }
            if(menor > t[i].numero){ menor = t[i].numero; indice_menor = i; }
        }
        ind[j] = indice_menor;
        control = 0;
        j++;
        menor = 10000000; indice_menor = -1;
    }
}

void imprimeTurma (int ind[], Aluno t[], int N){
    int i, aux;
    
    for(i = 0; i < N; i++){
        aux = ind[i];

        printf("%s ",t[aux].nome);
        printf("%d ",t[aux].numero);
        printf("%.2f\n",t[aux].teste);

    }
}