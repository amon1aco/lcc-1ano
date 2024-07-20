// Ficha 8

typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    
    if (r!=NULL){
        r->valor = x; r->prox = xs;
    }
    return r;
}


// No caso das stacks, os elementos são inseridos e removidos do inicio da lista.
typedef LInt Stack;

/* No caso das queues, e de forma a tornar as operacoes de adicao/remocao de um elemento
eficientes (e com uma eficacia que n ̃ao depende do tamanho da queue), ́e costume usar dois
enderecos: um para cada uma das extremidades da lista. A insercao ́e feita no final da lista e a
remocao do inicio. */
typedef struct {
    LInt inicio,fim;
} Queue;



// 1
void initStack (Stack *s){
    (*s) = NULL;
}

int SisEmpty (Stack s){
    return s == NULL;
}

int push (Stack *s, int x){
    (*s) = newLInt(x, (*s));
    return 0;
} 

int pop (Stack *s, int *x){
    if((*s) == NULL) return -1;
    else {
        *x = (*s) -> valor;
        (*s) = (*s) -> prox;
        return 0;
    }
}

int top (Stack s, int *x){
    if(s == NULL) return -1;
    else {
        (*x) = s -> valor;
        return 0; 
    }
}

// 2

void initQueue (Queue *q){
    q -> inicio == NULL; 
    q -> fim == NULL; 
}

int QisEmpty (Queue q){
    return q.inicio == NULL; 
}

int enqueue (Queue *q, int x){
    LInt temp = newLInt(x, NULL);
    if(q -> inicio == NULL) {
        q->inicio = temp;
        q->fim = temp;
    } 
    else {
        q->fim->prox = temp;
        q->fim = temp;
    }
}

int dequeue (Queue *q, int *x){
    LInt temp = q -> inicio;
    if (q -> inicio == NULL) return -1;

    *x = q -> inicio -> valor;

    q -> inicio = q -> inicio -> prox;
    free(temp);
    return 0;
}

int front(Queue q, int *x){
    if (q.inicio == NULL) return -1;
    *x = q.inicio->valor;
    
    return 0;
}

// Filas circulares
typedef LInt QueueC;


void initQueue (Queue *q){
    (*q) = NULL;
}

int QisEmpty (Queue q){
    return q == NULL;
}


int enqueue (Queue *q, int x){
    if(*q == NULL){
        *q = newLInt(x,NULL);
        (*q) -> prox = *q;
    }
    else {
        (*q) -> prox = newLInt(x, (*q) -> prox);
        (*q) = (*q) -> prox;
    }
    return 0;
}

int dequeue (Queue *q, int *x){
    if((*q) == NULL) return -1;
    LInt temp = NULL;
    if (*q == (*q)->prox) { // caso so tenha 1 elemento
        temp = *q;
        *q = NULL;
    }
    else {
        temp = (*q)->prox;
        (*q)->prox = temp->prox; 
    }
    *x = temp->valor;
    free(temp);
    return 0;
}


// Pergunta 4
typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} *DList;

typedef struct {
    DList back, front;
} Deque;


void initQueue (Queue *q){
    (*q) = NULL;
}

int QisEmpty (Queue q){
    return q == NULL;
}

int pushBack (Deque *q, int x){
    DList nova = malloc(sizeof(struct dlist));
    nova -> valor = x;
    nova -> prox = NULL;
    nova -> ant = NULL;

    if((*q) == NULL) {
        (*q) -> inicio = (*q) -> fim = nova;
    }
    else {
        nova -> ant = (*q) -> fim
        (*q) -> fim -> prox = nova;
        (*q) -> fim = nova;                 // not sure if it works
    }
}


int pushFront (Deque *q, int x){
    DList nova = malloc(sizeof(struct dlist));
    nova -> valor = x;

    if((*q) == NULL) {
        nova -> prox = NULL;
        nova -> ant = NULL;
        (*q) -> inicio = (*q) -> fim = nova;
    }
    else {
        (*q) -> inicio -> ant = nova;
        nova -> prox = inicio;
        (*q) -> inicio = nova;                 // not sure if it works
        nova -> ant = NULL;
    }
}

int popBack (Deque *q, int *x){
    if((*q) == NULL) return -1;

    *x = (*q) -> fim -> valor;
    (*q) -> fim = (*q) -> fim -> ant;
}

int popFront (Deque *q, int *x){
    if((*q) == NULL) return -1;

    *x = (*q) -> inicio -> valor;
    (*q) -> inicio = (*q) -> incio -> prox;
}

int popMax (Deque *q, int *x){  
    DList maior = NULL; int valorm = (*q) -> inicio -> valor;
    while((*q) != NULL){
        q = &((*q)-> prox);

    }
}

// Por fazer:
int back (Deque q, int *x)
int front (Deque q, int *x)


