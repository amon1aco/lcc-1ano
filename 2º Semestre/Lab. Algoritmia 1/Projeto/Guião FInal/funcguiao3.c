// Funções para o guião 3

/**
* @file funcguiao3.c
* @brief Neste ficheiro são definidas as funções da parte da logica
*/

#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "func.h"
#include <math.h>

/// @brief Compára 2 strings e dá 0 se forem iguais.
int strcmp (const char* str1, const char* str2);

/// @brief Funçao e_maior para o caso de ser Long
void e_maiorLONG(STACK *s, data_type x, data_type y){
    if(tipo(y, LONG)){         /// No caso de 2 Longs. 
        if(y.LONG > x.LONG) push_LONG(s, y.LONG);
        else push_LONG(s, x.LONG);
    }
    else if(tipo(y, DOUBLE)){       /// No caso de Long e Double.
        if(y.DOUBLE > x.LONG) push_DOUBLE(s, y.DOUBLE);
        else push_LONG(s, x.LONG);
    } 
    else if(tipo(y, CHAR)){     /// No caso de ser Long e Char
        if(x.LONG >= 0 && x.LONG < 9){ 
            if(y.CHAR > (char)x.LONG) push_CHAR(s, y.CHAR);
            else push_LONG(s, x.LONG);
        }
        else push_LONG(s, x.LONG);
    } 
    else{       
        push_LONG(s, x.LONG);
    } 
}

/// @brief Funçao e_maior para o caso de ser Double
void e_maiorDOUBLE(STACK *s, data_type x, data_type y){
    if(tipo(y, DOUBLE)){     /// No caso de 2 Doubles.
        if(y.DOUBLE > x.DOUBLE) push_DOUBLE(s, y.DOUBLE);
        else push_DOUBLE(s, x.DOUBLE);
    } 
    else if(tipo(y, CHAR)){     /// No caso de ser Double com Char
        if((fmod(x.DOUBLE, 1) == 0) && (x.DOUBLE >= 0 && x.DOUBLE < 9)){
            if(x.DOUBLE > y.CHAR) push_DOUBLE(s, x.DOUBLE);
            else push_CHAR(s, y.CHAR);
        }
        else push_LONG(s, y.DOUBLE);
    } 
    else {     
        push_DOUBLE(s, x.DOUBLE);
    } 
}

/// @brief Funçao e_maior para o caso de ser Char
void e_maiorCHAR(STACK *s, data_type x, data_type y){
    if(tipo(y, LONG)){         /// No caso de Char com Long.
        if(y.LONG >= 0 && y.LONG < 9){
            if(x.CHAR > (char)y.LONG) push_CHAR(s, x.CHAR);
            else push_LONG(s, y.LONG);
        }
        else push_LONG(s, y.LONG);
    } 
    else if(tipo(y, DOUBLE)){         /// No caso de Char com Double.
        if((y.DOUBLE >= 0 && y.DOUBLE < 9) && fmod(y.DOUBLE, 1) == 0){
            if(x.CHAR > (char)y.DOUBLE) push_CHAR(s, x.CHAR);
            else push_DOUBLE(s, y.DOUBLE);
        }
        else push_DOUBLE(s, y.DOUBLE);
    } 
    else if(tipo(y, CHAR)){   /// No caso de ser 2 Chars
        if(y.CHAR > x.CHAR) push_CHAR(s, y.CHAR);
        else push_CHAR(s, x.CHAR);
    } 
    else{       
        if((char)(strlen(y.STRING)) > x.CHAR) push_STRING(s, y.STRING);
        else push_CHAR(s, x.CHAR);
    }
}

/// @brief Funçao e_maior para o caso de ser string
void e_maiorSTRING(STACK *s, data_type x, data_type y){
if(tipo(y, LONG)){      /// No caso de ser String com Long
        push_LONG(s, y.LONG); 
    }
    else if(tipo(y, DOUBLE)){    /// No caso de ser string com Double
        push_DOUBLE(s, y.DOUBLE);
    }
    else if(tipo(y, CHAR)){    /// No caso de ser string com Char
        if((y.CHAR) > (char)(strlen(x.STRING))) push_CHAR(s, y.CHAR);
        else push_STRING(s, x.STRING);
    }
    else {      /// No caso de ser 2 strings
        if((strlen(y.STRING) > strlen(x.STRING)) == 0) push_STRING(s, y.STRING);
        else push_STRING(s , x.STRING);
    }
}

/** @brief Função que fornece o maior dos 2 valores do topo da stack.
 * Consoante o tipo de valores fornecidos é apresentado uma função auxiliar acima que vai solucionar a operação pretendida.
 */
void e_maior(STACK *s){
    data_type x = pop(s);   
    data_type y = pop(s);   

    if(tipo(x,LONG)) e_maiorLONG(s, x, y); ///chama a funçao e_maior para longs
    if(tipo(x, DOUBLE)) e_maiorDOUBLE(s, x, y); ///chama a funçao e_maior para doubles
    if(tipo(x,CHAR)) e_maiorCHAR(s, x, y); ///chama a funçao e_maior para chars
    if(tipo(x, STRING)) e_maiorSTRING(s, x, y); ///chama a funçao e_maior para strings
}

/// @brief Funçao e_menor para o caso de ser long
void e_menorLONG(STACK *s, data_type x, data_type y){
    if(tipo(y, LONG)){         /// No caso de ser 2 Longs. 
        if(y.LONG < x.LONG) push_LONG(s, y.LONG);
        else push_LONG(s, x.LONG);
    }
    else if(tipo(y, DOUBLE)){       /// No caso de Long com Double.
        if (y.DOUBLE < x.LONG) push_DOUBLE(s, y.DOUBLE);
        else push_LONG(s, x.LONG);
    } 
    else if(tipo(y, CHAR)){     /// No caso de Long com char.
        if (x.LONG >= 0 && x.LONG < 9){
            if(y.CHAR < (char)x.LONG) push_CHAR(s, y.CHAR);
            else push_LONG(s, x.LONG);
        }
        else push_LONG(s, x.LONG); 
    } 
    else {       
        push_LONG(s, x.LONG);
    }
}

/// @brief Funçao e_menor para o caso de ser double
void e_menorDOUBLE(STACK *s, data_type x, data_type y){
    if(tipo(y, LONG)){       /// No caso de Double com Long.
        if(y.LONG < x.DOUBLE) push_LONG(s, y.LONG);
        else push_DOUBLE(s, x.DOUBLE);
    } 
    else if(tipo(y, DOUBLE)){     /// No caso de ser 2 Doubles.
        if(y.DOUBLE < x.DOUBLE) push_DOUBLE(s, y.DOUBLE);
        else push_DOUBLE(s, x.DOUBLE);
    } 
    else if(tipo(y, CHAR)){ /// No caso de doube com char.    
        if((fmod(x.DOUBLE, 1) == 0) && (x.DOUBLE >= 0 && x.DOUBLE < 9)){
            if(x.DOUBLE < y.CHAR) push_DOUBLE(s, x.DOUBLE);
            else push_CHAR(s, y.CHAR);
        }
        else push_LONG(s, y.DOUBLE);
    } 
    else{     
        push_DOUBLE(s, x.DOUBLE);
    }     
}

/// @brief Funçao e_menor para o caso de ser char
void e_menorCHAR(STACK *s, data_type x, data_type y){
        if(tipo(y, LONG)){         /// No caso de Char com Long.
        if(y.LONG >= 0 && y.LONG < 9){
            if(x.CHAR < (char)y.LONG) push_CHAR(s, x.CHAR);
            else push_LONG(s, y.LONG);
        }
        else push_LONG(s, y.LONG);
    } 
    else if(tipo(y, DOUBLE)){   /// No caso de Char com Double.
        if((y.DOUBLE >= 0 && y.DOUBLE < 9) && fmod(y.DOUBLE, 1) == 0){
            if (x.CHAR < (char)y.DOUBLE) push_CHAR(s, x.CHAR);
            else push_DOUBLE(s, y.DOUBLE);
        }
        else push_DOUBLE(s, y.DOUBLE);
    } 
    else if(tipo(y, CHAR)){   /// No caso de ser 2 Chars 
        if (y.CHAR < x.CHAR) push_CHAR(s, y.CHAR);
        else push_CHAR(s, x.CHAR);
    } 
    else {       /// No caso de Char com string
        if((char)(strlen(y.STRING)) < x.CHAR ) push_STRING(s, y.STRING);
        else push_CHAR(s, x.CHAR);
    }
}

/// @brief Funçao e_menor para o caso de ser string
void e_menorSTRING(STACK *s, data_type x, data_type y){
    if(tipo(y, LONG)){      /// No caso de ser string com Long
        push_LONG(s, y.LONG);
    }
    else if(tipo(y, DOUBLE)){ /// No caso de ser string com double      
        push_DOUBLE(s, y.DOUBLE);
    }
    else if(tipo(y, CHAR)){      /// No caso de ser string com Char
        if((y.CHAR) < (char)(strlen(x.STRING))) push_CHAR(s, y.CHAR);
        else push_STRING(s, x.STRING);
    }
    else {      /// No caso de ser 2 strings
        if(strlen(y.STRING) < strlen(x.STRING)) push_STRING(s, y.STRING);
        else push_STRING(s , x.STRING);
    }    
}

/** @brief Função que fornece o menor dos 2 valores do topo da stack.
 * Consoante o tipo de valores fornecidos é apresentado uma função auxiliar acima que vai solucionar a operação pretendida.
 */
void e_menor(STACK *s){
    data_type x = pop(s);   
    data_type y = pop(s);
    if(tipo(x,LONG)) e_menorLONG(s, x, y); ///chama a funçao e_menor para longs
    if(tipo(x,DOUBLE)) e_menorDOUBLE(s, x, y); ///chama a funçao e_maior para doubles
    if(tipo(x, CHAR)) e_menorCHAR(s, x, y); ///chama a funçao e_maior para chars
    if(tipo(x, STRING)) e_menorSTRING(s, x, y); ///chama a funçao e_maior para strings
}

/// @brief Funçao e_shortcut para o caso de ser long.
void e_shortcutLONG(STACK *s,data_type x, data_type y, data_type k){
    if(tipo(y, LONG)){     /// No caso de ser 2 Longs.
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
    else if(tipo(y, DOUBLE)){       /// No caso de Long com Double.
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
    else {         /// No caso de Long com Char.
        if(x.LONG == 0 || y.CHAR == 0){
            k.LONG = 0;
            push(s,k);
        } 
        else push(s,x);
    } 
}

/// @brief Funçao e_shortcut para o caso de ser double.
void e_shortcutDOUBLE(STACK *s,data_type x, data_type y, data_type k){
    if(tipo(y, LONG)){       /// No caso de Double com Long.
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
    else if(tipo(y, DOUBLE)){     /// No caso de ser 2 Doubles.    
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
    else{       /// No caso de ser Double com Char.
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
}

/// @brief Funçao e_shortcut para o caso de ser char.
void e_shortcutCHAR(STACK *s,data_type x, data_type y, data_type k){
    if(tipo(y, LONG)){     /// No caso de se Char com Long.
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

    else if(tipo(y, CHAR)){    /// No caso de ser 2 Chars.
        if(x.CHAR == 0 || y.CHAR == 0){
            k.LONG = 0;
            push(s,k);
        } 
        else push(s,x);
    } 

    else {    /// No caso de ser Char com Double.
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

/** @brief Função que fornece o resultado a operação e com shortcut dos 2 valores do topo da stack.
 * Se algum dos valores for 0 vai fornecer como resultado 0, caso contrario fornece o ultimo valor.
 * Consoante o tipo de valores fornecidos é apresentado uma função auxiliar acima que vai solucionar a operação pretendida.
 */
void e_shortcut(STACK *s){
    data_type x = pop(s);   
    data_type y = pop(s);   
    data_type k; 
   if(tipo(x,LONG)) e_shortcutLONG(s, x, y, k);
   if(tipo(x,DOUBLE)) e_shortcutDOUBLE (s, x, y, k);
   if(tipo(x,CHAR)) e_shortcutCHAR(s, x, y, k);
}
/// @brief Funçao ou_shortcut para o caso de ser long.
void ou_shortcutLONG(STACK *s, data_type x, data_type y, data_type r){
    if(tipo(y, LONG)){      /// No caso de ser 2 Longs.
        if(x.LONG == 0 && y.LONG == 0){
            r.LONG = 0;
            push(s,r);
        }
        if(x.LONG != 0 && y.LONG ==0) push(s,x);
        else push(s,y);
    } 
    else if(tipo(y, DOUBLE)){       /// No caso de ser Long com Double.
        if(x.LONG == 0 && y.DOUBLE == 0){
            r.LONG = 0;
            push(s,r);
        }
        if(x.LONG != 0 && y.DOUBLE ==0) push(s,x);
        else push(s,y);
    }    
     else{         /// No caso de ser Long com Char.
        if(x.LONG == 0 && y.CHAR == 0){
            r.LONG = 0;
            push(s,r);
        } 
        if(x.LONG != 0 && y.CHAR == 0) push(s,x); 
        else push(s,y);
    } 
}

/// @brief Funçao ou_shortcut para o caso de ser double.
void ou_shortcutDOUBLE(STACK *s, data_type x, data_type y, data_type r){
    if(tipo(y, LONG)){     /// No caso de ser Double com Long.
        if(x.DOUBLE == 0 && y.DOUBLE == 0){
            r.LONG = 0;
            push(s,r);
        } 
        if(x.DOUBLE != 0 && y.LONG ==0) push(s,x); 
        else push(s,y);
    } 
    else if(tipo(y, DOUBLE)){     /// No caso de ser 2 Doubles.
        if(x.DOUBLE == 0 && y.DOUBLE == 0){
            r.LONG = 0;
            push(s,r);
        } 
        if(x.DOUBLE != 0 && y.DOUBLE ==0) push(s,x);
        else push(s,y);
    }    
     else{       /// No caso de ser Double com Char.
        if(x.DOUBLE == 0 && y.CHAR == 0){
            r.LONG = 0;
            push(s,r);
        } 
        if(x.DOUBLE != 0 && y.CHAR ==0) push(s,x); 
        else push(s,y);
    } 
}

/// @brief Funçao ou_shortcut para o caso de ser char.
void ou_shortcutCHAR(STACK *s, data_type x, data_type y, data_type r){
    if(tipo(y, LONG)){         /// No caso de ser Char com Long.
        if(x.CHAR == 0 && y.LONG == 0){
            r.LONG = 0;
            push(s,r);
        } 
        if(x.CHAR != 0 && y.LONG ==0) push(s,x); 
        else push(s,y);
    } 

    else if(tipo(y, CHAR)){         /// No caso de ser 2 Chars.
        if(x.CHAR == 0 && y.CHAR == 0){
            r.LONG = 0;
            push(s,r);
        } 
        if (x.CHAR != 0 && y.CHAR ==0) push(s,x); 
        else push(s,y);
    } 

    else {       /// No caso de ser Char com Double.
        if(x.CHAR == 0 && y.DOUBLE == 0){
            r.LONG = 0;
            push(s,r);
        }
        if(x.CHAR != 0 && y.DOUBLE ==0) push(s,x);  
        else push(s,y);
    }
}

/** @brief Função que fornece o resultado a operação ou com shortcut dos 2 valores do topo da stack.
 * Se algum dos valores for 0 vai fornecer como resultado o outro valor, caso contrario fornece o primeiro valor.
 * Consoante o tipo de valores fornecidos é apresentado uma função auxiliar acima que vai solucionar a operação pretendida.
 */    
void ou_shortcut(STACK *s){
    data_type x = pop(s);   
    data_type y = pop(s);   
    data_type r; 
     if(tipo(x,LONG)) ou_shortcutLONG(s, x, y, r);
     if(tipo(x,DOUBLE)) ou_shortcutDOUBLE(s, x, y, r);
     if(tipo(x,CHAR)) ou_shortcutCHAR(s, x, y, r);
}

/// @brief Funçao igual para o caso de ser long.
void igual_LONG(STACK *s, data_type x, data_type y){

    if(tipo(y, LONG)){             /// No caso de ser 2 Longs.    
        if(x.LONG == y.LONG) push_LONG(s,1);     
        else push_LONG(s,0);
    }    
    else if(tipo(y, DOUBLE)){           /// No caso de ser Long com Double.
        if(x.LONG == y.DOUBLE) push_LONG(s,1);
        else push_LONG(s,0);   
    }    
    else if(tipo(y, CHAR)){             /// No caso de ser Long com Char.
        if(x.LONG == y.CHAR) push_LONG(s,1);
        else push_LONG(s,0);
    }     
}

/// @brief Funçao igual para o caso de ser double.
void igual_DOUBLE(STACK *s, data_type x, data_type y){
    if(tipo(y, LONG)){           /// No caso de ser Double com Long.
        if(x.DOUBLE == y.LONG) push_LONG(s,1);
        else push_LONG(s,0);
    }                   
    else if(tipo(y, DOUBLE)){         /// No caso de ser 2 Doubles.
        if(x.DOUBLE == y.DOUBLE) push_LONG(s,1);
        else push_LONG(s,0);
    }     
    else  if(tipo(y, CHAR)){           /// No caso de ser Double com Char.
        if(x.DOUBLE == y.CHAR) push_LONG(s,1);
        else push_LONG(s,0);
    }    
    else{           /// No caso de ser double com string.             
        push_LONG(s, 0);
    }
}

/// @brief Funçao igual para o caso de ser char.
void igual_CHAR(STACK *s, data_type x, data_type y){

    if(tipo(y, LONG)){             /// No caso de ser Char com Long.
        if(x.CHAR == y.LONG) push_LONG(s,1);
        else push_LONG(s,0);
    }                      
                  
    else if(tipo(y, DOUBLE)){           /// No caso de ser Char com Double.
        if(x.CHAR == y.DOUBLE) push_LONG(s,1);
        else push_LONG(s,0);
    }                

    else if(tipo(y, CHAR)){             /// No caso de ser 2 Chars.
        if(x.CHAR == y.CHAR) push_LONG(s,1);
        else push_LONG(s,0);
    } 

    else{             /// No caso de ser char com string.
        push_LONG(s, 0);
    } 
}

/// @brief Funçao igual para o caso de ser string.
void igual_STRING(STACK *s, data_type x, data_type y){
    if(tipo(x,STRING) && tipo(y,LONG)){             /// No caso de ser string com long.
        push_LONG(s, 0);
    } 
    else if(tipo(y,DOUBLE)){           /// No caso de ser string com double.
        push_LONG(s, 0);
    } 
    else if(tipo(y,LONG)){             /// No caso de ser string com long.
        push_LONG(s, 0);
    } 
    else if(tipo(y,CHAR)){             /// No caso de ser string com char.
        push_LONG(s, 0);
    } 
    else {           /// No caso de ser 2 strings.
        if(strcmp(x.STRING,y.STRING) == 0) push_LONG(s, 1);
        else push_LONG(s, 0);
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
    if(tipo(x,LONG)) igual_LONG(s, x, y);
    if(tipo(x,DOUBLE)) igual_DOUBLE(s, x, y);
    if(tipo(x,CHAR)) igual_CHAR(s,x,y);              
    if(tipo(x,STRING)) igual_STRING(s,x,y);
}

/// @brief Funçao menor para o caso de ser long.
void menor_LONG(STACK *s, data_type x, data_type y){
       if(tipo(y, LONG)){             /// No caso de ser 2 Longs.          
        if(y.LONG < x.LONG) push_LONG(s, 1);
        else push_LONG(s,0);
    }     
    else if(tipo(y, DOUBLE)){           /// No caso de ser long com double.
        if(y.DOUBLE < x.LONG) push_LONG(s, 1);
        else push_LONG(s,0);
    }                   
    else if(tipo(y, CHAR)){         /// No caso de ser long com char.
        if(y.CHAR < x.LONG) push_LONG(s, 1);
        else push_LONG(s, 0);
    }                 
    else if(tipo(y, STRING)){           /// No caso de ser Long com string.
        push_STRING(s, strndup(y.STRING, sizeof(char) * x.LONG));
    }           
}

/// @brief Funçao menor para o caso de ser double.
void menor_DOUBLE(STACK *s, data_type x, data_type y){
     if(tipo(y, LONG)){             /// No caso de ser double com long.
        if(y.LONG < x.DOUBLE) push_LONG(s, 1);
        else push_LONG(s, 0);
    }                      
    else if(tipo(y, DOUBLE)){             /// No caso de ser 2 doubles.
        if(y.DOUBLE < x.DOUBLE) push_LONG(s, 1);
        else push_LONG(s, 0);
    }                      
    else if(tipo(y, CHAR)){           /// No caso de ser Double com char.
        if((fmod(x.DOUBLE, 1) == 0) && (x.DOUBLE >= 0 && x.DOUBLE < 9)){
            if(y.CHAR < (char)x.DOUBLE) push_LONG(s, 1);
            else push_LONG(s, 0);
        }
        else push_LONG(s, 0);
    }                
    else{           /// No caso de ser Double com string.
        push_LONG(s, 0);
    }   
}

/// @brief Funçao menor para o caso de ser char.
void menor_CHAR(STACK *s, data_type x, data_type y){
     if(tipo(y, LONG)){             /// No caso de ser Char com long.
        if(y.LONG >= 0 && y.LONG < 9){
            if(y.LONG < x.CHAR) push_LONG(s, 1);
            else push_LONG(s, 0);
        }
        else push_LONG(s, 0);
    } 
    else if(tipo(y, DOUBLE)){         /// No caso de ser char com double.   
        if((y.DOUBLE >= 0 && y.DOUBLE < 9) && fmod(y.DOUBLE, 1) == 0){
            if((char)y.DOUBLE < x.CHAR) push_LONG(s, 1);
            else push_LONG(s, 0);
        }
        else push_LONG(s, 0);
    }   
    else if(tipo(y, CHAR)){     /// No caso de ser 2 chars.
        if(y.CHAR < x.CHAR) push_LONG(s, 1);
        else push_LONG(s, 0);
    }
    else{             /// No caso de ser char com string.
        push_LONG(s, 0);
    }    
}

/// @brief Funçao menor para o caso de ser string.
void menor_STRING(STACK *s, data_type x, data_type y){
      if(tipo(y, LONG)|| tipo(y, DOUBLE) || tipo(y, CHAR)){  /// No caso de ser string com long.
        push_LONG(s, 0);/// No caso de ser string com double.
        /// No caso de ser string com char.
      }
    if(tipo(y, STRING)){             /// No caso de ser 2 strings.
        if(strlen(y.STRING) < strlen(x.STRING)) push_LONG(s, 1);
        else if(strlen(y.STRING) == strlen(x.STRING))
            if(strcmp(y.STRING, x.STRING) < 0) push_LONG(s, 1);
        else if (strcmp(y.STRING, x.STRING) >= 0) push_LONG(s, 0);
            else push_LONG(s, 0);
        else push_LONG(s,0);
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
      if(tipo(x,LONG)) menor_LONG(s, x, y);
      if(tipo(x,DOUBLE)) menor_DOUBLE(s, x, y);
      if(tipo(x,CHAR)) menor_CHAR(s, x, y);
      if(tipo(x,STRING)) menor_STRING(s, x, y);
}

/// @brief Funçao maior para o caso de ser long.
void maior_LONG(STACK *s,data_type x, data_type y){ 
   if(tipo(y, LONG)){             /// No caso de ser 2 Longs.          
        if(y.LONG > x.LONG) push_LONG(s, 1);
        else push_LONG(s,0);
    }     
    else if(tipo(y, DOUBLE)){           /// No caso de ser long com double.
        if(y.DOUBLE > x.LONG) push_LONG(s, 1);
        else push_LONG(s,0);
    }                   
    else if(tipo(y, CHAR)){         /// No caso de ser long com char.
        if(x.LONG >= 0 && x.LONG < 9){
            if(y.CHAR > (char)x.LONG) push_LONG(s, 1);
            else push_LONG(s, 0);
        }
        else push_LONG(s, 0);
    }                 
    else if(tipo(y, STRING)){           /// No caso de ser Long com string.
        push_STRING(s, strdup(y.STRING + strlen(y.STRING) - x.LONG));
    }           
}

/// @brief Funçao maior para o caso de ser double.
void maior_DOUBLE(STACK *s,data_type x, data_type y){ 
    if(tipo(y, LONG)){             /// No caso de ser double e Long.
        if(y.LONG > x.DOUBLE) push_LONG(s, 1);
        else push_LONG(s, 0);
    }                      
    else if(tipo(y, DOUBLE)){             /// No caso de ser 2 doubles.
        if(y.DOUBLE > x.DOUBLE) push_LONG(s, 1);
        else push_LONG(s, 0);
    }                      
    else if(tipo(y, CHAR)){           /// No caso de ser double com char.
        if((fmod(x.DOUBLE, 1) == 0) && (x.DOUBLE >= 0 && x.DOUBLE < 9)){
            if(y.CHAR > x.DOUBLE) push_LONG(s, 1);
            else push_LONG(s, 0);
        }
        else push_LONG(s, 0);
    }                
    else{           /// No caso de ser Double com string.
        push_LONG(s, 0);
    }
}

/// @brief Funçao maior para o caso de ser char.
void maior_CHAR(STACK *s,data_type x, data_type y){ 
   if(tipo(y, LONG)){             /// No caso de ser char com long.
        if(y.LONG >= 0 && y.LONG < 9){
            if((char)y.LONG > x.CHAR) push_LONG(s, 1);
            else push_LONG(s, 0);
        }
        else push_LONG(s, 0);
    } 
    else if(tipo(y, DOUBLE)){             /// No caso de ser char com double.
        if((y.DOUBLE >= 0 && y.DOUBLE < 9) && fmod(y.DOUBLE, 1) == 0){
            if((char)y.DOUBLE > x.CHAR) push_LONG(s, 1);
            else push_LONG(s, 0);
        }
        else push_LONG(s, 0);
    }   
    else if(tipo(y, CHAR)){            /// No caso de ser 2 chars.
        if(y.CHAR > x.CHAR) push_LONG(s, 1);
        else push_LONG(s, 0);
    }
    else {        /// No caso de ser char com string.
        push_LONG(s, 0);
    } 
}

/// @brief Funçao maior para o caso de ser string.
void maior_STRING(STACK *s, data_type x, data_type y){ 
     if(tipo(y, LONG) || tipo(y, DOUBLE) || tipo(y, CHAR)){ /// No caso de ser string com long.
        push_LONG(s, 0);/// No caso de ser string com char.
    } /// No caso de ser string com double.
    
    else {             /// No caso de ser 2 strings.
        if(strlen(y.STRING) > strlen(x.STRING)) push_LONG(s, 1);
        else if (strlen(y.STRING) == strlen(x.STRING))
            if(strcmp(y.STRING, x.STRING) <= 0) push_LONG(s, 0);
        else if(strcmp(y.STRING, x.STRING) > 0) push_LONG(s, 1);
            else push_LONG(s, 0);
        else push_LONG(s,0);
    }  
}

/** @brief Caso o primeiro valor inserido for maior que o segundo o resultado final quando chamada esta função será 0.
 * Caso seja o primeiro valor mais pequeno, a função finalizará e retorna como resultado 1.
 * Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida.
 */
void maior(STACK *s){                                      
    data_type x = pop(s);                                     
    data_type y = pop(s);
         if(tipo(x,LONG)) maior_LONG(s, x, y);
         if(tipo(x,DOUBLE)) maior_DOUBLE(s, x, y);
         if(tipo(x,CHAR)) maior_CHAR(s, x, y);
         if(tipo(x,STRING)) maior_STRING(s, x, y);
}

/** @brief ao usar esta função iremos ter como resultado 1 quando O valor for diferente de 0.
 * quando o dado for igual a 0 tanto em char como long ou double retornará 1. 
 * Consoante o tipo de valores fornecidos é apresentado um conjunto de linhas que vai solucionar a operação pretendida.
 */ /// !
void negacao(STACK *s){
    data_type x = pop(s);
    
    if(tipo(x,LONG)){ /// No caso de ser long.
        if (x.LONG == 0) push_LONG(s, 1);
        else push_LONG(s, 0);
    }
    else if(tipo(x,DOUBLE)){ /// No caso de ser double.
        if (x.DOUBLE == 0) push_LONG(s, 1);
        else push_LONG(s, 0);
    }
    else if(tipo(x,CHAR)){ /// No caso de ser char.
        if(x.CHAR == (char)0) push_LONG(s, 1);
        else push_LONG(s, 0);
    }
    else { /// No caso de ser string.
        if(strcmp(x.STRING,"0") == 0) push_LONG(s, 1);
        else push_LONG(s, 0);
    }
}

/// @brief Funçao ponto_de_interrogacao para o caso de ser long.
void ponto_de_interrogacao_LONG(STACK *s, data_type z, data_type y, data_type x){
        if(x.LONG != 0){ /// trabalhando com longs.
            if(tipo(y, LONG)) push_LONG(s, y.LONG); /// No caso de ser long.
            else if(tipo(y, DOUBLE)) push_DOUBLE(s, y.DOUBLE); /// No caso de ser double.
            else if(tipo(y, CHAR)) push_CHAR(s, y.CHAR); /// No caso de ser char.
            else  push_STRING(s, y.STRING); /// No caso de ser string.
        }
        else {
            if(tipo(z, LONG)) push_LONG(s, z.LONG); /// No caso de ser long.
            else if(tipo(z, DOUBLE)) push_DOUBLE(s, z.DOUBLE); /// No caso de ser double.
            else if(tipo(z, CHAR)) push_CHAR(s, z.CHAR); /// No caso de ser char.
            else  push_STRING(s, z.STRING); /// No caso de ser string.
        }
}

/// @brief Funçao ponto_de_interrogacao para o caso de ser double.
void ponto_de_interrogacao_DOUBLE(STACK *s, data_type z, data_type y, data_type x){
    ///trabalhando com doubles.
        if(x.DOUBLE != 0){
            if(tipo(y, LONG)) push_LONG(s, y.LONG); /// No caso de ser long.
            else if(tipo(y, DOUBLE)) push_DOUBLE(s, y.DOUBLE); /// No caso de ser double.
            else if(tipo(y, CHAR)) push_CHAR(s, y.CHAR); /// No caso de ser char.
            else push_STRING(s, y.STRING); /// No caso de ser string.
        }
        else {
            if(tipo(z, LONG)) push_LONG(s, z.LONG); /// No caso de ser long.
            else if(tipo(z, DOUBLE)) push_DOUBLE(s, z.DOUBLE); /// No caso de ser double.
            else if(tipo(z, CHAR)) push_CHAR(s, z.CHAR); /// No caso de ser char.
            else push_STRING(s, z.STRING); /// No caso de ser string.
        }
}

/// @brief Funçao ponto_de_interrogacao para o caso de ser char.
void ponto_de_interrogacao_CHAR(STACK *s, data_type z, data_type y, data_type x){
    ///trabalhando com chars.
    if(x.CHAR != '0'){
        if(tipo(y, LONG)) push_LONG(s, y.LONG); /// No caso de ser long.
        else if(tipo(y, DOUBLE)) push_DOUBLE(s, y.DOUBLE); /// No caso de ser double.
        else if(tipo(y, CHAR)) push_CHAR(s, y.CHAR); /// No caso de ser char.
        else push_STRING(s, y.STRING); /// No caso de ser string.
    }
    else {
        if(tipo(z, LONG)) push_LONG(s, z.LONG); /// No caso de ser long.
        else if(tipo(z, DOUBLE)) push_DOUBLE(s, z.DOUBLE); /// No caso de ser double.
        else if(tipo(z, CHAR)) push_CHAR(s, z.CHAR); /// No caso de ser char.
        else push_STRING(s, z.STRING); /// No caso de ser string.
    }
}

/// @brief Funçao ponto_de_interrogacao para o caso de ser string.
void ponto_de_interrogacao_STRING(STACK *s, data_type z, data_type y, data_type x){
    ///trabalhando com strings.
    if(strcmp(x.STRING,"0") != 0){
        if(tipo(y, LONG)) push_LONG(s, y.LONG); /// No caso de ser long.
        else if(tipo(y, DOUBLE)) push_DOUBLE(s, y.DOUBLE); /// No caso de ser double.
        else if(tipo(y, CHAR)) push_CHAR(s, y.CHAR); /// No caso de ser char.
        else push_STRING(s, y.STRING); /// No caso de ser string.
    }
    else {
        if(tipo(z, LONG)) push_LONG(s, z.LONG); /// No caso de ser long.
        else if(tipo(z, DOUBLE)) push_DOUBLE(s, z.DOUBLE); /// No caso de ser double.
        else if(tipo(z, CHAR)) push_CHAR(s, z.CHAR); /// No caso de ser char.
        else push_STRING(s, z.STRING); /// No caso de ser string.
    }
} 

/// @brief Funçao ponto_de_interrogacao para o caso de ser array.
void ponto_de_interrogacao_ARRAY(STACK *s, data_type z, data_type y, data_type x){
    ///trabalhando com arrays.
    if(x.ARRAY -> n_elems != 0){
        if(tipo(y, LONG)) push_LONG(s, y.LONG); /// No caso de ser long.
        else if(tipo(y, DOUBLE)) push_DOUBLE(s, y.DOUBLE); /// No caso de ser double.
        else if(tipo(y, CHAR)) push_CHAR(s, y.CHAR); /// No caso de ser char.
        else push_STRING(s, y.STRING); /// No caso de ser string.
    }
    else {
        if(tipo(z, LONG)) push_LONG(s, z.LONG); /// No caso de ser long.
        else if(tipo(z, DOUBLE)) push_DOUBLE(s, z.DOUBLE); /// No caso de ser double.
        else if(tipo(z, CHAR)) push_CHAR(s, z.CHAR); /// No caso de ser char.
        else push_STRING(s, z.STRING); /// No caso de ser string.
    }
}

/// @brief Funçao ponto_de_interrogacao para o caso de ser bloco.
void ponto_de_interrogacao_BLOCO(STACK *s, data_type z, data_type y, data_type x){
    ///tralhando com blocos.
    if(x.ARRAY -> n_elems != 0){
        if(tipo(y, LONG)) push_LONG(s, y.LONG); /// No caso de ser long.
        else if(tipo(y, DOUBLE)) push_DOUBLE(s, y.DOUBLE); /// No caso de ser double.
        else if(tipo(y, CHAR)) push_CHAR(s, y.CHAR); /// No caso de ser char.
        else push_STRING(s, y.STRING); /// No caso de ser string.
    }
    else {
        if(tipo(z, LONG)) push_LONG(s, z.LONG); /// No caso de ser long.
        else if(tipo(z, DOUBLE)) push_DOUBLE(s, z.DOUBLE); /// No caso de ser double.
        else if(tipo(z, CHAR)) push_CHAR(s, z.CHAR); /// No caso de ser char.
        else push_STRING(s, z.STRING); /// No caso de ser string.
    }
}

/** @brief Esta função funciona como um if then else, if x==0 then z else y
*   se o valor inserido for igual a 0 a função retorna o z, caso contrario finaliza com o valor do y.
*/
void ponto_de_interrogacao(STACK *s){
    data_type z = pop(s);
    data_type y = pop(s);
    data_type x = pop(s); /// metidos ao contrario para a ordem ser a habitual da matematica.
   if(tipo(x,LONG)) ponto_de_interrogacao_LONG(s, z, y, x);
   if(tipo(x,DOUBLE)) ponto_de_interrogacao_DOUBLE(s, z, y, x);
   if(tipo(x,CHAR)) ponto_de_interrogacao_CHAR(s, z, y, x);  
   if(tipo(x,STRING)) ponto_de_interrogacao_STRING(s, z, y, x);
   if(tipo(x,ARRAY)) ponto_de_interrogacao_ARRAY(s, z, y, x);
   if(tipo(x,BLOCO)) ponto_de_interrogacao_BLOCO(s, z, y, x);
}

/**
* @brief Esta função recebe um long x e retorna um valor identico com o mesmo tipo mas em contexto stack
*/
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
	s -> array_abc[0] = cria_l(10);	 /// A   
	s -> array_abc[1] = cria_l(11);	  /// B  
	s -> array_abc[2] = cria_l(12);	    /// C 
	s -> array_abc[3] = cria_l(13);	    /// D 
	s -> array_abc[4] = cria_l(14);	    /// E 
	s -> array_abc[5] = cria_l(15);	    /// F 
	s -> array_abc[13] = cria_c('\n');	/// N 
	s -> array_abc[18] = cria_c(' ');   /// S 
	s -> array_abc[23] = cria_l(0);     /// X 
	s -> array_abc[24] = cria_l(1);     /// Y 
	s -> array_abc[25] = cria_l(2);     /// Z 
}

/// @brief Esta função coloca no topo da stack o valor da respetiva letra
void doisponto_letra(STACK *s, char letra){
	data_type x = top_da_stack(s);
    //printf("ola\n");
	long pos = letra;
	if(tipo(x,LONG))s -> array_abc[pos - 65] = cria_l(x.LONG);// printf("oLA\n");} /// "-65" porque 'A' corresponde a 65 na tabela ascii
	if(tipo(x,DOUBLE)) s -> array_abc[pos - 65] = cria_d(x.DOUBLE);
	if(tipo(x,CHAR)) s -> array_abc[pos - 65] = cria_c(x.CHAR); //printf("oLA\n");}
    if(tipo(x,STRING)){
        s -> array_abc[pos - 65].type = STRING;
        s-> array_abc[pos - 65].STRING = x.STRING;
        push_STRING(s, x.STRING);
    } 
    if(tipo(x,ARRAY)){
        s -> array_abc[pos - 65].type = ARRAY;
        s-> array_abc[pos - 65].ARRAY = x.ARRAY;
        push_ARRAY(s, x.ARRAY);
    } 
    if(tipo(x,STRING)){
        s -> array_abc[pos - 65].type = BLOCO;
        s-> array_abc[pos - 65].BLOCO = x.BLOCO;
        push_BLOCO(s, x.BLOCO);
    }  
}

/// @brief esta função coloca a respetiva "letra" no topo da stack
void letra(STACK *s, char letra){
	long x = letra;
	data_type y = (s -> array_abc[x-65]); /// "-65" porque 'A' corresponde a 65 na tabela ascii
	if(tipo(y,LONG)) push_LONG(s,y.LONG); /// No caso de ser long.
	if(tipo(y,DOUBLE)) push_DOUBLE(s,y.DOUBLE); /// No caso de ser double.
	if(tipo(y,CHAR)) push_CHAR(s,y.CHAR); /// No caso de ser char.
	if(tipo(y,STRING)) push_STRING(s,y.STRING); /// No caso de ser string.

  //  printf("ola\n");
}