/*Crie uma função recursiva em C chamada torre_hanoi que resolva o problema das 
Torres de Hanói com recursão. A função deve receber o número de discos e as 
torres de origem, destino e auxiliar como parâmetros.
Mover n - 1 discos da torre de origem para uma torre auxiliar, usando a torre de 
destino como torre auxiliar.
Mover o disco restante (o maior disco) da torre de origem para a torre de destino.
Mover os n - 1 discos da torre auxiliar para a torre de destino, usando a 
torre de origem como torre auxiliar.
*/

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