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
#include "funcguiao4.h"

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
	if(tipo(x,DOUBLE)) push_LONG(s,x.DOUBLE); 	/// No caso de der Double.  
   	if(tipo(x,CHAR)) push_LONG(s,x.CHAR); 		/// No caso de ser Char.  
   	if(tipo(x,STRING)){ 						/// No caso de ser String.
      	long y = atol(x.STRING);      
      	push_LONG(s,y); 
   	} 
   	else push(s,x);  
}

/** @brief Função que converte o topo de uma stack num Double.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void f_conver(STACK *s){
   	data_type x = pop(s);
   	if(tipo(x,LONG)) push_DOUBLE(s,x.LONG); /// No caso de ser Long.
   	if(tipo(x,CHAR)) push_DOUBLE(s,x.CHAR); /// No caso de ser Char.
   	if(tipo(x,STRING)){ 					/// No caso de ser String.
      	double y = atof(x.STRING);      
      	push_DOUBLE(s,y);
   	} 
   	if(tipo(x,DOUBLE)) push(s,x); 			/// No caso de ser Double.  
}

/** @brief Função que converte o topo de uma stack num Caratere.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void c_conver(STACK *s){
	data_type x = pop(s);
	if(tipo(x,CHAR)) push(s,x); 				/// No caso de ser Char.
	if(tipo(x,DOUBLE)) push_CHAR(s,x.DOUBLE); 	/// No caso de ser Double.
	if(tipo(x,LONG)) push_CHAR(s,x.LONG); 		/// No caso de ser Long.
}

/** @brief Função que incrementa um valor.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void incr(STACK *s){
	data_type x = pop(s);
/*	data_type d_val;
	if(tipo(x,LONG)){ 			/// No caso de der Long.
		d_val.type = LONG;
		d_val.LONG = ++x.LONG;
	}
	if(tipo(x,DOUBLE)){ 		/// No caso de der Double.
		d_val.type = DOUBLE;
		d_val.DOUBLE = ++x.DOUBLE;
	}
	if(tipo(x,CHAR)){ 			/// No caso de der Char.
		d_val.type = CHAR;
		d_val.CHAR = ++x.CHAR;
	} */
if(tipo(x,LONG)){
	push_LONG(s, x.LONG + 1);
}
if(tipo(x,DOUBLE)){ 
	push_DOUBLE(s,x.DOUBLE + 1);
}	
if(tipo(x,CHAR)){
push_LONG(s, x.CHAR + 1);
}
if(tipo(x,STRING)){ 
push_STRING(s, strndup(x.STRING, strlen(x.STRING) - 1));
push_STRING(s, strndup(x.STRING + strlen(x.STRING) -1, sizeof(char)));
}		
if(tipo(x,ARRAY)){ 		
init_arr(s, x.ARRAY);
}
//push(s,d_val);
}

/** @brief Função que decrementa um valor.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void decr(STACK *s){ 
	data_type x = pop(s);
/*	data_type d_val;
	if(tipo(x,LONG)){ 		/// No caso de der Long.
		d_val.type = LONG;
		d_val.LONG = --x.LONG;
	}
	if(tipo(x,DOUBLE)){ 	/// No caso de der Double.
		d_val.type = DOUBLE;
		d_val.DOUBLE = --x.DOUBLE;
	}
	if(tipo(x,CHAR)){ 		/// No caso de der Char.
		d_val.type = CHAR;
		d_val.CHAR = --x.CHAR;
	}*/
if(tipo(x,LONG)){
	push_LONG(s, x.LONG - 1);
}
if(tipo(x,DOUBLE)){ 
	push_DOUBLE(s,x.DOUBLE - 1);
}	
if(tipo(x,CHAR)){
push_LONG(s, x.CHAR - 1);
}
if(tipo(x,STRING)){ 
push_STRING(s, x.STRING + 1);
push_STRING(s, strndup(x.STRING, sizeof(char)));
}		
if(tipo(x,ARRAY)){
	init_arr(s, x.ARRAY);
}
//	push(s,d_val);
}

/** @brief Função que soma valores.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void add(STACK *s) {         	/// tem q se adicionar + para strings para mas concatena strigns    
data_type x = pop(s);
data_type y = pop(s);
/*data_type d_val;
if(tipo(x,LONG) && tipo(y,LONG)){ 		/// Soma de 2 Longs.
	d_val.type = LONG;
	d_val.LONG = x.LONG + y.LONG;
}
if(tipo(x,DOUBLE) && tipo(y,LONG)){ 	/// Soma de Double e Long com resultado Double.
	d_val.type = DOUBLE;
	d_val.DOUBLE = x.DOUBLE + y.LONG;
}
if(tipo(x,DOUBLE) && tipo(y,DOUBLE)){ 	/// Soma de 2 Doubles.
	d_val.type = DOUBLE;
	d_val.DOUBLE = x.DOUBLE + y.DOUBLE;
}
if(tipo(x,LONG) && tipo(y,DOUBLE)){ 	/// Soma de Long e Double com resultado Double.
	d_val.type = DOUBLE;
	d_val.DOUBLE = x.LONG + y.DOUBLE;
}
if(tipo(x,LONG) && tipo(y,CHAR)){ 		/// Soma de Long e Char com resultado Char.
	d_val.type = CHAR;
	d_val.CHAR = x.LONG + y.CHAR;
}
if(tipo(x,CHAR) && tipo(y,LONG)){ 		/// Soma de Char e Long com resultado Long.
	d_val.type = LONG;
	d_val.LONG = x.LONG + y.CHAR;
}
if(tipo(x,DOUBLE) && tipo(y,CHAR)){ 	/// Soma de Double e Char com resultado Double.
	d_val.type = DOUBLE;
	d_val.DOUBLE = x.DOUBLE + y.CHAR;
}
if(tipo(x,CHAR) && tipo(y,DOUBLE)){ 	/// Soma de Char e Double com resultado Double.
	d_val.type = DOUBLE;
	d_val.DOUBLE = x.DOUBLE + y.CHAR;
}
if(tipo(x,CHAR) && tipo(y,CHAR)){ 		/// Soma 2 Chars
	d_val.type = LONG;
	d_val.LONG = x.CHAR + y.CHAR;
} */
if(tipo(x,LONG) && tipo(y,LONG)){
	push_LONG(s, y.LONG + x.LONG);
} 
if(tipo(x,LONG) && tipo(y,DOUBLE)){
push_DOUBLE(s, y.DOUBLE + x.LONG);
}
if(tipo(x,LONG) && tipo(y,CHAR)){
push_LONG(s, x.LONG);
}
if(tipo(x,LONG) && tipo(y,STRING)){
push_LONG(s, x.LONG);
}
if(tipo(x,LONG) && tipo(y,ARRAY)){ 		/// tivemos que adicionar, para o operador + em strings fazer a sua concatenação
push_LONG(y.ARRAY, x.LONG);	            /// usamos os data_type "stack" e "array" como uma stack
push_ARRAY(s, y.ARRAY);
}
if(tipo(x,STRING) && tipo(y,LONG)){ 		
push_STRING(s,concat_geral(x.STRING, y)); //char *concat_geral(char *str, data_type x);
}
if(tipo(x,DOUBLE) && tipo(y,LONG)){ 
	push_DOUBLE(s,  y.LONG + x.DOUBLE);
}	
if(tipo(x,DOUBLE) && tipo(y,DOUBLE)){ 
	push_DOUBLE(s,  y.DOUBLE + x.DOUBLE);
}	
if(tipo(x,DOUBLE) && tipo(y,CHAR)){ 
	push_DOUBLE(s, x.DOUBLE);
}
if(tipo(x,DOUBLE) && tipo(y,STRING)){ 		
//push_DOUBLE(s, x.DOUBLE);
		  strncat(y.STRING, &(x.CHAR), 1);
         push_STRING(s, y.STRING);
}	
if(tipo(x,DOUBLE) && tipo(y,ARRAY)){ 	
push_DOUBLE(s, x.DOUBLE);
}	
if(tipo(x,CHAR) && tipo(y,LONG)){
push_LONG(s, y.LONG);
}
if(tipo(x,CHAR) && tipo(y,DOUBLE)){
push_DOUBLE(s, y.DOUBLE);
}
if(tipo(x,CHAR) && tipo(y,CHAR)){
 push_CHAR(s, x.CHAR);
 push_CHAR(s, y.CHAR);
}
if(tipo(x,CHAR) && tipo(y,STRING)){
strncat(y.STRING, &(x.CHAR), 1);
push_STRING(s, y.STRING);
}
if(tipo(x,CHAR) && tipo(y,ARRAY)){
push_CHAR(s, y.CHAR);
}	
if(tipo(x,STRING) && tipo(y,DOUBLE)){ 
push_STRING(s,concat_geral(x.STRING,y));			
}
if(tipo(x,STRING) && tipo(y,CHAR)){ 
push_STRING(s,concat_geral(x.STRING,y));		
}
if(tipo(x,STRING) && tipo(y,STRING)){ 		
push_STRING(s, concatstr(y.STRING, x.STRING));
}
if(tipo(x,STRING) && tipo(y,ARRAY)){ 
push_STRING(s,concat_geral(x.STRING, y));
}

if(tipo(x,ARRAY) && tipo(y,LONG)){ 		
		arr_vazio(y, x.ARRAY);    
		push_ARRAY(s, x.ARRAY);
}
if(tipo(x,ARRAY) && tipo(y,ARRAY)){ 
	concatenar(y.ARRAY,x.ARRAY);
	push_ARRAY(s, y.ARRAY);
}
//push(s,d_val);
}

/** @brief Função que subtrai valores.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void sub(STACK *s){             
data_type x = pop(s);
data_type y = pop(s);
/*data_type d_val;
if(tipo(x,LONG) && tipo(y,LONG)){ 		/// Subtração de 2 Longs.
	d_val.type = LONG;
	d_val.LONG = -x.LONG + y.LONG;
}
if(tipo(x,DOUBLE) && tipo(y,LONG)){ 	/// Subtração de Double 2 Long com resultado Double.
	d_val.type = DOUBLE;
	d_val.DOUBLE = -x.DOUBLE + y.LONG;
}
if(tipo(x,DOUBLE) && tipo(y,DOUBLE)){ 	/// Subtração de 2 Doubles.
	d_val.type = DOUBLE;
	d_val.DOUBLE = -x.DOUBLE + y.DOUBLE;
}
if(tipo(x,LONG) && tipo(y,DOUBLE)){ 	/// Subtração de Long e Double com resultado Double.
	d_val.type = DOUBLE;
	d_val.DOUBLE = -x.LONG + y.DOUBLE;
}
if(tipo(x,LONG) && tipo(y,CHAR)){ 		/// Subtração de Long e Char com resultado Char.
	d_val.type = CHAR;
	d_val.CHAR = -x.LONG + y.CHAR;
}
if(tipo(x,CHAR) && tipo(y,LONG)){ 		/// Subtração de Char e Long com resultado Long.
	d_val.type = LONG;
	d_val.LONG = -x.LONG + y.CHAR;
}
if(tipo(x,DOUBLE) && tipo(y,CHAR)){ 	/// Subtração de Double e Char com resultado Double.
	d_val.type = DOUBLE;
	d_val.DOUBLE = -x.DOUBLE + y.CHAR;
}
if(tipo(x,CHAR) && tipo(y,DOUBLE)){ 	/// Subtração de Char e Double com resultado Double.
	d_val.type = DOUBLE;
	d_val.DOUBLE = -x.DOUBLE + y.CHAR;
}
if(tipo(x,CHAR) && tipo(y,CHAR)){ 		/// Subtração de 2 Chars.
	d_val.type = LONG;
	d_val.LONG = -x.CHAR + y.CHAR;
} */
if(tipo(x,LONG) && tipo(y,LONG)){
push_LONG(s, y.LONG - x.LONG);
}
if(tipo(x,LONG) && tipo(y,DOUBLE)){ 
push_LONG(s, y.DOUBLE - x.LONG);
}
if(tipo(x,LONG) && tipo(y,CHAR)){ 
push_LONG(s, x.LONG);
}
if(tipo(x,LONG) && tipo(y,STRING)){ 		
push_LONG(s, x.LONG);
}
if(tipo(x,LONG) && tipo(y,ARRAY)){ 		/// tivemos que adicionar, para o operador - em strings fazer a sua concatenação
push_LONG(y.ARRAY, x.LONG);	 /// usamos os data_type "stack" e "array" como uma stack
push_ARRAY(s, y.ARRAY);
}
if(tipo(x,DOUBLE) && tipo(y,LONG)){
push_DOUBLE(s, y.LONG - x.DOUBLE);
}
if(tipo(x,DOUBLE) && tipo(y,DOUBLE)){
push_DOUBLE(s, y.DOUBLE - x.DOUBLE);
}
if(tipo(x,DOUBLE) && tipo(y,CHAR)){
push_DOUBLE(s, x.DOUBLE);
}
if(tipo(x,DOUBLE) && tipo(y,STRING)){ 		
//push_DOUBLE(s, x.DOUBLE);
  		strncat(y.STRING, &(x.CHAR), 1);
        push_STRING(s, y.STRING);
}
if(tipo(x,CHAR) && tipo(y,LONG)){
push_LONG(s, y.LONG);
}
if(tipo(x,CHAR) && tipo(y,DOUBLE)){
push_DOUBLE(s, y.DOUBLE);
}
if(tipo(x,CHAR) && tipo(y,CHAR)){
push_CHAR(s, x.CHAR);
push_CHAR(s, y.CHAR);
}
if(tipo(x,CHAR) && tipo(y,STRING)){ 		
//push_DOUBLE(s, x.CHAR);		
		strncat(y.STRING, &(x.CHAR), 1);
		push_STRING(s, y.STRING);
}
if(tipo(x,STRING) && tipo(y,LONG)){ 		
push_LONG(s, y.LONG);
}
if(tipo(x,STRING) && tipo(y,DOUBLE)){ 		
push_DOUBLE(s, y.DOUBLE);
}
if(tipo(x,STRING) && tipo(y,CHAR)){ 		
push_STRING(s, x.STRING); //char *concat_geral(char *str, data_type x);
}
if(tipo(x,STRING) && tipo(y,STRING)){ 		
push_STRING(s, x.STRING);
push_STRING(s, y.STRING);
}
if(tipo(x,ARRAY) && tipo(y,LONG)){ 		
	arr_vazio(y, x.ARRAY);          //ARRAY LONG
	push_ARRAY(s, x.ARRAY);
}
if(tipo(x,ARRAY) && tipo(y,ARRAY)){ 	//ARRAY ARRAY
	concatenar(y.ARRAY,x.ARRAY);
	push_ARRAY(s, y.ARRAY);
}
//push(s,d_val);
}

/** @brief Função que multiplica valores.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void mult(STACK *s){         	/// Esta função também teve que ser alterada para o guião 4, da mesma forma que a add    
  	data_type x = pop(s);
  	data_type y = pop(s);
 /* 	data_type d_val;
  	if(tipo(x,LONG) && tipo(y,LONG)){ 		/// Multiplicação de 2 Longs.
  		d_val.type = LONG;
  		d_val.LONG = x.LONG * y.LONG;
  	}
	if(tipo(x,DOUBLE) && tipo(y,LONG)){ 	/// Multiplicação de Double e Long com resultado Double.
  		d_val.type = DOUBLE;
  		d_val.DOUBLE = x.DOUBLE * y.LONG;
  	}
  	if(tipo(x,DOUBLE) && tipo(y,DOUBLE)){ 	/// Multiplicação de 2 Doubles.
  		d_val.type = DOUBLE;
  		d_val.DOUBLE = x.DOUBLE * y.DOUBLE;
	  }
  	if(tipo(x,LONG) && tipo(y,DOUBLE)){ 	/// Multiplicação de Long e Double com resultado Double.
  		d_val.type = DOUBLE;
  		d_val.DOUBLE = x.LONG * y.DOUBLE;
  	}
  	if(tipo(x,LONG) && tipo(y,CHAR)){ 		/// Multiplicação de Long e Char com resultado Char.
  		d_val.type = CHAR;
  		d_val.CHAR = x.LONG * y.CHAR;
  	}
  	if(tipo(x,CHAR) && tipo(y,LONG)){ 		/// Multiplicação de Char e Long com resultado Long.
  		d_val.type = LONG;
  		d_val.LONG = x.LONG * y.CHAR;
  	}
  	if(tipo(x,DOUBLE) && tipo(y,CHAR)){ 	/// Multiplicação de Double e Char com resultado Double.
  		d_val.type = DOUBLE;
  		d_val.DOUBLE = x.DOUBLE * y.CHAR;
  	}
  	if(tipo(x,CHAR) && tipo(y,DOUBLE)){ 	/// Multiplicação de Char com Double com resultado Double.
  		d_val.type = DOUBLE;
  		d_val.DOUBLE = x.DOUBLE * y.CHAR;
  	}    //ARRAY LONG
  	if(tipo(x,CHAR) && tipo(y,CHAR)){ 		/// Multiplicação de 2 Chars.
  		d_val.type = LONG;
  		d_val.LONG = x.CHAR * y.CHAR;
  	} */
if(tipo(x,LONG) && tipo(y,LONG)){
push_LONG(s, x.LONG * y.LONG);
}
if(tipo(x,LONG) && tipo(y,DOUBLE)){
push_LONG(s, x.LONG * y.DOUBLE);
}
if(tipo(x,LONG) && tipo(y,CHAR)){
push_LONG(s, x.LONG);
}
if(tipo(x,LONG) && tipo(y,STRING)){ 		
multiplica_str(y.STRING, x.LONG);
push_STRING(s, y.STRING);
}
if(tipo(x,LONG) && tipo(y,ARRAY)){ 		
multiplica_arr(y.ARRAY, x.LONG);
push_ARRAY(s, y.ARRAY);  
}
if(tipo(x,DOUBLE) && tipo(y,LONG)){
push_DOUBLE(s, x.DOUBLE * y.LONG);
}
if(tipo(x,DOUBLE) && tipo(y,DOUBLE)){
push_DOUBLE(s, x.DOUBLE * y.DOUBLE);
}
if(tipo(x,DOUBLE) && tipo(y,CHAR)){
push_DOUBLE(s, x.DOUBLE);
}
if(tipo(x,DOUBLE) && tipo(y,STRING)){ 		
push_DOUBLE(s, x.DOUBLE); 
}
if(tipo(x,DOUBLE) && tipo(y,ARRAY)){ 		
push_DOUBLE(s, x.DOUBLE); 
}
if(tipo(x,CHAR) && tipo(y,LONG)){
push_LONG(s, y.LONG);
}
if(tipo(x,CHAR) && tipo(y,DOUBLE)){
push_DOUBLE(s, y.DOUBLE);
}
if(tipo(x,CHAR) && tipo(y,CHAR)){
push_CHAR(s, x.CHAR);
push_CHAR(s, y.CHAR);
}
if(tipo(x,CHAR) && tipo(y,STRING)){ 		
push_CHAR(s, x.CHAR);
}
if(tipo(x,CHAR) && tipo(y,ARRAY)){ 		
push_CHAR(s, x.CHAR);
}
if(tipo(x,STRING) && tipo(y,LONG)){ 		
push_LONG(s, y.LONG);
}
if(tipo(x,STRING) && tipo(y,DOUBLE)){ 		
push_DOUBLE(s, y.DOUBLE);
}  
if(tipo(x,STRING) && tipo(y,CHAR)){ 		
push_STRING(s, x.STRING);
}  
if(tipo(x,STRING) && tipo(y,STRING)){ 		
push_STRING(s, x.STRING);
push_STRING(s, y.STRING);
}  
if(tipo(x,STRING) && tipo(y,ARRAY)){ 		
push_STRING(s, x.STRING);
}  
if(tipo(x,ARRAY) && tipo(y,LONG)){ 		
multiplica_arr(x.ARRAY, y.LONG);
push_ARRAY(s, x.ARRAY);
} 
if(tipo(x,ARRAY) && tipo(y,DOUBLE)){ 		
push_ARRAY(s, x.ARRAY);
}   
if(tipo(x,ARRAY) && tipo(y,CHAR)){ 		
push_ARRAY(s, x.ARRAY);
}  
if(tipo(x,ARRAY) && tipo(y,STRING)){ 		
push_ARRAY(s, x.ARRAY);
} 
if(tipo(x,ARRAY) && tipo(y,ARRAY)){ 		
push_ARRAY(s, x.ARRAY);
}                    

  //	push(s,d_val);
}

/** @brief Função que dá o modulo de valores.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void modulo(STACK *s){                        
    data_type y = pop(s);                                
    data_type x = pop(s);                                
   /* data_type d_val;  
 	if(tipo(x, LONG) && tipo(y, LONG)){ /// Modulo de 2 Longs.        
    	d_val.type = LONG;                                     
    	d_val.LONG = x.LONG % y.LONG;
	}                       
  	if(tipo(x, CHAR) && tipo(y, LONG)){ /// Modulo de Char e Long com resultado Long.  
    	d_val.type = LONG;                                     
    	d_val.LONG = x.CHAR % y.LONG;
	}                       
  	if(tipo(x, LONG) && tipo(y, CHAR)){ /// Modulo de Long e Char com resultado Long. 
    	d_val.type = LONG;                                     
    	d_val.LONG = x.LONG % y.CHAR; 
	}                       
 	if(tipo(x, CHAR) && tipo(y, CHAR)){ /// Modulo de 2 Chars.   
    	d_val.type = LONG;                                     
    	d_val.LONG = x.CHAR % y.CHAR;
	} */
	if(tipo(x,LONG) && tipo(y,LONG)){
push_LONG(s, y.LONG % x.LONG);
}
if(tipo(x,LONG) && tipo(y,DOUBLE)){
push_DOUBLE(s, fmod(y.DOUBLE, x.LONG));
}
if(tipo(x,LONG) && tipo(y,CHAR)){
push_LONG(s, x.LONG);
}
if(tipo(x,LONG) && tipo(y,STRING)){ 		
push_LONG(s, x.LONG);
}
if(tipo(x,LONG) && tipo(y,ARRAY)){ 		
push_LONG(s, x.LONG);  
}
if(tipo(x,DOUBLE) && tipo(y,LONG)){
push_DOUBLE(s, fmod(y.LONG, x.DOUBLE));
}
if(tipo(x,DOUBLE) && tipo(y,DOUBLE)){
push_DOUBLE(s, fmod(y.DOUBLE, x.DOUBLE));
}
if(tipo(x,DOUBLE) && tipo(y,CHAR)){
push_DOUBLE(s, x.DOUBLE);
}
if(tipo(x,DOUBLE) && tipo(y,STRING)){ 		
push_DOUBLE(s, x.DOUBLE); 
}
if(tipo(x,DOUBLE) && tipo(y,ARRAY)){ 		
push_DOUBLE(s, x.DOUBLE); 
}
if(tipo(x,CHAR) && tipo(y,LONG)){
push_LONG(s, y.LONG);
}
if(tipo(x,CHAR) && tipo(y,DOUBLE)){
push_DOUBLE(s, y.DOUBLE);
}
if(tipo(x,CHAR) && tipo(y,CHAR)){
push_CHAR(s, x.CHAR);
push_CHAR(s, y.CHAR);
}
if(tipo(x,CHAR) && tipo(y,STRING)){ 		
push_CHAR(s, x.CHAR);
}
if(tipo(x,CHAR) && tipo(y,ARRAY)){ 		
push_CHAR(s, x.CHAR);
}
if(tipo(x,STRING) && tipo(y,LONG)){ 		
push_LONG(s, y.LONG);
}
if(tipo(x,STRING) && tipo(y,DOUBLE)){ 		
push_DOUBLE(s, y.DOUBLE);
}  
if(tipo(x,STRING) && tipo(y,CHAR)){ 		
push_STRING(s, x.STRING);
}  
if(tipo(x,STRING) && tipo(y,STRING)){ 		
push_STRING(s, x.STRING);
push_STRING(s, y.STRING);
}  
if(tipo(x,STRING) && tipo(y,ARRAY)){ 		
push_STRING(s, x.STRING);
}  

 	//push(s,d_val);
}

/** @brief Função que divide valores.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void divisao(STACK *s){                            
    data_type x = pop(s);                                     
    data_type y = pop(s);                                     
 /*    data_type d_val;
 	if(tipo(x, LONG) && tipo(y, LONG)){ 	/// Divisão de 2 Longs.          
    	d_val.type = LONG;                                     
    	d_val.LONG = y.LONG / x.LONG; 
	}                   
  	if(tipo(x, DOUBLE) && tipo(y, DOUBLE)){ /// Divisão de 2 Doubles.
    	d_val.type = DOUBLE;                                   
    	d_val.DOUBLE = y.DOUBLE / x.DOUBLE;  
	}                 
  	if(tipo(x, LONG) && tipo(y, DOUBLE)){ 	/// Divisão de Long e Double com resultado Double.
    	d_val.type = DOUBLE;                                   
    	d_val.DOUBLE = y.DOUBLE / x.LONG; 
	}                   
  	if(tipo(x, CHAR) && tipo(y, LONG)){ 	/// Divisão de Char e Long com resultado Long.
    	d_val.type = LONG;                                     
    	d_val.LONG = y.LONG / x.CHAR;   
	}                       
  	if(tipo(x, LONG) && tipo(y, CHAR)){ 	/// Divisão de Long e Char com resultado Long.
    	d_val.type = LONG;                                     
    	d_val.LONG = y.CHAR / x.LONG;  
	}                       
  	if(tipo(x, CHAR) && tipo(y, DOUBLE)){ 	/// Divisão de Char e Double com resultado Double.
    	d_val.type = DOUBLE;                                   
    	d_val.DOUBLE = y.DOUBLE / x.CHAR;  
	}                 
 	if(tipo(x, DOUBLE) && tipo(y, CHAR)){ 	/// Divisão de Double e Char com resultado Double.
    	d_val.type = DOUBLE;                                   
    	d_val.CHAR = y.CHAR / x.DOUBLE;
	}                 
 	if(tipo(x, CHAR) && tipo(y, CHAR)){ 	/// Divisão de 2 Chars.   
    	d_val.type = LONG;                                     
    	d_val.CHAR = y.CHAR / x.CHAR; 
	}  */            
if(tipo(x,LONG) && tipo(y,LONG)){
push_LONG(s, x.LONG / y.LONG);
}
if(tipo(x,LONG) && tipo(y,DOUBLE)){
push_LONG(s, y.DOUBLE / x.LONG);
}
if(tipo(x,LONG) && tipo(y,CHAR)){
push_LONG(s, x.LONG);
}
if(tipo(x,LONG) && tipo(y,STRING)){ 		
push_LONG(s, x.LONG);
}
if(tipo(x,LONG) && tipo(y,ARRAY)){ 		
push_LONG(s, x.LONG);  
}
if(tipo(x,DOUBLE) && tipo(y,LONG)){
push_DOUBLE(s, y.LONG / x.DOUBLE);
}
if(tipo(x,DOUBLE) && tipo(y,DOUBLE)){
push_DOUBLE(s, y.DOUBLE / x.DOUBLE);
}
if(tipo(x,DOUBLE) && tipo(y,CHAR)){
push_DOUBLE(s, x.DOUBLE);
}
if(tipo(x,DOUBLE) && tipo(y,STRING)){ 		
push_DOUBLE(s, x.DOUBLE); 
}
if(tipo(x,DOUBLE) && tipo(y,ARRAY)){ 		
push_DOUBLE(s, x.DOUBLE); 
}
if(tipo(x,CHAR) && tipo(y,LONG)){
push_LONG(s, y.LONG);
}
if(tipo(x,CHAR) && tipo(y,DOUBLE)){
push_DOUBLE(s, y.DOUBLE);
}
if(tipo(x,CHAR) && tipo(y,CHAR)){
push_CHAR(s, x.CHAR);
push_CHAR(s, y.CHAR);
}
if(tipo(x,CHAR) && tipo(y,STRING)){ 		
push_CHAR(s, x.CHAR);
}
if(tipo(x,CHAR) && tipo(y,ARRAY)){ 		
push_CHAR(s, x.CHAR);
}
if(tipo(x,STRING) && tipo(y,LONG)){ 		
push_LONG(s, y.LONG);
}
if(tipo(x,STRING) && tipo(y,DOUBLE)){ 		
push_DOUBLE(s, y.DOUBLE);
}  
if(tipo(x,STRING) && tipo(y,CHAR)){ 		
push_STRING(s, x.STRING);
}  
if(tipo(x,STRING) && tipo(y,STRING)){ 		
sub_arr (s, x.STRING, y.STRING);
}  
if(tipo(x,STRING) && tipo(y,ARRAY)){ 		
push_STRING(s, x.STRING);
}  
if(tipo(x,ARRAY) && tipo(y,LONG)){ 		
push_ARRAY(s, x.ARRAY);
} 
if(tipo(x,ARRAY) && tipo(y,DOUBLE)){ 		
push_ARRAY(s, x.ARRAY);
}   
if(tipo(x,ARRAY) && tipo(y,CHAR)){ 		
push_ARRAY(s, x.ARRAY);
}  
if(tipo(x,ARRAY) && tipo(y,STRING)){ 		
push_ARRAY(s, x.ARRAY);
} 
if(tipo(x,ARRAY) && tipo(y,ARRAY)){ 		
push_ARRAY(s, x.ARRAY);
}       


 	//push(s,d_val); 
}

/** @brief Função que dá a potencia de valores.
*Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
*/
void potencia(STACK *s){             
  	data_type x = pop(s);
  	data_type y = pop(s);
  /*	data_type d_val;
  	if(tipo(x,LONG) && tipo(y,LONG)){ 		/// Potencia de base Long e expoente Long com resultado Long.
  		d_val.type = LONG;
  		d_val.LONG = powl(y.LONG, x.LONG);  /// Função powl, faz uma pow normal mas para longs
}		  */									// este comentario pode ser repetido ao longo da func								  
if(tipo(x,LONG) && tipo(y,LONG)){
push_LONG(s, powl(y.LONG,x.LONG));
}
if(tipo(x,LONG) && tipo(y,DOUBLE)){
push_DOUBLE(s, powf(y.DOUBLE,x.LONG));
}
if(tipo(x,LONG) && tipo(y,CHAR)){
push_LONG(s, x.LONG);
}
if(tipo(x,LONG) && tipo(y,STRING)){ 		
push_LONG(s, x.LONG);
}
if(tipo(x,LONG) && tipo(y,ARRAY)){ 		
push_LONG(s, x.LONG);  
}
if(tipo(x,DOUBLE) && tipo(y,LONG)){
push_DOUBLE(s, powf(y.LONG,x.DOUBLE));
}
if(tipo(x,DOUBLE) && tipo(y,DOUBLE)){
push_DOUBLE(s, powf(y.DOUBLE,x.DOUBLE));
}
if(tipo(x,DOUBLE) && tipo(y,CHAR)){
push_DOUBLE(s, x.DOUBLE);
}
if(tipo(x,DOUBLE) && tipo(y,STRING)){ 		
push_DOUBLE(s, x.DOUBLE); 
}
if(tipo(x,DOUBLE) && tipo(y,ARRAY)){ 		
push_DOUBLE(s, x.DOUBLE); 
}
if(tipo(x,CHAR) && tipo(y,LONG)){
push_LONG(s, y.LONG);
}
if(tipo(x,CHAR) && tipo(y,DOUBLE)){
push_DOUBLE(s, y.DOUBLE);
}
if(tipo(x,CHAR) && tipo(y,CHAR)){
push_CHAR(s, x.CHAR);
push_CHAR(s, y.CHAR);
}
if(tipo(x,CHAR) && tipo(y,STRING)){ 		
push_CHAR(s, x.CHAR);
}
if(tipo(x,CHAR) && tipo(y,ARRAY)){ 		
push_CHAR(s, x.CHAR);
}
if(tipo(x,STRING) && tipo(y,LONG)){ 		
push_LONG(s, y.LONG);
}
if(tipo(x,STRING) && tipo(y,DOUBLE)){ 		
push_DOUBLE(s, y.DOUBLE);
}  
if(tipo(x,STRING) && tipo(y,CHAR)){ 		
push_STRING(s, x.STRING);
}  
if(tipo(x,STRING) && tipo(y,STRING)){ 		
push_LONG(s, sub_str2(x.STRING, y.STRING));
}  
if(tipo(x,STRING) && tipo(y,ARRAY)){ 		
push_STRING(s, x.STRING);
}  
if(tipo(x,ARRAY) && tipo(y,LONG)){ 		
push_ARRAY(s, x.ARRAY);
} 
if(tipo(x,ARRAY) && tipo(y,DOUBLE)){ 		
push_ARRAY(s, x.ARRAY);
}   
if(tipo(x,ARRAY) && tipo(y,CHAR)){ 		
push_ARRAY(s, x.ARRAY);
}  
if(tipo(x,ARRAY) && tipo(y,STRING)){ 		
push_ARRAY(s, x.ARRAY);
} 
if(tipo(x,ARRAY) && tipo(y,ARRAY)){ 		
push_ARRAY(s, x.ARRAY);
}
  						
							
  //	push(s,d_val);
}

/// @brief Função que duplica valores.
void duplicar(STACK *s){
	data_type x = pop(s);
	push(s,x);
	push(s,x);
}

/// @brief Função que troca os dois elementos to topo da stack.
void troca(STACK *s){
	data_type x = pop(s);
	data_type y = pop(s);
	push(s,x);
	push(s,y);
}

/// @brief Função que roda os três elementos no topo da stack.
void rodar(STACK *s){
	data_type x = pop(s);
	data_type y = pop(s);
	data_type z = pop(s);
	push(s,y); 	///2 elemento passa para o meio da stack.
	push(s,x); 	///topo da stack passa para o meio.
	push(s,z); 	///base da stack passa para o topo.
}

void pop_v1(STACK *s){
	pop(s);
}


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
 	if(tipo(x, CHAR) && tipo(y, LONG)){ 	/// No caso de Char e Long com resultado Long.    
    	d_val.type = LONG;                                     
    	d_val.LONG = x.CHAR & y.LONG;  
	}                        
 	if(tipo(x, LONG) && tipo(y, CHAR)){ 	/// No caso de Long e Char com resultado Long.     
    	d_val.type = LONG;                                     
    	d_val.LONG = x.LONG & y.CHAR;  
	}                       
 	if(tipo(x, CHAR) && tipo(y, CHAR)){ 	/// No caso de 2 Chars.     
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
 	if(tipo(x, CHAR) && tipo(y, LONG)){ 	/// No caso de Char e Long com resultado Long. 
    	d_val.type = LONG;                                     
    	d_val.LONG = (x.CHAR | y.LONG);
	}                     
 	if(tipo(x, LONG) && tipo(y, CHAR)){ 	/// No caso de Long e Char com resultado Long.
    	d_val.type = LONG;                                     
    	d_val.LONG = (x.LONG | y.CHAR);  
	}                     
 	if(tipo(x, CHAR) && tipo(y, CHAR)){ 	/// No caso de 2 Chars.     
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
  	if(tipo(x, CHAR) && tipo(y, LONG)){ 	/// No caso de Char e Long com resultado Long.    
    	d_val.type = LONG;                                     
    	d_val.LONG = x.CHAR ^ y.LONG;  
	}                       
  	if(tipo(x, LONG) && tipo(y, CHAR)){ 	/// No caso de Long e Char com resultado Long.    
    	d_val.type = LONG;                                     
    	d_val.LONG = x.LONG ^ y.CHAR;  
	}                       
 	if(tipo(x, CHAR) && tipo(y, CHAR)){ 	/// No caso de 2 Chars.     
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
    data_type d_val;  
 	if(tipo(x, LONG) == 0){                                 
    	d_val.type = LONG;                                     
    	d_val.LONG = ~(x.LONG);  
	}                             
  	if(tipo(x, CHAR) == 0){                          
    	d_val.type = CHAR;                                     
    	d_val.CHAR = ~(x.CHAR); 
	}  

 	push(s,d_val);
}



        
