#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aplicativo.h"
int buscarRestauranteAplicativo(ListaRestaurante *listaRestaurante)
{
  if (listaVaziaRestaurante(listaRestaurante) != 1)
  {
    return 2;
  }
  
  int opt, tipoProcurado, i;
  char texto[50], nomeBusca[50];
  NoRestaurante *aux = listaRestaurante->inicio;
  do
  {
    printf("\nSelecione a opcao:\n[1] Buscar restaurante por nome\n[2] Categorias\nR= ");
    scanf("%d", &opt);

    system("cls");
    if (opt == 1)
    {
      strcpy(texto, "BUSCAR RESTAURANTE");
      printTitle(texto, strlen(texto));
      printf("Digite o nome do restaurante: ");
      setbuf(stdin, NULL);
      gets(nomeBusca);
      // Se encontrar o restaurante procurado...
      if (buscarRestauranteNome(listaRestaurante, nomeBusca) == 0)
      {
        printf("\nQual opcao voce deseja acessar?\nR= ");
        scanf("%d", &opt);

        i = 0;
        
        system("cls");
        // Percorre a lista buscando a opção do usuário
        while (aux != NULL && i <= opt)
        {
          if (comparaStrings(nomeBusca, aux->valor.nome) == 0)
          {
            if (i == opt)
            {
              // Ao encontrar a opção do usuário, exibe o menu do restaurante
              mostrarMenu(&aux->valor, listaRestaurante);
              break;
            }
            else
            {
              i++;
            }
          }
          aux = aux->prox;
        }
      }
      // Se não encontrar o restaurante
      else
      {
        printf("Quer tentar novamente?\n[1] SIM\n[2] NAO\nR= ", nomeBusca);
        scanf("%d", &opt);
        if (opt == 1)
          buscarRestauranteAplicativo(listaRestaurante);

        return 1;
      }
    }
    else if (opt == 2)
    {
      do
      {
        strcpy(texto, "CATEGORIAS");
        printTitle(texto, strlen(texto));

        printf("Qual tipo de culinaria que voce esta procurando?\n");
        printf("\n[1] Lanches\n[2] Pizza\n[3] Salgados\n[4] Self-Service\n[5] Sobremesas\n[6] Vegetariano\n\n[0] Voltar\nR= ");
        scanf("%d", &tipoProcurado);
        // se o usuário escolher uma opção inválida
        if (tipoProcurado < 0 || tipoProcurado > 6)
          printf("Opcao invalida. Tente novamente.");
        else if (tipoProcurado != 0)
          if (buscarRestauranteTipo(listaRestaurante, tipoProcurado) == 0)
          {
            printf("Qual opcao voce deseja acessar?\nR= ");
            scanf("%d", &opt);

            i = 0;

            system("cls");
            while (aux != NULL)
            {
              if (tipoProcurado == aux->valor.categoria)
              {
                if (i == opt)
                {
                  mostrarMenu(&aux->valor, listaRestaurante);
                  return 0;
                }
                i++;
              }
              aux = aux->prox;
            }
          }
      } while (opt == 1 && tipoProcurado != 0);
    }
  } while (tipoProcurado == 0);
  return 0;
}