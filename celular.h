#define MAX 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celular {
	int chave;
	char marca[50];
	char modelo[20];
	char processador[20];
	char memoria[20];
	char tela[20];
	char cameraF[20];
	char cameraT[20];
	char geracao[20];
	char OS[20];
	char preco[20];
};
typedef struct celular Tcelular;

struct listaCelular {
	unsigned nco;  // N�mero de celulares na lista
	Tcelular celulares[MAX];
};
typedef struct listaCelular TlistaCelular;

void mostreCelular(Tcelular cel) {
	//printf("Chave: %d \n", cel.chave);
	printf("Marca: %s \n", cel.marca);
	printf("Modelo: %s \n", cel.modelo);
	printf("Processador: %s \n", cel.processador);
	printf("Memoria:  %s \n", cel.memoria);
	printf("Tela: %s \n", cel.tela);
	printf("Camera Frontal: %s \n", cel.cameraF);
	printf("Camera Traseira: %s \n", cel.cameraT);
	printf("Geracao: %s \n", cel.geracao);
	printf("Sistema Operacional: %s \n", cel.OS);
	printf("Preco: %s \n", cel.preco);
	printf("\n");
}
;

void mostralistaCelular(TlistaCelular *lis) {
	int i;
	printf("\n\n  ----------- Lista de celulares ------------\n");

	for (i = 0; i < lis->nco; i++) {
		printf("\n");
		mostreCelular(lis->celulares[i]);
		printf("\n");
	};
	printf("\n\n");
}
;

void insereCelular(TlistaCelular *lis, Tcelular cel) {
	lis->celulares[lis->nco] = cel;
	lis->nco++;
}
;

Tcelular removeCelular(TlistaCelular *lis, int ind) {
	int i;
	Tcelular res = lis->celulares[ind];
	for (i = ind; i < lis->nco - 1; i++)
		lis->celulares[i] = lis->celulares[i + 1];
	lis->nco--;
	return res;
}
;

int alterarCelular(TlistaCelular *lis) {
	char resp;
	do {
		printf("Modelo que deseja alterar: \n");

		Tcelular cel;
		scanf("%s", cel.modelo);
		int i = buscaModelo(lis, cel);

		if (i == -1) {
			printf("Celular nao encontado!\n\n");
			return;
		} else {
			cel = lis->celulares[i];
			Tcelular *c2 = &lis->celulares[i];
			mostreCelular(*c2);
			printf("\n\n Escolha a opcao que deseja modificar \n\n");
			printf("  A - Marca: \n");
			printf("  B - Modelo: \n");
			printf("  C - Processador: \n");
			printf("  D - Memoria: \n");
			printf("  E - Tela: \n");
			printf("  F - Camera Frontal: \n");
			printf("  G - Camera Traseira: \n");
			printf("  H - Geracao: \n");
			printf("  I - Sistema Operacional: \n");
			printf("  J - Preco: \n");
			printf("	K - Cancelar Edicao: \n");
			printf("DIGITE SUA OPCAO: \n");
			fflush(stdin);
			scanf("%c", &resp);

			switch (resp) {
			case 'A':
				printf("Nova marca: \n");
				scanf("%s", c2->marca);
				return 1;
			case 'B':
				printf("Novo modelo: \n");
				scanf("%s", c2->modelo);
				return;
				return 1;
			case 'C':
				printf("Novo Processador: \n");
				scanf("%s", c2->processador);
				return 1;
			case 'D':
				printf("Nova memoria: \n");
				scanf("%s", c2->memoria);
				return 1;
			case 'E':
				printf("Nova tela: \n");
				scanf("%s", c2->tela);
				return 1;
			case 'F':
				printf("Nova camera frontal: \n");
				scanf("%s", c2->cameraF);
				return 1;
			case 'G':
				printf("Nova camera traseira: \n");
				scanf("%s", c2->cameraT);
				return 1;
			case 'H':
				printf("Nova geracao: \n");
				scanf("%s", c2->geracao);
				return 1;
			case 'I':
				printf("Novo sistema operacional: \n");
				scanf("%s", c2->OS);
				return 1;
			case 'J':
				printf("Novo preco: \n");
				scanf("%s", c2->preco);
				return 1;
			case 'K':
				return 0;
			default:
				printf("Opcao invalida, digite novamente.\n\n");
			};

		}
	} while (1);
}
;

int ordenaPreco(const void *a, const void *b) {
	Tcelular *ca = (Tcelular *) a;
	Tcelular *cb = (Tcelular *) b;
	return strcmp(ca->preco, cb->preco);
}
;

int ordenaMarca(const void *a, const void *b) {
	Tcelular *ca = (Tcelular *) a;
	Tcelular *cb = (Tcelular *) b;
	return strcmp(ca->marca, cb->marca);
}
;

int ordenaProcessador(const void *a, const void *b) {
	Tcelular *ca = (Tcelular *) a;
	Tcelular *cb = (Tcelular *) b;
	return strcmp(ca->processador, cb->processador);
}
;

int buscaModelo(TlistaCelular *lis, Tcelular cel) {
	int i;
	for (i = 0; i < lis->nco; i++)
		if (strcmp(cel.modelo, lis->celulares[i].modelo) == 0)
			return i;
	return -1;
}
;

int buscaMarca(TlistaCelular *lis, Tcelular cel) {
	int i;
	int count = 0;
	for (i = 0; i < lis->nco; i++) {
		if (strcmp(cel.marca, lis->celulares[i].marca) == 0) {
			if (count == 0)
				printf("Celulares Encontrados: \n\n");
			mostreCelular(lis->celulares[i]);
			count++;
		}
	}
	return count;
}
;

int buscaGeracao(TlistaCelular *lis, Tcelular cel) {
	int i;
	int count = 0;
	for (i = 0; i < lis->nco; i++) {
		if (strcmp(cel.geracao, lis->celulares[i].geracao) == 0) {
			if (count == 0)
				printf("Celulares Encontrados: \n\n");
			mostreCelular(lis->celulares[i]);
			count++;
		}
	}
	return count;
}
;
