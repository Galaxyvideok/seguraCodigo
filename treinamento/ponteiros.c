/*Escreva um programa que contenha duas variaveis inteiras. Leia essas vari ´ aveis do ´
teclado. Em seguida, compare seus enderec¸os e exiba o conteudo do maior enderec¸o.*/

#include <stdio.h>
#include <stdlib.h>

#define INICIO "--------INICIO--------"
#define FINAL "--------FINAL---------"
#define CORTE "----------------------"

int pedirNum(int desci){
    int num;
    if (desci == 0){
        printf("Digite o numero 1:");
        scanf("%d", &num);
    }else{
        printf("Digite o numero 2:");
        scanf("%d", &num);
    }
    return num;
}

int main(){
    int num1 = pedirNum(0);
    int num2 = pedirNum(1);
    if (&num1 > &num2){
        printf("\n\n%s\n\n", FINAL);
        printf("Endereço 1: %p\n", &num1);
        printf("Endereço 2: %p\n", &num2);
        printf("O endereço do primeiro inteiro e maior!!!\n");
        printf("\n\n%s\n\n", CORTE);
    }else{
        printf("\n\n%s\n\n", FINAL);
        printf("Endereço 1: %d\n", &num1);
        printf("Endereço 2: %d\n", &num2);
        printf("O endereço do segundo inteiro e maior!!!\n");
        printf("\n\n%s\n\n", CORTE);
    }
}