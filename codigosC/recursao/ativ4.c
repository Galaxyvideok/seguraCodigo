/*Escreva uma função recursiva em C chamada busca_binaria_recursiva que implemente uma busca 
binária em um array ordenado. A função deve retornar a posição do elemento procurado se 
ele estiver no array, ou -1 se o elemento não for encontrado.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"

int pesquisar(int *vet, int quanti, int pesq){
    if (quanti < 0){
        return -1;
    }else if (vet[quanti] == pesq){
        return quanti;
    }else{
        return pesquisar(vet,quanti-1,pesq);
    }
}

int main(){
    int res, n;
    int vet[10] = {20,50,21,27,57,60,80,91,2,1};
    int quanti = 10;
    printf("\n%s\n", INICIO);
    printf("Digite o numero que voce deseja pesquisar: ");
    scanf("%d", &n);
    printf("\n%s\n", RESULTADO);
    res = pesquisar(vet,quanti,n);
    if (res != -1){
        printf("o indice que o numero %d apareçe no vetor e: %d\n", n, res);
    }else{
        printf("O numero %d nao foi encontrado no vetor.",n);
    }
    printf("\n%s\n", CORTE);
    return 0;
}