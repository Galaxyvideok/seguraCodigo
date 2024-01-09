/*Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. 
Associe as variaveis aos ponteiros (use &). Modifique os valores de ´cada variavel usando os ponteiros. 
Imprima os valores das varivaveis antes e ap ´ os a ´
modificac¸ao. */

#include <stdio.h>
#include <stdlib.h>

#define INICIO "--------INICIO--------"
#define FINAL "--------FINAL---------"
#define CORTE "----------------------"

void trocar(int *inteiro, float *real, char *caracter){
    *inteiro = 4;
    *real = 5.2;
    *caracter = 'r';
}

void imprimir(int *inteiro, float *real, char *caracter){
    printf("Numero: %d\n", *inteiro);
    printf("Numero Real: %.2f\n", *real);
    printf("Caracter: %c", *caracter);
    printf("\n\n%s\n\n", CORTE);
}

int main(){
    int num = 3;
    float numReal = 7.5;
    char letra = 'a';
    char ind = 'w';
    int *pontNum = &num;
    float *pontNumReal = &numReal;
    char *pontChar = &letra;
    printf("\n\n%s\n\n", INICIO);
    imprimir(pontNum,pontNumReal,pontChar);
    // trocar(pontNum,pontNumReal,pontChar);
    pontChar = &ind;
    printf("\n\n%s\n\n", FINAL);
    imprimir(pontNum,pontNumReal,pontChar);
}