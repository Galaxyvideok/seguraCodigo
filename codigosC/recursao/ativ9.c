/*Dado um array de inteiros e o seu número
de elementos, inverta a posição dos seus
elementos.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"
#define MAX 6

void contrario(int *vetor, int ini, int fim){
    int i;
    if (ini > fim){
       return;         
    }
    i = vetor[ini];
    vetor[ini] = vetor[fim];
    vetor[fim] = i;
    contrario(vetor,ini+1,fim-1);
}

void imprimirVetor(int *vet, int quanti){
    int i;
    for (i = 0; i < quanti; i++){
        printf(" %d ", vet[i]);
    }
}

int main(){
    // int res;
    int vetor[MAX] = {1,2,3,4,5,6}; 
    printf("\n%s\n", INICIO);
    imprimirVetor(vetor,MAX);
    contrario(vetor,0,MAX-1);
    printf("\n%s\n", RESULTADO);
    imprimirVetor(vetor,MAX);
    printf("\n%s\n", CORTE);
    return 0;
}