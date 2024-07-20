/**
* @file stack.c
* @brief Neste ficheiro são definidas as funções fundamentais do funcionamento de uma stack.
* Para além das funções fundamentais, estão também defenidas funções que imprimem a stack e que verificam o tipo dos elementos da stack...
*/

#include <stdio.h>
#include <stdlib.h> /// Necessário para funções como o calloc, realloc.
#include "stack.h"  /// Incluida a stack

/// @brief Nesta função é criada uma nova stack
STACK *new_stack(){
    STACK *s = (STACK *) calloc(1, sizeof(STACK)); /// É alocado espaço na memoria para a stack
    s -> n_elems = 0; 	/// A stack começa com 0 elementos, vazia
    s -> s_size = 100;	/// E o tamanho maximo da stack fica a 100 elementos
    s -> stack = (data_type *) calloc(s -> s_size, sizeof(data_type)); /// Aloco o espaço necessario para os 100 elementos da stack
    return s; /// retorna a nova stack, s
}

/// @brief Nesta Função é "pushado" um elemento para o topo da stack  
void push(STACK *s, data_type elem){
    if(s -> s_size == s -> n_elems){  /// verifica se a stack está cheia
        s -> s_size += 100;		/// caso a stack esteja cheia é adicionado 100 de memoria
        s -> stack = (data_type *) realloc(s -> stack, s -> s_size * sizeof(data_type)); /// Aloca o espaço necessario para mais 100 elementos.
    }
    s -> stack[s -> n_elems] = elem; /// "Pusha" para o topo da stack o elem
    s -> n_elems++; /// E adiciona 1, ao numero de elementos
}

/// @brief Nesta Função é definido o Pop que remove o valor do topo da stack
data_type pop(STACK *s){
    s -> n_elems--;	/// Diminui 1 ao numero de elementos
    return s -> stack[s->n_elems]; /// Retorna o valor relativo ao numero de elementos, visto que o mesmo foi decrementado
}

/// As funções que se seguem tiveram que ser alteradas por causa do guião 4.
///@brief Esta função devolve o valor do topo da stack sem o remover
data_type top_da_stack(STACK *s){
    data_type x; /// Variavel de retorno
    x = s->stack[s->n_elems - 1]; /// Variavel de retorno = ao elemento do topo da stack
    return x; /// Retorno do valor do topo da stack
}

///@brief Esta função "pusha" um long para o topo da stack 
void push_LONG(STACK *s, long x){
	data_type aux; 		/// É criada uma variavel nova
	aux.type = LONG; 	/// O type da variavel nova fica LONG
	aux.LONG = x; 		/// E essa variavel é igual ao long recebido
	push(s, aux); 		/// Para finalizar há o push normal para o topo da stack
}

///@brief Esta função "pusha" um double para o topo da stack 
void push_DOUBLE(STACK *s, double x){
	data_type aux;		/// É criada uma variavel nova
	aux.type = DOUBLE;	/// O type da variavel nova fica DOUBLE
	aux.DOUBLE = x;		/// E essa variavel é igual ao double recebido
	push(s, aux);		/// Para finalizar há o push normal para o topo da stack
}

///@brief Esta função "pusha" um char para o topo da stack 
void push_CHAR(STACK *s, char x){
	data_type aux;		/// É criada uma variavel nova
	aux.type = CHAR;	/// O type da variavel nova fica CHAR
	aux.CHAR = x;		/// E essa variavel é igual ao CHAR recebido
	push(s, aux);		/// Para finalizar há o push normal para o topo da stack
}

///@brief Esta função "pusha" uma string para o topo da stack 
void push_STRING(STACK *s, char *x){
	data_type aux;		/// É criada uma variavel nova
	aux.type = STRING;	/// O type da variavel nova fica STRING
	aux.STRING = x;		/// E essa variavel é igual ao apontador de char recebido
	push(s, aux);		/// Para finalizar há o push normal para o topo da stack
}

///@brief Esta função "pusha" um array para o topo da stack 
void push_ARRAY(STACK *s, STACK *x){
	data_type aux;		/// É criada uma variavel nova
	aux.type = ARRAY;	/// O type da variavel nova fica ARRAY
	aux.ARRAY = x;		/// E essa variavel é igual à stack recebida
	push(s, aux);		/// Para finalizar há o push normal para o topo da stack	
}   

///@brief Esta função remove um valor do topo da stack e retorna-o
long pop_LONG(STACK *s){
	data_type aux = pop(s);   /// Cria uma variavel auxiliar igual ao elemento removido do topo da stack
	assert(aux.type == LONG); /// Verifica se o topo da stack é de facto um LONG
	return aux.LONG;		  /// Retorna esse valor
}

///@brief Esta função remove um valor do topo da stack e retorna-o
double pop_DOUBLE(STACK *s){
	data_type aux = pop(s);		/// Cria uma variavel auxiliar igual ao elemento removido do topo da stack
	assert(aux.type == DOUBLE);	/// Verifica se o topo da stack é de facto um DOUBLE
	return aux.DOUBLE;			/// Retorna esse valor
}

///@brief Esta função remove um valor do topo da stack e retorna-o
char pop_CHAR(STACK *s){
	data_type aux = pop(s); 	/// Cria uma variavel auxiliar igual ao elemento removido do topo da stack
	assert(aux.type == CHAR);	/// Verifica se o topo da stack é de facto um CHAR
	return aux.CHAR;			/// Retorna esse valor
}

///@brief Esta função remove um valor do topo da stack e retorna-o
char * pop_STRING(STACK *s){
	data_type aux = pop(s);		 /// Cria uma variavel auxiliar igual ao elemento removido do topo da stack
	assert(aux.type == STRING);	/// Verifica se o topo da stack é de facto um STRING
	return aux.STRING;			/// Retorna esse valor
}

///@brief Esta função remove um valor do topo da stack e retorna-o
STACK * pop_ARRAY(STACK *s){
	data_type aux = pop(s);		 /// Cria uma variavel auxiliar igual ao elemento removido do topo da stack
	assert(aux.type == ARRAY);	/// Verifica se o topo da stack é de facto um ARRAY
	return aux.ARRAY;			/// Retorna esse valor
}   

/// @brief Esta função verifica se um elemento é de um certo tipo
int tipo(data_type elem, int mask){
    if((elem.type & mask) != 0) return 1; /// Caso o elemento seja do tal "type" então retorna 0
    else return 0; /// caso não o seja retorna 1
}

/// @brief Esta Função imprime a stack
void imprime_s (STACK *s){ 
    int i; /// Esta variavel serve meramente para o ciclo "for" que percorre a stack
    for(i = 0; i < s -> n_elems; i++){
        data_type elem = s -> stack[i];
        TYPE tipo = elem.type; /// Esta assim definida porque foi criada antes da função tipo
        if(tipo == LONG) printf("%ld", elem.LONG); 		/// caso o valor a imprimir seja do tipo long, então printf("%ld")
        if(tipo == DOUBLE) printf("%g", elem.DOUBLE);	/// caso o valor a imprimir seja do tipo double, então printf("%g")
        if(tipo == CHAR) printf("%c", elem.CHAR);		/// caso o valor a imprimir seja do tipo char, então printf("%c")
        if(tipo == STRING) printf("%s", elem.STRING);	/// caso o valor a imprimir seja do tipo string, então printf("%s")
		if(tipo == ARRAY) aux_print_arr(elem.ARRAY);	/// caso o valor a imprimir seja do tipo array, então chama uma função auxiliar
    	if(tipo == BLOCO) printf("%s", elem.BLOCO);
	}
    putchar('\n'); /// No final da impressão troca de linha
}

/// @brief Esta função é auxiliar da função imprime_s
void aux_print_arr(STACK *s){ 
	int i;	/// Esta variavel serve meramente para o ciclo "for" que percorre a stack
	for(i = 0; i < s -> n_elems; i++){
		data_type elem = s->stack[i];
		TYPE tipo = elem.type; /// Esta assim definida porque foi criada antes da função tipo
		if(tipo == LONG) printf("%ld", elem.LONG); 		/// caso o elemento do array seja um long, imprime um long
        if(tipo == DOUBLE) printf("%g", elem.DOUBLE);	/// caso o elemento do array seja um double, imprime um double
        if(tipo == CHAR) printf("%c", elem.CHAR);		/// caso o elemento do array seja um char, imprime um char
        if(tipo == STRING) printf("%s", elem.STRING);	/// caso o elemento do array seja uma string, imprime uma string
		if(tipo == ARRAY) aux_print_arr(elem.ARRAY);	/// caso o elemento do array seja um array, volta a chamar a própria função
		if(tipo == ARRAY) printf("%s", elem.BLOCO);
	}
}

///@brief Esta função "pusha" um array para o topo da stack 
void push_BLOCO(STACK *s, char *val){
	data_type aux;		/// É criada uma variavel nova
	aux.type = BLOCO;	/// O type da variavel nova fica BLOCO
	aux.BLOCO = val;	/// E essa variavel é igual ao apontador char recebido
	push(s, aux);		/// Para finalizar há o push normal para o topo da stack
}