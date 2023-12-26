// 1. Escreva uma função recursiva para calcular o valor de uma base x elevada a um expoente y. 

#include <stdio.h>
#include <stdlib.h>

int potencia(int x, int y){
    if (y == 0){
        return 1;
    } else {
        return x * potencia(x, y-1);
    }
}

int main(){
    int base = 0, expoente = 0, res;
    printf("Digite o valor da base: ");
    scanf("%d", &base);
    printf("Digite o valor do expoente: ");
    scanf("%d", &expoente);
    res = potencia(base, expoente);
    printf("O calculo da função recursiva de x: %d e y: %d, é: %d", base, expoente, res);
    return 0;
}