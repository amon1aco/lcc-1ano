// PI em Abril
// Ficheiro globalmente não executável

#include <stdio.h>
#include <stdlib.h>

/* Strutcters
"struct", armazena diversos dados, relativos à mesma coisa 
strcpy() serve para defenir strings em strutcs, usa-se: strcpy(aluno.nome, "Eduardo")   */

int main(){
    struct ficha_aluno
    {
        char nome[40];
        int numero;
        float nota;
    }; // Defenição da strutc
    
    struct ficha_aluno aluno;
    printf("Digite o nome do aluno: \n");
    fgets(aluno.nome,40,stdin);
    printf("Digite o numero do aluno: \n");
    scanf("%d", &aluno.numero);
    printf("Digite a nota do aluno: \n");
    scanf("%f", &aluno.nota);

    printf("Nome: %s",aluno.nome);
    printf("Numero: %d\n",aluno.numero);
    printf("Nota: %.1f\n",aluno.nota);
}   

// "typedef" redefine um tipo, dá um apelido a um tipo ja existente

// Treino structres
struct student
{
    char name[50];
    int age;
    int number;
    float marks;
};

void print(char name[],int age, int number, float marks){
    printf("%s %d %d %.2f\n",name,age,number,marks);
}

int main(){
    struct student manel = {"manel",20,98989,100.00};
    print(manel.name,manel.age,manel.number,manel.marks);
}   

//
struct point
{
    int x;
    int y;
};

void print(struct point p){
    printf("%d %d \n", p.x,p.y);
}

int main(){
    struct point ponto_cartesiano1 = {1,2};
    struct point ponto_cartesiano2 = {3,5};
    print(ponto_cartesiano1);
    print(ponto_cartesiano2);
    return 0;
}   

//
struct point
{
    int x;
    int y;
};

void print(struct point *p){
    printf("%d %d \n", p -> x, p -> y);
}

int main(){
    struct point ponto_cartesiano1 = {1,2};
    struct point ponto_cartesiano2 = {3,5};
    print(&ponto_cartesiano1);
    print(&ponto_cartesiano2);
    return 0;
}   

//
struct point
{
    int x;
    int y;
};

void print(struct point p){
    printf("%d %d \n", p.x,p.y);
}

struct point edit(struct point p){
    (p.x)++;
    (p.y) += 5;
    return p;
}

int main(){
    struct point ponto_cartesiano1 = {1,2};
    struct point ponto_cartesiano2 = {3,5};
    ponto_cartesiano1 = edit (ponto_cartesiano1);
    ponto_cartesiano2 = edit (ponto_cartesiano2);
    print(ponto_cartesiano1);
    print(ponto_cartesiano2);
    return 0;
}   

//
struct point{
    int x;
    int y;
};

struct point* fun(int a,int b){
    struct point *ptr = (struct point *) malloc(sizeof(struct point));
    // O malloc reserva espaço na memoria, e como sabemos as variaveis locais ao sair da função são esquecidas
    // porém com o malloc a memoria fica reservada e fica guardada. Então como neste caso quero trabalhar
    // com apontadores necessito de um malloc para criar na memoria um espaço fixo dedicado à struct
    ptr->x = a;
    ptr->y = b+5;
    return ptr;
}


void print(struct point *ptr){
    printf("%d %d\n", ptr->x, ptr->y);
}

int main(){
    struct point *ptr1, *ptr2;
    ptr1 = fun(2,3);
    ptr2 = fun(6,9);
    print(ptr1); print(ptr2);
    free(ptr1); free(ptr2); // O free é simplesmente para liberar o espaço reservado na memoria pelo malocc
    return 0;
}   

//
struct point
{
    int x;
    int y;
};

void print(struct point arr[]){
    for(int i = 0; i < 3; i++){
        printf("%d %d\n",arr[i].x,arr[i].y);
    }
}

int main(){
    struct point arr[3] = {{1,2},{2,3},{7,4}};
    print(arr);
    return 0;
}   

// Self referential structures: https://www.youtube.com/watch?v=otu7gJVcwDw


/// BUFFERS
// começando pela limpeza de um buffer
int main(){
    char a,b,c; 

    a = getchar();
    b = getchar();
    c = getchar();

    printf("%c %c %c", a, b, c);// Este programa n funciona pk o buffer armazena o \n e imprimi-o como se fosse o b
    return 0;
} 

//
int main(){
    void limpador(void);
    char a,b,c; 

    a = getchar();
    limpador();
    b = getchar();
    limpador();
    c = getchar();
    limpador();

    printf("%c %c %c\n", a, b, c);
    return 0;
} 

void limpador(void){
    char c;
    while((c = getchar()) != '\n' && c != EOF); // EOF end of file
}   