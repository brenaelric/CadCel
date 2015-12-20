#define MAX 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celular
{
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

struct listaCelular
{
    unsigned nco;  // N�mero de celulares na lista
    Tcelular celulares[MAX];
};
typedef struct listaCelular TlistaCelular;

void mostreCelular(Tcelular cel)
{
    printf("Chave: %d \n", cel.chave);
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
};

void mostralistaCelular (TlistaCelular *lis)
{
    int i;
    printf("\n\n  ----------- Lista de celulares ------------\n");

    for(i=0; i<lis->nco; i++) {
        printf("\n");
        mostreCelular(lis->celulares[i]);
        printf("\n");
    };
    printf("\n\n");
};

void insereCelular(TlistaCelular *lis, Tcelular cel)
{
    lis->celulares[lis->nco] = cel;
    lis->nco++;
};

Tcelular removeCelular(TlistaCelular *lis, int ind)
{
    int i;
    Tcelular res = lis->celulares[ind];
    for(i=ind; i<lis->nco-1; i++)
        lis->celulares[i] = lis->celulares[i+1];
    lis->nco--;
    return res;
};

void alterarCelular(TlistaCelular *lis)
{
  int num;
  int resp;
  do
  {
    printf("Modelo que deseja alterar: \n");

    Tcelular cel;
    scanf("%s",cel.modelo);
    int i = buscaModelo(&lis,cel);

    if(i==-1)
    {
      printf("Celular nao encontado!\n");
      return;
    }

    else
    {
    cel = lis->celulares[i];
    mostreCelular(cel);
    printf ("\n\nEscolha a opcao que deseja modificar\n\n");
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
    printf("DIGITE SUA OPÇÃO: ");
    fflush(stdin);
    resp = getchar();

    switch(resp){
    case 'A':
      printf("Nova marca: \n");
      scanf("%s",cel.marca);
    break;
    case 'B':
      printf("Novo modelo: \n");
      scanf("%s",cel.modelo);
      return;
    break;
    case 'C':
      printf("Novo Processador: \n");
      scanf("%s",cel.processador);
    break;
    case 'D':
      printf("Nova memoria: \n");
      scanf("%s",cel.memoria);
    break;
    case 'E':
      printf("Nova tela: \n");
      scanf("%s",cel.tela);
    break;
    case 'F':
      printf("Nova camera frontal: \n");
      scanf("%s",cel.cameraF);
    break;
    case 'G':
      printf("Nova camera traseira: \n");
      scanf("%s",cel.cameraT);
    break;
    case 'H':
      printf("Nova geracao: \n");
      scanf("%s",cel.geracao);
    break;
    case 'I':
      printf("Novo sistema operacional: \n");
      scanf("%s",cel.OS);
    break;
    case 'J':
      printf("Novo preco: \n");
      scanf("%s",cel.preco);
    break;
    default:
      printf ("Opcao invalida, digite novamente.\n\n");
    };
  }
}
  while(1);
};

int ordenaPreco(const void *a, const void *b)
{
    Tcelular *ca = (Tcelular *) a;
    Tcelular *cb = (Tcelular *) b;
    return strcmp(ca->preco,cb->preco);
};

int ordenaMarca(const void *a, const void *b)
{
    Tcelular *ca = (Tcelular *) a;
    Tcelular *cb = (Tcelular *) b;
    return strcmp(ca->marca,cb->marca);
};

int ordenaProcessador(const void *a, const void *b)
{
    Tcelular *ca = (Tcelular *) a;
    Tcelular *cb = (Tcelular *) b;
    return strcmp(ca->processador,cb->processador);
};

int buscaMarca(TlistaCelular *lis, Tcelular cel)
{
    int i;
    for(i=0; i<lis->nco; i++)
        if(strcmp(cel.marca,lis->celulares[i].marca) == 0)
            return i;
    return -1;
};

int buscaModelo(TlistaCelular *lis, Tcelular cel)
{
    int i;
    for(i=0; i<lis->nco; i++)
        if(strcmp(cel.modelo,lis->celulares[i].modelo) == 0)
            return i;
    return -1;
};

int buscaGeracao(TlistaCelular *lis, Tcelular cel)
{
    int i;
    for(i=0; i<lis->nco; i++)
        if(strcmp(cel.geracao,lis->celulares[i].geracao) == 0)
            return i;
    return -1;
};
