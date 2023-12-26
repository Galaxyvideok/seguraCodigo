#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"
#define MAX 1000

void menu(char  *respostaUsuario) {
    printf("Ola, bem vindo ao sistema Operacional MAX.\n"); 
    printf("Os comandos disponiveis sao: \n");
    printf("1.ls\n");
    printf("2.pwd\n");
    printf("3.du\n"); 
    printf("4.ps\n");
    printf("5.df\n");
    printf("6.uptime\n");
    printf("7.date\n");
    printf("8.exit\n");
    printf("Digite o comando: ");
    fgets(respostaUsuario, MAX, stdin);
    respostaUsuario[strcspn(respostaUsuario, "\n")] = '\0'; // Remove a quebra de linha
}

FILE * abrirArquivo(char * nomeArq, char * modo) {
    FILE * arq;
    arq = fopen( nomeArq, modo );
    if ( arq == NULL) {
        printf("ERRO ao abrir o arquivo.");
        exit(-1);
    }
    return arq;
}

void gravarArquivo(FILE * arquivo, char *texto, int quanti) {
    fwrite(texto,sizeof(char),quanti, arquivo);
}

void retorno(FILE * arquivo,char *resposta,int quanti){
    fread(resposta,sizeof(char),quanti,arquivo);
}

int main() {
    FILE *arquivo;
    arquivo = fopen("../arquivos/saida.bin", "wb");
    char comandoSelecionado[MAX];
    char retornoBash[MAX];
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return -1;
    }
    menu(comandoSelecionado);
    int quantiResp = strlen(comandoSelecionado);
    fwrite(comandoSelecionado, sizeof(char), quantiResp, arquivo);
    fclose(arquivo);
    system("../arquivos/shellMAX.sh");
    arquivo = fopen("../arquivos/entrada.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return -1;
    }
    while (fgets(retornoBash, MAX, arquivo) != NULL) {
        printf("%s", retornoBash);
    }
    fclose(arquivo);
    return 0;
} 

