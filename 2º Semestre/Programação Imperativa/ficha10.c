// Ficha 10 - Árvores binárias de procura

typedef struct nodo{
    int valor;
    struct nodo *esq, *dir;
} *ABin;


ABin removeMenor (ABin *a){
    ABin aux = *a, ant = NULL;
    while(aux -> esq != NULL){
        ant = aux;
        aux = aux->esq;
    }
    if(ant == NULL) *a = aux -> dir;
    else ant -> esq = aux -> dir;
   
    return aux; 
}

void removeRaiz (ABin *a){
    ABin t = *a, x;

    if((*a) -> esq == NULL){
        *a = *a -> dir;
    }
    else if((*a) -> dir == NULL){
        *a = *a -> esq;
    }
    else {
        x = removeMenor(&((*a)->dir));
        x -> esq = t -> esq;
        x -> dir = t -> dir;
        *a = x;
    }
    free(t);
}

int removeElem (ABin *a, int x){
    int r = 1;
    while((*a) -> valor != x && (*a) != NULL){
        if((*a)->valor < x){
            a = &((*a)->esq);
        }
        else a = &((*a)->dir);
    }   
    if((*a) -> valor == x){
        removeElem(a, x);
        r = 0;
    }
    
    return r;
}

