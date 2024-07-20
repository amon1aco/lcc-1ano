// ficha 7 - listas ligadas

#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

// 1
void libertaLista (Palavras l){
    free(l);
}

// 2
int quantasP (Palavras l){
    int retorno = 0;

    while(l != NULL){
        retorno++;
        l = l->prox;
    }
    return retorno;
}

// 3
void listaPal (Palavras l){
    while(l != NULL){
        printf("Palavra e Ocorrencias: %s %d\n", l->palavra, l->ocorr);
        l = l -> prox;
    }
}

// 4 
char * ultima (Palavras l){
    while(l->prox != NULL){
        l = l -> prox;
    }
    return l->palavra;
}

// 5
Palavras acrescentaInicio (Palavras l, char *p){
    Palavras nova = malloc(sizeof(struct celula));
    nova -> ocorr = 1;
    nova -> palavra = p;
    nova -> prox = l;

    return nova;
}

// 6
Palavras acrescentaFim (Palavras l, char *p){
    Palavras aux;
    Palavras nova = malloc(sizeof(struct celula));
    nova -> ocorr = 1;
    nova -> palavra = p;
    nova -> prox = NULL;

    if(aux == NULL) return l;
    while (aux -> prox != NULL){
        aux = aux->prox;
    }
    aux -> prox = nova;

    return l;
}

// 7
Palavras acrescenta (Palavras l, char *p){
    Palavras aux = l;
    if(aux == NULL){ 
        Palavras nova = malloc(sizeof(struct celula));
        nova -> ocorr = 1;
        nova -> palavra = p;
        nova -> prox = NULL;

        return nova;
    }
    while(aux != NULL){
        if(strcmp(aux -> palavra, p) == 0){
            aux -> ocorr++;
            return l;
        }
        else {
            aux = aux -> prox;
        }
    }
    Palavras nova = malloc(sizeof(struct celula));
    nova -> ocorr = 1;
    nova -> palavra = p;
    nova -> prox = l;

    return nova; 
}

// 8
struct celula * maisFreq (Palavras l){
    Palavras aux = l;
    Palavras p_maisfq = l;
    int maisfq = l -> ocorr;
    while(aux != NULL){
        if(aux -> ocorr > maisfq){
            p_maisfq = aux;
            maisfq = aux -> ocorr;
        }
        aux = aux -> prox;
    }

    return p_maisfq;
}
