/*Escreva uma função recursiva que determine quantas
vezes um dígito K ocorre em um número natural N. Por
exemplo, o dígito 2 ocorre 3 vezes em 762021192.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"
#define MAX 6

int procuraDigito(int sequencia, int pesq){
    int num = sequencia/10; 
    if (sequencia == 0){
        return 0;
    }else{
        return procuraDigito(num,pesq) + (sequencia % 10 == pesq);
    }
}

void imprimirVetor(int *vet, int quanti){
    int i;
    for (i = 0; i < quanti; i++){
        printf(" %d ", vet[i]);
    }
}

int main(){
    int res, x, seque;
    // int vetor[MAX] = {1,2,3,4,5,6}; 
    printf("\n%s\n", INICIO);
    // imprimirVetor(vetor,MAX);
    printf("Digite uma sequencia de numeros(ex:42212):");
    scanf("%d", &seque);
    printf("Digite um numero que voce deseja pesquisar nessa sequencia: ");
    scanf("%d", &x);  
    printf("\n%s\n", RESULTADO);
    res = procuraDigito(seque,x);
    printf("A quantidade de vezes que o numero %d apareçe e: %d vez(es)", x,res);
    // imprimirVetor(vetor,MAX);
    printf("\n%s\n", CORTE);
    return 0;
}