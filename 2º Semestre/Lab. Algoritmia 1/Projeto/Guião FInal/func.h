/**
 * @file func.h
 * @brief Este ficheiro contem todos os cabeçalhos das funções criadas no documento func.c para evitar warnings e poder incluir estas funções neste documento.
 */
/// @brief Função que vai ler a linha em Questão.
void l_token(STACK *s);

///@brief cabeçalho das funçoes de conversao.
void i_conver(STACK *s);
void f_conver(STACK *s);
void c_conver(STACK *s);

///@brief cabeçalho da funçao auxiliar para strings da funçao incr.
void incr_STRING(STACK *s);
///@brief cabeçalho da funçao incr.
void incr(STACK *s);

///@brief cabeçalho da funçao auxiliar para strings da funçao decr.
void decr_STRING(STACK *s);
///@brief cabeçalho da funçao decr e uma sua auxiliar.
void decr(STACK *s);

///@brief cabeçalho da funçao add.
void add(STACK *s);
///@brief cabeçalho da funçao auxiliar para longs da funçao add.
void add_LONG(STACK *s);
///@brief cabeçalho da funçao auxiliar para doubles da funçao add.
void add_DOUBLE(STACK *s);
///@brief cabeçalho da funçao auxiliar para chars da funçao add.
void add_CHAR(STACK *s);
///@brief cabeçalho da funçao auxiliar para strings da funçao add.
void add_STRING(STACK *s);
///@brief cabeçalho da funçao auxiliar para arrays da funçao add.
void add_ARRAY(STACK *s);

///@brief cabeçalho da funçao sub.
void sub(STACK *s);
///@brief cabeçalho da funçao auxiliar para longs da funçao sub.
void sub_LONG(STACK *s);
///@brief cabeçalho da funçao auxiliar para doubles da funçao sub.
void sub_DOUBLE(STACK *s);
///@brief cabeçalho da funçao auxiliar para chars da funçao sub.
void sub_CHAR(STACK *s);
///@brief cabeçalho da funçao auxiliar para strings da funçao sub.
void sub_STRING(STACK *s);

///@brief cabeçalho da funçao mult.
void mult(STACK *s);
///@brief cabeçalho da funçao auxiliar para longs da funçao mult.
void mult_LONG(STACK *s);
///@brief cabeçalho da funçao auxiliar para doubles da funçao mult.
void mult_DOUBLE(STACK *s);
///@brief cabeçalho da funçao auxiliar para chars da funçao mult.
void mult_CHAR(STACK *s);
///@brief cabeçalho da funçao auxiliar para strings da funçao mult.
void mult_STRING(STACK *s);
///@brief cabeçalho da funçao auxiliar para arrays da funçao mult.
void mult_ARRAY(STACK *s);

///@brief cabeçalho da funçao modulo.
void modulo(STACK *s);
///@brief cabeçalho da funçao auxiliar para longs da funçao modulo.
void modulo_LONG(STACK *s);
///@brief cabeçalho da funçao auxiliar para doubles da funçao modulo.
void modulo_DOUBLE(STACK *s);
///@brief cabeçalho da funçao auxiliar para chars da funçao modulo.
void modulo_CHAR(STACK *s);
///@brief cabeçalho da funçao auxiliar para strings da funçao modulo.
void modulo_STRING(STACK *s);

///@brief cabeçalho da funçao divisao.
void divisao(STACK *s);
///@brief cabeçalho da funçao auxiliar para longs da funçao divisao.
void divisao_LONG(STACK *s);
///@brief cabeçalho da funçao auxiliar para doubles da funçao divisao.
void divisao_DOUBLE(STACK *s);
///@brief cabeçalho da funçao auxiliar para chars da funçao divisao.
void divisao_CHAR(STACK *s);
///@brief cabeçalho da funçao auxiliar para strings da funçao divisao.
void divisao_STRING(STACK *s);

///@brief cabeçalho da funçao potencia.
void potencia(STACK *s);
///@brief cabeçalho da funçao auxiliar para longs da funçao potencia.
void potencia_LONG(STACK *s);
///@brief cabeçalho da funçao auxiliar para doubles da funçao potencia.
void potencia_DOUBLE(STACK *s);
///@brief cabeçalho da funçao auxiliar para chars da funçao potencia.
void potencia_CHAR(STACK *s);
///@brief cabeçalho da funçao auxiliar para strings da funçao potencia.
void potencia_STRING(STACK *s);
///@brief cabeçalho da funçao auxiliar para arrays da funçao potencia.
void potencia_ARRAY(STACK *s);

///@brief cabeçalho da funçao duplicar.
void duplicar(STACK *s);
///@brief cabeçalho da funçao auxiliar para longs da funçao duplicar.
void duplicar_LONG(STACK *s);
///@brief cabeçalho da funçao auxiliar para doubles da funçao duplicar.
void duplicar_DOUBLE(STACK *s);
///@brief cabeçalho da funçao auxiliar para chars da funçao duplicar.
void duplicar_CHAR(STACK *s);
///@brief cabeçalho da funçao auxiliar para strings da funçao duplicar.
void duplicar_STRING(STACK *s);
///@brief cabeçalho da funçao auxiliar para arrays da funçao duplicar.
void duplicar_ARRAY(STACK *s);

///@brief cabeçalho da funçao troca.
void troca(STACK *s);
///@brief cabeçalho da funçao auxiliar para longs da funçao troca.
void troca_LON(STACK *s);
void troca_LONG(STACK *s);
///@brief cabeçalho da funçao auxiliar para doubles da funçao troca.
void troca_DOU(STACK *s);
void troca_DOUBLE(STACK *s);
///@brief cabeçalho da funçao auxiliar para chars da funçao troca.	
void troca_CHA(STACK *s);
void troca_CHAR(STACK *s);
///@brief cabeçalho da funçao auxiliar para strings da funçao troca.	
void troca_STR(STACK *s);
void troca_STRING(STACK *s);
///@brief cabeçalho da funçao auxiliar para arrays da funçao troca.	
void troca_ARR(STACK *s);
void troca_ARRAY(STACK *s);
///@brief cabeçalho da funçao auxiliar para blocos da funçao troca.	
void troca_BLO(STACK *s);
void troca_BLOCO(STACK *s);

///@brief cabeçalho da funçao rodar.
void rodar(STACK *s);

///@brief cabeçalho da funçao pop_v1.
void pop_v1(STACK *s);

///@brief cabeçalho da funçao n_esimo.
void n_esimo(STACK *s);

/// cabeçalho das funçoes bit.
///@brief cabeçalho da funçao and.
void and(STACK *s);
///@brief cabeçalho da funçao or.
void or(STACK *s);
///@brief cabeçalho da funçao xor.
void xor(STACK *s);
///@brief cabeçalho da funçao not.
void not(STACK *s);