#include <stdio.h>
#include <stdlib.h>
#include "celular.h"

char menu()
{
    printf("**************************************\n");
    printf("***       LISTA DE CELULARES       ***\n");
    printf("**************************************\n\n");
    printf("  1 - Inserir Celular\n");
    printf("  2 - Remover Celular\n");
    printf("  3 - Alterar Celular\n");
    printf("  4 - Mostrar Celular pelo Pre%co\n", 135);
    printf("  5 - Mostrar Celular pela Marca\n");
    printf("  6 - Mostrar Celular pelo Processador\n");
    printf("  7 - Buscar Celular pela Marca\n");
    printf("  8 - Buscar Celular pela Gera%c%co\n", 135, 198);
    printf("\n  0 - Sair do Aplicativo\n");
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
              printf("\n\n  ****INSERIR NOVO CELULAR****\n\n");
              printf("  Modelo: ");
              scanf("%s", &cel.modelo);
              rb = buscaModelo(&liscel,cel);
              if(rb == 0)
                  printf("\n  **** Celular j%c existe ****\n\n", 160);
              else
              {
                printf("  Marca: ");
                fflush(stdin);
                scanf("%s",cel.marca);
                printf("  Processador: ");
                scanf("%s",cel.processador);
                printf("  Memoria: ");
                scanf("%s",cel.memoria);
                printf("  Tela: ");
                scanf("%s",cel.tela);
                printf("  C%cmera Frontal: ", 131);
                scanf("%s",cel.cameraF);
                printf("  C%cmera Traseira: ", 131);
                scanf("%s",cel.cameraT);
                printf("  Gera%c%co: ", 135, 198);
                scanf("%s",cel.geracao);
                printf("  Sistema Operacional: ");
                scanf("%s",cel.OS);
                printf("  Pre%co: ", 135);
                scanf("%s",cel.preco);
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
            scanf("%s",cel.modelo);
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
          system ("cls");
          qsort(liscel.celulares,liscel.nco,sizeof(Tcelular),ordenaMarca);
          mostralistaCelular(&liscel);
          break;

      case '6':
          qsort(liscel.celulares,liscel.nco,sizeof(Tcelular),ordenaProcessador);
          mostralistaCelular(&liscel);
          break;

     case '7':
          printf("\n\n  **** BUSCAR Celular pela Marca ****\n");
          printf("  Marca: ");
          fflush(stdin);
          scanf("%s",cel.marca);
          rb = buscaMarca(&liscel,cel);
          if(rb==0)
            printf("\n  **** Marca n%co encontrada ****\n",198);
          break;
          // if(rb < 0)
          // else
          // {
          //     printf("Celulares Encontrados: \n");
          //            liscel.celulares[rb].marca;
          // }
          // printf("\n\n");
          // break;

    case '8':
         printf("\n\n  **** BUSCAR Celular pela Gera%c%co ****\n", 135, 198);
         printf("  Gera%c%co: ", 135, 198);
         fflush(stdin);
         scanf("%s",cel.geracao);
         rb = buscaGeracao(&liscel,cel);
         if(rb==0)
           printf("\n  **** Geracao n%co existe ****\n",198);
         break;
        //  rb =
        //  if(rb < 0)
        //      printf("\n  **** Gera%c%co N%co Existe ****\n", 135, 198, 198);
        //  else
        //  {
        //      printf("Celulares Encontrados: \n");
        //             liscel.celulares[rb].geracao;
        //  }
        //  printf("\n\n");
        //
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
