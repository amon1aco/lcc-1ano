// Ficha 4 -- Strings e arrays ordenados
// Ficheiro globalmente não executável

#include <stdio.h>

// --1 só para minusculas
int main(){
    int vogais = 0;
    char string[] = "a maria foi pescar com o zeca";

    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == 'a' || string[i] == 'e'|| string[i] == 'i' || string[i] == 'o' || string[i] == 'u'){
            vogais++;
        }
    }
    printf("%d\n",vogais);
}   

// --2 só para minusculas          
int main(){
    char str[] = "estaa e umaa string coom duuuplicadoos";
    int contador = 0;
    int i, j;

    for(i=0;str[i] != '\0'; i++){
        if(str[i] == 'a' || str[i] == 'e'|| str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            if(str[i] == str[i+1]){
                contador++;
                for(j = i; str[j] != '\0'; j++){
                    str[j] = str[j+1];
                }
                i--;
            }
        }
    }
    printf("%s",str);
    printf("  %d",contador);
    putchar('\n');
} 

int main(){
    char str[] = "estaa e umaa string coom duuuplicadoos";
    char straux[] = "                                         ";
    int contador = 0;
    int i, j = 0;

    for(i=0;str[i] != '\0'; i++){
        if(str[i] == 'a' || str[i] == 'e'|| str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            if(str[i] == str[i+1]){
                contador++;
            }
            else {
                straux[j] = str[i]; j++;
            }
        }
        else {
            straux[j] = str[i];
            j++;
        }
    }
    for(int k = 0; str[k] != '\0'; k++){
        str[k] = straux[k];
    }

    printf("%s",str);
    printf("  %d",contador);
    putchar('\n');
} */

// --3 só para minusculas  
int main(){
    char str[] = "esta e uma string sem duplicados                ";
    char straux[] = "                                              ";
    int i, j = 0;

    for(i=0;str[i] != '\0'; i++){
        if(str[i] == 'a' || str[i] == 'e'|| str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            straux[j] = str[i]; j++;
            straux[j] = str[i]; j++;
        }
        else {
            straux[j] = str[i];
            j++;
        }
    }
    for(int k = 0; str[k] != '\0'; k++){
        str[k] = straux[k];
    }

    printf("%s",str);
    putchar('\n');
} 

#include <string.h>

int main(){                         //STACK SMASHING, N SEI CORRIGIR :(
    char str[] = "esta e uma string sem duplicados";
    int i, j;
    int tamanho = strlen(str);

    for(i=0;str[i] != '\0'; i++){
        if(str[i] == 'a' || str[i] == 'e'|| str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            tamanho++;
            for(j = tamanho-1; j != i; j--){
                str[j] = str[j-1];
            }
            str[tamanho] = '\0';
            i++;
        }
    }

    printf("%s",str);
    putchar('\n');
} 

// Arrays Ordenados
// --1      
int main(){
    int anterior = 0;
    int acc = 0;
    int ar[] = {1,2,5,4,5,6};

    for(int i = 0; i < 6; i++){
        if(ar[i] > ar[i+1]) acc++;
        anterior = ar[i];
    }
    if (acc != 0) printf("Não\n");
    else printf("Sim\n");
}   */

// --2             TA COM UM PEQUENO PROBLEMA EM FUNÇÕES DE TAMANHO DIFERENTE
int main(){
    int a1[] = {1,3,5,7,9};
    int a2[] = {2,4,6,8};
    int tamanho = 10;
    int af[tamanho];
    int i = 0,j = 0, k = 0;

    while (i < tamanho){
        if(j < 4){
            if(a1[k] >= a2[j]){
                af[i] = a2[j];
                j++;
                i++;
            }
        }
        if(k < 5){
            if(a1[k] < a2[j]){
                af[i] = a1[k];
                k++;
                i++;
            }
        }
        if(k == 5 && j == 4){
            if(k > j) af[i] = a1[k-1];
            else af[i] = a2[k-1];
            break;
        }
    }
    for(int ind = 0; ind < tamanho; ind++) printf("%d ",af[ind]);
    putchar('\n');
} 