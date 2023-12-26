#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_VETOR 70

struct Pessoa {
    char nome[101];
    int telefone;
    char email[101];
};
typedef struct Pessoa Pessoa;

struct Funcionario {
    int matricula;
    float salario;
    Pessoa individuo;
};
typedef struct Funcionario Funcionario;

int aleatorio(int n){
    return ( rand() % n) + 1;
}

FILE * abrirArquivo(char * nomeArq, char * modo) {
    // ABRIR o arquivo
    FILE * arq;
    arq = fopen( nomeArq, modo );
    if ( arq == NULL) {
        printf("ERRO ao abrir o arquivo.");
        exit(-1);
    }
    return arq;
}

void gravarArquivo(FILE *arquivo, Funcionario *vet, int qtde) {
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }

    fwrite(&qtde, sizeof(int), 1, arquivo);
    for (int i = 0; i < qtde; i++) {
        fwrite(&vet[i], sizeof(Funcionario), 1, arquivo);
    }
}

void simularDados(Funcionario *vet, int *qtde) {
    int i;
    char codStr[101];
    Funcionario ct;
    char *nomesDisponiveis[] = {
    "Alice", "Bob", "Charlie", "David", "Emma", "Frank", "Grace", "Henry", "Ivy", "Jack",
    "Kate", "Liam", "Mia", "Noah", "Olivia", "Peter", "Quinn", "Rose", "Sam", "Tara",
    "Uma", "Victor", "Wendy", "Xavier", "Yara", "Zane",
    "Aaron", "Abigail", "Benjamin", "Chloe", "Daniel", "Ella", "Fiona", "Gavin", "Hannah", "Isaac",
    "Jessica", "Kevin", "Lily", "Michael", "Natalie", "Oscar", "Penelope", "Quentin", "Rachel", "Simon",
    "Taylor", "Ursula", "Vincent", "Willa", "Xander", "Yasmine", "Zara",
    "Alex", "Bella", "Caleb", "Diana", "Ethan", "Felicity", "George", "Holly", "Ian", "Jasmine",
    "Keith", "Leah", "Max", "Nora", "Owen", "Pamela", "Quincy", "Rebecca", "Samantha", "Theo",
    "Ulysses", "Violet", "William", "Xena", "Yvonne", "Zachary"};
    int numNomesDisponiveis = sizeof(nomesDisponiveis) / sizeof(nomesDisponiveis[0]);

    for (i = 0; i < *qtde; i++) {
        // Simular os dados
        vet[i].matricula = aleatorio(TAM_VETOR * 10);
        vet[i].salario = aleatorio(TAM_VETOR * 10);

        // Escolher um nome aleatório da lista de nomes disponíveis
        int indiceNome = aleatorio(numNomesDisponiveis) - 1;
        strcpy(vet[i].individuo.nome, nomesDisponiveis[indiceNome]);

        // Gerar e atribuir o email
        sprintf(codStr, "%d", aleatorio(1000));
        strcpy(vet[i].individuo.email, codStr);
        strcat(vet[i].individuo.email, "@empresa.com");

        // Gerar e atribuir o telefone
        vet[i].individuo.telefone = aleatorio(999999999);
    }
}


int main () {
    FILE * arquivo; 
    Funcionario vetor[TAM_VETOR];
    int qtde = TAM_VETOR;

    // SEMENTE DOS NUMEROS ALEATÓRIOS. Usa a hora local
    srand( (unsigned) time(NULL) );

    simularDados(vetor, &qtde);

    arquivo = abrirArquivo("../arquivo/listaFuncionarios.bin", "wb");    
    gravarArquivo(arquivo, vetor, qtde);
    fclose(arquivo);

    
    printf("FIM. Dados gerados com SUCESSO.");
    return 0;
}
