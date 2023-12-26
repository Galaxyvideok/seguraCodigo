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

int particao(int vet[], int ini,int fim){
    int pivo = vet[ini];
    int i = ini + 1;
    int f = fim;

    while (i <= f){
        if (vet[i] <= pivo){
            i++;
        }else if (vet[f] > pivo){
            f--;
        }
        else{
            trocar(vet, i, f);
            i++;
            f--;
        }
    }
    trocar(vet, ini, f);
    return f;
}

void quickSort(int vet[], int ini, int fim){
    int posPivo;

    if (ini < fim){
        posPivo = particao(vet,ini,fim);
        quickSort(vet, ini, posPivo - 1);
        quickSort(vet, posPivo + 1, fim);
    }
}

void imprimir(long int * vetor, long int tam) {
	int i;
	for (i=0; i < tam; i++) {
		printf("  %ld", vetor[i]);
	}
}


int main() {
	// SEMENTE DOS NUMEROS ALEATÓRIOS. Usa a hora local
    srand( (unsigned)time(NULL) );
    
	// int vetor[10] = {54, 2, 17, 65, 9, 1, 38, 13};
	// int n = 12;	
	// long int vetor[TAM] = {55, 10, 44, 21, 8, 19, 33, 41, 5, 16, 27, 30};
	// long int vetor[TAM] = {60, 55, 51, 48, 42, 39, 35, 27, 22, 19, 15, 5};

	long int vetor[TAM] = {80, 67,13, 9, 55, 5, 2, 51, 1, 23};
	long int n = TAM;
	// gerarAleatorio(vetor,n);
	
    // shakeSort(vetor,n);
	// shakeSortRE(vetor,0,n);
    combSort(vetor,n);
	
	printf("\n\nDEPOIS: ");
	imprimir(vetor,n);
    return 0;
	
}