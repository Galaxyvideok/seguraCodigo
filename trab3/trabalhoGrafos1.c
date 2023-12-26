/*1. Qual cidade possui o maior número de vizinhos? Informar cidade e quantidade de vizinhos. 

2. Qual cidade possui o menor número de vizinhos? Informar cidade e quantidade de vizinhos.

3. Qual cidade possui o vizinho mais distante? Informar cidade, vizinho e distancia.

4. Qual cidade possui o vizinho mais próximo? Informar cidade, vizinho e distância.

5. Dado os nomes de duas cidades pertencentes a matriz de adjacência, qual a distância entre elas?*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"
#define MAX 13
#define TAM 30

FILE * abrirArquivo(char * nomeArq, char * modo) {
    FILE * arq;
    arq = fopen( nomeArq, modo );
    if ( arq == NULL) {
        printf("ERRO ao abrir o arquivo.");
        exit(-1);
    }
    return arq;
}

void carregarArquivo1(FILE *arquivo, int *guarda) {
    char lixo;
    fscanf(arquivo, "%d", guarda);
    fscanf(arquivo, " %c", &lixo);
}

void carregarArquivo2(FILE *arquivo, int quanti, char resposta[][MAX]) {
    int i;
    char lixo;
    int guarda;
    for (i = 0; i < quanti; i++){
        fscanf(arquivo, "%d", &guarda);
        fscanf(arquivo, " %c", &lixo); 
        fscanf(arquivo, "%12s", resposta[i]); 
    }
}

void carregarArquivo3(FILE *arquivo, int quanti, float resposta[][TAM]) {
    int i, j;
    char lixo;
    fscanf(arquivo, "%c", &lixo);
    for (i = 0; i < quanti; i++){
        for (j = 0; j < quanti; j++){
            fscanf(arquivo, "%f", &resposta[i][j]);
            fscanf(arquivo, "%c", &lixo); 
        }
        
    }
}

void listar(char vet[][MAX], int quanti){
    int i, j;
    for (i = 0; i < quanti; i++){
        for (j = 0; j < MAX-1; j++){
            printf("%c",vet[i][j]);
        }
        printf("\n");
    }
    
}

void listar2(float vet[][MAX], int quanti){
    int i, j;
    for (i = 0; i < quanti; i++){
        for (j = 0; j < quanti; j++){
            printf("%6.2f | ",vet[i][j]);
        }
        printf("\n");
    }
}

void encontraMaiorMenorVizinhos(float cidades[][TAM], int quanti, int *cidadeMaisVizinhos, int *cidadeMenosVizinhos, int *maiorVizinhos, int *menorVizinhos) {
    *maiorVizinhos = 0;
    *menorVizinhos = TAM * TAM;
    int i,j;
    for (i = 0; i < quanti; i++) {
        int contVizinhos = 0;
        for (j = 0; j < quanti; j++) {
            if (cidades[i][j] > 0) {
                contVizinhos++;
            }
        }
        if (contVizinhos > *maiorVizinhos) {
            *maiorVizinhos = contVizinhos;
            *cidadeMaisVizinhos = i;
        }
        if (contVizinhos < *menorVizinhos && contVizinhos > 0) {
            *menorVizinhos = contVizinhos;
            *cidadeMenosVizinhos = i;
        }
    }
}

void defineVizinhos(float cidades[][TAM], int quanti, char listagemNomes[][MAX], int desci) {
    int cidadeMaisVizinhos, cidadeMenosVizinhos, maiorVizinhos, menorVizinhos;
    encontraMaiorMenorVizinhos(cidades, quanti, &cidadeMaisVizinhos, &cidadeMenosVizinhos, &maiorVizinhos, &menorVizinhos);

    if (desci == 0) {
        printf("A cidade com mais vizinhos é: %s\n", listagemNomes[cidadeMaisVizinhos]);
        printf("Quantidade de vizinhos: %d\n", maiorVizinhos);
    } else {
        printf("A cidade com menos vizinhos é: %s\n", listagemNomes[cidadeMenosVizinhos]);
        printf("Quantidade de vizinhos: %d\n", menorVizinhos);
    }
}

void encontraVizinhoDistancia(float cidades[][TAM], int quanti, int *cidadeMaisDistante, int *vizinhoMaisDistante, float *maiorDistancia, int *cidadeMaisProxima, int *vizinhoMaisProximo, float *menorDistancia) {
    *maiorDistancia = 0;
    *menorDistancia = 100.00 * 100.00;
    int i,j;
    for (i = 0; i < quanti - 1; i++) {
        for (j = 0; j < quanti; j++) {
            if (cidades[i][j] > *maiorDistancia) {
                *maiorDistancia = cidades[i][j];
                *cidadeMaisDistante = i;
                *vizinhoMaisDistante = j;
            }
        }
    }

    for (i = 0; i < quanti; i++) {
        for (j = 0; j < quanti; j++) {
            if (cidades[i][j] < *menorDistancia && cidades[i][j] > 0) {
                *menorDistancia = cidades[i][j];
                *cidadeMaisProxima = i;
                *vizinhoMaisProximo = j;
            }
        }
    }
}

void vizinhoDistancia(float cidades[][TAM], int quanti, char listagemNomes[][MAX], int desci) {
    int cidadeMaisDistante, vizinhoMaisDistante, cidadeMaisProxima, vizinhoMaisProximo;
    float maiorDistancia, menorDistancia;
    encontraVizinhoDistancia(cidades, quanti,&cidadeMaisDistante, &vizinhoMaisDistante, &maiorDistancia, &cidadeMaisProxima, &vizinhoMaisProximo, &menorDistancia);

    if (desci == 0) {
        printf("A cidade com vizinho mais distante é: %s\n", listagemNomes[cidadeMaisDistante]);
        printf("Vizinho: %s\n", listagemNomes[vizinhoMaisDistante]);
        printf("Distância: %.2f\n", maiorDistancia);
    } else {
        printf("A cidade com vizinho mais próximo é: %s\n", listagemNomes[cidadeMaisProxima]);
        printf("Vizinho: %s\n", listagemNomes[vizinhoMaisProximo]);
        printf("Distância: %.2f\n", menorDistancia);
    }
}

void calculoDistanciaCidades(float cidades[][TAM], int quanti, char listagemNomes[][MAX]){
    char nomeCity1[MAX], nomeCity2[MAX];
    printf("Digite o nome da primeira cidade: ");
    scanf(" %s", nomeCity1);
    printf("Digite o nome da segunda cidade: ");
    scanf(" %s", nomeCity2);
    int i;
    int cidade1 = -1, cidade2 = -1;
    for (i = 0; i < quanti; i++){
        if (strcmp(listagemNomes[i], nomeCity1) == 0){
            cidade1 = i;
        }
        if (strcmp(listagemNomes[i], nomeCity2) == 0){
            cidade2 = i;
        }
    }

    if (cidade1 != -1 && cidade2 != -1){
        float distancia = cidades[cidade1][cidade2];
        if (distancia == 0.00){
            printf("Essas duas cidades nao sao vizinhas.\n");
        }else{
            printf("A distância entre as cidades %s e %s é: %.2f\n", nomeCity1, nomeCity2, distancia);
        }
    }    
}

int menu() {
    int op;
    printf("\n\nMENU CIDADES\n\n");
    printf("1 - Maior número de vizinhos\n");
    printf("2 - Menor número de vizinhos\n");
    printf("3 - Vizinho mais distante\n");
    printf("4 - Vizinho mais próximo\n");
    printf("5 - Distância entre duas cidades\n");
    printf("0 - Sair\n");
    do {
        printf("Escolha sua opção: ");
        scanf(" %d", &op);
    } while (op < 0 || op > 5);
    return op;
}

int main() {
    FILE * arquivo;
    arquivo = abrirArquivo("../arq.txt", "r");
    int quantiCity, op;
    carregarArquivo1(arquivo, &quantiCity);
    char listagemNomes[quantiCity][MAX];
    carregarArquivo2(arquivo, quantiCity, listagemNomes);
    float cidades[quantiCity][quantiCity];
    carregarArquivo3(arquivo, quantiCity, cidades);
    listar(listagemNomes,quantiCity);
    listar2(cidades,quantiCity);
    do{
        op = menu();
        switch (op) {
            case 1:
                defineVizinhos(cidades,quantiCity,listagemNomes,0);
                break;
            case 2:
                defineVizinhos(cidades,quantiCity,listagemNomes,1);
                break;
            case 3:
                vizinhoDistancia(cidades,quantiCity,listagemNomes,0);
                break;
            case 4:
                vizinhoDistancia(cidades,quantiCity,listagemNomes,1);
                break;
            case 5:
                calculoDistanciaCidades(cidades,quantiCity,listagemNomes);
                break;
            case 0:
                printf("FIM DO PROGRAMA!");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (op != 0);
    fclose(arquivo);
	return 0;
}