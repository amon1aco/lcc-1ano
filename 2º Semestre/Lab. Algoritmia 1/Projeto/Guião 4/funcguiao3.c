// Funções para o guião 3

/**
* @file funcguiao3.c
* @brief Neste ficheiro são definidas as funções da parte da logica
*/

#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "func.h"
#include "funcguiao4.h"

int strcmp (const char* str1, const char* str2);

/** @brief Função que fornece o maior dos 2 valores do topo da stack.
 * Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
 */  

void e_maior(STACK *s){
    data_type x = pop(s);   
    data_type y = pop(s);   
    if(tipo(x, LONG) && tipo(y, LONG)){         /// No caso de 2 Longs. 
        if(x.LONG>y.LONG) push(s,x);
        else push(s,y);
    }
    if(tipo(x, LONG) && tipo(y, DOUBLE)){       /// No caso de Long e Double.
        if(x.LONG>y.DOUBLE) push(s,x);
        else push(s,y);
    } 
    if(tipo(x, DOUBLE) && tipo(y, LONG)){       /// No caso de Double e Long.
        if(x.DOUBLE>y.LONG) push(s,x);
        else push(s,y); 
    } 
    if(tipo(x, DOUBLE) && tipo(y, DOUBLE)){     /// No caso de 2 Doubles.
        if(x.DOUBLE>y.DOUBLE) push(s,x);
        else push(s,y);
    } 
    if(tipo(x, CHAR) && tipo(y, LONG)){         /// No caso de Char e Long.
        if(y.LONG>x.CHAR ) push(s,y);
        else push(s,x);
    } 
    if(tipo(x, LONG) && tipo(y, CHAR)){         /// No caso de Long e Char.
        if(x.LONG>y.CHAR ) push(s,x);
        else push(s,y);
    } 
    if(tipo(x, CHAR) && tipo(y, CHAR)){         /// No caso de 2 Chars.
        if(x.CHAR>y.CHAR ) push(s,x);
        else push(s,y);
    } 
    if(tipo(x, DOUBLE) && tipo(y, CHAR)){       /// No caso de Double e Char.
        if(x.DOUBLE>y.CHAR ) push(s,x);
        else push(s,y);
    } 
    if(tipo(x, CHAR) && tipo(y, DOUBLE)){       /// No caso de Char e Double.
        if(x.CHAR>y.DOUBLE ) push(s,x);
        else push(s,y);
    }
}

/** @brief Função que fornece o menor dos 2 valores do topo da stack.
 * Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida
 */
void e_menor(STACK *s){
    data_type x = pop(s);   
    data_type y = pop(s);
    if(tipo(x, LONG) && tipo(y, LONG)){         /// No caso de 2 Longs. 
        if(x.LONG>y.LONG) push(s,y);
        else push(s,x);
    }
    if(tipo(x, LONG) && tipo(y, DOUBLE)){       /// No caso de Long e Double.
        if(x.LONG>y.DOUBLE) push(s,y);
        else push(s,x);
    } 
    if(tipo(x, DOUBLE) && tipo(y, LONG)){       /// No caso de Double e Long.
        if(x.DOUBLE>y.LONG) push(s,y);
        else push(s,x);
    } 
    if(tipo(x, DOUBLE) && tipo(y, DOUBLE)){     /// No caso de 2 Doubles.
        if(x.DOUBLE>y.DOUBLE) push(s,y);
        else push(s,x);
    } 
    if(tipo(x, CHAR) && tipo(y, LONG)){         /// No caso de Char e Long.
        if(y.LONG>x.CHAR ) push(s,x);
        else push(s,y);
    } 
    if(tipo(x, LONG) && tipo(y, CHAR)){         /// No caso de Long e Char.
        if(x.LONG>y.CHAR ) push(s,y);
        else push(s,x);
    } 
    if(tipo(x, CHAR) && tipo(y, CHAR)){         /// No caso de 2 Chars.
        if(x.CHAR>y.CHAR ) push(s,y);
        else push(s,x);
    } 
    if(tipo(x, DOUBLE) && tipo(y, CHAR)){       /// No caso de Double e Char.
        if(x.DOUBLE>y.CHAR ) push(s,y); 
        else push(s,x);
    } 
    if(tipo(x, CHAR) && tipo(y, DOUBLE)){       /// No caso de Char e Double.
        if(x.CHAR>y.DOUBLE ) push(s,y); 
        else push(s,x);
    }
}

/** @brief Função que fornece o resultado a operação e com shortcut dos 2 valores do topo da stack.
 * Se algum dos valores for 0 vai fornecer como resultado 0, caso contrario fornece o ultimo valor.
 * Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida.
 */
void e_shortcut(STACK *s){
    data_type x = pop(s);   
    data_type y = pop(s);   
    data_type k; 
    if(tipo(x, LONG) && tipo(y, LONG)){         /// No caso de 2 Longs.
        if(x.LONG == 0 || y.LONG == 0){
            k.type = LONG;
            k.LONG = 0;
        } 
        else{
            k.type = LONG; 
            k.LONG = x.LONG;                     
        }
        push(s,k);
    } 
    if(tipo(x, LONG) && tipo(y, DOUBLE)){       /// No caso de Long e Double.
        if(x.LONG == 0 || y.DOUBLE== 0){ 
            k.type = LONG;
            k.LONG = 0;
        } 
        else{
            k.type = LONG; 
            k.LONG = x.LONG;                     
        }
        push(s,k);
    } 
    if(tipo(x, DOUBLE) && tipo(y, LONG)){       /// No caso de Double e Long.
        if(x.DOUBLE == 0 || y.LONG == 0){ 
            k.type = LONG;
            k.LONG = 0;
        } 
        else{
            k.type = DOUBLE; 
            k.DOUBLE = x.DOUBLE;
        }
        push(s,k); 
    } 
    if(tipo(x, DOUBLE) && tipo(y, DOUBLE)){     /// No caso de 2 Doubles.    
        if(x.DOUBLE == 0 || y.DOUBLE == 0){ 
            k.type = LONG;
            k.LONG = 0;
        } 
        else{
            k.type = DOUBLE; 
            k.DOUBLE = x.DOUBLE;                     
        }
        push(s,k);
    } 
    if(tipo(x, CHAR) && tipo(y, LONG)){         /// No caso de Char e Long.
        if(y.LONG == 0 || x.CHAR == 0){ 
            k.type = LONG;
            k.LONG = 0;
        } 
        else{
            k.type = CHAR; 
            k.CHAR = x.CHAR;                     
        }
        push(s,k);
    } 
    if(tipo(x, LONG) && tipo(y, CHAR)){         /// No caso de Long e Char.
        if(x.LONG == 0 || y.CHAR == 0){
            k.LONG = 0;
            push(s,k);
        } 
        else push(s,x);
    } 
    if(tipo(x, CHAR) && tipo(y, CHAR)){         /// No caso de 2 Chars.
        if(x.CHAR == 0 || y.CHAR == 0){
            k.LONG = 0;
            push(s,k);
        } 
        else push(s,x);
    } 
    if(tipo(x, DOUBLE) && tipo(y, CHAR)){       /// No caso de Double e Char.
        if(x.DOUBLE == 0 || y.CHAR == 0){ 
            k.type = LONG;
            k.LONG = 0;
        } 
        else{
            k.type = DOUBLE; 
            k.DOUBLE = x.DOUBLE;                     
        }
        push(s,k);
    } 
    if(tipo(x, CHAR) && tipo(y, DOUBLE)){       /// No caso de Char e Double.
        if(x.CHAR == 0 || y.DOUBLE == 0){ 
            k.type = LONG;
            k.LONG = 0;
        } 
        else{
            k.type = CHAR; 
            k.CHAR = x.CHAR;                     
        }
        push(s,k);
    }
}

/** @brief Função que fornece o resultado a operação ou com shortcut dos 2 valores do topo da stack.
 * Se algum dos valores for 0 vai fornecer como resultado o outro valor, caso contrario fornece o primeiro valor.
 * Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida.
 */
void ou_shortcut(STACK *s){
    data_type x = pop(s);   
    data_type y = pop(s);   
    data_type r; 
    if(tipo(x, LONG) && tipo(y, LONG)){         /// No caso de 2 Longs.
        if(x.LONG == 0 && y.LONG == 0){
            r.LONG = 0;
            push(s,r);
        }
        if(x.LONG != 0 && y.LONG ==0) push(s,x);
        else push(s,y);
    } 
    if(tipo(x, LONG) && tipo(y, DOUBLE)){       /// No caso de Long e Double.
        if(x.LONG == 0 && y.DOUBLE == 0){
            r.LONG = 0;
            push(s,r);
        }
        if(x.LONG != 0 && y.DOUBLE ==0) push(s,x);
        else push(s,y);
    } 
    if(tipo(x, DOUBLE) && tipo(y, LONG)){       /// No caso de Double e Long.
        if(x.DOUBLE == 0 && y.DOUBLE == 0){
            r.LONG = 0;
            push(s,r);
        } 
        if(x.DOUBLE != 0 && y.LONG ==0) push(s,x); 
        else push(s,y);
    } 
    if(tipo(x, DOUBLE) && tipo(y, DOUBLE)){     /// No caso de 2 Doubles.
        if(x.DOUBLE == 0 && y.DOUBLE == 0){
            r.LONG = 0;
            push(s,r);
        } 
        if(x.DOUBLE != 0 && y.DOUBLE ==0) push(s,x);
        else push(s,y);
    } 
    if(tipo(x, CHAR) && tipo(y, LONG)){         /// No caso de Char e Long.
        if(x.CHAR == 0 && y.LONG == 0){
            r.LONG = 0;
            push(s,r);
        } 
        if(x.CHAR != 0 && y.LONG ==0) push(s,x); 
        else push(s,y);
    } 
    if(tipo(x, LONG) && tipo(y, CHAR)){         /// No caso de Long e Char.
        if(x.LONG == 0 && y.CHAR == 0){
            r.LONG = 0;
            push(s,r);
        } 
        if(x.LONG != 0 && y.CHAR == 0) push(s,x); 
        else push(s,y);
    } 
    if(tipo(x, CHAR) && tipo(y, CHAR)){         /// No caso de 2 Chars.
        if(x.CHAR == 0 && y.CHAR == 0){
            r.LONG = 0;
            push(s,r);
        } 
        if (x.CHAR != 0 && y.CHAR ==0) push(s,x); 
        else push(s,y);
    } 
    if(tipo(x, DOUBLE) && tipo(y, CHAR)){       /// No caso de Double e Char.
        if(x.DOUBLE == 0 && y.CHAR == 0){
            r.LONG = 0;
            push(s,r);
        } 
        if(x.DOUBLE != 0 && y.CHAR ==0) push(s,x); 
        else push(s,y);
    } 
    if(tipo(x, CHAR) && tipo(y, DOUBLE)){       /// No caso Char e Double.
        if(x.CHAR == 0 && y.DOUBLE == 0){
            r.LONG = 0;
            push(s,r);
        }
        if(x.CHAR != 0 && y.DOUBLE ==0) push(s,x);  
        else push(s,y);
    }
}

/** @brief 
 * Caso os dados inseridos forem os 2 iguais o resultado final quando chamada esta função será 1.
 * Caso os dados sejam diferentes a função finalizará e retorna como resultado 0.
 * Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida.
 */
void igual(STACK *s) {                                      
    data_type x = pop(s);                                     
    data_type y = pop(s);  
    if(tipo(x, LONG) && tipo(y, LONG)){             /// No caso de 2 Longs.    
        if(x.LONG == y.LONG) push_LONG(s,1);     
        else push_LONG(s,0);
    }     
    if(tipo(x, DOUBLE) && tipo(y, LONG)){           /// No caso de Double e Long.
        if(x.DOUBLE == y.LONG) push_LONG(s,1);
        else push_LONG(s,0);
    }                   
    if(tipo(x, DOUBLE) && tipo(y, DOUBLE)){         /// No caso de 2 Doubles.
        if(x.DOUBLE == y.DOUBLE) push_LONG(s,1);
        else push_LONG(s,0);
    }                 
    if(tipo(x, LONG) && tipo(y, DOUBLE)){           /// No caso de Long e Double.
        if(x.LONG == y.DOUBLE) push_LONG(s,1);
        else push_LONG(s,0);   
    }                  
    if(tipo(x, CHAR) && tipo(y, LONG)){             /// No caso de Char e Long.
        if(x.CHAR == y.LONG) push_LONG(s,1);
        else push_LONG(s,0);
    }                      
    if(tipo(x, LONG) && tipo(y, CHAR)){             /// No caso de Long e Char.
        if(x.LONG == y.CHAR) push_LONG(s,1);
        else push_LONG(s,0);
    }                      
    if(tipo(x, CHAR) && tipo(y, DOUBLE)){           /// No caso de Char e Double.
        if(x.CHAR == y.DOUBLE) push_LONG(s,1);
        else push_LONG(s,0);
    }                
    if(tipo(x, DOUBLE) && tipo(y, CHAR)){           /// No caso de Double e Char.
        if(x.DOUBLE == y.CHAR) push_LONG(s,1);
        else push_LONG(s,0);
    }
    if(tipo(x, CHAR) && tipo(y, CHAR)){             /// No caso de 2 Chars.
        if(x.CHAR == y.CHAR) push_LONG(s,1);
        else push_LONG(s,0);
    } 
    if(tipo(x,LONG) && tipo(y,STRING)){             
        sub_str(x.LONG, y.STRING, s);
    }
    if(tipo(x,LONG) && tipo(y,ARRAY)){             
        procura_arr(x.LONG, y.ARRAY, s);
    }
    if(tipo(x,DOUBLE) && tipo(y,STRING)){             
        push_LONG(s, 0);
    } 
    if(tipo(x,CHAR) && tipo(y,STRING)){             
        push_LONG(s, 0);
    } 
    if(tipo(x,STRING) && tipo(y,LONG)){             
        push_LONG(s, 0);
    } 
    if(tipo(x,STRING) && tipo(y,DOUBLE)){             
        push_LONG(s, 0);
    } 
    if(tipo(x,STRING) && tipo(y,LONG)){             
        push_LONG(s, 0);
    } 
    if(tipo(x,STRING) && tipo(y,CHAR)){             
        push_LONG(s, 0);
    } 
    if(tipo(x,STRING) && tipo(y,STRING)){             
        if(strcmp(x.STRING,y.STRING) == 0) push_LONG(s, 1);
        else push_LONG(s, 0);
    } 
}

/** @brief 
 * Caso o primeiro valor inserido for mais pequeno que o segundo o resultado final quando chamada esta função será 0.
 * Caso seja o primeiro valor maior, a função finalizará e retorna como resultado 1.
 * Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida.
 */
void menor(STACK *s){                                      
    data_type x = pop(s);                                     
    data_type y = pop(s);  
    if(tipo(x, LONG) && tipo(y, LONG)){             /// No caso de 2 Longs.          
        if(x.LONG < y.LONG) push_LONG(s,0);
        else push_LONG(s,1);
    }     
    if(tipo(x, DOUBLE) && tipo(y, LONG)){           /// No caso de Double e Long.
        if(x.DOUBLE < y.LONG) push_LONG(s,0);
        else push_LONG(s,1);
    }                   
    if(tipo(x, DOUBLE) && tipo(y, DOUBLE)){         /// No caso de 2 Doubles.
        if (x.DOUBLE < y.DOUBLE) push_LONG(s,0);
        else push_LONG(s,1);
    }                 
    if(tipo(x, LONG) && tipo(y, DOUBLE)){           /// No caso de Long e Double.
        if(x.LONG < y.DOUBLE) push_LONG(s,0);
        else push_LONG(s,1);
    }                  
    if(tipo(x, CHAR) && tipo(y, LONG)){             /// No caso de Char e Long.
        if(x.CHAR < y.LONG) push_LONG(s,0);
        else push_LONG(s,1);
    }                      
    if(tipo(x, LONG) && tipo(y, CHAR)){             /// No caso de Long e Char.
        if(x.LONG < y.CHAR) push_LONG(s,0);
        else push_LONG(s,1);
    }                      
    if(tipo(x, CHAR) && tipo(y, DOUBLE)){           /// No caso de Char e Double.
        if(x.CHAR < y.DOUBLE) push_LONG(s,0);
        else push_LONG(s,1);
    }                
    if(tipo(x, DOUBLE) && tipo(y, CHAR)){           /// No caso de Double e Char.
        if(x.DOUBLE < y.CHAR) push_LONG(s,0);
        else push_LONG(s,1);
    }
    if(tipo(x, CHAR) && tipo(y, CHAR)){             /// No caso de 2 Chars.
        if(x.CHAR < y.CHAR) push_LONG(s,0);
        else push_LONG(s,1);
    } 
    if(tipo(x, LONG) && tipo(y, STRING)){             
        push_STRING(s, strndup(y.STRING, sizeof(char) * x.LONG));
    }   
    if(tipo(x, LONG) && tipo(y, ARRAY)){             
        remove_men_arr(x.LONG, y.ARRAY);
        push_ARRAY(s, y.ARRAY);
    }  
    if(tipo(x, CHAR) && tipo(y, STRING)){             
        push_LONG(s, 0);
    }
    if(tipo(x, STRING) && tipo(y, LONG)){             
        push_LONG(s, 0);
    } 
    if(tipo(x, STRING) && tipo(y, DOUBLE)){             
        push_LONG(s, 0);
    } 
    if(tipo(x, STRING) && tipo(y, CHAR)){             
        push_LONG(s, 0);
    }      
    if(tipo(x, STRING) && tipo(y, STRING)){             
        if(strlen(y.STRING) < strlen(x.STRING)) push_LONG(s, 1);
        else if(strlen(y.STRING) == strlen(x.STRING)){ 
            if(strcmp(y.STRING, x.STRING) < 0) push_LONG(s, 1);
            else if(strcmp(y.STRING, x.STRING) >= 0) push_LONG(s, 0);
            else push_LONG(s, 0);
        }
        else push_LONG(s,0);
    }  

}
 
/** @brief 
 * Caso o primeiro valor inserido for maior que o segundo o resultado final quando chamada esta função será 0.
 * Caso seja o primeiro valor mais pequeno, a função finalizará e retorna como resultado 1.
 * Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida.
 */
void maior(STACK *s){                                      
    data_type x = pop(s);                                     
    data_type y = pop(s);
    if(tipo(x, LONG) && tipo(y, LONG)){             /// No caso de 2 Longs.     
        if(x.LONG > y.LONG) push_LONG(s,0);
        else push_LONG(s,1);
    }     
    if(tipo(x, DOUBLE) && tipo(y, LONG)){           /// No caso de Double e Long.
        if(x.DOUBLE > y.LONG) push_LONG(s,0);
        else push_LONG(s,1);
    }                   
    if(tipo(x, DOUBLE) && tipo(y, DOUBLE)){         /// No caso de 2 Doubles.
        if(x.DOUBLE > y.DOUBLE) push_LONG(s,0);
        else push_LONG(s,1);
    }                 
    if(tipo(x, LONG) && tipo(y, DOUBLE)){           /// No caso de Long e Double.
        if(x.LONG > y.DOUBLE) push_LONG(s,0);
        else push_LONG(s,1);
    }                  
    if(tipo(x, CHAR) && tipo(y, LONG)){             /// No caso de Char e Long.
        if(x.CHAR > y.LONG) push_LONG(s,0);
        else push_LONG(s,1);
    }                      
    if(tipo(x, LONG) && tipo(y, CHAR)){             /// No caso de Long e Char.
        if(x.LONG > y.CHAR) push_LONG(s,0);
        else push_LONG(s,1);
    }                      
    if(tipo(x, CHAR) && tipo(y, DOUBLE)){           /// No caso de Char e Double.
        if(x.CHAR > y.DOUBLE) push_LONG(s,0);
        else push_LONG(s,1);
    }                
    if(tipo(x, DOUBLE) && tipo(y, CHAR)){           /// No caso de Double e Char.
        if(x.DOUBLE > y.CHAR) push_LONG(s,0);
        else push_LONG(s,1);
    }
    if(tipo(x, CHAR) && tipo(y, CHAR)){             /// No caso de 2 Chars.
        if(x.CHAR > y.CHAR) push_LONG(s,0);
        else push_LONG(s,1);
    } 
    if(tipo(x, LONG) && tipo(y, STRING)){             
        push_STRING(s, strdup(y.STRING + strlen(y.STRING) - x.LONG));
    }  
    if(tipo(x, LONG) && tipo(y, ARRAY)){             
        push_ARRAY(s , remove_mai_arr(x.LONG, y.ARRAY));
    }
    if(tipo(x, LONG) && tipo(y, STRING)){             
        push_LONG(s, 0);
    }
    if(tipo(x, CHAR) && tipo(y, STRING)){             
        push_LONG(s, 0);
    } 
    if(tipo(x, STRING) && tipo(y, LONG)){             
        push_LONG(s, 0);
    }               
    if(tipo(x, STRING) && tipo(y, DOUBLE)){             
        push_LONG(s, 0);
    }             
    if(tipo(x, STRING) && tipo(y, CHAR)){             
        push_LONG(s, 0);
    }
    if(tipo(x, STRING) && tipo(y, STRING)){             
        if (strlen(y.STRING) > strlen(x.STRING)) push_LONG(s, 1);
        else if (strlen(y.STRING) == strlen(x.STRING)){
            if (strcmp(y.STRING, x.STRING) <= 0) push_LONG(s, 0);
            else if (strcmp(y.STRING, x.STRING) > 0) push_LONG(s, 1);
            else push_LONG(s, 0);
        }
        else push_LONG(s,0);
    }      
}

       

/** @brief 
 * ao usar esta função iremos ter como resultado 1 quando O valor for diferente de 0.
 * quando o dado for igual a 0 tanto em char como long ou double retornará 1. 
 * Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida.
 */
void negacao(STACK *s){
    data_type x = pop(s);
    if(x.LONG == 0 || x.DOUBLE == 0.0 || x.CHAR == 0) { /// so quando x.LONG x.DOUBLE ou x.CHAR forem 0 é que entra no if caso contrario retorna 0
        if(x.LONG == 0) push_LONG(s,1);
        if(x.DOUBLE == 0.0) push_LONG(s,1);
        if(x.CHAR == 0) push_LONG(s,1);
    }
    else push_LONG(s,0);
    }

/** @brief Esta função funciona como um if then else, if x==0 then z else y
*   se o valor inserido for igual a 0 a função retorna o z, caso contrario finaliza com o valor do y.
*/
void ponto_de_interrogacao(STACK *s){
    data_type z = pop(s);
    data_type y = pop(s);
    data_type x = pop(s);
    if(x.LONG == 0) push(s,z);
    else push(s,y);
}

/// @brief Esta função recebe um long x e retorna um valor identico com o mesmo tipo mas em contexto stack
data_type cria_l(long x){
	data_type ret;
	ret.LONG = x;
	ret.type = LONG;
	return ret;
}

/// @brief Esta função recebe um double x e retorna um valor identico com o mesmo tipo mas em contexto stack
data_type cria_d(double x){
	data_type ret;
	ret.DOUBLE = x;
	ret.type = DOUBLE;
	return ret;
}

/// @brief Esta função recebe um char x e retorna um valor identico com o mesmo tipo mas em contexto stack
data_type cria_c(char x){
	data_type ret;
	ret.CHAR = x;
	ret.type = CHAR;
	return ret;
}

/// @brief Esta função preenche o array com os valores das letras por omissão
void preenche_array(STACK *s){
	s -> array_abc[0] = cria_l(10);	    
	s -> array_abc[1] = cria_l(11);	    
	s -> array_abc[2] = cria_l(12);	    
	s -> array_abc[3] = cria_l(13);	    
	s -> array_abc[4] = cria_l(14);	    
	s -> array_abc[5] = cria_l(15);	    
	s -> array_abc[13] = cria_c('\n');	
	s -> array_abc[18] = cria_c(' ');   
	s -> array_abc[23] = cria_l(0);     
	s -> array_abc[24] = cria_l(1);     
	s -> array_abc[25] = cria_l(2);     	
}

/// @brief Esta função coloca no topo da stack o valor da respetiva letra
void doisponto_letra(STACK *s, char letra){
	data_type x = top_da_stack(s);
	long pos = letra;
	if(tipo(x,LONG)) s -> array_abc[pos - 65] = cria_l(x.LONG); /// "-65" porque 'A' corresponde a 65 na tabela ascii
	if(tipo(x,DOUBLE)) s -> array_abc[pos - 65] = cria_d(x.DOUBLE);
	if(tipo(x,CHAR)) s -> array_abc[pos - 65] = cria_c(x.CHAR);
}

/// @brief esta função coloca a respetiva "letra" no topo da stack
void letra(STACK *s, char letra){
	long x = letra;
	data_type y = (s->array_abc[x-65]); /// "-65" porque 'A' corresponde a 65 na tabela ascii
	if(tipo(y,LONG)) push_LONG(s,y.LONG);
	if(tipo(y,DOUBLE)) push_DOUBLE(s,y.DOUBLE);
	if(tipo(y,CHAR)) push_CHAR(s,y.CHAR);
	if(tipo(y,STRING)) push_STRING(s,y.STRING);
}