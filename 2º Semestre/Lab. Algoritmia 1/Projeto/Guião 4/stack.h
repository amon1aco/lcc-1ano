/**
* @file stack.h
* @brief Neste ficheiro são definidos tipos que vão ser utilizados ao do código.
*/
#include <stdbool.h>
#include <assert.h>

typedef enum{ 
    LONG = 1,    
    DOUBLE = 2,  
    CHAR = 4,    
    STRING = 8,  
    ARRAY = 16
} TYPE;

//#define INTEGER (LONG | CHAR)
//#define NUMBER (INTEGER | DOUBLE)

struct stack;
typedef struct stack STACK;

/// @brief Definição da struct data_type.
typedef struct data{
    TYPE type;            
    long LONG;            
    double DOUBLE;        
    char CHAR;            
    char *STRING; 
    STACK *ARRAY;   
} data_type;

/// @brief Definição da struct STACK.
typedef struct stack{  
    data_type *stack;     
    int s_size;        
    int n_elems; 
    data_type array_abc[26]; /// 26 porque de A a Z  
} STACK;

                            //convem ser tudo organizado e tudo comentado
STACK *new_stack();
void push(STACK *s, data_type elem);
data_type pop(STACK *s);
int tipo(data_type elem, int mask);
void imprime_s(STACK *s);
void aux_print_arr(STACK *s);
data_type top_da_stack(STACK *s);
void push_LONG(STACK *s, long val);
void push_DOUBLE(STACK *s, double val);
void push_CHAR(STACK *s, char val);
void push_STRING(STACK *s, char * val);
void push_ARRAY(STACK *s, STACK * val);
long pop_LONG(STACK *s);
double pop_DOUBLE(STACK *s);
char pop_CHAR(STACK *s);
char *pop_STRING(STACK *s);
STACK *pop_ARRAY(STACK *s);