#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char nome[30];
  int idade;
  int altura;
} Pessoa;

void *adicionar(Pessoa *p, int *count);
void listar(Pessoa *p, int *count);

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

void *adicionar(Pessoa *p, int *count)
{
  p = (Pessoa *)realloc(p, ((*count) * sizeof(Pessoa)));
  printf("Nome:\n");
  scanf("%s", (p + (*count - 1))->nome);
  printf("Idade:\n");
  scanf("%d", &(p + (*count - 1))->idade);
  printf("Altura:\n");
  scanf("%d", &(p + (*count - 1))->altura);
  return p;
}

void listar(Pessoa *p, int *count)
{
  for (int i = 0; i < *count; i++)
  {
    printf("Nome: %s\n", (p + i)->nome);
    printf("Idade: %d\n", (p + i)->idade);
    printf("Altura: %d\n\n", (p + i)->altura);
  }
}