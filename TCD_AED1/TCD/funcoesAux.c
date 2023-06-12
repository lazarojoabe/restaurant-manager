#include <stdio.h>
#include <string.h>
#include <time.h>  //Para adiocionar a função my_sleep(deley para informações).
#include <windows.h>
#include <ctype.h> // adciona a função "tolower()"
#include <unistd.h>
#include "funcoesAux.h"

//Função usada para adicionar timer
void my_sleep(int sleepms)
{
#ifdef WINDOWS_SYSTEM
  Sleep(sleepms);
#else
  usleep(sleepms * 1000);
#endif
}

//Função que printa a string como se estivesse escrevendo. Possui um timer em cada letra.
void printTimer(char *str, int width)
{
  for (int i = 0; i < width; i++)
  {
    printf("%c", *str);
    my_sleep(40);
    str++;
  }
}

//Função que printa títulos:
/*
======================
        TÍTULO
======================
*/
void printTitle(char *str, int width)
{
  int calc;
  calc = (32 - width) / 2;
  printf("\n");
  for (int i = 0; i < 32; i++)
  {
    printf("=");
  }
  printf("\n");
  for (int i = 0; i < calc; i++)
  {
    printf(" ");
  }
  printf("%s", str);
  for (int i = 0; i < calc; i++)
  {
    printf(" ");
  }
  printf("\n");
  for (int i = 0; i < 32; i++)
  {
    printf("=");
  }
  printf("\n");
}

//Traduz qual é a categoria do restaurante e printa na tela
void printCategoria(int num)
{
  switch (num)
  {
  case 1:
    printf("Lanches\n");
    break;
  case 2:
    printf("Pizza\n");
    break;
  case 3:
    printf("Salgados\n");
    break;
  case 4:
    printf("Self-Service\n");
    break;
  case 5:
    printf("Sobremesas\n");
    break;
  case 6:
    printf("Vegetariano\n");
    break;

  default:
    break;
  }
}

//Printa uma linha de "=" de 32 caracteres
void printaLinha()
{
  printf("\n");
  for (int i = 0; i < 32; i++)
  {
    printf("=");
  }
  printf("\n");
}

int comparaStrings(char *s1, char *s2)
{
  char str1[30], str2[30];
  //Gravamos o valora de s1 e s2 em variáveis auxiliares para que o seu valor original não seja alterado.
  strcpy(str1, s1);
  strcpy(str2, s2);
  for (int i = 0; str1[i]; i++)
  {
    str1[i] = tolower(str1[i]);
  }
  for (int i = 0; str2[i]; i++)
  {
    str2[i] = tolower(str2[i]);
  }

  if (strcmp(str1, str2) == 0)
  {
    return 0;
  }
  return 1;
}
