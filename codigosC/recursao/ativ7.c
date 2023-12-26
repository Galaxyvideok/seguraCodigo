/* Implemente uma função recursiva que,
dados dois números inteiros x e n, calcula o
valor de xn.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"
#define MAX 50

int multi(int x, int n){
    if (n == 0){
        return 1;
    }else if (n == 1){
        return x;
    }else{
        return (x * multi(x,n-1));
    }
}

int main(){
    int x, n, res;
    printf("\n%s\n", INICIO);
    printf("Digite o valor de x:");
    scanf("%d", &x);
    printf("Digite o valor de n:");
    scanf("%d", &n);
    printf("\n%s\n", RESULTADO);
    res = multi(x,n);
    printf("O resultado da multiplicacao e: %d\n", res);
    printf("\n%s\n", CORTE);
    return 0;
}