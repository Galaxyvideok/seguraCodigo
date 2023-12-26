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

void bubbleSort(long int * vetor, long int tam) {
	long int i, aux, fim = tam - 1;
    long int trocas;
    int acumula;
    do{
        trocas = 0;
        for (i = 0; i < fim; i++){
            if (vetor[i] > vetor[i+1]){
                aux = vetor[i+1];
                vetor[i+1] = vetor[i];
                vetor[i] = aux;
                trocas++;
            }
        }
        fim--;
        acumula += trocas;
    }while(trocas > 0);
}

void combSort(long int * vetor, long int tam) {
	long int i, aux;
    long int trocas;
    long int h = tam;
    int acumula;
    do{
        h = h/1.3;
        if ((h == 9)||(h == 10)){
            h = 11;
        }else if (h == 0){
            h = 1;
        }
        // printf("%ld\n", h);
        trocas = 0;
        for (i = 0; i < tam - h; i++){
            if (vetor[i] > vetor[i+h]){
                aux = vetor[i+h];
                vetor[i+h] = vetor[i];
                vetor[i] = aux;
                trocas++;
            }
        }
        if (h == 1){
            tam--;
        }
        acumula += trocas;
    }while((trocas > 0)||(h > 1));
    printf("TROCAS : %d\n", acumula);
}

void shakeSort(long int * vetor, long int tam) {
	long int i, f, aux;
    long int trocas;
    int acumula;
    int ini = 0, fim = tam-1;
    do{
        trocas = 0;
        for (i = ini, f = fim; i < fim; i++,f--){
            if (vetor[i] > vetor[i+1]){
                aux = vetor[i+1];
                vetor[i+1] = vetor[i];
                vetor[i] = aux;
                trocas++;
            }
            if (vetor[f] < vetor[f-1]){
                aux = vetor[f-1];
                vetor[f-1] = vetor[f];
                vetor[f] = aux;
                trocas++;
            }
        }
        ini++;
        fim--;
        acumula = acumula + trocas;
    }while(trocas > 0);

    printf("Trocas: %d", acumula);
}

void shakeSortRE(long int * vetor, long int ini, long int n) {
	long int i, f, aux;
    long int trocas;
    int fim = n - 1;
    // int acumula;

        trocas = 0;
        for (i = ini, f = fim; i < fim; i++,f--){
            if (vetor[i] > vetor[i+1]){
                aux = vetor[i+1];
                vetor[i+1] = vetor[i];
                vetor[i] = aux;
                trocas++;
            }
            if (vetor[f] < vetor[f-1]){
                aux = vetor[f-1];
                vetor[f-1] = vetor[f];
                vetor[f] = aux;
                trocas++;
            }
        }
        ini++;
        fim--;
        // acumula = acumula + trocas;

        if (trocas > 0){
            shakeSortRE(vetor,ini+1,n-1);
        }
        

    // printf("Trocas: %d", acumula);
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