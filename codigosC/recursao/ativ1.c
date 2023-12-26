/*Tarefa: Escreva uma função em C chamada calcular_fatorial que 
utilize recursão para calcular o fatorial de um número inteiro não 
negativo n. Certifique-se de tratar o caso base.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"

int fatorial(int n){
    if (n == 0){
        return 1;
    }else{
        return n * fatorial(n-1);
    }
}

int main(){
    int res,n;
    printf("\n%s\n", INICIO);
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    res = fatorial(n);
    printf("\n%s\n", RESULTADO);
    printf("O fatorial de %d e: %d\n",n,res);
    printf("\n%s\n", CORTE);
    return 0;
}