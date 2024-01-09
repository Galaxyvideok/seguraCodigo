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

/*Escreva um programa que contenha duas variaveis inteiras. Compare seus enderec¸os e ´
exiba o maior enderec¸o.*/

int main(){
    int num1 = 12;
    int num2 = 9;
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

/*Escreva um programa que contenha duas variaveis inteiras. Leia essas vari ´ aveis do ´
teclado. Em seguida, compare seus enderec¸os e exiba o conteudo do maior enderec¸o.*/

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
        printf("Endereço 1: %p\n", &num1);
        printf("Endereço 2: %p\n", &num2);
        printf("O endereço do segundo inteiro e maior!!!\n");
        printf("\n\n%s\n\n", CORTE);
    }
}

/*Fac¸a um programa que leia 2 valores inteiros e chame uma func¸ao que receba estas ˜
2 variaveis e troque o seu conte ´ udo, ou seja, esta func¸ ´ ao˜ e chamada passando duas ´
variaveis A e B por exemplo e, ap ´ os a execuc¸ ´ ao da func¸ ˜ ao, A conter ˜ a o valor de B e B ´
tera o valor de A.*/

int pedirNum(int desci){
    int num;
    if (desci == 0){
        printf("Digite o numero A:");
        scanf("%d", &num);
    }else{
        printf("Digite o numero B:");
        scanf("%d", &num);
    }
    return num;
}

void trocar(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(){
    printf("\n\n%s\n\n", INICIO);
    int a = pedirNum(0);
    int b = pedirNum(1);
    trocar(&a,&b);
    printf("\n\n%s\n\n", FINAL);
    printf("Valor de A: %d\n", a);
    printf("Valor de B: %d\n", b);
    printf("\n\n%s\n\n", CORTE);
    return 0;
}




