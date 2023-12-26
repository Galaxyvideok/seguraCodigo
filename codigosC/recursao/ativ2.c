/* Implemente uma função recursiva em C chamada potencia que calcule a 
elevado à potência b, onde a e b são números inteiros positivos. 
Certifique-se de tratar os casos especiais, como quando b é 
zero (a^0 = 1) e quando a é zero (0^b = 0).*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"

int potencia(int base, int expoente){
    if (expoente == 1){
        return base;
    }else if (expoente == 0){
        return 1;
    }else if (base == 0){
        return 0;
    }else{
        return base * potencia(base,expoente-1);
    }
}

int main(){
    int res, a, b;
    printf("\n%s\n", INICIO);
    printf("Digite um numero inteiro: ");
    scanf("%d", &a);
    printf("Digite o expoente desse numero: ");
    scanf("%d", &b);
    printf("\n%s\n", RESULTADO);
    res = potencia(a,b);
    printf("A potencia %d^%d e: %d\n",a,b,res);
    printf("\n%s\n", CORTE);
    return 0;
}