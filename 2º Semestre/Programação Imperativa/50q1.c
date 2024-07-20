// 50 Questões Parte 1

#include <stdio.h>
#include <string.h>
#include <limits.h>

// -- 1             
/*
main(){
	int p;
	scanf("%d", &p);
	int max = p;
	while(p != 0) {
		scanf("%d", &p);
		if (p > max)
			max = p;
	}
	printf("%d\n", max);
	return max;
} */

// -- 2             
/*
int main(){
    int acc=0,d,total=0;
    scanf("%d", &d);
    while(d!=0){
        acc++;
        total += d;
        scanf("%d", &d);
    }
    printf("A média dos valores é: %d\n",(total/acc));
}
*/

// -- 3
/*
int main(){                     
    int maior, segundo_maior;
    int valor;

    scanf("%d", &valor);
    maior = valor;
    segundo_maior = INT_MIN;

    while(valor != 0){
        scanf("%d",&valor);
        if(valor > maior){
            segundo_maior = maior;
            maior = valor;
        }
        else if(valor > segundo_maior) segundo_maior = valor;
    }
    printf("%d\n",segundo_maior);
}  */

// -- 4                         
/*
int main(){
    int acc=0,d,i;
    scanf("%d", &d);
    for(i=0;i<d;i++){
        if(d%2!=0){ 
            acc++;
        }
        d /= 2;
    }
    printf("O digito tem %d valores em binário\n",(acc+1));
} */

// -- 5                         
/*
int main(){
    int acc=0,d,i;
    scanf("%d", &d);
    for(i=0;i<d;i++){
        if(d%2==0){ 
            acc++;
        }
        d /= 2;
    }
    printf("O digito tem %d valores em binário\n",(acc));
} */

// -- 6                       
/*
int main(){
    int d,i,resto = 0, r = 0;
    scanf("%d", &d);
    for(i=1;resto!=d;i *= 10){
        resto = d % i;
        if(resto!=d) r++;
    }
    printf("O valor tem %d digitos\n",r);
}   */

// -- 7
/*
int main(){
    char s1[] = "ola ";
    char s2[] = "mundo";
    int p,i;
	
    for(p = 0; s1[p] != '\0'; p++);
	
    for (i = 0; s2[i] != '\0';i++,p++) s1[p] = s2[i];
	
    s1[p] = '\0';

    printf("%s",s1);
}   */

// -- 8
/*
char * mystrcpy (char *dest, char source[]){
    char * retorno = dest;

    int i;
    for(i = 0; source[i] != '\0'; i++){
        *dest = source[i];
        dest = dest + 1;
    } 
    *dest = '\0';

    return retorno;
} */

// -- 9
/*
int main(){
    char s1[] = "eduardo";
    char s2[] = "eduardovski";
    
    int i;

    for(i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);

    printf("%d\n",s1[i]-s2[i]);
}   */

// -- 10
/*
int main(){
    char s1[] = "o menino eduardo";
    char s2[] = "eduardo";
    int i,j = 0, k;

    for(i = 0; s1[i] != '\0'; i++){
        i = k;
        j = 0;
        while(s1[k] == s2[j]){
            j++;
            k++;
        }
        if(s2[j] == '\0') return i;
    }
    return NULL;
}   */

// -- 11
/*
void strrev (char s[]){
    char aux;
    int t = strlen(s) - 1;
    int i;
    for(i = 0; i < strlen(s)/2; i++, t--){
        aux = s[i];
        s[i] = s[t];
        s[t] = aux; 
    }
}  

for(tamanho = 0; s[tamanho]!= '\0'; tamanho++); // Calcular o tamnho da string sem usar o strlen() */

// -- 12
// Só considerei as letras minusculas !! 
/*
int main(){
    char s[10] = "fdaheifdjo";
    int j;

    for(j=0; s[j] != '\0'; j++){
        int i = j;
        if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                while(s[i] != '\0'){        // Basicamente esta while puxa a string toda pra traz 1a casa e 
                                            // elimina a vogal
                    s[i] = s[i+1];
                    i++;
                }
                j--;    // caso o while seja executado convem voltar uma casa para o caso de haver 
                        // 2 vogais seguidas serem as duas removidas
        }
    }
    for(int n=0; s[n] != '\0'; n++) printf("%c ", s[n]);
    putchar('\n');
}   */

// -- 13    
/*
int main(){
    char s[] = "liberdade, igualdade e fraternidade";
    int n = 4;
    int i, nn = 0, pos = 0;

    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == ' '){
            nn = 0;
            s[pos] = ' ';
            pos++;
        }
        else if(nn < n){
            s[pos] = s[i];
            nn++;
            pos++;
        }
    }
    s[pos] = '\0';
    printf("%s\n",s);
}   */

// -- 14 
/*
int main (){
    char s[] = "bbgggh";

    char maisFreq = '0';
    int i, j, freq = 0, freqmax = 0;
    
    for(i = 0; s[i] != '\0'; i++){
        freq = 0;
            for(j = 0; s[j] != '\0'; j++){
                if(s[i] == s[j]) freq++;
            }
        if (freq > freqmax){
            freqmax = freq;
            maisFreq = s[i];
        }
    }
	printf("%c\n",maisFreq);
} */

// -- 15 
/*
int iguaisConsecutivos (char s[]){
    if(s[0] == '\0') return 0;
    int i, maiorstr = 1, substr = 1, j;
    for(i = 0; s[i] != '\0'; i++){
        j = i;
        while(s[j] == s[j+1]){
            substr++;
            j++;
        }
        if(substr > maiorstr){
            maiorstr = substr;
        }
        substr = 1;
    }
    return maiorstr;
} */

// -- 16
/*
int not_in_prev(char str[], int k, int n) {
    int i;
    int ans = 1;
    for(i = k; i < n; i++) {
        if(str[i] == str[n]) {
            return 0;
        }
    }
    return ans;
}

int difConsecutivos(char s[]) {
    int j, i;
    int ans = 0;
    for(i = 0; s[i] != '\0'; i++) {
        int consec = 0;
        for( j = i; s[j] != '\0'; j++) {
            if(not_in_prev(s,i,j) != 0) consec++;
            else break;
        }
        if (consec > ans) ans = consec;
    }
    return ans;
} */

// -- 17
/*
int main(){
    char s1[] = "abcddeolamanel";
    char s2[] = "abcdexauzeca";

    int i = 0, acc = 0;

    while (s1[i] == s2[i]){
        acc++;
        i++;
    } 
    printf("%d\n",acc);
}   */

// -- 18
/*
int maiorSufixo (char s1 [], char s2 []) {
    int t1 = strlen(s1)-1;
    int t2 = strlen(s2)-1;
    int acc = 0;
    
    while(s1[t1] == s2[t2]){
        acc++; t1--; t2--;
    }
    
    return acc;
} */

// -- 19 
/*
int sufPref (char s1[], char s2[]) {
    int ans = 0, i, j = 0;
    for(i = 0; s1[i]; i++) {
        if(s1[i] == s2[j++]) ans++;
        else ans = j = 0;
    }
    return ans;
} */

// -- 20 
/*
int contaPal (char s[]) {
    int inWord = 0, total = 0; int i;
    for(i = 0; s[i]; i++) {
        if(s[i] == ' ' || s[i] == '\n') {
            if(inWord != 0) total++;
            inWord = 0;
        }
        else inWord = 1;
    }
    if(inWord != 0) total++;
    return total;
} */

// -- 21
/*
int main(){
    char teste[] = "o nando vai dormir";
    int i, vogais = 0;

    for(i = 0; teste[i] != '\0'; i++){
        if(teste[i] == 'a' ||teste[i] == 'e' ||teste[i] == 'i' ||teste[i] == 'o' ||teste[i] == 'u') vogais++;
    }
    printf("Tem %d vogais\n", vogais);
}   */

// -- 22
/*
int main(){
    char s[] = "braga";
    char teste[] = "bracara augusta";

    int i, acc, j, falso = 0;

    for(i = 0; s[i] != '\0'; i++){
        acc = 0;
        for(j = 0; teste[j] != '\0'; j++){
            if(s[i] == teste[j]) acc++;
        }
        if(acc == 0) falso++;
    }
    if(falso != 0) printf("Falso\n");
    else printf("Verdade\n");
}   */

// -- 23
/*
int main(){
    char teste[] = "ABABA";
    char acumula[strlen(teste)];
    int i, j = strlen(teste) -1;
    int acc = 0;

    for(i = 0; i < strlen(teste); i++){
        acumula[i] = teste[j];
        j--;
    }
    acumula[strlen(teste)] = '\0';

    for(int k = 0; teste[k] != '\0'; k++){
        if(teste[k] == acumula[k]) continue;
        else acc++;
    }
    if(acc == 0) printf("True\n");
    else printf("False\n");
}   */

// -- 24
/*
int main(){
    char s[] = "aaabaaabbbaaa";
    int i, j = 0;
    char acc;
    int add = 1;

    for(i = 0; s[i] != '\0'; i++){
        acc = s[i];
        j = i;
        if(s[i] == s[i+1]){
            while (s[j] != '\0'){
                s[j] = s[j+1];
                j++;
            }
        i--;
        }
    }
    printf("%s\n",s);
}   */

// -- 25
/*
int main(){
    char teste[] = "eduardo    ser    lindo  ";
    char final[strlen(teste)];
    char espaco = ' ';

    int i, j = 0;

    for(i = 0; teste[i] != '\0'; i++){
        final[j] = teste[i];
        if(teste[i] == espaco){
            while (teste[i] == espaco){
                i++;
            }
            i--;
        }
        j++;
    }
    final[j] = '\0';
    printf("%s\n",final);
}   */

// -- 26       
/*
void insere (int s[], int N, int x){
    int i, j;
    
    for(i = 0; s[i] < x; i++);
    for(j = N+1; j > i; j--){
        s[j] = s[j-1];
    }
    s[i] = x;
}*/

// -- 27 
/*
int main(){
    int v1[] = {1,3,5,7};
    int v2[] = {2,4};
    int na = 4;
    int nb = 2;
    int final[6];

    int i = 0,j = 0, k = 0;
    
    while(k < 6){
        if(i < na && j < nb){
            if(v1[i] < v2[j]){
                final[k] = v1[i];
                i++;
                k++;
            }
            if(v1[i] >= v2[j]){
                final[k] = v2[j];
                j++;
                k++;
            }
        }
        else {
            if(i < j){
                final[k] = v2[j];
                k++; j++;
            }
            else{
                final[k] = v1[i];
                k++; i++;
            }
        }
    }
    for(int l = 0; l < 6; l++) printf("%d ", final[l]);
    putchar('\n');
}   */

// --28
/*
int main(){
    int vetor[] = {3,4,1,2,3,4,8,1};
    int i = 2, j = 4;

    int acc = 0;
    
    while (i < j){
        if(vetor[i] <= vetor[i+1]);
        else acc++;

        i++;
    }
    printf("%d\n", acc);
}   */

// -- 29        
/*
int main(){
    int vetor[] = {1,2,(-3), 5,(-1)};
    int N = 5;

    int i, j;

    for(i = 0; i<N; i++){
        j = i;
        if(vetor[i] < 0){
            while(j<N){
                vetor[j] = vetor[j+1];
                j++;
            }
            i--;
            N--;
        }
    }
    for(int k = 0; k < N; k++) printf("%d ",vetor[k]);
    putchar('\n');
} */

// -- 30       
/*
int main(){
    int vetor[] = {1,2,2,2,3,3,6,6,8};
    int tamanho = 9;

    int valor;
    int nr_do_valor = 0;
    int menor = vetor[0];
    int nr_do_menor = 100000;
    
    int i, k, controlo;

    for(i = 0; i < tamanho; i++){
        nr_do_valor = 0;
        valor = vetor[i];
        k = i;
        controlo = 0;
        while(valor == vetor[k]){
            nr_do_valor++;
            k++; i++;
            controlo++;
        }
        if(controlo != 0) i--;
        if(nr_do_valor < nr_do_menor){
            nr_do_menor = nr_do_valor;
            menor = valor;
        }
    }
    printf("%d\n",menor);
}   */

// -- 31
/*
int main(){
    int vetor[] = {1,1,2,2,3,3,8,8,8};
    int tamanho = 9;

    int valor;
    int nr_do_valor = 0;
    int maior = vetor[0];
    int nr_do_maior = 0;
    
    int i, k, controlo;

    for(i = 0; i < tamanho; i++){
        nr_do_valor = 0;
        valor = vetor[i];
        k = i;
        controlo = 0;
        while(valor == vetor[k]){
            nr_do_valor++;
            k++; i++;
            controlo++;
        }
        if(controlo != 0) i--;
        if(nr_do_valor > nr_do_maior){
            nr_do_maior = nr_do_valor;
            maior = valor;
        }
    }
    printf("%d\n",maior);
}   */

// -- 32
/*
int main(){
    int vetor[] = {1, 2, 3, 2, 1, 4, 14, 12, 5, 4};
    int tamanho = 10;

    int sequencia;
    int maior_sequencia = 0;
    int i = 0;

    while(i < tamanho){
        sequencia = 1;
        if(vetor[i] < vetor[i+1]){
            while(vetor[i] < vetor[i+1]){
                sequencia++;
                i++;
            }
        }
        else i++;
        
        if(sequencia > maior_sequencia) maior_sequencia = sequencia;
    }
    printf("%d\n", maior_sequencia);
}   */

// -- 33        
/*
int main(){
    int vetor[] = {1,2,3,2,1,4,2,4,5,4};
    int tamanho = 10;
    int i, take = 0, acc, j, k;

    for(i = 0; i<tamanho; i++){
        acc = vetor[i];
        for(j = i+1; j < tamanho; j++){
            if(acc == vetor[j]){
                k = j;
                while(k < tamanho){
                    vetor[k] = vetor[k+1];
                    k++;
                }
                tamanho--;
            }
           // i--;
        }
    }

    for(int p = 0; p < tamanho; p++) printf("%d ",vetor[p]);
    putchar('\n');
}   */

// -- 34        
/*
int main(){
    int vetor[] = {1,1,2,2,3,3,4,4,5,5};
    int tamanho = 10;

    int i, take = 0, acc, j, k;

    for(i = 0; i<tamanho; i++){
        acc = vetor[i];
        for(j = i+1; j < tamanho; j++){
            if(acc == vetor[j]){
                k = j;
                while(k < tamanho){
                    vetor[k] = vetor[k+1];
                    k++;
                }
                tamanho--;
            }
           // i--;
        }
    }

    for(int p = 0; p < tamanho; p++) printf("%d ",vetor[p]);
    putchar('\n');
}   */

// -- 35
/*
int main(){
    int v1[] = {1,2,3,4,5};
    int tamanho_v1 = 5;
    int v2[] = {1,3,5};
    int tamanho_v2 = 3;

    int i,j, acc = 0;

    for(i = 0; i < tamanho_v1; i++){
        for(j = 0; j< tamanho_v2; j++){
            if(v1[i] == v2[j]) acc++;
        }
    }
    printf("%d\n",acc);
}   */

// -- 36
/*
int main(){
    int v1[] = {5,1,2,44,35};
    int tamanho_v1 = 5;
    int v2[] = {5,1,3};
    int tamanho_v2 = 3;

    int i,j, acc = 0;

    for(i = 0; i < tamanho_v1; i++){
        for(j = 0; j< tamanho_v2; j++){
            if(v1[i] == v2[j]) acc++;
        }
    }
    printf("%d\n",acc);
}   */

// -- 37
/*
int main(){
    int v1[] = {4,6,7,3,1,6,3};
    int tamanho_v1 = 7;

    int i, acc = 0, menor = v1[0];

    for(i = 0; i < tamanho_v1; i++){
        if(v1[i] < menor){
            menor = v1[i];
            acc = i;
        }
    }
    printf("Posição: %d, valor: %d\n",acc,menor);
}   */

// -- 38
/*
int main(){
    int v1[] = {1,2,3,4,5,6};
    int tamanho = 6;
    int final[6];

    int i, acc = 0;

    for(i = 0; i < tamanho; i++){
        acc += v1[i];
        final[i] = acc;
    }
    for(int k = 0; k < tamanho; k++){
        printf("%d ",final[k]);
    }   putchar('\n');
}   */

// -- 39
/*
int main(){
    int tamanho = 4;
    int matz[4][4] = {{1,2,3,4},
                      {0,2,3,4},
                      {0,0,3,4},
                      {0,0,0,1}};

    int i, j, acc = 0;

    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            if(j < i && matz [i][j] != 0) acc++;
        }
    }
    if(acc != 0) printf("False\n");
    else printf("True\n");
}   */

// -- 40        
/*
int main(){
    int tamanho = 4;
    int matriz[4][4] = {{1,1,1,1},
                      {2,2,2,2},
                      {3,3,3,3},
                      {4,4,4,4}};

    int linha, coluna, aux;

    for (linha = 0; linha < tamanho; linha++){
        for (coluna = 0; coluna < tamanho; coluna++){
            if (linha > coluna){
                aux = matriz[linha][coluna];
                matriz[linha][coluna] = matriz[coluna][linha];
                matriz[coluna][linha] = aux;
            }
        }
    }

    for (linha = 0; linha < tamanho; linha++){
        for (coluna = 0; coluna < tamanho; coluna++){
            printf("%d ", matriz[linha][coluna]);
        }
    putchar('\n');
    }
}   */

// -- 41
/*
int main(){
    int linha = 3, coluna = 2;
    int mat1[3][2] = {{1,2},
                      {3,4},
                      {5,6}};
    int mat2[3][2] = {{1,1},
                      {1,1},
                      {1,2}};

    int i, j;

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            mat1[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    for (i = 0; i < linha; i++){
        for (j = 0; j < coluna; j++){
            printf("%d ", mat1[i][j]);
        }
    putchar('\n');
    }
}   */

// -- 42       
/*
int main(){
    int v1[] = {0,1,0,0,1,0,0,1};
    int v2[] = {1,0,1,0,1,1,1,0};
    int vfinal[8];
    int tamanho = 8;

    int i;

    for(i = 0; i < tamanho; i++){
        if(v1[i] == 1 || v2[i] == 1) vfinal[i] = 1;
        else vfinal[i] = 0;
    }
    for(int j = 0; j < tamanho; j++) printf("%d ",vfinal[j]);
    putchar('\n');
}   */

// -- 43
/*
int main(){
    int v1[] = {0,1,0,0,1,0,0,1};
    int v2[] = {1,0,1,0,1,1,1,0};
    int vfinal[8];
    int tamanho = 8;

    int i;

    for(i = 0; i < tamanho; i++){
        if(v1[i] == 1 && v2[i] == 1) vfinal[i] = 1;
        else vfinal[i] = 0;
    }
    for(int j = 0; j < tamanho; j++) printf("%d ",vfinal[j]);
    putchar('\n');
}   */

// -- 44
/*
int main(){
    int v1[] = {0,2,0,0,1,0,0,3};
    int v2[] = {1,1,0,1,4,2,0,0};
    int vfinal[8];
    int tamanho = 8;

    int i;

    for(i = 0; i < tamanho; i++){
        if(v1[i] < v2[i]) vfinal[i] = v1[i];
        else vfinal[i] = v2[i];
    }
    for(int j = 0; j < tamanho; j++) printf("%d ",vfinal[j]);
    putchar('\n');
}      */

// -- 45
/*
int main(){
    int v1[] = {0,2,0,0,1,0,0,3};
    int v2[] = {1,1,0,1,4,2,0,0};
    int vfinal[8];
    int tamanho = 8;

    int i;

    for(i = 0; i < tamanho; i++){
        vfinal[i] = v1[i] + v2[i];
    }
    for(int j = 0; j < tamanho; j++) printf("%d ",vfinal[j]);
    putchar('\n');
}   */

// -- 46
/*
int main(){
    int v1[] = {0,2,0,0,1,0,0,3};
    int tamanho = 8;

    int i, cardinal = 0;

    for(i = 0; i < tamanho; i++){
        cardinal += v1[i];
    }
    printf("%d\n",cardinal);
}   */

// -- 47  
/*
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;

typedef struct posicao {
    int x, y;
} Posicao;
*/
/*
Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i;
    Posicao p = inicial;
    
    for(i = 0; i < N; i++){
        if(mov[i] == Sul) p.y--;
        else if(mov[i] == Norte) p.y++;
        else if(mov[i] == Este) p.x++;
        else if(mov[i] == Oeste) p.x--;
    }
    return p;
} */

// -- 48
/*
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i = 0;
    Posicao p = inicial;
    
    while(i < N){
        if(p.x < final.x){ 
            mov[i] = Este;
            p.x++;
        }
        else if(p.x > final.x){ 
            mov[i] = Oeste;
            p.x--;
        }
        else if(p.y < final.y){ 
            mov[i] = Norte;
            p.y++;
        }
        else if(p.y > final.y){ 
            mov[i] = Sul;
            p.y--;
        }
        else break;
        i++;
    }
    if(p.x != final.x || p.y != final.y) return -1;
    return i;
} */

// -- 49
/*
int maiscentral (Posicao pos[], int N) {
    int i, maiscentral = 0;
    float dismaiscentral = dist(pos[0].x, pos[0].y);
    for(i = 1; i < N; i++){
        if(dist(pos[i].x, pos[i].y) < dismaiscentral){
            maiscentral = i;
            dismaiscentral = dist(pos[i].x, pos[i].y);
        }
    }
    return maiscentral;
}

float dist(int x, int y){
    return sqrt(pow(x,2)+pow(y,2));
}  */

// -- 50
/*
int vizinhos (Posicao p, Posicao pos[], int N) {
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(manDist(pos[i].x,pos[i].y,p.x,p.y) == 1) ans++;
    }
    return ans;
}   

int manDist(int x, int y, int x0, int y0) {return abs(x - x0) + abs(y - y0);}*/