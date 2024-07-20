// Ficha 2
// Ficheiro globalmente não executavel.

#include <stdio.h>

// -- 1
float main (){
    float r = 0,m;
    int i,n;
    scanf("%d %f",&n,&m);
    for (i = 0; i < n; i++) r += m;
    printf("%f\n",r);
    return r;
} 

// -- 2
int main(){ 
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d\n",multiplica2(x,y));
    return 0;
}

multiplica2(int x, int y){
    int i, r=0;
    if (x>y){
        for(i=0;i!=x;){
            y = y*2;
            x = x/2;
            if(x%2!=0)r = r+y;
        }
    }
    return r;
}

// -- 3
int main(){ 
    int x,y;
    scanf("%d %d",&x,&y);
    mdc1(x,y);
    return 0;
}

int mdc1 (x,y){
    int i,div=1;
    for(i=y;i>0;i--){
        if (x%i==0 && y%i==0) div = i;
    }
    printf("O mdc é %d\n",div);
    return div;
}   

// -- 4
int main(){ 
    int x,y;
    scanf("%d %d",&x,&y);
    mdc2(x,y);
    return 0;
}

int mdc2(x,y){
    if(x>y){
        mdc2(x-y,y);
    }
    else if(x<y){
        mdc2(x,y-x);
    }
    else if(x==y){
        printf("O mdc é %d\n",x);
    }
return 0;
} 

// -- 5
int main(){ 
    int x,y;
    scanf("%d %d",&x,&y);
    mdc3(x,y);
    return 0;
}

int mdc3(x,y){
    while (x != 0 && y != 0) {
        if (x > y) x%=y;
        else y%=x;
    }
    printf("O mdc é %d\n",x+y);
return 0;
} 

// -- 6 a)
main(){
    int x;
    scanf("%d\n", &x);
    printf("%d\n",fib(x));
    return 0;
}

int fib(int x){
    int r;
    if(x<2)r=1;
    else r = fib(x-1) + fib(x-2);
    return r;
}  // Versão extremamemente ineficiente

// -- 6 b) 
main(){
    int x;
    scanf("%d", &x);
    printf("%d\n",fib2(x));
    return 0;
}

int fib2(int x){
    int ant = 1, antant = 0, val = 1;

    for(int i = 0; i < x; i++){
        if(i < 2){
            ant = 1; antant = 0; val = 1;
        }
        val = ant + antant;
        antant = ant;
        ant = val;
    }
    return val;
}
