/**
* @file func.c
* @brief Neste ficheiro são definidas as funções principais que vão ser utilizados ao do código.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fenv.h>
#include <string.h>
#include "stack.h"

/// @brief Função que vai ler a linha em Questão
void l_token(STACK *s){
  	char line[BUFSIZ];
	assert(fgets(line,BUFSIZ,stdin)!=NULL);
  	assert(line[strlen(line)-1]=='\n');
    push_STRING(s,line);
}

/** @brief Função que converte o topo da stack num Inteiro.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void i_conver(STACK *s){
   	data_type x = pop(s); 
	if(tipo(x,LONG)) push(s,x);
	else if(tipo(x,DOUBLE)) push_LONG(s, (long)x.DOUBLE); //printf("ola\n");}	/// No caso de der Double.  
   	else if(tipo(x,CHAR)) push_LONG(s, (long)x.CHAR); 		/// No caso de ser Char.  
   	else if(tipo(x,STRING)){ 						/// No caso de ser String.
		long y = atol(x.STRING);      
      	push_LONG(s,y); 
   	} 
}

/** @brief Função que converte o topo de uma stack num Double.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void f_conver(STACK *s){
   	data_type x = pop(s);
   	if(tipo(x,LONG)) push_DOUBLE(s,x.LONG); /// No caso de ser Long.
   	else if(tipo(x,CHAR)) push_DOUBLE(s,x.CHAR); /// No caso de ser Char.
   	else if(tipo(x,STRING)){ 					/// No caso de ser String.
      	double y = atof(x.STRING);      
      	push_DOUBLE(s,y);
   	} 
   	else if(tipo(x,DOUBLE)) push(s,x); 			/// No caso de ser Double.  
}

/** @brief Função que converte o topo de uma stack num Caratere.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void c_conver(STACK *s){
	data_type x = pop(s);
	if(tipo(x,CHAR)) push(s,x); 				/// No caso de ser Char.
	else if(tipo(x,DOUBLE)) push_CHAR(s,x.DOUBLE); 	/// No caso de ser Double.
	else if(tipo(x,LONG)) push_CHAR(s,x.LONG); 		/// No caso de ser Long.
}

/** @brief Função que incrementa um valor do tipo string.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void incr_STRING(STACK *s, data_type x){
	push_STRING(s, strndup(x.STRING, strlen(x.STRING) - 1));
	push_STRING(s, strndup(x.STRING + strlen(x.STRING) -1, sizeof(char)));
}

/** @brief Função que incrementa um valor.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void incr(STACK *s){
	data_type x = pop(s);
	if(tipo(x,LONG))  push_LONG(s, x.LONG + 1);///funçao que recebe 1 long e devolve o long+1.
	else if(tipo(x,DOUBLE)) push_DOUBLE(s,x.DOUBLE + 1);  ///função que recebe 1 double e devolve o double+1.
	else if(tipo(x,CHAR))   push_CHAR(s, x.CHAR + 1);        ///função que recebe 1 char e devolve o char+1.
	else if(tipo(x,STRING)) incr_STRING(s, x); 
}

/** @brief Função que decrementa um valor.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void decr_STRING(STACK *s, data_type x){
	if(tipo(x,STRING)){ 
		push_STRING(s,x.STRING + 1);
		push_STRING(s, strndup(x.STRING, sizeof(char)));
	}	
}

/** @brief Função que decrementa um valor.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void decr(STACK *s){ 
	data_type x = pop(s);
	if(tipo(x,LONG)){        ///funçao que recebe 1 long e devolve o long-1.
		push_LONG(s,x.LONG - 1);
	}
	else if(tipo(x,DOUBLE)){ 
		push_DOUBLE(s,x.DOUBLE - 1); ///funçao que recebe 1 double e devolve o double-1.
	}	
	else if(tipo(x,CHAR)){           ///funçao que recebe 1 char e devolve o char-1.
		push_CHAR(s, x.CHAR - 1);
	}
	else if(tipo(x,STRING)) decr_STRING(s, x);	
}

/** @brief Função que soma valores LONGS.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void add_LONG(STACK *s, data_type x, data_type y){ 
	if(tipo(y,LONG)){/// Função que soma 2 valores longs devolve a soma em long.
		push_LONG(s, y.LONG + x.LONG); 
	} 
	else if(tipo(y,DOUBLE)){/// Função que soma 2 valores, 1 long e um double devolve a soma em double.
		push_DOUBLE(s, y.DOUBLE + x.LONG);
	}
	else if((tipo(y,CHAR)) || (tipo(y,STRING))){/// Função que soma 2 valores 1 longs e um char devolve o long.
		push_LONG(s, x.LONG);/// Função que soma 2 valores 1 longs e uma string devolve o long.
	}
	else if(tipo(y,ARRAY)){ 		/// tivemos que adicionar, para o operador + em strings fazer a sua concatenação
		push_LONG(y.ARRAY, x.LONG);	            /// usamos os data_type "stack" e "array" como uma stack
		push_ARRAY(s, y.ARRAY);
	}
}

/** @brief Função que soma valores DOUBLES.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void add_DOUBLE(STACK *s, data_type x, data_type y){
    if(tipo(y,LONG)){  /// Função que soma 2 valores 1 double e um long devolve a soma em double.
		push_DOUBLE(s, y.LONG + x.DOUBLE);
	}
	else if(tipo(y,DOUBLE)){   /// Função que soma 2 valores doubles devolve em double.
		push_DOUBLE(s, y.DOUBLE + x.DOUBLE); 
	}
	else if((tipo(y,CHAR)) || (tipo(y,STRING))){ 
		/// Função que soma 2 valores 1 double e um char devolve o double.
		push_DOUBLE(s, x.DOUBLE);
	}
}

/** @brief Função que soma valores CHARS.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void add_CHAR(STACK *s, data_type x, data_type y){
	if(tipo(y,LONG)){   /// Função que soma 2 valores 1 char e um long devolve o long.
		push_LONG(s, y.LONG);    
	}
	else if(tipo(y,DOUBLE)){ /// Função que soma 2 valores 1 char e um double devolve o double.
		push_DOUBLE(s, y.DOUBLE);
	}
	else if(tipo(y,CHAR)){ /// Função que soma 2 valores chars devolve os 2 chars separados.
		push_CHAR(s, x.CHAR);
 		push_CHAR(s, y.CHAR);
	}
	else if(tipo(y,STRING)){   /// Função que soma 2 valores 1 char e um string.
		strncat(y.STRING, &(x.CHAR), 1);
		push_STRING(s, y.STRING);
	}
}

/** @brief Função que chama as funções que somam os valores.
*/
void add(STACK *s){         	/// tem q se adicionar + para strings para mas concatena strigns    
	data_type x = pop(s);
	data_type y = pop(s);
    if(tipo(x,LONG)) add_LONG(s, x, y); ///chama a função add_long.
	else if(tipo(x,DOUBLE)) add_DOUBLE(s, x, y); ///chama a função add_double.
	else if(tipo(x,CHAR)) add_CHAR(s, x, y);  ///chama a funcao add_char.
}  

/** @brief Função que subtrai valores LONG.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void sub_LONG(STACK *s, data_type x, data_type y){
	if(tipo(y,LONG)){   /// Função que subtrai 2 valores longs devolve em long.
		push_LONG(s, y.LONG - x.LONG);
	}
	else if(tipo(y,DOUBLE)){ /// Função que subtrai 2 valores 1 long e um double devolve em long.
		push_LONG(s, y.DOUBLE - x.LONG);
	}
	else if((tipo(y,CHAR)) || (tipo(y,STRING))){ /// Função que subtrai 2 valores 1 long e um char devolve o long.
		push_LONG(s, x.LONG);    /// Função que subtrai 2 valores 1 long e uma string devolve a string.
	}
}

/** @brief Função que subtrai valores DOUBLE.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void sub_DOUBLE(STACK *s, data_type x, data_type y){
    if(tipo(y,LONG)){      /// Função que subtrai 2 valores 1 long e um double devolve em double.
		push_DOUBLE(s, y.LONG - x.DOUBLE);
	}
	else if(tipo(y,DOUBLE)){    /// Função que subtrai 2 valores doubles devovle em double.
		push_DOUBLE(s, y.DOUBLE - x.DOUBLE);
	}
	else if((tipo(y,CHAR)) || (tipo(y,STRING))){ /// Função que subtrai 2 valores 1 double e um char devolve o double.
		push_DOUBLE(s, x.DOUBLE);        /// Função que subtrai 2 valores 1 double devolve o double.
	}	
}

/** @brief Função que subtrai valores CHARS.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void sub_CHAR(STACK *s, data_type x, data_type y){
    if(tipo(y,LONG)){    /// Função que subtrai 2 valores 1 char e um long devolve o long. 
		push_LONG(s, y.LONG);
	}
	else if(tipo(y,DOUBLE)){ /// Função que subtrai 2 valores 1 char e um double devolve o double. 
		push_DOUBLE(s, y.DOUBLE);
	}
	else if(tipo(y,CHAR)){  /// Função que subtrai 2 valores chars devolve os chars. 
		push_CHAR(s, x.CHAR);
		push_CHAR(s, y.CHAR);
	}
}

/** @brief Função que subtrai valores STRINGS.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void sub_STRING(STACK *s, data_type x, data_type y){
	if(tipo(y,LONG)){ 		/// Função que subtrai 2 valores 1 string e um long devolve o long. 
		push_LONG(s, y.LONG);
	}
	else if(tipo(y,DOUBLE)){ 		 /// Função que subtrai 2 valores 1 string e um double devolve o double.
		push_DOUBLE(s, y.DOUBLE);
	}
	else if(tipo(y,CHAR)){ 		
		push_STRING(s, x.STRING); //char *concat_geral(char *str, data_type x);
	}
	else if(tipo(y,STRING)){ 		 /// Função que subtrai 2 valores strings devolve as strings.
		push_STRING(s, x.STRING);
		push_STRING(s, y.STRING);
	}
}

/** @brief Função que chama as funcoes que subtrai valores.
*/
void sub(STACK *s){             
	data_type x = pop(s);
	data_type y = pop(s);
	if(tipo(x,LONG)) sub_LONG(s, x, y); ///chama a função sub_long.
	else if(tipo(x,DOUBLE)) sub_DOUBLE(s, x, y); ///chama a função sub_double.
	else if(tipo(x,CHAR)) sub_CHAR(s, x, y); ///chama a função sub_char.
	else if(tipo(x,STRING)) sub_STRING(s, x, y); ///chama a função sub_string.
}

/** @brief Função que multiplica valores LONGS.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void mult_LONG(STACK *s, data_type x, data_type y){
if(tipo(y,LONG)){   ///multiplica 2 longs.
		push_LONG(s, x.LONG * y.LONG);
	}
	if(tipo(y,DOUBLE)){   /// multiplica 1 long e um double devolve o resutlado em long.
		push_LONG(s, x.LONG * y.DOUBLE);
	}
	else if((tipo(y,CHAR)) || (tipo(y,STRING)) || (tipo(y,ARRAY))){ 		
		///multiplica 1 long e uma string devolve long.
		///multiplica 1 long e 1 char devolve o long.
		push_LONG(s, x.LONG);///multiplica 1 long e um array devolve long.
	}
}

/** @brief Função que multiplica valores DOUBLES.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void mult_DOUBLE(STACK *s, data_type x, data_type y){
if(tipo(y,LONG)){
		push_DOUBLE(s, x.DOUBLE * y.LONG); ///multiplica 1 double e um long devolve em double.
	}
	if(tipo(y,DOUBLE)){   /// multiplica 2 doubles devolve em double.
		push_DOUBLE(s, x.DOUBLE * y.DOUBLE);
	}
	else if((tipo(y,CHAR)) || (tipo(y,STRING)) || (tipo(y,ARRAY))){   
		/// multplica 1 double e um char devolve o double.
		push_DOUBLE(s, x.DOUBLE);///multplica 1 double e uma string devolve o double.
	}
}

/** @brief Função que multiplica valores CHARS.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void mult_CHAR(STACK *s, data_type x, data_type y){
    if(tipo(y,LONG)){
		push_LONG(s, y.LONG); ///multiplica 1 char com um long ou 1 string com um long devolve long.
	}
	else if(tipo(y,DOUBLE)){
		push_DOUBLE(s, y.DOUBLE);  ///multplica 1 char com double devolve double
	}
	else if(tipo(y,CHAR)){  ///devolve os 2 chars.
		push_CHAR(s, x.CHAR);
		push_CHAR(s, y.CHAR);
	}
	else if((tipo(y,STRING)) || (tipo(y,ARRAY))){ 		
		push_CHAR(s, x.CHAR); /// quando recebe 1 char e uma string ou 1 char e um array devolve o char.
	}
}

/** @brief Função que multiplica valores DE STRINGS.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void mult_STRING(STACK *s, data_type x, data_type y){
if((tipo(x,STRING) && tipo(y,CHAR))|| (tipo(x,STRING) && tipo(y,ARRAY))){ 		
		push_STRING(s, x.STRING); ///quando recebe 1 char e uma string ou 1 string e um array devolve o string.
	}
	if(tipo(y,LONG)){ ///devolve o long.
	push_LONG(s, y.LONG);
}
    else if(tipo(y,DOUBLE)){ /// devolve o double.
		push_DOUBLE(s, y.DOUBLE);
	}
	else if(tipo(y,STRING)){ 		
		push_STRING(s, x.STRING);  /// recebe 2 strings, devolve o mesmo.
		push_STRING(s, y.STRING);
	}  
}

/** @brief Função que multiplica valores.
*/
void mult(STACK *s){         	/// Esta função também teve que ser alterada para o guião 4, da mesma forma que a add    
  	data_type x = pop(s);
  	data_type y = pop(s);
	if(tipo(x,LONG)) mult_LONG(s, x, y); ///chama a função multlong.
	else if(tipo(x,DOUBLE)) mult_DOUBLE(s, x,y); ///chama a função multdouble.
    else if(tipo(x,CHAR)) mult_CHAR(s, x,y); ///chama a função multchar.
	else if(tipo(x,STRING)) mult_STRING(s, x,y); ///chama a função multstring.
}

/** @brief Função que dá o modulo de valores longs.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void modulo_LONG(STACK *s, data_type x, data_type y){ 
	if(tipo(y,LONG)){ ///devolve o modulo dos 2 longs.
		push_LONG(s, y.LONG % x.LONG);
	}
	else if(tipo(y,DOUBLE)){  ///recebe 1 long e um double devolve double
		push_DOUBLE(s, fmod(y.DOUBLE, x.LONG)); /// função fmod(), do header math. h. 
		                ///é usada quando precisamos obter o resto de uma divisão envolvendo valores de ponto flutuante.
	}
	else if((tipo(y,CHAR)) || (tipo(y,STRING)) || (tipo(y,ARRAY))){
		push_LONG(s, x.LONG); /// sempre recebe 1 long com char,string ou array devolve o long.
	}
}

/** @brief Função que dá o modulo de valores double.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void modulo_DOUBLE(STACK *s, data_type x, data_type y){   
	if(tipo(y,LONG)){ ///recebe um double e um long. 
		push_DOUBLE(s, fmod(y.LONG, x.DOUBLE));///função fmod(), do header math. h 
	///é usada quando precisamos obter o resto de uma divisão envolvendo valores de ponto-flutuante
	}
	else if(tipo(y,DOUBLE)){
		push_DOUBLE(s, fmod(y.DOUBLE, x.DOUBLE)); ///modulo de 2 doubles. fmod serve para obter o resto da divisao envolvendo valores decimais.
	}
	else if((tipo(y,CHAR)) || (tipo(y,STRING)) || (tipo(y,ARRAY))){ 
		/// 1 double e um char devolve o double.
		/// 1 double e uma string devolve o double.
		/// 1 double e um array devolve o array.
		push_DOUBLE(s, x.DOUBLE);
	}
}

/** @brief Função que dá o modulo de valores chars.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void modulo_CHAR(STACK *s, data_type x, data_type y){   
	if((tipo(y,LONG)) || (tipo(y,LONG))){  ///modulo de um char com um long devolve o long.
	///modulo de uma string com um long devolve o long.
		push_LONG(s, y.LONG);
	}
	else if((tipo(y,DOUBLE)) || (tipo(y,DOUBLE))){
		push_DOUBLE(s, y.DOUBLE);  ///modulo de um char com um double devolve o double.
		///modulo de uma string com um double devolve o double.
	}
	else if(tipo(y,CHAR)){
		push_CHAR(s, x.CHAR);  /// char com char devolve os chars.
		push_CHAR(s, y.CHAR);
	}
	else if((tipo(y,STRING))||(tipo(y,ARRAY))){ 
		///modulo de char com string ou array devolve o char.		
		push_CHAR(s, x.CHAR);
	}
}

/** @brief Função que dá o modulo de valores do tipo string.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void modulo_STRING(STACK *s, data_type x, data_type y){   
	if((tipo(y,CHAR)) || (tipo(y,ARRAY))){ 		
		push_STRING(s, x.STRING);///modulo de uma string com um char ou array devolve a string.
	}  
	else if(tipo(y,STRING)){ 		
		push_STRING(s, x.STRING);  ///devolve as 2 strings quando recebe 2 strings.
		push_STRING(s, y.STRING);
	}
}

/** @brief Função que chama as funções que devolve o modulo de valores.
*/
void modulo(STACK *s){                        
    data_type x = pop(s);                                
    data_type y = pop(s);                                
   if(tipo(x,LONG)) modulo_LONG(s, x, y); ///chama a função modulolong.
   else if(tipo(x,DOUBLE)) modulo_DOUBLE(s, x, y); ///chama a função modulodouble.
   else if(tipo(x,CHAR)) modulo_CHAR(s, x, y); ///chama a função modulochar.
   else if(tipo(x,STRING)) modulo_STRING(s,x,y); ///chama a função modulostring.
}

/** @brief Função que divide valores longs.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void divisao_LONG(STACK *s, data_type x, data_type y){
	if(tipo(y, LONG)){  ///divisao de 2 longs.
		push_LONG(s, y.LONG / x.LONG);
	}
	else if(tipo(y, DOUBLE)){ ///divisao de 1 double e um long.
		push_DOUBLE(s, y.DOUBLE / x.LONG);
	}
	else if((tipo(y, CHAR))||(tipo(y, STRING))){  ///divisao de 1 long com char devolve o long.
		push_LONG(s, x.LONG);
	}
}

/** @brief Função que divide valores doubles.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void divisao_DOUBLE(STACK *s, data_type x, data_type y){
	if(tipo(y, LONG)){
		push_DOUBLE(s, y.LONG / x.DOUBLE);   ///divisao de um long com double devolve double.
	}
	else if(tipo(y, DOUBLE)){
		push_DOUBLE(s, y.DOUBLE / x.DOUBLE); ///divisao de 2doubles.
	}
	else if((tipo(y, CHAR))||(tipo(y, STRING))){
		push_DOUBLE(s, x.DOUBLE); ///Divisao de 1 double com char ou string devolve double.
	}
}

/** @brief Função que divide valores do tipo chars.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void divisao_CHAR(STACK *s, data_type x, data_type y){
	if((tipo(y, LONG))){
		push_LONG(s, y.LONG); /// divisao de um char com long.
	}
	else if((tipo(y, DOUBLE))||(tipo(y, DOUBLE))){
		push_DOUBLE(s, y.DOUBLE);///divisao de um char com double ou string com double devolve double.
	}
	else if(tipo(y, CHAR)){
		push_CHAR(s, x.CHAR);
        push_CHAR(s, y.CHAR); /// divisao com 2chars, devolve os 2 chars.
	}
	else if(tipo(y, STRING)){
		push_DOUBLE(s, x.CHAR); /// divisao de um char com string devolve o char.
	}
}

/** @brief Função que divide valores do tipo strings.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void divisao_STRING(STACK *s, data_type x, data_type y){
	if(tipo(y, CHAR)){
		push_STRING(s, x.STRING); /// divisao de uma string com char devolve a string.
	}
	else if(tipo(x, STRING) && tipo(y, LONG)) ///string com long devolve long.
	push_LONG(s, y.LONG);
}

/**  @brief Função que chama as funçoes dividem valores.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void divisao(STACK *s){                            
    data_type x = pop(s);                                     
    data_type y = pop(s);                                     
   if(tipo(x,LONG)) divisao_LONG(s,x, y); ///chama a funcalo divisaolong.
   else if(tipo(x,DOUBLE)) divisao_DOUBLE(s,x,y); ///chama a funcalo divisaodouble.
   else if(tipo(x,CHAR)) divisao_CHAR(s, x, y); ///chama a funcalo divisaochar.
   else if(tipo(x,STRING)) divisao_STRING(s, x, y); ///chama a funcalo divisaostring.
} 

/** @brief Função que dá a potencia de valores.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void potencia_LONG(STACK *s, data_type x, data_type y){
	if(tipo(y,LONG)){    
	///se algum argumento tiver tipo long ou double, powl é chamado. 
		push_LONG(s, powl(y.LONG,x.LONG));   
	}
	else if(tipo(y,DOUBLE)){  ///se a possibilidade anterior nao existir, powf é chamado.
		push_DOUBLE(s, powf(y.DOUBLE,x.LONG));
	}
	else if((tipo(y,CHAR)) || (tipo(y,STRING)) || (tipo(y,ARRAY))){
		push_LONG(s, x.LONG);  ///se for do tipo long com char,string ou array devolve o long.
	}
}

/** @brief Função que dá a potencia de valores.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void potencia_DOUBLE(STACK *s, data_type x, data_type y){
	if(tipo(y,LONG)){   ///se a possibilidade anterior nao existir, powf é chamado.
		push_DOUBLE(s, powf(y.LONG,x.DOUBLE));
	}
	else if(tipo(y,DOUBLE)){   ///se a possibilidade anterior nao existir, powf é chamado.
		push_DOUBLE(s, powf(y.DOUBLE,x.DOUBLE));
	}
	else if((tipo(y,CHAR)) || (tipo(y,STRING)) || (tipo(y,ARRAY))){
		push_DOUBLE(s, x.DOUBLE);  ///se receber um double com char,string ou array devolve o double.
	}
}

/** @brief Função que dá a potencia de valores.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void potencia_CHAR(STACK *s, data_type x, data_type y){
	if((tipo(y,LONG)) || (tipo(y,LONG))){
		push_LONG(s, y.LONG);  ///caso receba um valor do tipo char com long ou uma string com long,devolve o long.
	}
	else if((tipo(y,DOUBLE)) || (tipo(y,DOUBLE))){
		push_DOUBLE(s, y.DOUBLE); ///caso receba um valor do tipo char com double ou string com double, devolve o double.
	}
	else if(tipo(y,CHAR)){
		push_CHAR(s, x.CHAR); /// char com char devolve novamente os 2 chars.
		push_CHAR(s, y.CHAR);
	}
	else if((tipo(y,STRING)) || (tipo(y,ARRAY))){ 		
		push_CHAR(s, x.CHAR);  ///potencia de char com string ou char com array devolve o char.
	}
}

/** @brief Função que dá a potencia de valores.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void potencia_STRING(STACK *s, data_type x, data_type y){
	if((tipo(y,CHAR)) || (tipo(y,ARRAY))){ 		
		push_STRING(s, x.STRING);  ///potencia de string com um char ou string com um array devolve a string.
	}  
}

/** @brief Função que dá a potencia de valores.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void potencia_ARRAY(STACK *s, data_type x, data_type y){
	if((tipo(y,LONG)) || (tipo(y,DOUBLE)) || (tipo(y,CHAR)) || (tipo(y,STRING)) || (tipo(y,ARRAY))){ 		
		push_ARRAY(s, x.ARRAY);///se receber um valor do tipo array com long double char string ou array devolve array.	
	} 					
}

/**
*@brief Função que dá a potencia de valores.
*/
void potencia(STACK *s){             ///Calcula o valor de base elevado à potência exponente.
  	data_type x = pop(s);
  	data_type y = pop(s);								  
    if(tipo(x,LONG)) potencia_LONG(s, x, y);  ///chama a função potencialong.
	else if(tipo(x,DOUBLE)) potencia_DOUBLE(s, x, y); ///chama a função potenciadouble.
	else if(tipo(x,CHAR)) potencia_CHAR(s, x, y); ///chama a função potenciachar.
	else if(tipo(x,STRING)) potencia_STRING(s, x, y); ///chama a função potenciastring.
    else if(tipo(x,ARRAY)) potencia_ARRAY(s, x, y); ///chama a função potenciaarray.
}

/** @brief Função que duplica valores longs.
*/
void duplicar_LONG(STACK *s, data_type x){
	if(tipo(x,LONG)){
		push_LONG(s, x.LONG);  ///retorna 2 vezes o long.
        push_LONG(s, x.LONG);
	}
}

/** @brief Função que duplica valores doubles.
*/
void duplicar_DOUBLE(STACK *s, data_type x){
	if(tipo(x,DOUBLE)){
		push_DOUBLE(s, x.DOUBLE); ///retorna 2 vezes o double.
		push_DOUBLE(s, x.DOUBLE);
	}
}

/** @brief Função que duplica valores chars.
*/
void duplicar_CHAR(STACK *s, data_type x){
	if(tipo(x,CHAR)){
		push_CHAR(s, x.CHAR);///retorna 2 vezes o char.
        push_CHAR(s, x.CHAR);
	}	
}

/** @brief Função que duplica valores do tipo string.
*/
void duplicar_STRING(STACK *s, data_type x){
	if(tipo(x,STRING)){
		push_STRING(s, x.STRING); ///retorna 2 vezes a string.
        push_STRING(s, x.STRING);
	}
}

/** @brief Função que chama as funçoes que duplicam valores.
*/
void duplicar(STACK *s){
	data_type x = pop(s);
	if(tipo(x,LONG)) duplicar_LONG(s, x );  ///chama a função dplicalong.
    else if(tipo(x,DOUBLE)) duplicar_DOUBLE(s, x); ///chama a função dplicadouble.
	else if(tipo(x,CHAR)) duplicar_CHAR(s, x); ///chama a função dplicachar.
	else if(tipo(x,STRING)) duplicar_STRING(s, x); ///chama a função dplicastring.
}

/** @brief Função que troca os dois elementos to topo da stack.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void troca(STACK *s){
	data_type y = pop(s);
	data_type x = pop(s);
	/// troca y
	if(tipo(y,LONG)) push_LONG(s, y.LONG); /// No caso de ser Long
	else if(tipo(y,DOUBLE)) push_DOUBLE(s, y.DOUBLE); /// No caso de ser Double
	else if(tipo(y,CHAR)) push_CHAR(s, y.CHAR); /// No caso de ser Char
	else if(tipo(y,STRING)) push_STRING(s, y.STRING); /// No caso de ser String
	else if(tipo(y,ARRAY)) push_ARRAY(s, y.ARRAY); /// No caso de ser Array
	else if(tipo(y,BLOCO)) push_BLOCO(s, y.BLOCO); /// No caso de ser Bloco
	///troca x
	if(tipo(x,LONG)) push_LONG(s, x.LONG); /// No caso de ser Long
	else if(tipo(x,DOUBLE)) push_DOUBLE(s, x.DOUBLE); /// No caso de ser Double
	else if(tipo(x,CHAR)) push_CHAR(s, x.CHAR); /// No caso de ser Char
	else if(tipo(x,STRING)) push_STRING(s, x.STRING); /// No caso de ser String
	else if(tipo(x,ARRAY)) push_ARRAY(s, x.ARRAY); /// No caso de ser Array
	else if(tipo(x,BLOCO)) push_BLOCO(s, x.BLOCO); /// No caso de ser Bloco
}

/** @brief Função que roda os três elementos no topo da stack.
 *Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
 */
void rodar(STACK *s){
	data_type x = pop(s);
	data_type y = pop(s);
	data_type z = pop(s);
	///roda y
	if(tipo(y, LONG)) push_LONG(s, y.LONG); /// No caso de ser Long
	else if(tipo(y, DOUBLE)) push_DOUBLE(s, y.DOUBLE); /// No caso de ser Double
	else if(tipo(y, CHAR)) push_CHAR(s, y.CHAR); /// No caso de ser Char
	else if(tipo(y, STRING)) push_STRING(s, y.STRING); /// No caso de ser String
	else if(tipo(y, ARRAY)) push_ARRAY(s, y.ARRAY); /// No caso de ser Array
	///roda x
	if(tipo(x, LONG)) push_LONG(s, x.LONG); /// No caso de ser Long
	else if(tipo(x, DOUBLE)) push_DOUBLE(s, x.DOUBLE); /// No caso de ser Double
	else if(tipo(x, CHAR)) push_CHAR(s, x.CHAR); /// No caso de ser Char
	else if(tipo(x, STRING)) push_STRING(s, x.STRING); /// No caso de ser String
	else if(tipo(x, ARRAY)) push_ARRAY(s, x.ARRAY); /// No caso de ser Array
	///roda z
	if(tipo(z, LONG)) push_LONG(s, z.LONG); /// No caso de ser Long
	else if(tipo(z, DOUBLE)) push_DOUBLE(s, z.DOUBLE); /// No caso de ser Double
	else if(tipo(z, CHAR)) push_CHAR(s, z.CHAR); /// No caso de ser Char
	else if(tipo(z, STRING)) push_STRING(s, z.STRING); /// No caso de ser String
	else if(tipo(z, ARRAY)) push_ARRAY(s, z.ARRAY); /// No caso de ser Array
}

///@brief funçao pop.
void pop_v1(STACK *s){
	pop(s);
}

/// @brief Função que coloca o n_esimo elemento no topo da stack
void n_esimo (STACK *s){
	STACK *stack_aux = new_stack();
	data_type indice = pop(s);
	long x = indice.LONG;
	int i = 0;
	while(i < x){
		data_type p = pop(s);
		push(stack_aux,p);
		i += 1;
	}
	data_type val = top_da_stack(s);
	int j = 0;
	while(j < i){
		data_type p = pop(stack_aux);
		push(s,p);
		j += 1;
	}
	push(s,val);
}

/** @brief Função que calcula o "Bitwise AND" entre valores.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void and(STACK *s){             
    data_type x = pop(s);                                
    data_type y = pop(s);                                
    data_type d_val;     
 	if(tipo(x, LONG) && tipo(y, LONG)){ 	/// No caso de 2 Longs.          
    	d_val.type = LONG;                                     
    	d_val.LONG = x.LONG & y.LONG;  
	}                       
 	else if(tipo(x, CHAR) && tipo(y, LONG)){ 	/// No caso de Char e Long com resultado Long.    
    	d_val.type = LONG;                                     
    	d_val.LONG = x.CHAR & y.LONG;  
	}                        
 	else if(tipo(x, LONG) && tipo(y, CHAR)){ 	/// No caso de Long e Char com resultado Long.     
    	d_val.type = LONG;                                     
    	d_val.LONG = x.LONG & y.CHAR;  
	}                       
 	else if(tipo(x, CHAR) && tipo(y, CHAR)){ 	/// No caso de 2 Chars.     
    	d_val.type = CHAR;                                     
    	d_val.CHAR = x.CHAR & y.CHAR;  
	}    
 	push(s,d_val);
}

/** @brief Função que calcula o "Bitwise OR" entre valores.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void or(STACK *s){                   
    data_type x = pop(s);                                
    data_type y = pop(s);                                
    data_type d_val;
 	if(tipo(x, LONG) && tipo(y, LONG)){ 	/// No caso de 2 Longs.         
    	d_val.type = LONG;                                     
    	d_val.LONG = (x.LONG | y.LONG);  
	}                     
 	else if(tipo(x, CHAR) && tipo(y, LONG)){ 	/// No caso de Char e Long com resultado Long. 
    	d_val.type = LONG;                                     
    	d_val.LONG = (x.CHAR | y.LONG);
	}                     
 	else if(tipo(x, LONG) && tipo(y, CHAR)){ 	/// No caso de Long e Char com resultado Long.
    	d_val.type = LONG;                                     
    	d_val.LONG = (x.LONG | y.CHAR);  
	}                     
 	else if(tipo(x, CHAR) && tipo(y, CHAR)){ 	/// No caso de 2 Chars.     
    	d_val.type = LONG;                                     
    	d_val.LONG = (x.CHAR | y.CHAR);  
	}   
 	push(s,d_val);
}

/** @brief Função que calcula o "Bitwise XOR" entre valores.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void xor(STACK *s){                          
    data_type x = pop(s);                                
    data_type y = pop(s);                                
    data_type d_val;
 	if(tipo(x, LONG) && tipo(y, LONG)){ 	/// No caso de 2 Longs.           
    	d_val.type = LONG;                                     
    	d_val.LONG = x.LONG ^ y.LONG; 
	}                       
  	else if(tipo(x, CHAR) && tipo(y, LONG)){ 	/// No caso de Char e Long com resultado Long.    
    	d_val.type = LONG;                                     
    	d_val.LONG = x.CHAR ^ y.LONG;  
	}                       
  	else if(tipo(x, LONG) && tipo(y, CHAR)){ 	/// No caso de Long e Char com resultado Long.    
    	d_val.type = LONG;                                     
    	d_val.LONG = x.LONG ^ y.CHAR;  
	}                       
 	else if(tipo(x, CHAR) && tipo(y, CHAR)){ 	/// No caso de 2 Chars.     
    	d_val.type = LONG;                                     
    	d_val.LONG = x.CHAR ^ y.CHAR;  
	}                 
 	push(s,d_val);
}

/** @brief Função que calcula o "Bitwise NOT" entre valores.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void not(STACK *s){                     
    data_type x = pop(s);                                

 	if(tipo(x, LONG)){                                 
    	push_LONG(s, ~(x.LONG)); /// No caso de ser Long
	}
	else if(tipo(x, DOUBLE)){                                 
    	if(fmod(x.DOUBLE, 1) == 0) push_LONG(s, ~((long)x.DOUBLE)); /// No caso de ser Double
	}                  
}