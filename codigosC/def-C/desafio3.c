/*Desenvolva um programa que simule a execução de processos utilizando 
uma estrutura de fila (FIFO) ou prioridade (comparando tempos de 
execução).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"
#define MAX 1000
#define TAMNOME 100

struct Processo{
    char nome[TAMNOME];
    int id;
    int prioridade;
    int tempoExecucao;
    int indicador;
};
typedef struct Processo Processo;

void startLista(Processo **lista1, Processo **lista2, Processo **lista3, int quanti){
    *lista1 = (Processo *)calloc(quanti, sizeof(Processo));
    *lista2 = (Processo *)calloc(quanti, sizeof(Processo));
    *lista3 = (Processo *)calloc(quanti, sizeof(Processo));
    if (*lista1 && *lista2 && *lista3) {
        for (int i = 0; i < quanti; i++) {
            (*lista1)[i].indicador = 0;
            (*lista2)[i].indicador = 0;
            (*lista3)[i].indicador = 0;
        }
    }
}

// int buscaBinaria(Processo * vet, int pesq, int ini, int fim) {
//     int meio;  // POSICOES
//     meio = (ini + fim) / 2;
//     if ( pesq == vet[meio].id ) {
//         return meio;
//     } else if ( ini >= fim ) {
//         return -1;  // NÃO ENCONTROU
//     } else if ( pesq > vet[meio].id ) {
//         return buscaBinaria(vet, pesq, meio+1, fim);
//     } else {
//         return buscaBinaria(vet, pesq, ini, meio - 1);
//     }
// }

void insertionSort(Processo *vetor, int n) {
    int valor;
    int k, j;
    for (int i = 1; i < n; i++) {
        valor = vetor[i].id;
        k = 0;
        j = i - 1;
        while (j >= 0 && valor < vetor[j].id) {
            vetor[j + 1].id = vetor[j].id;
            j--;
        }
        vetor[j + 1].id = valor;
    }
}

void impresao(Processo *lista, int quanti, int desci){
    int i;
    if (desci == 0){
        printf("| Prioridade 1: ");  
    }else if (desci == 1){
        printf("| Prioridade 2: ");
    }else{
        printf("| Prioridade 3: ");
    }
    for (i = 0; i < quanti; i++){
        if (lista[i].indicador != 0){
            printf(" %d ", lista[i].id);
        }else{
            printf(" %d ", lista[i].indicador);
        }
        
    }
    printf(" | ");
}

void imprimirLista(Processo *lista1, Processo *lista2, Processo *lista3, int quanti, int *numCiclos, int guarda){
    int i;
    Processo menor;
    menor.id = 99999999999999;
    if (numCiclos == 10){
        for (i = 0; i < quanti; i++){
            if (lista3[i].id < menor.id){
                menor.id = lista3[i].id;
                strcpy(menor.nome,lista3[i].nome);
            }
        }
        *numCiclos = 0;
    }else if (numCiclos == 5){
        for (i = 0; i < quanti; i++){
            if (lista2[i].id < menor.id){
                menor.id = lista2[i].id;
                strcpy(menor.nome,lista2[i].nome);
            }
        }
    }else{
        for (i = 0; i < quanti; i++){
            if (lista1[i].id < menor.id){
                menor.id = lista1[i].id;
                strcpy(menor.nome,lista1[i].nome);
            }
        }
    }
    impresao(lista1,quanti,0);
    impresao(lista2,quanti,1);
    impresao(lista3,quanti,2);
    printf("O processo em execucao no momento e:\n");
    printf("Nome: %s            Id: %d\n",menor.nome,menor.id);
    printf("Ja foi executado: %d ciclios\n", guarda);
}

int menu() {
    int op;
    printf("\n1 - Criar Processo\n");
    printf("2 - Matar Processo\n");
    printf("3 - Sair\n");
    printf("Caso queira continuar os ciclos precione '4'....");
    do {
        printf("Escolha sua opção: ");
        scanf("%d", &op);
    } while(op < 1 || op > 4);
    return op;
}

int main() {
    Processo pri1[MAX];
    Processo pri2[MAX];
    Processo pri3[MAX];
    int quanti;
    int op;
    int numCiclos = 0;
    int guarda = numCiclos;
    printf("\n%s\n", INICIO);
    printf("Qual e o tamanho maximo da fila de processos?: ");
    scanf("%d", &quanti);
    startLista(&pri1,&pri2,&pri3,quanti);
    do{
        imprimirLista(pri1,pri2,pri3,quanti,&numCiclos,guarda);
        op = menu();
        switch (op){
        case 1:
            inserirProcesso();
            insertionSort(pri1,quanti);
            insertionSort(pri2,quanti);
            insertionSort(pri3,quanti);
            break;
        
        case 2:
            excluirProcesso();
            break;
        
        case 3:
            return 0;
            break;
        
        default:
            break;
        }
    } while ((op >= 1) || (op <= 4));
    return 0;
}