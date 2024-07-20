/**
* @file main.c
* @brief Neste ficheiro esta presente a função main.
* Contém também a função fake_main que funciona vai buscar todas as funções necessarias para a execução de instruções.
* E contém também muitas outras funções auxiliares.
*/

/// São incluidos todos os outros ficheiros porque a função fake_main chama quase todas as funções criadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "func.h"
#include "funcguiao3.h" 

/// Estas pré defenições servem apenas para evitar warnings na compilação
/// @brief strcmp, compara duas strings e caso sejam iguais retorna 0.
int strcmp (const char *__s1, const char *__s2);

/// @brief strtok quebra a string recebida numa serie de tokens atravéz de um dado delimitador
char *strtok(char *str, const char *delim);

/// @brief strtod converte a string apontada no argumento para um numero flutuante
double strtod(const char *str, char **endptr);

/// @brief Função defenida por nós que serve para ler a proxima linha caso seja recebido o token l
void l_token(STACK *s);

/// @brief Função que caso seja chamada verifica se o token recebido corresponde ao token chamador de determinadas funções
int direciona0(char *token, STACK *s, char *line, char **rest);

int direciona(char *token, STACK *s);

int direciona1(char *token, STACK *s);

int direciona2(char *token, STACK *s);

/// @brief Função que caso seja chamada verifica se o token recebido corresponde ao token chamador de determinadas funções
int letras(char *token, STACK *s);

int letras1(char *token, STACK *s);

int letras2(char *token, STACK *s);

/// @brief Função que caso seja chamada verifica se o token recebido corresponde ao token chamador de determinadas funções
int doispontos_letras(char *token, STACK *s);

int doispontos_letras1(char *token, STACK *s);

int doispontos_letras2(char *token, STACK *s);

/// @brief Ex função main, mas teve se ser alterada para poder ser chamada novamente
STACK *fake_main(STACK *s, char *line);

/// @brief Função que cria arrays quando recebe o token "[""
void criar_array(STACK *s, char *line);

/// @brief Função que visa o tratamento de arrays dentro de arrays e o fecho do array
char *limitadores(char *line, char *delim, char **rest);

/// @brief Funções para tentar trocar a strtok para o guião 4 mas está a funcionar mal
char *prime_strtok(char *line, char **rest);
char *resto_s (char *line);

/// @brief Função que cria strings quando recebe o token """
char *cria_str(char *line, char **rest);

/// @brief copia o caractere C para os primeiros N caracteres da string apontada por *STR
void *memset(void *str, int c, size_t n);

/// @brief Esta main teve q ser criada para poder usar ser chamada novamente para funções criardores de arrays e strings
/// @return Retorna sempre 0
int main(){ 
	STACK *s = new_stack(); /// É criada uma nova stack, s
    char line[BUFSIZ];		/// A linha é criada com o tamanho necessário, BUFSIZ

    assert(fgets(line,BUFSIZ,stdin) != NULL); /// Faz a leitura atravéz do terminal e incliu uma nova linha, caso seja diferente de NULL devolve a stack.
	assert(line[strlen(line)-1] == '\n');  	  /// Verifica se o ultimo elemento da linha é '\n'

	preenche_array(s);		/// Esta função preenche o array da stack com as variaveis do guião 3
    
	s = fake_main(s,line);	/// A stack criada é alterada pela fake_main
    imprime_s(s); 			/// Imprime a stack gerada
    return 0; 				/// Retorna 0
}

/// @brief Esta função chama as operações invocadas
/// @return Retorna sempre a stack resultante
STACK *fake_main(STACK *s, char *line){		/// Recebe a stack e a linha
	char *delim = " \t\n";	/// delimitador, necessário para a strtok
	char **rest = malloc(sizeof(char *));
	for(char *token = strtok(line,delim); token != NULL ; token = strtok(NULL,delim)){	/// Enquanto o token for diferente de NULL, continua a receber tokens
	//for(char *token = prime_strtok(line, rest); *rest != NULL ; token = prime_strtok(line, rest)){
		char *char_1;	/// Apontador para um char.
		char *char_2; 	/// Apontador para um segundo char.

    	long val_l = strtol(token, &char_1, 10);			/// strtol passar uma string para um long em base 10, no caso.
		double val_d = strtod(token, &char_2);				/// strtod passar uma string para um double em base 10, no caso.
		if(strlen(char_1) == 0) push_LONG(s, val_l);		/// Se o char1 for um LONG então pusha o valor para o topo da stack.
		else if(strlen(char_2) == 0) push_DOUBLE(s, val_d);	/// Se o char2 for um DOUBLE então pusha o valor para o topo da stack.
		else {
			if(direciona0(token, s, line, rest) != 0);
			else if(direciona(token, s) != 0); 		   /// Caso o token não corresponda a nenhum dos anteriores então é verificado se corresponde a outros tokens chamados nesta função.
			else if(direciona1(token, s) != 0);
			else if(direciona2(token, s) != 0);
			else if(letras(token, s) != 0);    		   /// Caso o token não corresponda a nenhum dos anteriores então é verificado se corresponde a outros tokens chamados nesta função.
			else if(letras1(token, s) != 0);
			else if(letras2(token, s) != 0);
			else if(doispontos_letras(token, s) != 0); /// Caso o token não corresponda a nenhum dos anteriores então é verificado se corresponde a outros tokens chamados nesta função. 
			else if(doispontos_letras1(token, s) != 0);
			else if(doispontos_letras2(token, s) != 0);	
			else push_STRING(s, token); /// Caso não seja nenhum dos tokens, então apenas pusha a linha como string.
		}	
		line = *rest; /// A linha fica com o valor apontado pelo resto e continua o ciclo "for".	
	}
	return s; /// Retorna a stack, pós operações.
}

int direciona0(char *token, STACK *s, char *line, char **rest){ /// Recebe o token e a stack em questão.
	int retorno = 0; /// Valor de retorno	
	char *delim = " \t\n";
		if(strcmp(token, "[") == 0){
			criar_array(s, limitadores(line + strlen(token), delim, rest)); retorno++;		/// Se o token for '[' cria um array.
		} 
		else if(strchr(token, '\"') != NULL){
			push_STRING(s, cria_str(line, rest));  retorno++;		/// Se o token for '[' cria um array.
		} 
	return retorno; /// Retorna 0 caso não encontre o token desejado, 1 caso encontre
}	

///@brief Esta função verifica se o token corresponde a algum dos seus casos.
///@return Retorna 1 caso o token corresponda a algum dos seus casos.
int direciona(char *token, STACK *s){ /// Recebe o token e a stack em questão.
	int retorno = 0; /// Valor de retorno
			if(strcmp(token, "l") == 0){ 
				l_token(s); retorno++;		/// Se o token for "l" então chama a função l_token e incrementa a variavel retorno.
			} 
			else if(strcmp(token, "i") == 0){ 
				i_conver(s); retorno++;		/// Se o token for "i" então chama a função i_conver e incrementa a variavel retorno.
			} 
			else if(strcmp(token, "f") == 0){ 
				f_conver(s); retorno++;		/// Se o token for "f" então chama a função f_conver e incrementa a variavel retorno.
			} 
			else if(strcmp(token, "c") == 0){ 
				c_conver(s); retorno++;		/// Se o token for "c" então chama a função c_conver e incrementa a variavel retorno.
			} 
			else if(strcmp(token, ")") == 0){ 
				incr(s); retorno++;			/// Se o token for ")" então chama a função incr e incrementa a variavel retorno
			} 
			else if(strcmp(token, "(") == 0){ 
				decr(s); retorno++;			/// Se o token for "(" então chama a função decr e incrementa a variavel retorno
			} 
			else if(strcmp(token, "+") == 0){ 
				add(s); retorno++;			/// Se o token for "+" então chama a função add e incrementa a variavel retorno
			} 
			else if(strcmp(token, "-") == 0){ 
				sub(s); retorno++;			/// Se o token for "-" então chama a função sub e incrementa a variavel retorno
			} 
			else if(strcmp(token, "*") == 0){ 
				mult(s); retorno++;			/// Se o token for "*" então chama a função mult e incrementa a variavel retorno
			}
			else if(strcmp(token, "%") == 0){ 
				modulo(s); retorno++;		/// Se o token for "%" então chama a função modulo e incrementa a variavel retorno
			}  
	return retorno; /// Retorna 0 caso não encontre o token desejado, 1 caso encontre
}

int direciona1(char *token, STACK *s){
	int retorno = 0; /// Valor de retorno
			if(strcmp(token, "/") == 0){ 
				divisao(s); retorno++;		/// Se o token for "/" então chama a função divisao e incrementa a variavel retorno
			} 
			else if(strcmp(token, "#") == 0){ 
				potencia(s); retorno++;		/// Se o token for "#" então chama a função potencia e incrementa a variavel retorno
			} 
			else if(strcmp(token, "_") == 0){ 
				duplicar(s); retorno++;		/// Se o token for "_" então chama a função duplicar e incrementa a variavel retorno
			} 
			else if(strcmp(token, "\\") == 0){ 
				troca(s); retorno++;		/// Se o token for "\" então chama a função troca e incrementa a variavel retorno
			} 
			else if(strcmp(token, "@") == 0){ 
				rodar(s); retorno++;		/// Se o token for "@" então chama a função rodar e incrementa a variavel retorno
			} 
			else if(strcmp(token, ";") == 0){ 
				pop_v1(s); retorno++;		/// Se o token for ";" então chama a função pop_v1 e incrementa a variavel retorno
			} 
			else if(strcmp(token, "$") == 0){ 
				n_esimo(s); retorno++;		/// Se o token for "$" então chama a função n_esimo e incrementa a variavel retorno
			} 
			else if(strcmp(token, "&") == 0){ 
				and(s);retorno++;			/// Se o token for "&" então chama a função and e incrementa a variavel retorno
			} 
			else if(strcmp(token, "|") == 0){ 
				or(s); retorno++;			/// Se o token for "|" então chama a função or e incrementa a variavel retorno
			}
			else if(strcmp(token, "^") == 0){ 
				xor(s); retorno++;			/// Se o token for "^" então chama a função xor e incrementa a variavel retorno
			} 
	return retorno;
}

int direciona2(char *token, STACK *s){
	int retorno = 0; /// Valor de retorno
			if(strcmp(token, "e>") == 0){ 
				e_maior(s); retorno++;		/// Se o token for "e>" então chama a função e_maior e incrementa a variavel retorno
			} 
			else if(strcmp(token, "e<") == 0){ 
				e_menor(s); retorno++;		/// Se o token for "e<" então chama a função e_menor e incrementa a variavel retorno
			} 
			else if(strcmp(token, "e&") == 0){ 
				e_shortcut(s); retorno++;	/// Se o token for "e&" então chama a função e_shortcut e incrementa a variavel retorno
			} 
			else if(strcmp(token, "e|") == 0){ 
				ou_shortcut(s); retorno++;	/// Se o token for "e|" então chama a função ou_shortcut e incrementa a variavel retorno
			} 
			else if(strcmp(token, "=") == 0){ 
				igual(s); retorno++;		/// Se o token for "=" então chama a função igual e incrementa a variavel retorno
			} 
			else if(strcmp(token, "<") == 0){ 
				menor(s); retorno++;		/// Se o token for "<" então chama a função menor e incrementa a variavel retorno
			} 
			else if(strcmp(token, ">") == 0){ 
				maior(s); retorno++;		/// Se o token for ">" então chama a função maior e incrementa a variavel retorno
			} 
			else if(strcmp(token, "!") == 0){ 
				negacao(s); retorno++;		/// Se o token for "!" então chama a função negacao e incrementa a variavel retorno
			} 
			else if(strcmp(token, "?") == 0){ 
				ponto_de_interrogacao(s); retorno++;	/// Se o token for "?" então chama a função ponto_de_interrogacao e incrementa a variavel retorno
			} 
	return retorno;

}

///@brief Esta função verifica se o token corresponde a algum dos seus casos
///@return Retorna 1 caso o token corresponda a algum dos seus casos
int letras(char *token, STACK *s){	/// Recebe o token e a stack em questão
	int retorno = 0;	/// Valor de retorno
			if(strcmp(token, "A") == 0){
				letra(s,'A'); retorno++;	/// Se o token for a letra 'A' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "B") == 0){
				letra(s,'B'); retorno++;	/// Se o token for a letra 'B' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}   
			else if(strcmp(token, "C") == 0){
				letra(s,'C'); retorno++;	/// Se o token for a letra 'C' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			} 
			else if(strcmp(token, "D") == 0){
				letra(s,'D'); retorno++;	/// Se o token for a letra 'D' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "E") == 0){
				letra(s,'E'); retorno++;	/// Se o token for a letra 'E' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			} 
			else if(strcmp(token, "F") == 0){
				letra(s,'F'); retorno++;	/// Se o token for a letra 'F' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}   
			else if(strcmp(token, "G") == 0){
				letra(s,'G'); retorno++;	/// Se o token for a letra 'G' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "H") == 0){
				letra(s,'H'); retorno++;	/// Se o token for a letra 'H' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "I") == 0){
				letra(s,'I'); retorno++;	/// Se o token for a letra 'I' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "J") == 0){
				letra(s,'J'); retorno++;	/// Se o token for a letra 'J' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
	return retorno;		/// Retorna 0 caso não encontre o token desejado, 1 caso encontre
}

int letras1(char *token, STACK *s){
	int retorno = 0;	
			if(strcmp(token, "K") == 0){
				letra(s,'K'); retorno++;	/// Se o token for a letra 'K' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "L") == 0){
				letra(s,'L'); retorno++;	/// Se o token for a letra 'L' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "M") == 0){
				letra(s,'M'); retorno++;	/// Se o token for a letra 'M' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "N") == 0){
				letra(s,'N'); retorno++;	/// Se o token for a letra 'N' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "O") == 0){
				letra(s,'O'); retorno++;	/// Se o token for a letra 'O' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "P") == 0){
				letra(s,'P'); retorno++;	/// Se o token for a letra 'P' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			} 
			else if(strcmp(token, "Q") == 0){
				letra(s,'Q'); retorno++;	/// Se o token for a letra 'Q' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "R") == 0){
				letra(s,'R'); retorno++;	/// Se o token for a letra 'R' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "S") == 0){
				letra(s,'S'); retorno++;	/// Se o token for a letra 'S' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "T") == 0){
				letra(s,'T'); retorno++;	/// Se o token for a letra 'T' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
	return retorno;		/// Retorna 0 caso não encontre o token desejado, 1 caso encontre
}

int letras2(char *token, STACK *s){
	int retorno = 0;
			if(strcmp(token, "U") == 0){
				letra(s,'U'); retorno++;	/// Se o token for a letra 'U' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "V") == 0){
				letra(s,'V'); retorno++;	/// Se o token for a letra 'V' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "W") == 0){
				letra(s,'W'); retorno++;	/// Se o token for a letra 'W' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "X") == 0){
				letra(s,'X'); retorno++;	/// Se o token for a letra 'Z' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "Y") == 0){
				letra(s,'Y'); retorno++;	/// Se o token for a letra 'Y' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "Z") == 0){
				letra(s,'Z'); retorno++;	/// Se o token for a letra 'Z' então chama a função letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, "~") == 0){ 
				not(s); retorno++;			/// Se o token for "~" então chama a função not e incrementa a variavel retorno
			} 
	return retorno;
}

///@brief Esta função verifica se o token corresponde a algum dos seus casos
///@return Retorna 1 caso o token corresponda a algum dos seus casos
int doispontos_letras(char *token, STACK *s){	/// Recebe o token e a stack em questão
	int retorno = 0;	/// Valor de retorno
			if(strcmp(token, ":A") == 0){
				doisponto_letra(s,'A'); retorno++;	/// Se o token for a letra 'A' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":B") == 0){
				doisponto_letra(s,'B'); retorno++;	/// Se o token for a letra 'B' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}   
			else if(strcmp(token, ":C") == 0){
				doisponto_letra(s,'C'); retorno++;	/// Se o token for a letra 'C' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			} 
			else if(strcmp(token, ":D") == 0){
				doisponto_letra(s,'D'); retorno++;	/// Se o token for a letra 'D' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":E") == 0){
				doisponto_letra(s,'E'); retorno++;	/// Se o token for a letra 'D' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":F") == 0){
				doisponto_letra(s,'F'); retorno++;	/// Se o token for a letra 'F' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}   
			else if(strcmp(token, ":G") == 0){
				doisponto_letra(s,'G'); retorno++;	/// Se o token for a letra 'G' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":H") == 0){
				doisponto_letra(s,'H'); retorno++;	/// Se o token for a letra 'H' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":I") == 0){
				doisponto_letra(s,'I'); retorno++;	/// Se o token for a letra 'I' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":J") == 0){
				doisponto_letra(s,'J'); retorno++;	/// Se o token for a letra 'J' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
	return retorno;			/// Retorna 0 caso não encontre o token desejado, 1 caso encontre
}

int doispontos_letras1(char *token, STACK *s){
	int retorno = 0;
			if(strcmp(token, ":K") == 0){
				doisponto_letra(s,'K'); retorno++;	/// Se o token for a letra 'K' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":L") == 0){
				doisponto_letra(s,'L'); retorno++;	/// Se o token for a letra 'L' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":M") == 0){
				doisponto_letra(s,'M'); retorno++;	/// Se o token for a letra 'M' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":N") == 0){
				doisponto_letra(s,'N'); retorno++;	/// Se o token for a letra 'N' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":O") == 0){
				doisponto_letra(s,'O'); retorno++;	/// Se o token for a letra 'O' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":P") == 0){
				doisponto_letra(s,'P'); retorno++;	/// Se o token for a letra 'P' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			} 
			else if(strcmp(token, ":Q") == 0){
				doisponto_letra(s,'Q'); retorno++;	/// Se o token for a letra 'Q' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":R") == 0){
				doisponto_letra(s,'R'); retorno++;	/// Se o token for a letra 'R' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":S") == 0){
				doisponto_letra(s,'S'); retorno++;	/// Se o token for a letra 'S' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":T") == 0){
				doisponto_letra(s,'T'); retorno++;	/// Se o token for a letra 'T' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
	return retorno;			/// Retorna 0 caso não encontre o token desejado, 1 caso encontre
}

int doispontos_letras2(char *token, STACK *s){
	int retorno = 0;
			if(strcmp(token, ":U") == 0){
				doisponto_letra(s,'U'); retorno++;	/// Se o token for a letra 'U' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":V") == 0){
				doisponto_letra(s,'V'); retorno++;	/// Se o token for a letra 'V' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":W") == 0){
				doisponto_letra(s,'W'); retorno++;	/// Se o token for a letra 'W' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":X") == 0){
				doisponto_letra(s,'X'); retorno++;	/// Se o token for a letra 'X' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":Y") == 0){
				doisponto_letra(s,'Y'); retorno++;	/// Se o token for a letra 'Y' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
			else if(strcmp(token, ":Z") == 0){
				doisponto_letra(s,'Z'); retorno++;	/// Se o token for a letra 'Z' então chama a função doisponto_letra com a stack e o token em questão, após isso, incrementa o retorno
			}  
	return retorno;
}

///@brief Funcao que cria arrays com os elementos dentro dos tokens "[]"
void criar_array(STACK *s, char *line){		/// Recebe a stack e a linha em questão
	STACK *arr = new_stack();				///	Cria uma nova stack
	push_ARRAY(s, fake_main(arr, line));	/// Pusha o array gerado, chamando a fake_main novamente com a nova stack
}

///@brief esta função verifica onde acaba o array "]" e passa só o conteudo do seu interior
char *limitadores(char *line, char *delim, char **rest){ 
	int open_token = 1;				/// Contador do numero de aberturas
	char *token;					/// Apontador para um token
    char *aaa = strdup(line);		/// duplica a string
    char *arr = malloc(sizeof(char) * strlen(line));	/// Aloca na memória o tamanho da string
    
	memset(arr, '\0', sizeof(char) * strlen(line)); /// preenche a string arr
	token = strtok(aaa, delim);	 /// definição do apontador token
    while(open_token != 0){		/// Enquanto o contador de aberturas for maior que 0 continua o ciclo
			if(strcmp(token, "[") == 0){	/// Se o token for "[" 
                open_token++;				/// então o numero de aberturas é incrementado
                strcat(strcat(arr, token) , " "); 
            } 
			else if (strcmp(token, "]") == 0){ /// Se o token for "]"
                open_token--;				   /// Então decrementa o numero de aberturas, basicamente é um "fecho"
                if(open_token != 0) strcat(strcat(arr, token) , " ");
			} 
			else strcat(strcat(arr, token) , " ");
		token = strtok(NULL, delim); /// Atulização do token
    }
	*rest = strdup(line + strlen(arr) + 3);   
    return arr;	/// Retorna o arr alocado na memoria
}

///@brief Esta função transforma em string o que está entre aspas
char *cria_str(char *line, char **rest){ 
	int open_token = 2; /// O contador de aberturas começa inicializado a 2
	long i;				/// Variavel para o ciclo "for"
	char *arr = malloc(sizeof(char)*strlen(line)); /// É alocado na memória espaço necessário para o arr final
    char *letra;
    
	memset(arr, '\0', sizeof(char)*strlen(line));

    for(i = 0; open_token != 0; i++){	/// Enquanto o contador de aberturas for maior que 0, o ciclo continua
		letra = strndup(line + i, sizeof(char));	/// O apontador letra é atualizado
		
		if (strcmp(letra, " ") == 0){
            strcat(arr, letra);
		} 
		else if(strcmp(letra, "\"") == 0) open_token--;	 /// Se a letra for " então o contador de aberturas é decrementado, basicamente é um "fecho"
		 
		else if(strchr(letra, '\"') != NULL){  
                letra[strlen(letra)-1] = '\0';
                strcat(arr, letra);
                open_token--;
		} 
		else strcat(arr, letra);
    }
	*rest = strdup(line + strlen(arr) + 3); 
	return arr;		/// Retorna o arr gerado
} 