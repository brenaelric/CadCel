#include <stdio.h>
#include <stdlib.h>
#include "celular.h"

char menu()
{
    printf("***********************\n");
    printf("* Lista de Celulares *\n");
    printf("***********************\n\n");
    printf("  1 - INSERIR celular\n");
    printf("  2 - REMOVER celular\n");
    printf("  3 - ALTERAR celular\n");
    printf("  4 - MOSTRAR celular pela preco\n");
    printf("  5 - MOSTRAR celular pela marca\n");
    printf("  6 - MOSTRAR celular pelo processador\n");
    printf("  7 - BUSCAR celular pela marca\n");
    printf("  8 - BUSCAR celular pela geracao\n");
    printf("\n  0 - SAIR do aplicativo\n");
    printf("\n  Escolha uma op%c%co: ",135,198);
    fflush(stdin);
    return getchar();
}


int main ()
{
  TlistaCelular liscel;
  liscel.nco = 0;
  Tcelular cel;
  int rb;
  int alterado = 0;
  char op2 = 'A';
  char op = 'A';

  FILE *fp;
  fp = fopen("Celulares.arq","rb");

  if(fp != NULL) {
      fread(&liscel.nco,sizeof(unsigned),1,fp);
      fread(liscel.celulares,sizeof(Tcelular),liscel.nco,fp);
  }
  fclose(fp);

  while(op != '0')
  {
      op = menu();
      switch(op)
      {
          fflush(stdin);
          case '1':
              printf("\n\n  ****INSERIR NOVO CELULAR****\n");
              printf("  Modelo: ");
              gets(cel.modelo);
              rb = buscaModelo(&liscel,cel);
              if(rb >= 0)
                  printf("\n  **** Celular já existe ****\n\n");
              else
              {
                printf("  Marca: ");
                fflush(stdin);
                gets(cel.marca);
                printf("  Processador: ");
                gets(cel.processador);
                printf("  Memoria: ");
                gets(cel.memoria);
                printf("  Tela: ");
                gets(cel.tela);
                printf("  Camera Frontal: ");
                gets(cel.cameraF);
                printf("  Camera Traseira: ");
                gets(cel.cameraT);
                while(op2!='s' && op2!='S' && op2!='n' && op2!='N')
                {
                    printf("\n  Salvar celular? (s/n): ");
                    fflush(stdin);
                    op2 = getchar();
                    if(op2=='S' || op2=='s')
                    {
                      alterado = 1;
                      insereCelular(&liscel,cel);
                      printf("\n\n  **** Celular Adicionado ****\n\n");
                    }
                    else
                    if(op2!='N' && op2!='n')
                    printf("\n\n  **** Pressione S ou N ****\n\n");
                  }
                  }
                  op2 = 'A';

            break;
            case '2':
            fflush(stdin);
            printf("\n\n  **** REMOVER CELULAR ****\n");
            printf("  Modelo: ");
            gets(cel.modelo);
            rb = buscaModelo(&liscel,cel);
            if(rb < 0)
                printf("\n  **** Celular n%co existe ****\n",198);
            else
            {
                printf("  Excluir %s? (S/N):  ",cel.marca);
                op2 = getchar();
                if(op2=='s' || op2=='S')
                {
                  removeCelular(&liscel,rb);
                  alterado = 1;
                }
            }
            printf("\n\n");
            break;

      case '3':
          fflush(stdin);
          printf("\n\n  **** ALTERAR CELULAR ****\n");
          alterarCelular(&liscel);
          break;
      case '4':
          qsort(liscel.celulares,liscel.nco,sizeof(Tcelular),ordenaPreco);
          mostralistaCelular(&liscel);
          break;

      case '5':
          qsort(liscel.celulares,liscel.nco,sizeof(Tcelular),ordenaMarca);
          mostralistaCelular(&liscel);
          break;

      case '6':
          qsort(liscel.celulares,liscel.nco,sizeof(Tcelular),ordenaProcessador);
          mostralistaCelular(&liscel);
          break;

     case '7':
          printf("\n\n  **** BUSCAR celular pela marca ****\n");
          printf("  Marca: ");
          fflush(stdin);
          gets(cel.marca);
          rb = buscaMarca(&liscel,cel);
          if(rb < 0)
              printf("\n  **** Marca n%co existe ****\n",198);
          else
          {
              printf("Celulares encontrado: \n");
                     liscel.celulares[rb].marca;
          }
          printf("\n\n");
          break;

    case '8':
         printf("\n\n  **** BUSCAR celular pela geracao ****\n");
         printf("  Geracao: ");
         fflush(stdin);
         gets(cel.geracao);
         rb = buscaGeracao(&liscel,cel);
         if(rb < 0)
             printf("\n  **** Geracao n%co existe ****\n",198);
         else
         {
             printf("Celulares encontrado: \n");
                    liscel.celulares[rb].geracao;
         }
         printf("\n\n");
         break;
    }
  }

  if(alterado)
      {
          printf("\n\n  Arquivo alterado. Deseja salvar as altera%c%ces? (S/N): ",135,228);
          fflush(stdin);
          op2 = getchar();
          if(op2=='S' || op2=='s')
          {
              fp = fopen("Celulares.arq","wb");
              fwrite(&liscel.nco,sizeof(unsigned),1,fp);
              fwrite(liscel.celulares,sizeof(Tcelular),liscel.nco,fp);
              fclose(fp);
              printf("\n  **** O arquivo foi salvo ****\n");
          }
      }
      printf("\n");
      return 0;
}
