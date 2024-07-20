// Ficha 6 -- Buffers
// Ficheiro globalmente não executável

#include <stdio.h>
#include <stdlib.h>


#define Max 10

struct staticStack {
	int sp;
	int values [Max];
};
typedef struct staticStack *SStack;

void ShowSStack (SStack s);
void SinitStack (SStack s);
int SisEmpty (SStack s);
int Spush (SStack s, int x);
int Spop (SStack s, int *x);
int Stop (SStack s, int *x);

void ShowSStack (SStack s){
    int i;
    printf ("%d Items: ", s->sp);
    for (i=s->sp-1; i>=0; i--) 
        printf ("%d ", s->values[i]);
    putchar ('\n');
}

int main() {
    int i, *x;
    struct staticStack s1;
    SStack S1 = &s1;
  
    SinitStack (S1);
    Spush (S1, 42);
    Spush (S1, 74);
    if(SisEmpty) printf("Está vazia\n");
    else printf("Não esta vazia\n");
    Stop (S1, x);
    Spop(S1, x);
    
    ShowSStack (S1); 
  
    return 0;
} 

/// -- 1
void SinitStack (SStack s){
    s->sp = 0;
}

int SisEmpty (SStack s){
    return s->sp == 0;
}

int Spush (SStack s, int x){
    if(s->sp < 10){ s->values[(s->sp)++] = x; return 0; }

    return 1;
}

int Spop (SStack s, int *x){
    if(s->sp == 0) return 1;

    int y = s->values[s->sp];
    s->sp--;
    *x = y;
    return 0;
}

int Stop (SStack s, int *x){
    if(s->sp == 0) return 1;

    *x = s->values[s->sp-1];
    return 0;
}   */

/// -- 2
#define Max 10

struct staticQueue {
	int front;
	int length;
	int values [Max];
};
typedef struct staticQueue *SQueue;

void ShowSQueue (SQueue q);
void SinitQueue (SQueue q);
int SisEmptyQ (SQueue q);
int Senqueue (SQueue q, int x);
int Sdequeue (SQueue q, int *x);
int Sfront (SQueue q, int *x);

void ShowSQueue (SQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%Max;
    }
    putchar ('\n');
}

int main() {
    int i; int *x;


    struct staticQueue q1;
    SQueue Q1 = &q1;
  
    SinitQueue (Q1);
    Senqueue (Q1, 74);
    Senqueue (Q1, 42);
    Sdequeue (Q1, x);
    if(SisEmptyQ (Q1) == 0) printf("vazia\n");
    else printf("n vazia\n");
    Sfront (Q1, x);
    printf("%d\n",*x);
    
    ShowSQueue(Q1);
 
    return 0;
} 


void SinitQueue (SQueue q){
    q -> front = 0;
    q -> length = 0;
}

int SisEmptyQ (SQueue q){
    if(q -> length == 0) return 0;

    return 1;
}

int Senqueue (SQueue q, int x){
    if(q -> length == Max) return 1;

    q -> values[(q->length)++] = x;
}

int Sdequeue (SQueue q, int *x){ //Não me parece correto..
    if(q -> length == 0) return 1;

    int aux = q -> values[q->length];
    *x = aux;
    q->length--;

    return 0;
}

int Sfront (SQueue q, int *x){
    if(q -> length == 0) return 1;

    *x = q->values[q->length-1];
    return 0;
} */

eu tinha mal isto

int enqueue (QUEUE* q, int x) {
    if(q->inicio + q->tamanho >= MAX) return 1;
    else {
        q->valores[q->inicio + q->tamanho++] = x;
        return 0;
    }
}

// d)

int dequeue (QUEUE* q, int* x) {
    if(q->tamanho == 0) return 1;
    else {
        *x = q->valores[(q->inicio)++];
        (q->tamanho)--;
        return 0;
    }    
}

/// -- 3

typedef struct dinStack {
    int size; // guarda o tamanho do array values
    int sp;
    int *values;
} *DStack;

void ShowDStack (DStack s);
void DinitStack (DStack s);
int DisEmpty (DStack s);
int Dpush (DStack s, int x);
int dupStack (DStack s);

void ShowDStack (DStack s){
    int i;
    printf ("%d Items: ", s->sp);
    for (i=s->sp-1; i>=0; i--) 
        printf ("%d ", s->values[i]);
    putchar ('\n');
}


int main() {
    struct dinStack d1;
    DStack D1 = &d1;

    DinitStack (D1);
    ShowDStack (D1);
    Dpush (D1, 22);
    if(DisEmpty (D1) == 0) printf("Vazia  \n");
    else printf("n vazia \n");
  
    return 0;
} 

void DinitStack (DStack s){
    s -> size = 0;
}

int DisEmpty (DStack s){
    if(s->size == 0) return 0;
    return 1;
}

int  Dpush (DStack s, int x){ // NOT WORKING
	int r=0;
	
	if (s->sp == s->size) dupStack(s);
	s->values[(s->sp)++] = x;
	
	return r;
}

int dupStack (DStack s) {
	int r = 0, i;
	int *t = malloc (2*s->size*sizeof(int));

	if (t == NULL) r = 1;
	else {
		for (i=0; i<s->size; i++) 
			t[i] = s->values[i];
		//free (s->values);
		s->values = t;
		s->size*=2;
	}
	return r;
}