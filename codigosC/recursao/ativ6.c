/* Implemente uma função recursiva em C chamada caminhos_em_labirinto que 
encontre todos os caminhos possíveis em um labirinto representado como uma 
matriz, indo da posição inicial à posição final, evitando obstáculos.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"
#define MAX 50

void torreHanoi(int numDiscos, char torreOrigem, char torreAuxiliar, char torreDestino){
    if (numDiscos == 1){
        printf("Mover de %c para %c \n",torreOrigem,torreDestino);
    }else{
        torreHanoi(numDiscos-1,torreOrigem,torreAuxiliar,torreDestino);
        printf("Mover de %c para %c \n",torreOrigem,torreDestino);
        torreHanoi(numDiscos-1,torreAuxiliar,torreDestino,torreOrigem);
    }
}

int main(){
    int numDiscos;
    char torreOrigem = '1';
    char torreAuxiliar = '2';
    char torreDestino = '3';
    printf("\n%s\n", INICIO);
    printf("Digite o numero de discos: ");
    scanf("%d", &numDiscos);
    printf("\n%s\n", RESULTADO);
    torreHanoi(numDiscos,torreOrigem,torreAuxiliar,torreDestino);
    printf("\n%s\n", CORTE);
    return 0;
}