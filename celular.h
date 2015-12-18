#define MAX 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celular
{
    char marca[50];
    char modelo[20];
    char processador[20];
    char memória[20];
    char tela[20];
    char cameraF[20];
    char cameraT[20];
    char geracao[20];
    char OS[20];
    float preco[20];
}
typedef struct celular Tcelular;

struct listaCelular
{
    unsigned nco;  // N�mero de celulares na lista
    Tcelular celulares[MAX];
}
typedef struct listaCelular TlistaCelular;

void mostreCelular(Tcelular cel)
{
    printf("Marca: %s \n", cel.marca);
    printf("Modelo: %s \n", cel.modelo);
    printf ("Processador: %s \n", cel.processador);
    printf ("Memoria:  %s \n", cel.memoria);
    printf ("Tela: %s \n", cel.tela);
    printf ("Camera Frontal: %s \n", cel.cameraF);
    printf ("Camera Traseira: %s \n", cel.cameraT);
    printf ("Geracao: %s \n", cel.geracao);
    printf ("Sistema Operacional: %s \n", cel.OS);
    printf ("Preco: %.2f", cel.preco);
}

void mostralistaCelular (TlistaCelular *lis)
{
    int i;
    printf("\n\n  ----------- Lista de celulares ------------\n");

    for(i=0; i<lis->nco; i++) {
        printf("  ");
        mostreCelular(lis->celulares[i]);
        printf("\n");
    }
    printf("\n\n");
}

void insereCelular(TlistaCelular *lis, Tcelular cel)
{
    lis->celulares[lis->nco] = cel;
    lis->nco++;
}

Tcelular removeCelular(TlistaCelular *lis, int ind)
{
    int i;
    Tcelular res = lis->celulares[ind];
    for(i=ind; i<lis->nco-1; i++)
        lis->celulares[i] = lis->celulares[i+1];
    lis->nco--;
    return res;
}

void alterarCelular()
{
  int num;
  int resp;
  arq=fopen("Celulares.arq","r+b");

  if(arq==NULL)
  {
    printf ("Erro ao abrir o arquivo.\n");
    return;
  }
  do
  {
    system ("cls");
    printf ("\n\nEscolha a opcao que deseja modificar\n\n");
    printf("Marca: \n");
    printf("Modelo: \n");
    printf ("Processador: \n");
    printf ("Memoria: \n");
    printf ("Tela: \n");
    printf ("Camera Frontal: \n");
    printf ("Camera Traseira: \n");
    printf ("Geracao: \n");
    printf ("Sistema Operacional: \n");
    printf ("Preco: %.2f");

    switch(resp){
    case 1: nome();
    break;
    case 2: numAtomico();
    break;
    case 3: numMassa();
    break;
    default: printf ("Numero invalido, digite novamente.\n\n");
    }
    system ("PAUSE");
}while(resp<1||resp>3);
}

int ordenaPreco(const void *a, const void *b)
{
    Tcelular *ca = (Tcelular *) a;
    Tcelular *cb = (Tcelular *) b;
    return strcmp(ca->preco,cb->preco);
}

int ordenaMarca(const void *a, const void *b)
{
    Tcelular *ca = (Tcelular *) a;
    Tcelular *cb = (Tcelular *) b;
    return strcmp(ca->marca,cb->marca);
}

int ordenaProcessador(const void *a, const void *b)
{
    Tcelular *ca = (Tcelular *) a;
    Tcelular *cb = (Tcelular *) b;
    return strcmp(ca->processador,cb->processador);
}

int buscaMarca(TlistaCelular *lis, Tcelular cel)
{
    int i;
    for(i=0; i<lis->nco; i++)
        if(strcmp(cel.marca,lis->celulares[i].marca) == 0)
            return i;
    return -1;
}

int buscaModelo(TlistaCelular *lis, Tcelular cel)
{
    int i;
    for(i=0; i<lis->nco; i++)
        if(strcmp(cel.modelo,lis->celulares[i].modelo) == 0)
            return i;
    return -1;
}

int buscaGeracao(TlistaCelular *lis, Tcelular cel)
{
    int i;
    for(i=0; i<lis->nco; i++)
        if(strcmp(cel.geracao,lis->celulares[i].geracao) == 0)
            return i;
    return -1;
}
