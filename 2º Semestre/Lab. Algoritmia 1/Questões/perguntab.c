/* Pergunta B mooshak */

/* Recebe 3 valores, raio maior, altura e raio menor. Considerando pi = 3.14 calcula o volume com a seguinte
formula: (h*pi)/3 * (R^2 + R*r * r^2) */

#include <stdio.h>

int main(){
    int R,h,r,c;
    if(scanf("%d %d %d",&R,&h,&r) == 3)
    c = (h*3.14)/3 * ((R*R) + (R*r) + (r*r));
    printf("%d\n",c);
    return 0;
}

