#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"
#define MAX 101

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

FILE * abrirArquivo(char * nomeArq, char * modo) {
    FILE * arq;
    arq = fopen( nomeArq, modo );
    if ( arq == NULL) {
        printf("ERRO ao abrir o arquivo.");
        exit(-1);
    }
    return arq;
}

int pesquisar(Funcionario *vetor, int quanti, int pesq) {
    int i;
    for (i = 0; i < quanti; i++) {
        if (vetor[i].matricula == pesq) {
            return i;
        }
    }
    return -1;
}

int pesquisar2(Funcionario *vetor, int pesq, int ini, int fim) {
    int meio = (ini + fim)/2;
    if (vetor[meio].matricula == pesq){
        return meio;
    }else if (ini >= fim){
        return -1;
    }else if (vetor[meio].matricula < pesq){
        return pesquisar2(vetor,pesq,meio,fim);
    }else{
        return pesquisar2(vetor,pesq,ini,meio);
    }
    printf("\nbusca binaraia feita\n");
}

int maiorValor(Funcionario *vetor, int quanti){
    int maior = 0;
    int i;
    for (i = 0; i < quanti; i++){
        if (vetor[i].matricula > vetor[maior].matricula){
            maior = i;
        }
    }
    return maior;
}

void trocar(Funcionario * vet, int i, int f, int *numTrocas) {
    Funcionario aux;
    aux = vet[i];
    vet[i] = vet[f];
    vet[f] = aux;
    (*numTrocas)++;
}

void selectSort(Funcionario *vetor, int quanti){
    int indiceMaior;
    int i, trocas = 0;
    for (i = quanti; i > 1; i--){
        indiceMaior = maiorValor(vetor,i);
        if (indiceMaior != i - 1){
            trocar(vetor,indiceMaior,i-1,&trocas);
            trocas++;
        }
    }
    printf("\nNumero de trocas: %d\n",trocas);
}

int particao(Funcionario *vetor, int ini, int fim, int *numTrocas){
    int pivo, i, f;
    pivo = vetor[ini].matricula;
    i = ini + 1;
    f = fim;
    // int trocas = 0;
    while (i <= f){
        if (vetor[i].matricula < pivo){
            i++;
        }else if (vetor[f].matricula >= pivo){
            f--;
        }else{
            trocar(vetor,i,f,numTrocas);
            i++;
            f--;
            // trocas++;
        }
    }
    trocar(vetor,ini,f,numTrocas);
    // trocas++;
    // printf("\nTROCAS = %d", trocas);
    return f;
}

void quickSort(Funcionario *vetor, int ini, int fim, int *numTrocas){
    int indicePivo;
    if (ini < fim){
        indicePivo = particao(vetor,ini,fim,numTrocas);
        quickSort(vetor,ini, indicePivo - 1,numTrocas);
        quickSort(vetor,indicePivo + 1, fim,numTrocas);
    }
}

void remover(Funcionario *vetor, int *qtde, int pos) {
    int matriculaARemover, anterior, quanti = *qtde;
    if (pos >= 0 ) {
        matriculaARemover = pesquisar(vetor, quanti, pos);
        if (matriculaARemover != -1){
            anterior = vetor[matriculaARemover].matricula;
            if (matriculaARemover < quanti - 1) {
                memcpy(&vetor[matriculaARemover], &vetor[matriculaARemover + 1], sizeof(Funcionario) * (quanti - matriculaARemover - 1));
            }
            vetor[quanti - 1].matricula = 0; 
            vetor[quanti - 1].salario = 0.0; 
            strcpy(vetor[quanti - 1].individuo.nome, ""); 
            vetor[quanti - 1].individuo.telefone = 0; 
            strcpy(vetor[quanti - 1].individuo.email, ""); 
            (*qtde)--;
            printf("\n%s\n", RESULTADO);
            printf("Funcionário com a matrícula %d removido com sucesso.\n", anterior);
            printf("\n%s\n", CORTE);
        }
    } else {
        printf("\n%s\n", RESULTADO);
        printf("A matrícula informada não corresponde a um funcionário válido.\n");
        printf("\n%s\n", CORTE);
    }
}


void inserirFunc(Funcionario *vetor, int *quanti) {
    printf("\n%s\n", INICIO);
    char nome[101];
    int telefone;
    char email[101];
    int matricula;
    float salario;
    do {
        printf("Digite o nome do funcionário: ");
        scanf(" %100[^\n]s", nome);
    } while (pesquisar(vetor, *quanti, matricula) != -1);
    do {
        printf("Digite o telefone do funcionário: ");
        scanf("%d", &telefone);
    } while (pesquisar(vetor, *quanti, matricula) != -1);
    do {
        printf("Digite o e-mail do funcionário: ");
        scanf(" %100[^\n]s", email);
    } while (pesquisar(vetor, *quanti, matricula) != -1);
    do {
        printf("Digite a matrícula do funcionário: ");
        scanf("%d", &matricula);
    } while (pesquisar(vetor, *quanti, matricula) != -1);
    do {
        printf("Digite o salário do funcionário: ");
        scanf("%f", &salario);
    } while (pesquisar(vetor, *quanti, matricula) != -1);
    strcpy(vetor[*quanti].individuo.nome, nome);
    vetor[*quanti].individuo.telefone = telefone;
    strcpy(vetor[*quanti].individuo.email, email);
    vetor[*quanti].matricula = matricula;
    vetor[*quanti].salario = salario;
    (*quanti)++;
    printf("\n%s\n", CORTE);
}

void procuraMatricula(char *resposta, Funcionario *vetor, int pesq, int quanti, int desci) {
    int indiceEncontrado;
    if (desci == 0){
        indiceEncontrado = pesquisar(vetor, quanti, pesq);
    }else{
        indiceEncontrado = pesquisar2(vetor, pesq, 0, quanti-1);
    }
    if (indiceEncontrado != -1) {
        strcpy(resposta, vetor[indiceEncontrado].individuo.nome);
        printf("\n%s\n", RESULTADO);
        printf("Para essa matrícula, consta no sistema o funcionario:\n");
        printf("Nome: %s\n", resposta);
        printf("Telefone: %d\n", vetor[indiceEncontrado].individuo.telefone);
        printf("E-mail: %s\n", vetor[indiceEncontrado].individuo.email);
        printf("Matrícula: %d\n", vetor[indiceEncontrado].matricula);
        printf("Salário: %.2f\n", vetor[indiceEncontrado].salario);
        printf("\n%s\n", CORTE);
    }
}

void procurarNome(Funcionario *vetor, char pesq[], int quanti) {
    int i;
    for (i = 0; i < quanti; i++) {
        if (strcmp(vetor[i].individuo.nome, pesq) == 0) {
            printf("\n%s\n", RESULTADO);
            printf("Para esse nome, consta no sistema o funcionário:\n");
            printf("Nome: %s\n", vetor[i].individuo.nome);
            printf("Telefone: %d\n", vetor[i].individuo.telefone);
            printf("E-mail: %s\n", vetor[i].individuo.email);
            printf("Matrícula: %d\n", vetor[i].matricula);
            printf("Salário: %.2f\n", vetor[i].salario);
            printf("\n%s\n", CORTE);
        }
    }
}

void aumentaSalario(Funcionario *vetor, int quanti, int matricula, float porcentagem){
	int localMatricula = pesquisar(vetor,quanti,matricula);
	float x;
	vetor[localMatricula].salario += (vetor[localMatricula].salario * (porcentagem/100));
	x = vetor[localMatricula].salario;
	printf("\n%s\n", RESULTADO);
	printf("O salario do individuo: %s\n", vetor[localMatricula].individuo.nome);
	printf("Foi reajustado para: %.2f",x);
	printf("\n%s\n", CORTE);
}

void maiorSalario(Funcionario *vetor, int quanti){
	int i, referencia;
	float maior = 0.0;
	for (i = 0; i < quanti; i++){
		if (vetor[i].salario >= maior){
			maior = vetor[i].salario;
            referencia = i;
		}
	}
	printf("\n%s\n", RESULTADO);
	printf("Nome: %s\n", vetor[referencia].individuo.nome);
	printf("Telefone: %d\n", vetor[referencia].individuo.telefone);
    printf("E-mail: %s\n", vetor[referencia].individuo.email);
    printf("Matrícula: %d\n", vetor[referencia].matricula);
    printf("Salário: %.2f\n", vetor[referencia].salario);
	printf("\n%s\n", CORTE);
}

void gravarArquivo(FILE * arquivo, Funcionario * vetor, int qtde) {
    fwrite( &qtde, sizeof(int), 1, arquivo  );
    fwrite( vetor, sizeof(Funcionario), qtde, arquivo  );
}

int selecionarAlgortimo(){
    int num;
    printf("Digite o numero do algoritmo de ordenaçao que voce deseja usar: \n");
    printf("1 - QUICK SORT \n");
    printf("2 - SELECT SORT \n");
    printf("Resposta: ");
    scanf("%d", &num);
    return num;
}

void organizar(Funcionario * vetor, int qtde, int *muda){
    int i;
    int desci;
    int trocas = 0;
    desci = selecionarAlgortimo();
    if (desci == 1){
        quickSort(vetor,0,qtde-1,&trocas);
        printf("Trocas : %d\n", trocas);
    }else{
        selectSort(vetor,qtde);
    }
    printf("\n%s\n", RESULTADO);
    printf("Matricula|Nome                   |telefone|e-mail              |Salario   |\n");
    for( i=0; i < qtde; i++) {
        printf("%9d|%-23s|%8d|%-20s|%10.2f|\n", vetor[i].matricula, vetor[i].individuo.nome, vetor[i].individuo.telefone, vetor[i].individuo.email,vetor[i].salario  );
    }
    printf("\n%s\n", CORTE);
    *muda = 1;
}

void listar(Funcionario * vetor, int qtde) {
    int i;
    printf("\n%s\n", RESULTADO);
    printf("Matricula|Nome                   |telefone|e-mail              |Salario   |\n");
    for( i=0; i < qtde; i++) {
        printf("%9d|%-23s|%8d|%-20s|%10.2f|\n", vetor[i].matricula, vetor[i].individuo.nome, vetor[i].individuo.telefone, vetor[i].individuo.email,vetor[i].salario  );
    }
    printf("\n%s\n", CORTE);
}

void carregarArquivo(FILE * arquivo, Funcionario * vetor, int *qtde) {
    fread( qtde, sizeof(int), 1, arquivo  );
    fread( vetor, sizeof(Funcionario), *qtde, arquivo  );
}

int menu() {
	int op;
// 	system("@cls||clear");  // LIMPA A TELA
	printf("\n\nSISTEMA FOLHA DE PAGAMENTO\n\n");
	printf("1 - Inserir funcionario\n");
	printf("2 - Pesquisar por matricula\n");
	printf("3 - Pesquisar por nome\n");
	printf("4 - Aumentar salario\n");
	printf("5 - Maior salario\n");
	printf("6 - Excluir\n");
	printf("7 - Listar\n");
    printf("8 - Organizar dados\n");
	printf("0 - Sair\n");
	do {
		printf("Escolha sua opção: ");
		scanf(" %d", &op);
	} while(op < 0 || op > 8);
	return op;
	
}

int main() {
    int op;
    FILE * arquivo;
    Funcionario vetor[MAX];
    int quanti = 0;
    int res, desci = 0;
	float porce;
	arquivo = abrirArquivo("../arquivo/listaFuncionarios.bin", "rb");
    char resposta[MAX];
	do {
		op = menu();
		switch ( op ) {
			case 0:
                arquivo = abrirArquivo("../arquivo/listaFuncionarios.bin", "wb");
				gravarArquivo(arquivo,vetor,quanti);
                fclose(arquivo);
				break;
			case 1:
                carregarArquivo(arquivo,vetor,&quanti);
				inserirFunc(vetor,&quanti);
				break;
			case 2:
                carregarArquivo(arquivo,vetor,&quanti);
                printf("Digite o numero da matricula: ");
                scanf("%d", &res);
				procuraMatricula(resposta,vetor,res,quanti,desci);
				break;
			case 3:
                carregarArquivo(arquivo,vetor,&quanti);
				printf("Digite o nome do funcionario: ");
                scanf(" %100[^\n]s", resposta);
				procurarNome(vetor,resposta,quanti);
				break;
			case 4:
                carregarArquivo(arquivo,vetor,&quanti);
				printf("Diga o numero da matricula: ");
				scanf("%d", &res);
				printf("Diga a porcentagem de aumento: ");
				scanf("%f", &porce);
				aumentaSalario(vetor,quanti,res,porce);
				break;
			case 5:
				maiorSalario(vetor,quanti);
				break;
			case 6:
                carregarArquivo(arquivo,vetor,&quanti);
				printf("Diga o numero da matricula que deseja remover: ");
				scanf("%d", &res);
				remover(vetor,&quanti,res);
				break;
			case 7:
                carregarArquivo(arquivo,vetor,&quanti);
				listar(vetor,quanti);
				break;
            case 8:
                organizar(vetor,quanti,&desci);
                break;
			default:
				printf ("\n\nOpção inválida!\n\n");
		}
	} while (op != 0);
	return 0;
}