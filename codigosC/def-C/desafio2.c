/*Crie um programa que encontre todas as ocorrências de um padrão 
específico em um texto fornecido pelo usuário, usando a técnica 
de busca de padrões.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"
#define MAX 10000

int pesquisar(char *texto, int quanti1, char *palavra, int quanti2){
    int i,j = 0, recebe = 0, res = 0;
    for (i = 0; i < quanti1; i++){
        if (texto[i] == palavra[j]){
            j++;
            recebe++;
            if (recebe == quanti2){
                res++;
                j = 0;
            }
        }
    }
    return res;
}

int main() {
    char texto[MAX];
    char palavra[MAX];
    int quanti1, quanti2;
    int cont = 0;
    printf("\n%s\n", INICIO);
    printf("Digite o texto aqui: ");
    scanf(" %9999[^\n]s", texto);
    quanti1 = strlen(texto);
    printf("%s\n", CORTE);
    printf("Digite a palavra ou letra que deseja pesquisar: ");
    scanf(" %9999[^\n]s", palavra);
    quanti2 = strlen(palavra);
    cont = pesquisar(texto,quanti1,palavra,quanti2);
    printf("\n%s\n", RESULTADO);
    printf("A quantidade de vezes que '%s' apareçe e : %d",palavra,cont);
    printf("\n%s\n", CORTE);
    return 0;
}