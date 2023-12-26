#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1000

long int gerarAleatorio(long int * vetor, long int n){
    long int i;
    for(i=0; i< n; i++){
        vetor[i] = ( rand() % n) * ( rand() % n) + 1;
    }
}

void trocar (long int * vetor, long int i, long int j) {
	long int aux;
	aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}


void intercalar (long int * vetor, long int ini1, long int fim1, long int ini2, long int fim2  ) {

	long int tam = fim2 - ini1 + 1;
	long int * vetorAux = (long int *) malloc ( tam * sizeof(long int) );
	
	long int ind1 = ini1;
	long int ind2 = ini2;
	long int k = 0;
	
	while ( ( ind1 <= fim1  ) && ( ind2 <= fim2 ) ) {
		if ( vetor[ind1] <= vetor[ind2] ) {
			vetorAux[k] = vetor[ind1];
			ind1++;
			k++;
		} else {
			vetorAux[k] = vetor[ind2];
			ind2++;
			k++;
		}		
	}
	
	while ( ind1 <= fim1 ) {
		vetorAux[k] = vetor[ind1];
		ind1++;
		k++;
	}
	
	while ( ind2 <= fim2 ) {
		vetorAux[k] = vetor[ind2];
		ind2++;
		k++;
	}

	// COPIAR DO AUX para o VETOR PRINCIPAL
//	for (k=0; k < tam; k++) {
//		vetor[ini1+k] = vetorAux[k];
//	}	
	
	// COPIAR BLOCOS de MEMÓRIA
	memcpy( &vetor[ini1], vetorAux, tam * sizeof(long int) );
	
	free(vetorAux);
}


void mergeSort(long int * vetor, long int ini, long int fim ) {

	if ( ini < fim) {
		long int meio = (ini + fim) / 2;
		mergeSort(vetor, ini, meio);
		mergeSort(vetor, meio + 1, fim);
		
		intercalar(vetor, ini, meio, meio + 1, fim);		
	}	
}

void imprimir(long int * vetor, long int tam) {
	long int i;
	for (i=0; i < tam; i++) {
		printf("  %ld", vetor[i]);
	}
}


void main() {
	// SEMENTE DOS NUMEROS ALEATÓRIOS. Usa a hora local
    srand( (unsigned)time(NULL) );
    
//	int vetor[10] = {54, 2, 17, 65, 9, 1, 38, 13};
//	int n = 12;	
//	long int vetor[TAM] = {55, 10, 44, 21, 8, 19, 33, 41, 5, 16, 27, 30};
//	long int vetor[TAM] = {60, 55, 51, 48, 42, 39, 35, 27, 22, 19, 15, 5};

//	int n = 9;	
//	long int vetor[TAM] = {50, 33, 22, 20, 24, 18, 5, 12, 1};
	
	
	long int * vetor = (long int*) malloc(TAM * sizeof(long int) );
	long int n = TAM;
	gerarAleatorio(vetor,n);

	mergeSort(vetor,0, n-1);
	
//	printf("\n\nDEPOIS: ");
	imprimir(vetor,n);

	
}