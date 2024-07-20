/* Problema F 

Input: primeiro recebe sempre um numero, depois recebe letras, no maximo 26 letras, ou seja 26x2 por causa 
dos espaços
primeira linha é a frequencia minima para aprecer no output

para a primeira linha - scanf de um int
para a segunda linha while (fgets(str,52,stdin) != NULL)

olhar para o input como uma matriz de A a Z por A a Z   */

#include <stdio.h>

int conta_itens(int frequencia_minima, char str[52][52]);
int menor_char(char str[]);
int linha_matriz(char str[]);


int main (){ // Control D para testar

    int frequencia_minima;
    char str[52][52];  
    
    scanf("%d\n", &frequencia_minima);
    for(int i = 0; i < 52; i++){
        while(fgets(str[i][52],52,stdin) != NULL){   // TENHO Q METER AQUI 52 = 26 letras do alfabeto * 2 (Espaços)
            fgets(str[i][52],52,stdin);              // Enquanto estiver a receber inputs continua a receber
        } 
    }                 
    conta_itens(frequencia_minima, str);
} 


//  Esta função trabalha o input e guarda os seus valores numa matriz 26x26
int conta_itens(int frequencia_minima, char str[52][52]){ 
    int linha;
    int indice;
    int aux = 0;

    char abc_chars[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R',
                        'S','T','U','V','W','X','Y','Z'}; 
    
    int abc_acc[26][26] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};


    for(int i = 0; i < 52; i++){
        for(int j = 0; j < 52; j++){ 
            indice = menor_char(str[i]);
            linha = linha_matriz(str[i]);

            for(int k = 0; k < 26; k++){ 
                aux = 0;
                if(str[i][indice] == abc_chars[k]) abc_acc[k][k]++;
                    while (aux < 52){
                        if(linha != k && str[i][aux] == abc_chars[k]) abc_acc[linha][k]++; 
                        aux++;
                    }
            }
            str[i][indice] = '[';
        }
    }

    // Output:
    for(int p = 0; p < 26; p++){
        if(abc_acc[p][p] >= frequencia_minima) printf("%c = %d\n",abc_chars[p], abc_acc[p][p]);
            for(int ind = 0; ind < 26; ind++){
                if(abc_acc[p][ind] >= frequencia_minima && abc_chars[p] != abc_chars[ind] && p < ind) 
                        printf("%c%c = %d\n",abc_chars[p], abc_chars[ind], abc_acc[p][ind]);
        }
    }
}

//  Esta função recebe a uma linha da matriz e dá a posição do seu menor char
int menor_char(char str[]){
    char acc = '[';
    int i,j; 

    for(i = 0; i < 52; i++){
        if (str[i] < acc) {
          acc = str[i];
      }
    }
    for(j = 0; j < 52; j++){
      if (str[j] == acc){ 
        return j;
      }
    }
}


//  Esta função recebe uma linha da matriz e dá a linha a que o menor char pertence na matriz 26x26
int linha_matriz(char str[]){
    char abc_chars[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R',
                        'S','T','U','V','W','X','Y','Z'};

    char acc = '[';
    int i,j,linha;

    for(i = 0; i < 52; i++){
        if (str[i] < acc) {
          acc = str[i];
      }
    }
    for(j = 0; j < 26; j++){
        if (acc == abc_chars[j]){ 
            return j;
      }
    }
}