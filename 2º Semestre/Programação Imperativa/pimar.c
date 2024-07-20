// Porgramação Imperativa de Março
// Ficheiro globalmente não executável

#include <stdio.h>

/* Aritemetica de endereços: 
    a[i] = *(a+i)
*/

// Função que calcula o minimo de um array 
int main (){
    int v[] = {4,6,3,2,9,1};
    int i,m = v[0];
    for (i=1;i<7;i++){
        if(v[i]<m) m = v[i];
    }
    printf("O menor valor da lista é %d.\n",m);
    return m;
}

// Questão das 50q
int main(){
    int v[] = {3,6,1,3,6};
    int i, m = 0;
    for(i=1;i<5;i++){
        if (v[i]<v[m])m = i;
    }
    printf("A posição do menor valor é %d\n",m);
    return 0;
} 

// Função que procura um valor na lista e se o encontrar retorna o seu indice, se não o encontra
// returna -1;

int procura (int x,int v[],int n);

int main(){
    int v[]={1,2,4,5,63};
    int x = 63, n = 5;
    printf("%d\n",procura(x,v,n));
    return 0;
}

int procura (int x,int v[],int n){
    int i;
    for(i=0;i<n;i++){
        if(v[i]==x)return i;
    }
    return (-1);
} 

// Versões com returns mais "disciplinados"

int procura (int x,int v[],int n);

int main(){
    int v[]={1,2,4,5,63};
    int x = 63, n = 5;
    printf("%d\n",procura(x,v,n));
    return 0;
}

int procura (int x,int v[],int n){
    int i;
    for(i=0;i<n;i++){
        if(v[i]==x)break;
    }
    if(i==n) return (-1);
    else return i;
} 

// Função que gera um array e procura um elemento do array
/* O comando "#define" cria uma constante, o mesmo acontece se "const int", constantes são valores que
ao longo do programa mantém sempre o mesmo valor e não pode ser alterado */

#define MAX 300

int main(){
    int v[MAX], i;
    for(i=0;i<MAX;i++){
        v[i]=3*i;
    }
    printf("%d\n",procura(40,v+10,MAX));
    printf("%d\n",procura(141,v+10,40));
    return 0;
}

int procura (int x,int v[],int n){
    int i;
    for(i=0;i<n;i++){
        if(v[i]==x)break;
    }
    if(i==n) return (-1);
    else return i;
} 

// Mais uma função procura, mas desta vez toda marada

int main (){
    int v[]={1,2,4,5,63};
    int x = 63, N = 5;
    procuraBR(x,v,0,N-1);
    return 0;
}

int procuraBR(int x, int v[], int inf, int sup){
    int r = -1, n,m;
    if(inf <= sup){
        m = (inf + sup)/2;
            if(v[m]==x) r = m;
            else if (v[m]>x) r = procuraBR(x,v,inf,m-1);
                else r = procuraBR(x,v,m+1,sup);
    }
    printf("%d\n",r);
    return r;
} 
/* Basicamente esta função recebe um valor a procurar, um array, um minimo e um maximo e se o valor
do meio do array n for o valor desejado então volta a executar a função na metade superior ou inferior
dependendo do valor a procurar (Porém esta me a imprimir 3 digitos não sei porquê) */


int main(){
    int x = 8,v[]={1,3,4,5,7,8,9}, n = 7;
    int inf = 0, sup = n-1, m, r = -1;
    while(inf <= sup && r == -1){
        m = (inf + sup)/2;
    if (v[m] == x) r = m;
    else if (v[m]>x) sup = m-1;
    else inf = m+1;
    }
    printf("%d\n",r);
    return r;
}   

// Funções que ordenam arrays, este algoritmo usa um insere e vai inserindo um valor numa lista ordenada
// como a lista de origem não está ordenada primeiro insere numa lista só com 1 valor e vai aumentando sucessivamente

int main(){
    int v[]={6,33,41,5,17,28,9}, n = 7;
    int i,j; 
    for(i=1; i<n; i++){
        insere(v[i],v,i);
    }
    for(j=0; j<n; j++) printf("%d ",v[j]);
    putchar('\n');
}

void insere (int x, int v[], int n){
    int i = n-1;
    while(i >= 0 && v[i] > x){
        v[i+1] = v[i];
        i--;
    }
    v[i+1] = x;
}   

// Outro algarismo de ordenação,  este algarismo basicamente pega no máximo e coloca o no fim da lista e 
// vai sucessivamente colocando o maximo numa porção da lista mais pequena

int maxInd(int v[],int n){
    int i; r = 0;
    for(i=1; i < n; i++)
        if(v[i]>v[r]) v = i;
        return r;
}

int main (){
    int v[]={6,33,41,5,17,28,9}, n = 7;
    int i,m;
    for(i=n;i>1;i--){
        m = maxInd(v,i);
        swap(v,m,i-1);
    }
    for(j=0; j<n; j++) printf("%d ",v[j]);
    putchar('\n');
}

void swap(int v[],int m,int i){
    int acc;
    acc = v[m];
    v[m] = v[i];
    v[i] = acc;
}   

// Outro algoritmo de ordenação "Bubble", esta forma basicamente troca o membro anterior com o posterior se
// este foi menor e faz isso até a lista estar ordenada

void swap(int v[],int m,int i){
    int acc;
    acc = v[m];
    v[m] = v[i];
    v[i] = acc;
}  

int bubble (int v[], int n){
    int i;
    for(i=1;i<n;i++)
        if(v[i-1]>v[i])
            swap(v,i,i-1);
}

int main (){
    int v[]={6,33,41,5,17,28,9}, n = 7;
    int i,j; 
    for(i = 0; i < n-1; i++) bubble (v,n-i);
    for(j=0; j<n; j++) printf("%d ",v[j]);
    putchar('\n');
}   

/* Strings em C
Strings são arrays de chars com o terminal '\0'
Este caracter especial é só para as strings e está no final de todas as strings

As strings representam-se por "abcde"   */


// Preparação para o mini-teste 21 Mar

/* Operador '&' devolve o endereço de memória do seu operando

Exemplo: 
    int *p, acm = 35;
    p = &acm; //// P recebe o valor do endereço de acm 


caso na memória estivesse: 
    1003 [1292] p
    (...)
    1292 [35] acm

No final do código, p = 1292


    Operador '*' devolve o conteúdo do apontador

Exemplo: 
    int *p, q, acm = 35;
    p = &acm;
    q = p*; ////  q vai ser igual ao espaço da memoria com o valor de p

caso na memória estivesse: 
    1003 [1292] p
    (...)
    1292 [35] acm

No final do código, q = 35

# O tipo dos ponteiros é importante */

int main(){
    int x = 8;
    int *p1;
    int *p2;
    p1 = &x;
    p2 = p1;
    printf("%d %d\n",p1,*p1);
    printf("%d %d\n",p2,*p2);
}

Output: (O primeiro valor do output varia a cada execução)
779885316 8
779885316 8


int main(){    // String copy - questão das 50 questões
    char dest[10];
    char origem[10] = "aaaaaaaaaa";

    int i; 
    for(i = 0; origem[i] != '\0'; i++){
        dest[i] = origem[i];
    }
    dest[i] = '\0';
    for(int j = 0; dest[j] != '\0'; j++){
        printf("%c",dest[j]);
    }
    putchar('\n');
}

int main(){         // String concat
    char result[20];
    char s1[] = "aaaaaaaaaa";
    char s2[] = "bbbbbbbbbb";
    int i;

    for(i = 0; s1[i]!='\0';i++) result[i] = s1[i];
    for(int k = 0; s2[k]!='\0';k++){ result[i] = s2[k];
                                     i++;}
    result[i] = '\0';
    for(int j = 0; result[j] != '\0'; j++){
        printf("%c",result[j]);
    }
    putchar('\n');                               
}   

int main(){         // Outra String Concat
                     FUNCIONOU MAS DEU STACK SMASHING..
    char s1[] = "maria"; char s2[] = "zeca";

    int i,j;
    for(i = 0; s1[i]!='\0'; i++);
    for(j = 0; s2[j]!='\0'; j++){
        s1[i] = s2[j];
        i++;
    }
    s1[i]='\0';
    printf("%s\n",s1);
}   
