// Segundas 50 questões -- memória dinâmica

#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

// 1
int length (LInt l){
    
    int i = 0;
    while(l != NULL){
        i++;
        l = l->prox;
    }
    return i;
}

// 2
void freeL (LInt l){       
    LInt x;

    while(l != NULL){
        x = l -> prox;
        free(l);
        l = x;
    }
}

// 3
void imprimeL (LInt l){             
    
    while(l != NULL){
        printf("%d", l->valor);
        l = l ->prox;
    }
}

// 4
LInt reverseL(LInt l) {         // Segmentation fault...
    int len = length(l); 
    int i = 0;
    LInt array[len];

    while(i < len){
        array[i] = l;
        l = l->prox;
        i++;
    }

    i = len-1;

    while(i>0){
        array[i]->prox = array[i-1];
        i--;
    }

    array[0]->prox = NULL;

    return array[len - 1];
}

// 5
void insertOrd (LInt *l, int x){     
    LInt ant = NULL;
    LInt nova = malloc(sizeof(struct lligada));

    nova -> valor = x;
    nova -> prox = NULL;


    while((*l) != NULL && (*l)->valor < x){
        ant = (*l); l = &((*l)->prox);
    }

    if(ant != NULL){
        nova -> prox = (*l);
        ant -> prox = nova;
    }
    else {
        nova -> prox = (*l);
        (*l) = nova;
    }  
}

// 6
int removeOneOrd (LInt *l, int x){      // só da 1 teste certo mas n encontro o erro.. 
    LInt ant = NULL;

    while((*l) != NULL && (*l) -> valor != x){
        ant = (*l);
        l = &((*l) -> prox);
    } 

    if((*l) == NULL || (*l) -> valor != x) return 1;

    if(ant == NULL){
        l = &((*l) -> prox);
        free(*l);
    }
    else {
        ant -> prox = (*l) -> prox;
        free(*l);
    }
    
    return 0;
}

// 7
void merge (LInt *r, LInt a, LInt b){      
    if(a == NULL && b == NULL) return;

    if(b == NULL || (a != NULL  && a->valor < b -> valor)){
        (*r) = a;
        merge(&((*r)->prox), a->prox, b);
    }
    else {
        (*r) = b;
        merge(&((*r)->prox), a, b->prox);
    }
}

// 8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    if(l == NULL) return;

    if(l->valor < x) {
        (*mx) = l;
        (*Mx) = NULL;
        splitQS(l->prox, x, &((*mx)->prox), Mx);
    }
    else {
        (*Mx) = l;
        (*mx) = NULL;
        splitQS(l->prox, x, mx, &((*Mx)->prox));
    }
}

// 9
LInt parteAmeio (LInt *l){         
    int meio = length(*l)/2; int i; 
    LInt pt = *l, prev = NULL;

    if(meio == 0) return NULL;

    for(i = 0; i < meio; i++){
        prev = (*l);
        (*l) = (*l) -> prox;
    }
    prev -> prox = NULL;
    return pt;
}

// 10
int removeAll (LInt *l, int x){     // 6 testes corretos
    LInt pt = (*l);        
    int ocorrencias = 0;
    LInt ant = NULL;

    while((*l) != NULL){
        if((*l) -> valor == x && ant == NULL){
            (*l) = (*l) -> prox;
            free(pt);
            ocorrencias++;
        }
        if((*l) -> valor == x && ant != NULL){
            pt = (*l);
            ant -> prox = (*l) -> prox;
            free(pt);
            ocorrencias++;
        }
        else {
            ant = *l;
            l = &((*l)->prox);
        }
    }
    return ocorrencias;
}

// 11  
int removeDups (LInt *l){           
    int remocoes = 0;   
    LInt prevAux = (*l), aux = (*l)->prox;

    while((*l) != NULL){
        prevAux = (*l);
        aux = (*l)->prox;
        
        while(aux != NULL){
            if(aux -> valor == (*l) -> valor){
                prevAux -> prox = aux -> prox;
                free(aux);
                remocoes++;
            }
            else prevAux = aux;

            aux = prevAux -> prox;
        }
        
        l = &((*l)->prox);
    }
    return remocoes;
}

// 12
int removeMaiorL (LInt *l){  
    int max = (*l) -> valor;
    LInt prev = NULL;
    LInt maxPrev = NULL;
    LInt maxL = (*l);
    LInt list = (*l);

    while(list != NULL){
        if(list->valor > max){
            maxPrev = prev;
            maxL = list;
            max = list->valor;
        }
        prev = list; 
        list = list -> prox;
    }
    
    if(maxPrev == NULL) (*l) = (*l)->prox;
    else maxPrev->prox = maxL->prox;
    
    return max;
}

// 13           
void init (LInt *l){             

    while((*l) -> prox != NULL){
        l = &((*l) -> prox);
    } 
    
    (*l) = NULL;
    free(*l);
}

// 14
void appendL (LInt *l, int x){  
    LInt nova = malloc(sizeof(struct lligada));
    nova -> valor = x;
    nova -> prox = NULL;

    if((*l) != NULL){
        while((*l) -> prox != NULL){
            l = &((*l) -> prox);
        } 

        (*l) -> prox = nova;
    }
    else {
        (*l) = nova;
    }
}

// 15
void concatL (LInt *a, LInt b){             
    if((*a) == NULL){
        (*a) = b;
    }
    else {
        while((*a)->prox != NULL){
            a = &((*a)->prox);
        }
        (*a) -> prox = b;
    }
}

// 16 
LInt cloneL (LInt l){       // maybe right
    LInt a = NULL;
    a = malloc(sizeof(struct lligada));
    a -> valor = l -> valor;
    a -> prox = cloneL(l->prox);
    
    return a;
}

// 17   
LInt cloneRev (LInt l){             
    LInt aux = NULL, lista = NULL;

    while(l != NULL){
        aux = malloc(sizeof(struct lligada));
        aux -> valor = l -> valor;
        aux -> prox = lista;
        lista = aux;

        l = l->prox;
    }
    return lista;
}

// 18
int maximo (LInt l){
    int max = l->valor;

    while(l != NULL){
        if(l->valor > max) max = l->valor;
        l = l->prox;
    } 
    
    return max;
}

// 19
int take (int n, LInt *l){      
    LInt temp; int i = 0;

    for(;i < n && (*l) != NULL; i++, l = &((*l)->prox));
    
    if((*l) == NULL) return i;
    
    while((*l) != NULL){
        temp = (*l)->prox;
        free(*l);
        *l = temp;
    }

    return n;    
}

// 20
int drop (int n, LInt *l){      
    int ret = 0;
    LInt aux;

    while(n > 0 && (*l) != NULL){
        aux = (*l) -> prox;
        free(*l);
        (*l) = aux;
        ret++;
        n--;
    }

    return ret;
}

// 21
LInt NForward (LInt l, int N){
    if(l == NULL) return NULL;

    while(N > 0){
        l = l->prox;
        N--;
    }
    return l;
}

// 22
int listToArray (LInt l, int v[], int N){
    int i;

    for(i = 0; i < N && l != NULL; i++){
        v[i] = l->valor;
        l = l->prox;
    }
    return i;
}

// 23
LInt arrayToList (int v[], int N){
    LInt l = NULL;
    if(N == 0) return l;

    l = malloc(sizeof(struct lligada));
    l -> valor = v[0];
    l -> prox = arrayToList(v+1,N-1);

    return l;
}

// 24
LInt somasAcL (LInt l){                       
    LInt aux, criar = NULL, outra = NULL;

    int acc = 0;

    while(l != NULL){
        acc += l -> valor;
        aux = malloc(sizeof(struct lligada));
        aux -> valor = acc;
        aux -> prox = NULL;

        if(criar == NULL){
            criar = aux; outra = criar;
        }
        else {
            outra->prox = aux;
            outra = outra -> prox;
        }

        l = l->prox;
    }
    return criar;
}

// 25     
void remreps(LInt l) {             
    LInt temp = NULL;

    if(l != NULL) {
        while(l -> prox != NULL){
            if(l -> prox -> valor == l -> valor){
                temp = l->prox;
                l -> prox = temp -> prox;
                free(temp);
            }
            else l = l->prox;
        }
    }
}

// 26
LInt rotateL (LInt l){      
    if(l == NULL || l->prox == NULL) return l;

    LInt aux = l, primeiro = l;
    while(l->prox != NULL) l = l->prox;

    primeiro = primeiro -> prox;
    l -> prox = aux;
    aux -> prox = NULL;
    
    return primeiro;        
}

// 27 
LInt parte (LInt l){       
    if(l == NULL || l -> prox == NULL) return NULL;

    LInt aux = l -> prox;

    l->prox = l->prox->prox;
    aux -> prox = parte(l->prox);
    return aux;
}


// ARVORES BINARIAS

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;


// 28                                   
int altura (ABin a){
    if(a == NULL) return 0;
    if(altura(a -> esq) > altura(a -> dir)) return 1 + altura(a -> esq);
    else return 1 + altura(a -> dir);
} 

// 29                             
ABin cloneAB (ABin a){
    if(a == NULL) return NULL;

    ABin nova = malloc(sizeof(struct nodo));
    nova -> valor = a -> valor;
    nova -> esq = cloneAB(a -> esq);
    nova -> dir = cloneAB(a -> dir);
    return nova;
}

// 30                          
void mirror (ABin *a){
    if((*a) != NULL){
        ABin aux = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = aux;
        mirror(&((*a)->esq));
        mirror(&((*a)->dir));
    }
}

// 31                                       
void inorder(ABin a, LInt * l){
    LInt nova;

    if(a != NULL){
        inorder(a -> dir,l);

        nova = malloc(sizeof(struct lligada));
        nova -> valor = a -> valor;
        nova -> prox = *l;

        *l = nova;

        inorder(a -> esq,l);
    }
}


// 32                                   
void preorderaux(ABin a, LInt *l) {
    LInt aux;
    if(a){
        preorderaux(a->dir,l);
        preorderaux(a->esq,l);

        aux = malloc(sizeof(struct lligada));
        aux->valor = a->valor;
        aux->prox = *l;

        *l = aux;
    }
}

void preorder(ABin a, LInt *l){
    *l = NULL;
    preorderaux(a,l);
}

// 33                                        
void posorderaux(ABin tree, LInt * list) {
    if(tree){
        LInt new = malloc(sizeof(struct lligada));
        new->valor = tree->valor;
        new->prox = (*list);
        (*list) = new;
        posorderaux(tree->dir,list);
        posorderaux(tree->esq,list);
    }
}

void posorder(ABin tree, LInt * list) {
    *list = NULL;
    posorderaux(tree,list);
}

// 34                             
int depth (ABin a, int x){
    if(a == NULL) return -1;
    if(a -> valor == x) return 1;
   
    int esq = depth(a->esq,x);
    int dir = depth(a->dir,x);

    if(esq == -1 && dir == -1) return -1;
    if(esq == -1) return 1+dir;
    if(dir == -1) return 1+esq;
    if(esq < dir) return 1+esq; else return 1+dir;
}


// 35
int freeAB (ABin a){
    if(a == NULL) return 0;
    ABin aux = a;
    int r = 0, e,d;
    e = freeAB(a -> esq);
    d = freeAB(a -> dir);
    free(aux);
    r++;
    return r + d + e;
}

// 36                       
int pruneAB (ABin *a, int x){
    if((*a) == NULL) return 0;
    int r;
    if(x == 0){
        r = 1 + pruneAB(&((*a)->esq),0) + pruneAB(&((*a)->dir),0);
        free(*a);
        (*a) = NULL; // so pa dar certo no codeboard, ig
    }
    else r = pruneAB(&((*a)->esq),x - 1) + pruneAB(&((*a)->dir),x - 1);

    return r;
}

// 37                           
int iguaisAB (ABin a, ABin b){
    if((a == NULL && b != NULL) || (a != NULL && b == NULL)) return 0;
    if(a == NULL && b == NULL) return 1;

    return a->valor == b->valor && iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir);
}

// 38                          
LInt concat(LInt a, LInt b) {
    if(a == NULL) return b;
    LInt temp = a;
    while(temp->prox != NULL) temp = temp->prox;
    temp->prox = b;
    return a;
}
 
LInt nivelL (ABin a, int n) {
    if(a == NULL || n < 1) return NULL;
    if(n == 1){
        LInt new = malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = NULL;
        return new;
    }
    else return concat(nivelL(a->esq,n - 1),nivelL(a->dir,n - 1));
} 

// 39                                
int nivelV (ABin a, int n, int v[]){
    if(a == NULL || n < 1) return 0;
    if(n == 1){
        *v = a->valor;
        return 1;
    }
    else {
        int e = nivelV(a->esq,n - 1,v);
        int d = nivelV(a->dir,n - 1,v+e);
        return e + d;
    }
}

// 40                               
int dumpAbin (ABin a, int v[], int N) {
    int e, d;
    if(a != NULL && N != 0) {
        e = dumpAbin(a->esq,v,N);
        if(e < N) {
            v[e] = a->valor;
            return 1 + e + dumpAbin(a->dir,v+e+1,N-e-1);
        }
        else return N;
    }
    else return 0;
}

// Suposta pergunta 41, interpretei errado mas como ficou tao bonita e direitinha deixei tar..
ABin somasAcA (ABin a){
    if(a == NULL) return NULL;
    int acc = a -> valor;

    ABin nova = malloc(sizeof(struct nodo));
    nova -> valor = acc;
    nova -> dir = novonodo(a->dir, nova, acc);
    nova -> esq = novonodo(a->esq, nova, acc);
    
    return nova;
}

ABin novonodo(ABin a, ABin b, int acc){
    if(a == NULL) return NULL;

    ABin nova = malloc(sizeof(struct nodo));
    acc += a -> valor;
    nova -> valor = acc;
    nova -> dir = novonodo(a->dir, nova, acc);
    nova -> esq = novonodo(a->esq, nova, acc);
    
    return nova;
}

// 41                       
ABin somasAcA (ABin a){
    if(a == NULL) return NULL;

    int ve = 0;
    int vd = 0;

    ABin new = malloc(sizeof(struct nodo));
    new->esq = somasAcA(a->esq);
    new->dir = somasAcA(a->dir);
    if(new -> esq != NULL) ve = new->esq->valor;
    if(new -> dir != NULL) vd = new->dir->valor;
    new->valor = a->valor + ve + vd;
    
    return new;
}

// 42
int contaFolhas (ABin a){
    if(a == NULL) return 0;

    if(a->dir == NULL && a->esq == NULL) return 1;

    return contaFolhas(a->esq) + contaFolhas(a->dir);
}

// 43
ABin cloneMirror (ABin a){
    if(a == NULL) return NULL;
    ABin nova = malloc(sizeof(struct nodo));
    nova -> valor = a -> valor;
    nova -> esq = cloneMirror(a -> dir);
    nova -> dir = cloneMirror(a -> esq);
    
    return nova;
}

// 44                       
int addOrd (ABin *a, int x){
    while((*a) != NULL){
        if((*a)->valor == x) return 1;
        if((*a)->valor > x) a = &((*a)->esq);
        else a = &((*a)->dir);
    }
    ABin nova = malloc(sizeof(struct nodo));
    nova -> valor = x;
    nova -> esq = NULL;
    nova -> dir = NULL;
    (*a) = new; // isto aqui liga a arvore ao novo nodo, porque o apontador de "a" esta a apontar para null neste momento e é o next de algum nodo

    return 0;
}

// 45
int lookupAB (ABin a, int x){
    while(a != NULL){
        if(a -> valor == x) return 1;
        if(a -> valor < x) a = a->dir;
        else a = a -> esq;
    }
    return 0;
}

// 46
int depthOrd (ABin a, int x){
    int nivel = 1; // raiz é o nivel 1
    while(a != NULL && a -> valor != x){
        nivel++;
        if(a -> valor < x) a = a -> dir;
        else a = a -> esq;
    }
    if(a == NULL) return -1;
    return nivel;
}

// 47 
int maiorAB (ABin a){
    if(a -> dir == NULL) return a -> valor;
    int maior;
    maior = maiorAB(a -> dir);

    return maior;
}

// 48                       
void removeMaiorA (ABin *a){
    if((*a) -> dir == NULL){
        ABin ant = (*a);
        free(*a);
        (*a) = ant -> esq;
    }
    else removeMaiorA(&((*a)->dir));
}

// 49                               
int quantosMaiores (ABin a, int x){
    if(a == NULL) return 0;
    if(a -> valor <= x) return quantosMaiores(a -> dir,x);
    return 1 + quantosMaiores(a -> esq,x) + quantosMaiores(a -> dir,x);
}



// 50                               
void listToBTree (LInt l, ABin *a) {
    if(l == NULL) return;
    
    ABin new = malloc(sizeof(struct nodo));
    int meio = length(l) / 2;
    LInt temp = l, prev = NULL;
    int i;
    for(i = 0; i < meio; i++) {
        prev = temp;
        temp = temp->prox;
    }
    new->valor = temp->valor;
    new->esq = new->dir = NULL;
    if(prev) prev->prox = NULL;
    
    if(l != temp) listToBTree(l,&(new->esq));
    if(temp->prox) listToBTree(temp->prox,&(new->dir));
    (*a) = new;
}

// 51                                   
int deProcuraAux(ABin a, int x, int maior) {
    if(!a) return 1;
    if((maior && a->valor < x) || (!maior && a->valor > x)) return 0;
    return deProcuraAux(a->esq,x,maior) && deProcuraAux(a->dir,x,maior);
}

int deProcura (ABin a) {
    if(!a) return 1;
    int b = deProcuraAux(a->esq,a->valor, 0) && deProcura(a->esq);
    int c = deProcuraAux(a->dir,a->valor, 1) && deProcura(a->dir);
    return b && c;
}











