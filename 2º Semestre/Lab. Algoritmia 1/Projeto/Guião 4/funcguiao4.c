// funcguiao4.c

/// Este guião vai tratar da implementação de strings ou arrays.

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "funcguiao3.h"
#include <string.h>

char *strcat(char *destination, const char *source);
void inverte_s(STACK *s_origem, STACK *s); /// só para não dar warning na primeira funcao
char *strncpy(char *dest, const char *src, size_t n);
char *strtok(char *str, const char *delim);
char *strndup( const char *str, size_t size );


void concatenar(STACK *s, STACK *s_aux){
	STACK *aux = new_stack();

	while(s_aux -> n_elems > 0){
		data_type x = pop(s_aux);
               
            if(tipo(x,LONG) == 0){                                                                                            
                push_LONG(aux, x.LONG);
			}
			else if(tipo(x,DOUBLE) == 0){                   
                push_DOUBLE(aux, x.DOUBLE);
			}
			else if(tipo(x,CHAR) == 0){                   
                push_CHAR(aux, x.CHAR);
			}
			else if(tipo(x,STRING) == 0){                    
                push_STRING(aux, x.STRING);
			}
			else if(tipo(x,ARRAY) == 0){                    
                push_ARRAY(aux, x.ARRAY);                                   
			}
    }
    inverte_s(aux, s);
    free(aux);
}

void inverte_s(STACK *s_origem, STACK *s){ 
    while(s_origem->n_elems > 0){
        data_type val = pop(s_origem);

        if(tipo(val,LONG) == 0) push_LONG(s, val.LONG);             
        else if(tipo(val,DOUBLE) == 0) push_DOUBLE(s, val.DOUBLE); 
        else if(tipo(val,CHAR) == 0) push_CHAR(s, val.CHAR);
        else if(tipo(val,STRING) == 0) push_STRING(s, val.STRING);
        else if(tipo(val,ARRAY) == 0) push_ARRAY(s, val.ARRAY); 
    }
}

/// concatena 2 strings
char *concatstr(char *s1, char *s2) { /// tem este tipo para poder ser utilizada no push 
    long len1 = strlen(s1); long len2 = strlen(s2);
    long lentotal = len1 + len2;
    long lengts = sizeof(char) * (lentotal); ///teve q ser criado porque estava a dar warning na otimização -O2
    char *alloc_s = malloc(lengts); 
    
    strcpy(alloc_s, s1); /// funcão alterada porque estava a dar warning na otimização -O2
    alloc_s[lengts - 1] = '\0';
    size_t size = strlen (alloc_s); /// este tipo size_t é "medido" em memória, precisamos dele para usar a strncat
    strncat (alloc_s, s2, (lengts) - size);
    
    return alloc_s;
} 


///Esta função serve para concatenar também porem funciona para todos os tipos
/// é uma função * para poder ser usar dentro do "push"
char *concat_geral(char *str, data_type x){
    char *new_s = malloc(sizeof(char) * (strlen(str)+2));
    
        if(tipo(x,LONG) == 0) new_s[0] = (char)x.LONG;
        else if(tipo(x,DOUBLE) == 0) new_s[0] = (char)x.DOUBLE;
        else if(tipo(x,CHAR) == 0) new_s[0] = (char)x.CHAR;

    new_s[(sizeof(char) * (strlen(str)+2)) - 1] = '\0';
    strcat(new_s, str); /// função pré defenida
    return new_s;
}

///Esta função coloca um valor num array vazio
void arr_vazio(data_type val, STACK *array) { 
    STACK *stack_aux = new_stack();
    inverte_s(array, stack_aux);

    if(tipo(val,LONG) == 0){
        push_LONG(stack_aux, val.LONG);
    }
    else if(tipo(val,DOUBLE) == 0){
        push_DOUBLE(stack_aux, val.DOUBLE);
    }
    else if(tipo(val,CHAR) == 0){
        push_CHAR(stack_aux, val.CHAR);
    }
    else if(tipo(val,STRING) == 0){
        push_STRING(stack_aux, val.STRING);
    }
    else if(tipo(val,ARRAY) == 0){
        push_ARRAY(stack_aux, val.ARRAY);
    }

    inverte_s(stack_aux, array);
}

void virgula(STACK *s){
    data_type x = pop(s);
    long i;
    STACK *arr = new_stack();

    if(tipo(x,LONG) == 0){
        for(i = 0; i < x.LONG; i++) push_LONG(arr, i);
        push_ARRAY(s, arr);
    }
    if(tipo(x,STRING) == 0){
        push_LONG(s, strlen(x.STRING));
    }
    if(tipo(x,ARRAY) == 0){
        push_LONG(s, x.ARRAY->n_elems);
    } 
}


void white_space(STACK *s){
	data_type elem = pop(s);

	int i = 0, j =0;
	char array[BUFSIZ];
	
	if(tipo(elem,STRING) == 0){
		char *string = elem.STRING;
		
		while(string[i] != '\0'){
			if(string[i] != ' '){
				array[j] = string[i];
			}
			else {
				push_STRING(s,array);
				j=0;
			}
			i++;
		}

		push_STRING(s,array);
	}

	else return;
}

void new_lines(STACK *s){
	data_type val = pop(s);
	char *string = val.STRING;

	if(tipo(val, STRING)){
		STACK *array = new_stack();
		char *limitador = "\n";
    	char *aaa = strdup(string);
		char *token = strtok(aaa, limitador);
                
		while(token != NULL){
			push_STRING(array, token);
			token = strtok(NULL, limitador);
		}
    	
    	push_ARRAY(s, array);
	}

	else return;
}

/// esta funcao multiplica o array x vezes
void multiplica_arr(STACK *s, long x){
    STACK *s_aux1 = new_stack();
    STACK s_aux2 = *s;

    while(x > 1){
        s_aux2 = *s;
        concatenar(s_aux1,&s_aux2);
        x--;
    }

    concatenar(s,s_aux1);
}

/// esta funcao multiplica uma sring x vezes
void multiplica_str(char *str, long x){
    long i = 1;
    char *ax = strdup(str);

    while(i < x){
        strcat(str, ax);
        i++;
    }
}

void init_arr(STACK *s, STACK *array){
    STACK arr = *array;
    STACK *aux = new_stack();
    STACK *aux2 = new_stack();

    inverte_s(&arr, aux);
    inverte_s(aux, aux2);

    data_type val = pop(aux2);
    push_ARRAY(s, aux2);
    

    if(tipo(val,LONG) == 0){
        push_LONG(s, val.LONG);
    }
    else if(tipo(val,DOUBLE) == 0){
        push_DOUBLE(s, val.DOUBLE);
    }
    else if(tipo(val,CHAR) == 0){
        push_CHAR(s, val.CHAR);
    }
    else if(tipo(val,STRING) == 0){
        push_STRING(s, val.STRING);
    }
    else if(tipo(val,ARRAY) == 0){
        push_ARRAY(s, val.ARRAY);
    }     
}

void remove_h_arr(STACK *s, STACK *array){
    STACK arr = *array;
    STACK *aux = new_stack();
    STACK *aux2 = new_stack();

    inverte_s(&arr, aux);
    data_type val = pop(aux); /// inverte se o array e dá se pop, volta se a inverter e está tirada a sua base
    inverte_s(aux, aux2);

    push_ARRAY(s, aux2);

    if(tipo(val,LONG) == 0){
        push_LONG(s, val.LONG);
    }
    else if(tipo(val,DOUBLE) == 0){
        push_DOUBLE(s, val.DOUBLE);
    }
    else if(tipo(val,CHAR) == 0){
        push_CHAR(s, val.CHAR);
    }
    else if(tipo(val,STRING) == 0){
        push_STRING(s, val.STRING);
    }
    else if(tipo(val,ARRAY) == 0){
        push_ARRAY(s, val.ARRAY);
    }    
}

/// esta funcao percorre o array e printa no terminal se encontrar um array igual
void sub_arr(STACK *s, char *str_menor, char *str_maior){
    STACK *array = new_stack();
    char *limitador = str_menor;
    char *aaa = strdup(str_maior);
    char *token = strtok(aaa, limitador);
    
    while(token != NULL){
        push_STRING(array, token);
        token = strtok(NULL, limitador);
    }
    push_ARRAY(s, array);
}

///verifica se uma string esta incluida na outra
void sub_str(long x, char *str, STACK *s){
    char *a = strndup(x + str, 1);
    push_STRING(s, a);
    
}
                                                        //#################### problema na diferenciação destas 2 funcs
///verifica se uma string esta incluida na outra, se n tiver retorna -1
long sub_str2(char *str_menor, char *str_maior){
    long r = -1;
    long n = strlen(str_menor);
    long i;

    for(i = 0; strcmp(str_maior + i + n - 1, "\0") != 0 ; i++) {
        if (strcmp(strndup(str_maior + i, n), str_menor) == 0) {
            r = i;
        }
    }
    return r;
}

/// percorre um array à procura de um igual ou contido
void procura_arr(long val, STACK * array, STACK * stack){
    STACK arr = *array;
    data_type x;

    long n = array -> n_elems - val;
    long i = 0;
    while(i < n){
        x = pop(&arr); 
        i++;
    }

    if(tipo(x,LONG) == 0){
        push_LONG(stack, x.LONG);
    }
    else if(tipo(x,DOUBLE) == 0){
        push_DOUBLE(stack, x.DOUBLE);
    }
    else if(tipo(x,CHAR) == 0){
        push_CHAR(stack, x.CHAR);
    }
    else if(tipo(x,STRING) == 0){
        push_STRING(stack, x.STRING);
    }
    else if(tipo(x,ARRAY) == 0){
        push_ARRAY(stack, x.ARRAY);
    }
}

/// esta funcao remove do array os valores menores que o long q recebe
void remove_men_arr(long val, STACK *arr){ 
    long i;
    long nrs_remov = (arr -> n_elems) - val;

    for(i = 0; i < nrs_remov; i++) {
        pop(arr);
    }
}

/// remove do array os elemtos maiores que val
STACK *remove_mai_arr(long val, STACK *arr){ 
    data_type x = pop(arr);
    long i = 0;
    STACK *aux1 = new_stack();
    STACK *aux2 = new_stack();
    
    while (i < val){
        
        if(tipo(x,LONG) == 0){
            push_LONG(aux2, x.LONG);
        }
        if(tipo(x,DOUBLE) == 0){
            push_DOUBLE(aux2, x.DOUBLE);
        }
        if(tipo(x,CHAR) == 0){
            push_CHAR(aux2, x.CHAR);
        }
        if(tipo(x,STRING) == 0){
            push_STRING(aux2, x.STRING);
        }
        if(tipo(x,STRING) == 0){
            push_ARRAY(aux2, x.ARRAY);
        }
    
        i++;
    }
    inverte_s(aux2, aux1);
    free(aux2);
    return aux1;
}


void t_token(STACK *s){ 
    char aux[BUFSIZ];
    char *string = malloc(sizeof(char)*BUFSIZ);
    memset(string, '\0', sizeof(char)*BUFSIZ);

    while(fgets(aux,BUFSIZ,stdin) != NULL && aux[0] != '\n'){ /// ordem teve que ser alterada por causa de erros na otimização -O2
        aux[strcspn(aux,"\n")] = '\n';
        strcat(string, aux);
    } 
    push_STRING(s,string);
}

















