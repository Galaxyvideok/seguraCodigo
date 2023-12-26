/*Usando recursividade, calcule a soma de
todos os valores de um array de reais.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"
#define MAX 6

int somaArray(int *vetor, int quanti){
    if (quanti == 0){
        return 0;
    }else{
        return (vetor[quanti-1] + somaArray(vetor,quanti-1));
    }
}

int main(){
    int res;
    int vetor[MAX] = {1,2,3,4,5,6}; 
    printf("\n%s\n", INICIO);
    res = somaArray(vetor,MAX);
    printf("\n%s\n", RESULTADO);
    printf("O resultado e: %d", res);
    printf("\n%s\n", CORTE);
    return 0;
}