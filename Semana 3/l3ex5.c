#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char nome[30];
  int idade;
  int altura;
} Pessoa;

void *adicionar(Pessoa *p, int *n);
void listar(Pessoa *p, int *n);

int main()
{

  int *opcao, *count;
  Pessoa *buffer;

  opcao = (int *)malloc(sizeof(int));
  count = (int *)malloc(sizeof(int));
  buffer = (Pessoa *)malloc(sizeof(Pessoa));

  *count = 0;

  do
  {
    printf("Menu:\n\n");
    printf("1)Adicionar Nome\n");
    printf("0)Sair...\n");
    scanf("%d", &(*opcao));

    switch (*opcao)
    {
    case 1:
      *count += 1;
      buffer = adicionar(buffer, count);
      break;
    case 0:
      listar(buffer, count);
      break;
    default:
      printf("Opcao Invalida!\n");
      break;
    }
  } while (*opcao != 0);

  free(count);
  free(opcao);
  free(buffer);

  return 0;
}

void *adicionar(Pessoa *p, int *n)
{
  p = (Pessoa *)realloc(p, ((*n) * sizeof(Pessoa)));
  printf("Nome:\n");
  scanf("%s", (p + (*n - 1))->nome);
  printf("Idade:\n");
  scanf("%d", &(p + (*n - 1))->idade);
  printf("Altura:\n");
  scanf("%d", &(p + (*n - 1))->altura);
  return p;
}

void listar(Pessoa *p, int *n)
{
  for (int i = 0; i < *n; i++)
  {
    printf("Nome: %s\n", (p + i)->nome);
    printf("Idade: %d\n", (p + i)->idade);
    printf("Altura: %d\n\n", (p + i)->altura);
  }
}