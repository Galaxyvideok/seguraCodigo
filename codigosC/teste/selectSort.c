#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

long int gerarAleatorio(long int * vetor, long int n){
    long int i;
    for(i=0; i< n; i++){
        vetor[i] = ( rand() % n) * ( rand() % n) + 1;
    }
    return 0;
}

int maiorValor(int *vetor, int quanti){
    int maior = 0;
    int i;
    for (i = 0; i < quanti; i++){
        if (vetor[i] > vetor[maior]){
            maior = i;
        }
    }
    return maior;
}

void trocar(int *vetor, int element1, int element2){
    int aux;
    aux = vetor[element1];
    vetor[element1] = vetor[element2];
    vetor[element2] = aux;
}

void trocar2(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
    printf("Troca:\n");
}

int filhoEsquerda(int raiz){
    return 2 * raiz + 1;
}

int filhoDireita(int raiz){
    return 2 * raiz + 2;
}

void atualizarHeap(int *vetor, int quanti, int indiceRaiz){
    int esquerda = filhoEsquerda(indiceRaiz);
    int direita = filhoDireita(indiceRaiz);
    int max;
    if (esquerda > quanti - 1){
        return;
    }else if (direita > quanti - 1){
        max = esquerda;
    }else{
        if (vetor[esquerda] > vetor[direita]){
            max = esquerda;
        }else{
            max = direita;
        }
    }
    if (vetor[max] > vetor[indiceRaiz]){
        trocar2(&vetor[max], &vetor[indiceRaiz]);
        atualizarHeap(vetor, quanti, max);
    }
}

void contruirHeap(int *vetor, int n){
    int i;
    for (i = n/2 - 1; i >= 0; i--){
        atualizarHeap(vetor,n,i);
    }
    
}

void heapSort(int *vetor, int quanti){
    int i;
        contruirHeap(vetor,quanti);
    for (i = quanti-1; i > 0; i--){
        trocar2(&vetor[i],&vetor[0]);
        atualizarHeap(vetor,i,0);
    }
    
}

void selectSort(int *vetor, int quanti){
    int indiceMaior;
    if (quanti > 1){
        indiceMaior = maiorValor(vetor,quanti);
        trocar(vetor,indiceMaior,quanti-1);
        selectSort(vetor,quanti-1);
    }
}

void selectSortNormal(int *vetor, int quanti){
    int indiceMaior;
    int f;
    int trocas = 0;
    for (f = quanti; f > 1; f--){
        indiceMaior = maiorValor(vetor,f);
        if (indiceMaior != f - 1){
            trocar(vetor,indiceMaior,f-1);
            trocas++;
        }
    }
    printf("\nNumero de trocas: %d\n", trocas);
}

void imprimir(int * vetor, int tam) {
	int i;
	for (i=0; i < tam; i++) {
		printf("  %d", vetor[i]);
	}
}


int main() {
	// SEMENTE DOS NUMEROS ALEATÓRIOS. Usa a hora local
    srand( (unsigned)time(NULL) );
    
	// int vetor[10] = {54, 2, 17, 65, 9, 1, 38, 13};
	// int n = 12;	
	// long int vetor[TAM] = {55, 10, 44, 21, 8, 19, 33, 41, 5, 16, 27, 30};
	// long int vetor[TAM] = {60, 55, 51, 48, 42, 39, 35, 27, 22, 19, 15, 5};

	int vetor[TAM] =  {80, 67,13, 9, 55, 5, 2, 51, 1, 23};
	int n = TAM;
	// gerarAleatorio(vetor,n);
	
    // shakeSort(vetor,n);
	// shakeSortRE(vetor,0,n);
    // selectSortNormal(vetor,n);
    heapSort(vetor,n);
	
	printf("\n\nDEPOIS: ");
	imprimir(vetor,n);
    return 0;
	
}