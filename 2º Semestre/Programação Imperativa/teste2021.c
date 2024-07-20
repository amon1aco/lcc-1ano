// Teste de PI 2021

#include <stdio.h>

/*
// -1       
int sumhtpo (int n) {
    int i, max = 0;

    for (i = 1; n != 1; i++) {
        if (n > max) max = n;

        if(n % 2 == 0) n = n/2;
        else n = 1 +(3*n);
    }
    if(i < 100) return -1;
    else return r;
}


// -2                   É assim não está testada mas parece me correta, o que importa é a ideia 
int moda(int v[], int N, int *m){   
    int moda = -1;
    int contador = 0, controlo = 0;
    int i,j;
    int valor;

    for(i = 0; i < N; i++){
        valor = v[i];
        for(j = 0; j < N; j++){
            if(valor == v[j]) contador++;
        }
        if(contador > moda) moda = contador;
        if(contador == moda) controlo++;
        contador = 0;
    }
    if(controlo != 0) return -1;
    
    *m = moda;
    return moda;
}

// -3                   Testar que é bom também ja era, ainda por cima quem fez as solucoes do necc nesta pergunta provavelmente estava embriagado
int procura (LInt *l, int x){
    LInt lista = *l;
    Lint ant = NULL;

    while(lista != NULL && lista -> valor != x){
        ant = lista;
        lista = lista -> prox;
    }
    if(lista -> valor != x) return -1;

    ant -> prox = lista -> prox;
    lista -> prox = l;
    return 0;
}

// -4
int freeAB(ABin a){
    if (a == NULL) return 0;

    int ret = freeAB(a->esq) + freeAB(a->dir) + 1;
    free(a);

    return ret;
} */


// -5   NUM PERCEBI UM CARALHO DESTA MERDA DO PAI

// Teste de uma cena que eu não vou de 2021

// -1
/*
void paresImpares(int v[], int N){ // 
    int i;

    while(N > 0){
        for(i = 0; i < N; i++){
            if(v[i] % 2 == 1) swap(&(v[i]),&(v[N]));
            N--; 
        }
    }
} */

/*
void swap(int *a, int *b){
    int *aux;
    *aux = *a;
    *a = *b;
    *b = *aux;
}

int main(){
    int v[] = {1,2,3,4,5,6,7,8,9};
    int N = 9;
    
    while(N > 0){
        for(int i = 0; i < N; i++){
            if(v[i] % 2 == 1){
                swap(&(v[i]),&(v[N]));
                N--;
            } 
        }
    }

    for(int j = 0; j < 9; j++){
        printf("%d ", v[j]);
    }
    putchar('\n');
} */

// -2   
/*
void merge (LInt *r, LInt a, LInt b){
    while(a != NULL && b != NULL){
        if(a -> valor > b -> valor){
            *r = b;
            b = b->prox;
        }
        else {
            *r = a;
            a = a -> prox;
        }
        r = &((*r) -> prox);
    }
    if(*r == NULL){
        if(a == NULL) *r = b; 
        if(b == NULL) *r = a;
    }
}   */

// -3
/*  int main(){             // CA PUTA DHYPE FI
    int N = 10;
    int m[10][10];

    for(int l = 0; l < N; l++){
        for(int c = 0; c < N; c++){
            if(l+c+1 <= N) m[l][c] = l+c+1;
            else m[l][c] = (l+c+1)%N;
        }
    } 

    for(int li = 0; li < N; li++){
        for(int co = 0; co < N; co++){
            printf("%d ", m[li][co]);
        }
        putchar('\n');
    }
return 0;
} */

// -4 
/*
typedef struct nodo {
    int valor;
    struct nodo *pai, *esq, *dir;
} *ABin;

ABin next (ABin a) {        // FODA PATROA
    if (a == NULL) return NULL;
    // sendo o pai o nodo anterior acho q ja percebi a situacao toda
    if (a->dir == NULL && a->pai == NULL) { // caso a direita seja nula e o pai seja nulo entao nao tem proximo, ta sosinha arvores
        return NULL;
    } else if (a->dir == NULL && a->pai->dir == a) { // caso a direita seja nula e o a seja a direita do pai entao retorno o pai do pai
        return a->pai->pai; // eu acho q aqui devia de ser recursiva :(
    } else if (a->dir == NULL && a->pai->esq == a) { // caso a direta seja nula e o a seja a esquerda do pai entao retorna o pai
        return a->pai;
    }

    return a->dir; // caso n entre em nenhum dos casos entao apenas devolve a direta q é o proximo elemento
} // nao sei se ta certa mas pelo menos tem alguma coisa escrita
 */


// Teste 17/18
// 1-
/* 
int main(){
    int N = 9;
    int v[] = {-1,2,-3,-4,5,6,-7,8,9};
    int i, counter = 0, j;

    for(i = 0; i < N; i++){
        if(v[i] >= 0) counter++;
        else {
            for(j = i; j < N; j++){
                v[j] = v[j+1];
            }
            N--;
            i--;
        }
    }
    for(int k = 0; k < N; k++) printf("%d ", v[k]);
    putchar('\n');
    return counter;
} */

// 2-
/*
int main(){
    char s[] = "aaabcccccd";
    int r;
    r = difConsecutivos(s);
    printf("%d\n",r);
    return 0;
} 


int not_in_prev(char str[], int k, int n) {
    int i;
    int ans = 1;
    for(i = k; i < n; i++) {
        if(str[i] == str[n]) {
            return 0;
        }
    }
    return ans;
}

int difConsecutivos(char s[]) {
    int j, i;
    int ans = 0;
    for(i = 0; s[i] != '\0'; i++) {
        int consec = 0;
        for( j = i; s[j] != '\0'; j++) {
            if(not_in_prev(s,i,j) != 0) consec++;
            else break;
        }
        if (consec > ans) ans = consec;
    }
    return ans;
} */
/*
LInt arraytolist(int v[], int N){
    if(N == 0) return NULL;

    LInt nova = malloc(sizeof(struct slist));
    nova -> valor = v[0];
    nova -> prox = arraytolist(v+1,N-1);

    return nova;    
}

LInt arrayToList(int v[], int N){
    if(N == 0) return NULL;
    int i; 

    LInt nova = malloc(sizeof(struct lligada));
    nova -> valor = v[0];

    LInt ant = nova;

    for(i = 1; i < N; i++){
        LInt aux = malloc(sizeof(struct lligada));
        aux -> valor = v[i];
        ant -> prox = aux;

        ant = aux;
    }
    ant -> prox = NULL;

    return nova;
} */

int minheapOK(ABin a){
    if(a == NULL) return 1;

    if(a -> valor < a -> esq -> valor) return 0;
    if(a -> valor < a -> dir -> valor) return 0;

    int esq *= minheapOK(a -> esq);
    int dir *= minheapOK(a -> dir);

    return esq*dir;
}
  


int minHeapOK(ABin a) { //1 se nao for min-heap, 0 se for min-heap
	if (a == NULL) return 0;
	int cond = 0;
	if (a->esq != NULL && a->esq->valor < a->valor) return 1;
	cond = minHeapOK(a->esq);
	if (cond == 0) {
		if (a->dir != NULL && a->dir->valor < a->valor) return 1;
		cond = minHeapOK(a->dir);
	}
	return cond;
}