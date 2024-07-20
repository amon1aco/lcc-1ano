/**
 * @file funcguiao3.h
 * @brief Este ficheiro contem todos os cabeçalhos das funções criadas no documento funcguiao3.c e alguns tipos para evitar warnings e poder incluir estas funções neste documento.
 */

///@brief cabeçalho da funçao e_maior.
void e_maior(STACK *s);
///@brief cabeçalho da funçao auxiliar para longs da funçao e_maior.
void e_maiorLONG(STACK *s);
///@brief cabeçalho da funçao auxiliar para doubles da funçao e_maior.
void e_maiorDOUBLE(STACK *s);
///@brief cabeçalho da funçao auxiliar para chars da funçao e_maior.
void e_maiorCHAR(STACK *s);
///@brief cabeçalho da funçao auxiliar para strings da funçao e_maior.
void e_maiorSTRING(STACK *s);

///@brief cabeçalho da funçao e_menor.
void e_menor(STACK *s);
///@brief cabeçalho da funçao auxiliar para longs da funçao e_menor.
void e_menorLONG(STACK *s);
///@brief cabeçalho da funçao auxiliar para doubles da funçao e_menor.
void e_menorDOUBLE (STACK *s);
///@brief cabeçalho da funçao auxiliar para chars da funçao e_menor.
void e_menorCHAR (STACK *s);
///@brief cabeçalho da funçao auxiliar para strings da funçao e_menor.
void e_menorSTRING(STACK *s);

///@brief cabeçalho da funçao e_shortcut.
void e_shortcut(STACK *s);
///@brief cabeçalho da funçao auxiliar para longs da funçao e_shortcut.
void e_shortcutLONG(STACK *s);
///@brief cabeçalho da funçao auxiliar para doubles da funçao e_shortcut.
void e_shortcutDOUBLE(STACK *s);
///@brief cabeçalho da funçao auxiliar para chars da funçao e_shortcut.
void e_shortcutCHAR(STACK *s);

///@brief cabeçalho da funçao ou_shortcut.
void ou_shortcut(STACK *s);
///@brief cabeçalho da funçao auxiliar para longs da funçao ou_shortcut.
void ou_shortcutLONG(STACK *s);
///@brief cabeçalho da funçao auxiliar para doubles da funçao ou_shortcut.
void ou_shortcutDOUBLE(STACK *s);
///@brief cabeçalho da funçao auxiliar para chars da funçao ou_shortcut.
void ou_shortcutCHAR(STACK *s);

///cabeçalho das funçoes de operaçoes e logica.
///@brief cabeçalho da funçao auxuliar da igual para longs.
void igual_LONG(STACK *s);
///@brief cabeçalho da funçao auxuliar da igual para double.
void igual_DOUBLE(STACK *s);
///@brief cabeçalho da funçao auxuliar da igual para char.
void igual_CHAR(STACK *s);
///@brief cabeçalho da funçao auxuliar da igual para STRING.
void igual_STRING(STACK *s);
///@brief cabeçalho da funçao igual.
void igual(STACK *s);
///@brief cabeçalho da funçao auxiliar menor para longs.
void menor(STACK *s);
///@brief cabeçalho da funçao auxiliar menor para doubles.
void menor(STACK *s);
///@brief cabeçalho da funçao auxiliar menor para chars.
void menor(STACK *s);
///@brief cabeçalho da funçao auxiliar menor para strings.
void menor(STACK *s);
///@brief cabeçalho da funçao menor.
void menor(STACK *s);
///@brief cabeçalho da funçao auxiliar maior para longs.
void maior(STACK *s);
///@brief cabeçalho da funçao auxiliar maior para doubles.
void maior(STACK *s);
///@brief cabeçalho da funçao auxiliar maior para chars.
void maior(STACK *s);
///@brief cabeçalho da funçao auxiliar maior para strings.
void maior(STACK *s);
///@brief cabeçalho da funçao maior.
void maior(STACK *s);
///@brief cabeçalho da funçao negaçao.
void negacao(STACK *s);
///@brief cabeçalho da funçao auxiliar ponto_de_interrogacao para longs.
void ponto_de_interrogacao_LONG(STACK *s);
///@brief cabeçalho da funçao auxiliar ponto_de_interrogacao para doubles.
void ponto_de_interrogacao_DOUBLE(STACK *s);
///@brief cabeçalho da funçao auxiliar ponto_de_interrogacao para chars.
void ponto_de_interrogacao_CHAR(STACK *s);
///@brief cabeçalho da funçao auxiliar ponto_de_interrogacao para strings.
void ponto_de_interrogacao_STRING(STACK *s);
///@brief cabeçalho da funçao auxiliar ponto_de_interrogacao para arrays.
void ponto_de_interrogacao_ARRAY(STACK *s);
///@brief cabeçalho da funçao auxiliar ponto_de_interrogacao para blocos.
void ponto_de_interrogacao_BLOCO(STACK *s);
///@brief cabeçalho da funçao ponto_de_interrogacao.
void ponto_de_interrogacao(STACK *s);

///alguns tipos definidos que sao utilizados ao longo do codigo.
///@brief cabeçalho do tipo cria_l.
data_type cria_l(long x);
///@brief cabeçalho do tipo cria_d.
data_type cria_d(double x);
///@brief cabeçalho do tipo cria_c.
data_type cria_c(char x);

///cabeçalho das funçoes usadas nas operaçoes com letras.
///@brief cabeçalho da funçao doisponto_letra.
void doisponto_letra(STACK *s, char letrinha);
///@brief cabeçalho da funçao preenche_array.
void preenche_array(STACK *s);
///@brief cabeçalho da funçao letra.
void letra(STACK *s, char letrinha);