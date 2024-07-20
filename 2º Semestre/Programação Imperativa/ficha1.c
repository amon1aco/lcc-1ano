/* Ficha 1 */ 
////// Ficheiro globalmente não executavel

#include <stdio.h>
#include <math.h>

/* Exercicio 1 */
// --1

#include <stdio.h>
main(){
int x, y;
x = 3; y = x+1;
x = x*y; y = x + y;
printf("%d %d\n", x, y);
}
output: 12 16 

// -- 2 
#include <stdio.h>
void main(){
int x, y;
x = 0;
printf ("%d %d\n", x, y);
}
output: 0 0 


// -- 3 (assuma que os codigos ASCII dos caracteres ’A’, ’0’, ’ ’ e ’a’ s ̃ao respectivamente
// 65, 48, 32 e 97) 

#include <stdio.h>
main (){
char a, b, c;
a = 'A'; b = ' '; c = '0';
printf ("%c %d\n", a, a);
a = a+1; c = c+2;
printf ("%c %d %c %d\n", a, a, c, c);
c = a + b;
printf ("%c %d\n", c, c); 
}
output: A 65 \n B 66 2 50 \n b 98


// -- 4 
#include <stdio.h>
main(){
int x, y;
x = 200; y = 100;
x = x+y; y = x-y; x = x-y;
printf ("%d %d\n", x, y);
}
output: 100 200 

/* Exercicio 3 */
//-- 1 

#import <stdio.h> 
void desenha (int);

main () {
int x;
printf("Digite um valor: \n");
scanf ("%d",&x);
desenha (x);
return 0;
}

void desenha (x) {
    int i,j;
    for (i = 0; i < x; i++) {
		for (j = 0; j < x; j++)
			printf("#");
		printf("\n");
	}
}       

// -- 2
int main (){
	int x = 5;
	quadradof(x);
	return 0;
}

void quadradof(int x){
	int i,j;
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
			putchar(((i+j)%2)==0?'#':'_');
		}
	putchar('\n');
	}
} 

// -- 3 A
int main (){
	int x = 5;
	triangulo(x);
	return 0;
}

void triangulo(int x){
	int i,j;
	for(i=0;i<x;i++){
		for(j=0;j<=i;j++){
			putchar('#');
		}
	putchar('\n');
	}
	for(i=x-1;i>0;i--){
		for(j=0;j<i;j++){
			putchar('#');
		}
		printf("\n");
	}
} 

// -- 3 B
int main (){
	int x = 5;
	triangulob(x);
	return 0;
}

void triangulob(int x){
	int i,j,e = x-1,c = 1;
	for(i=0;i<x;i++){
		for(j=0;j<e;j++) putchar(' ');
		for(j=0;j<c;j++) putchar('#');
		putchar('\n');
		e -= 1;
		c += 2;
	}
} 

// -- 4        
int main(){
	int x;
	scanf("%d",&x);
	circulo(x);
	return 0;
}

int circulo(int n) {
	int l,c;
		for(l=-n;l<=n;l++){				// de -n a n porque o diametro = 2r
			for(c=-n;c<=n;c++)
				if((l*l)+(c*c)<=(n*n)) putchar('#');
				else putchar (' ');
			putchar('\n');
		}
} 

