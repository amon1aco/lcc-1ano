/**
* @file stack.c
* @brief Neste ficheiro são definidas funções auxiliares que vão ser utilizados ao do código.
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/// @brief Nesta função é definida a stack utilizada no projeto.
STACK *new_stack(){
    STACK *s = (STACK *) calloc(1, sizeof(STACK));
    s -> n_elems = 0;
    s -> s_size = 100;
    s -> stack = (data_type *) calloc(s -> s_size, sizeof(data_type));
    return s;
}

/// @brief Nesta Função é definido o Push que é usado para movimentar os valores fornecidos.  
void push(STACK *s, data_type elem){
    if(s -> s_size == s -> n_elems){ /// caso a stack esteja cheia é adicionado 100 de mmemoria
        s -> s_size += 100;
        s -> stack = (data_type *) realloc(s -> stack, s -> s_size * sizeof(data_type));
    }
    s -> stack[s -> n_elems] = elem;
    s -> n_elems++;
}

/// @brief Nesta Função é definido o Push que é usado para movimentar os valores recebidos.
data_type pop(STACK *s){
    s -> n_elems--;
    return s -> stack[s->n_elems];
}

int tipo(data_type elem, int mask){
    if((elem.type & mask) != 0) return 1;
    else return 0;
}

/// @brief A Função imprime vai printar os valores dos resultados obtivos consoante as operações usadas e consoante o tipo de valor do resultado obtido. 
void imprime_s (STACK *s){ 
    int i;
    for(i = 0; i < s -> n_elems; i++){
        data_type elem = s -> stack[i];
        TYPE tipo = elem.type;
        if(tipo == LONG) printf("%ld", elem.LONG);
        if(tipo == DOUBLE) printf("%g", elem.DOUBLE);
        if(tipo == CHAR) printf("%c", elem.CHAR);
        if(tipo == STRING) printf("%s", elem.STRING);
		if(tipo == ARRAY) aux_print_arr(elem.ARRAY);
    }
    putchar('\n');
}

void aux_print_arr(STACK *s){
	int i;
	for(i = 0; i < s -> n_elems; i++){
		data_type elem = s->stack[i];
		TYPE tipo = elem.type;

		if(tipo == LONG) printf("%ld", elem.LONG);
        if(tipo == DOUBLE) printf("%g", elem.DOUBLE);
        if(tipo == CHAR) printf("%c", elem.CHAR);
        if(tipo == STRING) printf("%s", elem.STRING);
		if(tipo == ARRAY) aux_print_arr(elem.ARRAY);
	}
}


///As operações "stack proto" foram alteradas para funções individuais para conseguir utilizar arrays


						// convem ser tudo comentado // convem ser tudo comentado
data_type top_da_stack(STACK *s){
    data_type x;

    x = s->stack[s->n_elems - 1];
    return x;
}
  
void push_LONG(STACK *s, long x){
	data_type aux;

	aux.type = LONG;
	aux.LONG = x;
	push(s, aux);
}

void push_DOUBLE(STACK *s, double x){
	data_type aux;

	aux.type = DOUBLE;
	aux.DOUBLE = x;
	push(s, aux);
}

void push_CHAR(STACK *s, char x){
	data_type aux;

	aux.type = CHAR;
	aux.CHAR = x;
	push(s, aux);
}

void push_STRING(STACK *s, char * x){
	data_type aux;

	aux.type = STRING;
	aux.STRING = x;
	push(s, aux);
}

void push_ARRAY(STACK *s, STACK *x){
	data_type aux;

	aux.type = ARRAY;
	aux.ARRAY = x;
	push(s, aux);
}   

long pop_LONG(STACK *s){
	data_type aux = pop(s);

	assert(aux.type == LONG);
	return aux.LONG;
}

double pop_DOUBLE(STACK *s){
	data_type aux = pop(s);

	assert(aux.type == DOUBLE);
	return aux.DOUBLE;
}

char pop_CHAR(STACK *s){
	data_type aux = pop(s);

	assert(aux.type == CHAR);
	return aux.CHAR;
}

char * pop_STRING(STACK *s){
	data_type aux = pop(s);

	assert(aux.type == STRING);
	return aux.STRING;
}

STACK * pop_ARRAY(STACK *s){
	data_type aux = pop(s);

	assert(aux.type == ARRAY);
	return aux.ARRAY;
}   