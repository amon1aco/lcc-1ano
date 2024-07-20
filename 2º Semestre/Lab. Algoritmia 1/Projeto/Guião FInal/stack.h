/**
* @file stack.h
* @brief Neste ficheiro fundamentalmente está "criada" a stack.
* Para além da stack estão criados structers referentes aos tipos dos elementos da stack
* E estão também defenidos operações base da stack, como o push e o pop
*/

#include <stdbool.h> /// Estes includes são para evitar ter que incluir a mesma coisa em todos os documentos
#include <assert.h> /// Por exemplo este include, inclui a função assert que é utilizada nas operações de "pop"

/// @brief Esta struct define os tipos possiveis de cada elemento da stack, para podermos operarmos com eles
typedef enum {
    LONG = 1,    /// Tipo long, exp 1
    DOUBLE = 2,  /// Tipo double, exp 1,0
    CHAR = 4,    /// Tipo char, exp 'a'
    STRING = 8,  /// Tipo string, exp "ola"
    ARRAY = 16,  /// Tipo array, exp [1,2,3]
    BLOCO = 32   /// Tipo Bloco, exp {a}
} TYPE;

/// @brief Estas defeniçoes servem apenas para não dar erro de tipo na definição da stack
struct stack;
typedef struct stack STACK;

/// @brief Definição da struct data_type.
typedef struct data { /// Esta struct define o tipo de cada elemento da stack, para podermos operarmos com eles
    TYPE type;      /// Este type contem o tipo de cada elemento da stack
    long LONG;      /// Tipo long, definido como long    
    double DOUBLE;  /// Tipo double, definido como double   
    char CHAR;      /// Tipo char, definido como char    
    char *STRING;   /// Tipo string, definido como um apontador de char 
    STACK *ARRAY;   /// Tipo array, definido como uma stack
    char *BLOCO;    /// Tipo bloco, definido como um apontador de um char
} data_type;

/// @brief Definição da struct STACK.
typedef struct stack{  /// Esta struct define a stack, o "centro" do projeto
    data_type *stack;  /// Este valor do tipo data_type guarda o topo da stack
    int s_size;        /// Este inteiro guarda o valor máximo da stack
    int n_elems;       /// Este inteiro guarda o numero de elementos que estão na stack
    data_type array_abc[26]; /// Este array guarda as variaveis pedidas no guião 3
} STACK;

/// @brief Funções definidas em "stack.c"

/// @brief cabeçalho da funçao tipo.
int tipo(data_type elem, int mask); /// Verifica se um valor é de um dado tipo

/// @brief cabeçalho da funçao imprime_s.
void imprime_s(STACK *s); /// Imprime a stack no terminal

/// @brief cabeçalho da funçao aux_print_arr.
void aux_print_arr(STACK *s); /// Auxiliar da função que imprime a stack

///@brief cabeçalho das funçoes push.
/// @brief cabeçalho da funçao principal push.
void push(STACK *s, data_type elem); /// "Pusha" um valor para o topo da stack
/// @brief cabeçalho da funçao push para longs.
void push_LONG(STACK *s, long val);     /// "Pusha" um long para o topo da stack
/// @brief cabeçalho da funçao push para doubles.
void push_DOUBLE(STACK *s, double val); /// "Pusha" um double para o topo da stack
/// @brief cabeçalho da funçao push para chars.
void push_CHAR(STACK *s, char val);     /// "Pusha" um char para o topo da stack
/// @brief cabeçalho da funçao push para strings.
void push_STRING(STACK *s, char * val); /// "Pusha" uma string para o topo da stack
/// @brief cabeçalho da funçao push para arrays.
void push_ARRAY(STACK *s, STACK * val); /// "Pusha" um array para o topo da stack

///@brief cabeçalho das funçoes pop.
/// @brief cabeçalho da funçao pop para longs.
long pop_LONG(STACK *s);      /// Elimina um long do topo da stack
/// @brief cabeçalho da funçao pop para doubles.      
double pop_DOUBLE(STACK *s);  /// Elimina um double do topo da stack
/// @brief cabeçalho da funçao pop para chars.
char pop_CHAR(STACK *s);      /// Elimina um char do topo da stack
/// @brief cabeçalho da funçao pop para strings.
char *pop_STRING(STACK *s);   /// Elimina uma string do topo da stack
/// @brief cabeçalho da funçao push para blocos.
void push_BLOCO(STACK *s, char * val); /// Elimina um bloco do topo da stack

///@brief Alguns tipos usados ao longo do codigo.
data_type pop(STACK *s); /// Elimina um valor do topo da stack
data_type top_da_stack(STACK *s); /// Retorna o valor no topo da stack sem o eliminar
///@brief cabeçalhos de funçoes que efetuam alteraçoes em stacks.
STACK *pop_ARRAY(STACK *s);   /// Elimina um array do topo da stack
STACK *new_stack(); /// Cria uma nova stack
