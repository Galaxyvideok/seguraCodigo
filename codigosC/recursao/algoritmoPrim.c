#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define MAX 10

struct Vertice {
    int indice;
    float valor;
    int visitado;
};
typedef struct Vertice Vertice;

struct Aresta {
    int pontoOrigem;
    int pontoDestino;
    float distancia;
    Vertice listaVizinhos[MAX];
};
typedef struct Aresta Aresta;

struct Grafo {
    Vertice listaLinhas[MAX];
    Vertice listaColunas[MAX];
};
typedef struct Grafo Grafo;

int buscaMenorDistancia(Grafo grafite[][MAX], int quanti, int indiceInicial, Aresta *guardaDistancia){
    int k = 0;
    for (int i = 0; i < quanti; i++){
        for (int j = 0; j < quanti; j++){
            if ((grafite[i][j].listaLinhas[i].valor < guardaDistancia[k].distancia) && (grafite[i][j].listaLinhas[i].visitado != 1)){
                guardaDistancia[k].distancia = grafite[i][j].listaLinhas[i].valor;
                guardaDistancia[k].pontoOrigem = i;
                guardaDistancia[k].pontoDestino = j;
            }
        }
    }
    return 0; // Suponho que deva retornar algum valor ou condição de término
}

void algoritmoPrim(Grafo grafite[][MAX], int quanti, int indiceInicial, Aresta *guardaDistancia){
    Vertice arvoreGeradora[MAX];
    arvoreGeradora[indiceInicial].visitado = 1;

    for (int i = 0; i < quanti - 1; i++){
        int indiceVizinhoMenor = buscaMenorDistancia(grafite, quanti, indiceInicial, guardaDistancia);
        
        arvoreGeradora[guardaDistancia[indiceVizinhoMenor].pontoDestino].visitado = 1;

        printf("(%d) -> (%d) - Peso: %.2f\n", 
            guardaDistancia[indiceVizinhoMenor].pontoOrigem, 
            guardaDistancia[indiceVizinhoMenor].pontoDestino, 
            guardaDistancia[indiceVizinhoMenor].distancia);
    }
}

int main() {
    // Criando uma matriz de Grafo com valores literais
    Grafo grafite[MAX][MAX];
    Aresta guardaDistancia[MAX * MAX]; // Número máximo de arestas possíveis

    // Preenchendo a matriz com valores literais
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            // Preenchendo os vértices das listas de linhas e colunas com valores fictícios
            grafite[i][j].listaLinhas[i].indice = i + 1;
            grafite[i][j].listaLinhas[i].valor = (float)i * 10;

            grafite[i][j].listaColunas[j].indice = j + 1;
            grafite[i][j].listaColunas[j].valor = (float)j * 5;

            // Preenchendo uma distância fictícia para as arestas
            grafite[i][j].listaLinhas[i].valor = (float)(i + j);
        }
    }

    // Chamando a função algoritmoPrim para realizar o algoritmo de Prim
    algoritmoPrim(grafite, MAX, 0, guardaDistancia);

    return 0;
}


