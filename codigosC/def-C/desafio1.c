/*Implemente um algoritmo básico de criptografia, como o ciframento de César
, para codificar e decodificar mensagens.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 63 
#define TAM2 1000

void criptografar(char *frase, int quanti, int *resposta) {
    int i;
    for (i = 0; i < quanti; i++) {
        resposta[i] = (int)frase[i] + 1; 
    }
}

void descriptografar(char *frase, int quanti, int *resposta){
    int i;
    for (i = 0; i < quanti; i++){
        resposta[i] = (int)frase[i] - 1;
    }
}

void restaurar(char *frase, int quanti, int *resposta){
    int i;
    for (i = 0; i < quanti; i++){
        frase[i] = resposta[i];
    }
    
}

int menu() {
    int op;
    printf("\n\nMENU\n\n");
    printf("1 - Criptografar\n");
    printf("2 - Descriptografar\n");
    printf("3 - Sair\n");
    do {
        printf("Escolha sua opção: ");
        scanf("%d", &op);
    } while(op < 1 || op > 3);
    return op;
}

int main() {
    int op;
    char frase[TAM2];
    char frase2[TAM2];
    printf("Digite a frase: ");
    scanf(" %999[^\n]s", frase);
    int quanti = strlen(frase);
    int resposta[TAM2];
    int resposta2[TAM2];
    do {
        op = menu();
        switch (op){
            case 1:
                criptografar(frase, quanti, resposta);
                printf("A resposta é: ");
                for (int i = 0; i < quanti; i++) {
                    printf("%c", resposta[i]);
                }
                printf("\n");
                restaurar(frase2,quanti,resposta);
                break; 

            case 2:
                descriptografar(frase2,quanti,resposta2);
                printf("A resposta é: ");
                for (int i = 0; i < quanti; i++) {
                    printf("%c", resposta2[i]);
                }
                printf("\n");
                break;

            case 3:
                exit(0);
                break;

            default:
                break;
        }
    } while ((op >= 1) || (op <= 3));
    return 0;
}
