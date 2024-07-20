/**
* @file main.c
* @brief Neste ficheiro é definida a função main que vai ser fazer funcionar todo o código contido nos outros ficheiros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "func.h"
#include "funcguiao3.h"
#include "funcguiao4.h"


/// strcmp, compara duas strings e caso sejam iguais retorna 0.
int strcmp (const char *__s1, const char *__s2);
/// strtok quebra a string recebida numa serie de tokens atravez de um dado delimitador
char *strtok(char *str, const char *delim);
/// strtod converte a string apontada no argumento para um numero flotuante
double strtod(const char *str, char **endptr);
/// função defenida por nós que serve para ler a proxima linha caso seja recebido o token l
void l_token(STACK *s);
int direciona(char *token, STACK *s);
int letras(char *token, STACK *s);
STACK *fake_main(STACK *s, char *line);
void criar_array(STACK *s, char *line);
char *limitadores(char *line, char *delim, char **rest);
char *prime_strtok(char *line, char **rest);
char *resto_s (char *line);
char *cria_str(char *line, char **rest);
void *memset(void *str, int c, size_t n);

///main teve q ser criada para poder usar ser chamada novamente para funções criardores de arrays e strings
int main(){
	STACK *s = new_stack();
    char line[BUFSIZ];

    assert(fgets(line,BUFSIZ,stdin)!=NULL); ///faz a leitura a partir de um arquivo de dados e incliu uma nova linha caso seja diferente de NULL devolve a stack.
	assert(line[strlen(line)-1]=='\n'); 

	preenche_array(s);
    
	s = fake_main(s,line);
    imprime_s(s); 
    return 0;
}

/// @brief Ao longo da função main temos vários ifs que irão ser ultilizados para consoante o simbolo que for fornecido a função main conseguir ir buscar as funções necessárias para fornecer o resultado.
STACK *fake_main(STACK *s, char *line){	
	//char line[BUFSIZ];
	char *delim = " \t\n"; 
	
	char **rest = malloc(sizeof(char *));

	//for(char *token = strtok(line,delim); token != NULL ; token = strtok(NULL,delim)){
	for (char *token = prime_strtok(line, rest); *rest != NULL ; token = prime_strtok(line, rest)){
		char *char_1;  
		
    	long val_l = strtol(token, &char_1, 10);	
		if(strlen(char_1) == 0) push_LONG(s, val_l);
		else {
	
	/*for(char *token = strtok(line,delim); token != NULL ; token = strtok(NULL,delim)){		
		char *char_1;
		double val_d = strtod(token, &char_1); 
		if(strlen(char_1) == 0) push_DOUBLE(s,val_d); 
		else if(strlen(sobra2) == 0) push_DOUBLE(s, val_d);
		else {*/
			/// usamos a função strcmp uma vez que estamos a comparar 2 strings.
			/// -1 indicando que o parâmetro 1 é menor que o parâmetro 2.
			///  0 indicando que os parâmetros são iguais.
			///  1 caso o primeiro seja maior que o segundo parâmetro.
			/// so quando os parametros forem iguais, ou seja, iguais a zero é que vai entrar dentro dos if's.
			
			if(strcmp(token, "[") == 0) criar_array(s, limitadores( line + strlen(token), delim, rest));
			else if(strchr(token, '\"') != NULL) push_STRING(s, cria_str(line, rest));  
			else if(strcmp(token, "t") == 0) t_token(s);

        
		    /// DOISPONTOS_LETRA copia o topo da stack à variavel
			else if(direciona(token, s) != 0);
            ///A até Z Coloca no topo da stack o conteúdo da variável
			else if(letras(token, s) != 0); 

			else if(strcmp(token, ",") == 0) virgula(s);	
			else if(strcmp(token, "S/") == 0) white_space(s);
			else if(strcmp(token, "N/") == 0) new_lines(s);

			
			else push_STRING(s, token);
             		
		}	
		line = *rest;	
	}
	//imprime_s(s);
	return s; 
}



int direciona(char *token, STACK *s){
	int retorno = 0;
			if(strcmp(token, "l") == 0){ 
				l_token(s); retorno++;
			} 
			if(strcmp(token, "i") == 0){ 
				i_conver(s); retorno++;
			} 
			if(strcmp(token, "f") == 0){ 
				f_conver(s); retorno++;
			} 
			if(strcmp(token, "c") == 0){ 
				c_conver(s); retorno++;
			} 
			if(strcmp(token, ")") == 0){ 
				incr(s); retorno++;
			} 
			if(strcmp(token, "(") == 0){ 
				decr(s); retorno++;
			} 
			if(strcmp(token, "+") == 0){ 
				add(s); retorno++;
			} 
			if(strcmp(token, "-") == 0){ 
				sub(s); retorno++;
			} 
			if(strcmp(token, "*") == 0){ 
				mult(s); retorno++;
			}
			if(strcmp(token, "%") == 0){ 
				modulo(s); retorno++;
			} 
			if(strcmp(token, "/") == 0){ 
				divisao(s); retorno++;
			} 
			if(strcmp(token, "#") == 0){ 
				potencia(s); retorno++;
			} 
			if(strcmp(token, "_") == 0){ 
				duplicar(s); retorno++;
			} 
			if(strcmp(token, "\\") == 0){ 
				troca(s); retorno++;
			} 
			if(strcmp(token, "@") == 0){ 
				rodar(s); retorno++;
			} 
			if(strcmp(token, ";") == 0){ 
				pop_v1(s); retorno++;
			} 
			if(strcmp(token, "$") == 0){ 
				n_esimo(s); retorno++;
			} 
			if(strcmp(token, "&") == 0){ 
				and(s);retorno++;
			} 
			if(strcmp(token, "|") == 0){ 
				 or(s); retorno++;
			}
			if(strcmp(token, "^") == 0){ 
				xor(s); retorno++;
			} 
			if(strcmp(token, "~") == 0){ 
				not(s); retorno++;
			} 
			if(strcmp(token, "e>") == 0){ 
				e_maior(s); retorno++;
			} 
			if(strcmp(token, "e<") == 0){ 
				e_menor(s); retorno++;
			} 
			if(strcmp(token, "e&") == 0){ 
				e_shortcut(s); retorno++;
			} 
			if(strcmp(token, "e|") == 0){ 
				ou_shortcut(s); retorno++;
			} 
			if(strcmp(token, "=") == 0){ 
				igual(s); retorno++;
			} 
			if(strcmp(token, "<") == 0){ 
				menor(s); retorno++;
			} 
			if(strcmp(token, ">") == 0){ 
				maior(s); retorno++;
			} 
			if(strcmp(token, "!") == 0){ 
				negacao(s); retorno++;
			} 
			if(strcmp(token, "?") == 0){ 
				ponto_de_interrogacao(s); retorno++;
			} 
	return retorno;
}


int letras(char *token, STACK *s){
	int retorno = 0;
			if(strcmp(token, "A") == 0){
				letra(s,'A'); retorno++;
			}  
			if(strcmp(token, "B") == 0){
				letra(s,'B'); retorno++;
			}   
			if(strcmp(token, "C") == 0){
				letra(s,'C'); retorno++;
			} 
			if(strcmp(token, "D") == 0){
				letra(s,'D'); retorno++;
			}  
			if(strcmp(token, "E") == 0){
				letra(s,'E'); retorno++;
			}  
			if(strcmp(token, "F") == 0){
				letra(s,'F'); retorno++;
			}   
			if(strcmp(token, "G") == 0){
				letra(s,'G'); retorno++;
			}  
			if(strcmp(token, "H") == 0){
				letra(s,'H'); retorno++;
			}  
			if(strcmp(token, "I") == 0){
				letra(s,'I'); retorno++;
			}  
			if(strcmp(token, "J") == 0){
				letra(s,'J'); retorno++;
			}  
			if(strcmp(token, "K") == 0){
				letra(s,'K'); retorno++;
			}  
			if(strcmp(token, "L") == 0){
				letra(s,'L'); retorno++;
			}  
			if(strcmp(token, "M") == 0){
				letra(s,'M'); retorno++;
			}  
			if(strcmp(token, "N") == 0){
				letra(s,'N'); retorno++;
			}  
			if(strcmp(token, "O") == 0){
				letra(s,'O'); retorno++;
			}  
			if(strcmp(token, "P") == 0){
				letra(s,'P'); retorno++;
			} 
			if(strcmp(token, "Q") == 0){
				letra(s,'Q'); retorno++;
			}  
			if(strcmp(token, "R") == 0){
				letra(s,'R'); retorno++;
			}  
			if(strcmp(token, "S") == 0){
				letra(s,'S'); retorno++;
			}  
			if(strcmp(token, "T") == 0){
				letra(s,'T'); retorno++;
			}  
			if(strcmp(token, "U") == 0){
				letra(s,'U'); retorno++;
			}  
			if(strcmp(token, "V") == 0){
				letra(s,'V'); retorno++;
			}  
			if(strcmp(token, "W") == 0){
				letra(s,'W'); retorno++;
			}  
			if(strcmp(token, "X") == 0){
				letra(s,'X'); retorno++;
			}  
			if(strcmp(token, "Y") == 0){
				letra(s,'Y'); retorno++;
			}  
			if(strcmp(token, "Z") == 0){
				letra(s,'Z'); retorno++;
			}  
	return retorno;
}

///funcao que cria arrays com os elementos dentro dos tokens "[]"
void criar_array(STACK *s, char *line){	
	STACK *arr = new_stack();
	
	push_ARRAY(s, fake_main(arr, line));
}


/// esta função verifica onde acaba o array "]" e passa so o conteudo do seu interior
char *limitadores(char *line, char *delim, char **rest){ 
	int open_token = 1;
	char *token;
    char *aaa = strdup(line);
    char *arr = malloc(sizeof(char) * strlen(line));
    
	memset(arr, '\0', sizeof(char) * strlen(line));
	token = strtok(aaa, delim);
    while(open_token != 0){
			if(strcmp(token, "[") == 0){
                open_token++;
                strcat(strcat(arr, token) , " ");
            } 
			else if (strcmp(token, "]") == 0){
                open_token--;
                if(open_token != 0) strcat(strcat(arr, token) , " ");
			} 
			else strcat(strcat(arr, token) , " ");
        
		token = strtok(NULL, delim);
    }
	*rest = strdup(line + strlen(arr) + 3);   
    return arr;
}

/// esta funcao substitui a strtok para tentar obter tokens e conseguir trabalhar com arrays
char *prime_strtok(char *line, char **rest){ 
    char *token;
	char *resto;

    resto = resto_s(line);
    
    if(resto != NULL){ 
        if(strcmp(strndup(resto + 1, sizeof(char)), " ") == 0){ 
            token = strndup(line, strlen(line)-strlen(resto + 1));  
            *rest = strdup(resto + 2); 
        } 
		else {
            token = strndup(line, strlen(line)-strlen(resto));    
            *rest = strdup(resto + 1); 
        }
    } 
	else {
      token = line; 
      *rest = NULL;
    }

    return token;
}

/// transforma em string o que está entre aspas
char *cria_str(char *line, char **rest){ 
	int open_token = 2;
	long i;
	char *arr = malloc(sizeof(char)*strlen(line));
    char *letra;
    
	memset(arr, '\0', sizeof(char)*strlen(line));

    for(i = 0; open_token != 0; i++){
		letra = strndup(line + i, sizeof(char));
		
		if (strcmp(letra, " ") == 0){
            strcat(arr, letra);
		} 
		else if(strcmp(letra, "\"") == 0){
              open_token--;
		} 
		else if(strchr(letra, '\"') != NULL){  
                letra[strlen(letra)-1] = '\0';
                strcat(arr, letra);
                open_token--;
		} 
		else strcat(arr, letra);
    }
	*rest = strdup(line + strlen(arr) + 3); 
	return arr;
}

 
 
/// funcao q recebe a line e devolve o resto dos operandos e operadores
char *resto_s (char *line){    

    char *space, *new_l, *tab, *resto;
    int space_int, new_l_int, tab_int;

	resto = NULL;
    
    if(line != NULL){                          
    	space = strchr(line, ' ');	new_l = strchr(line, '\n'); tab = strchr(line, '\t');    
      
    	if(space != NULL) space_int = strlen(space);
    	else space_int = 0;

    	if(new_l != NULL) new_l_int = strlen(new_l);
    	else new_l_int = 0;

    	if(tab != NULL) tab_int = strlen(tab);
    	else tab_int = 0;

    	if(space_int > tab_int && space_int > new_l_int) resto = space;
    	else if (tab_int > new_l_int) resto = tab;
    	else resto = new_l;
    } 
    return resto;
}

