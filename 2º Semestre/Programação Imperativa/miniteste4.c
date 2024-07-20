
/*
Aceda ao projecto codeboard https://codeboard.io/projects/244370 e implemente a função procura por forma a 
que devolva o endereço do 35º nodo a contar do final da lista. Caso esse endereço não exista deve devolver NULL. */


#include "miniteste.h"
#include <stdlib.h>

LInt procura(LInt l){
    int val = 0;
    LInt aux = l;

    while(aux != NULL){
        val++;
        aux = aux -> prox;
    }
    if(val < 35) return NULL;
    else if(val == 35) return l;
    else{
        val = val - 35 + 1;
        while(val > 0){
            l = l->prox;
            val--;
        }
    }
    return l;
}

/* Aceda ao projecto codeboard https://codeboard.io/projects/244621 e implemente a função cria por forma 
a que devolva uma árvore equilibrada com tamanho 37. A árvora é equilibrada se em todos os nodos o número 
de elementos do lado esquerdo difere do número de elementos do lado direito no máximo numa unidade. */

#include "miniteste.h"
#include <stdlib.h>

int preenchearr(int v[],int n);
ABin newNode(int val);
ABin array_para_abin(int v[], int start, int end);

ABin cria(){
    int v[37];
    preenchearr(v,37);

    ABin a = array_para_abin(v,0,37);
    return a;
}


int preenchearr(int v[],int n){
    int i;
    for (i=0; i<n;i++) v[i]= i;

    return 0;
}


ABin newNode(int val){
    ABin new = malloc(sizeof(struct nodo));
    new -> valor = val;
    new -> esq = NULL;
    new -> dir= NULL;
 
    return new;
}

ABin array_para_abin(int v[], int start, int end){
    if(start > end) return NULL;
    int mid = (start + end)/2;
    ABin nodo = newNode(v[mid]);
    nodo -> esq =  array_para_abin(v, start, mid-1);
    nodo -> dir = array_para_abin(v, mid+1, end);
 
    return nodo;
}


