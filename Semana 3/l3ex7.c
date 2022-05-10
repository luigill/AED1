#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHAR (sizeof(char))
#define INT (sizeof(int))

typedef struct
{
  char nome[30];
  int idade;
  int altura;
} Pessoa;

void *incluir(Pessoa p[], void *pBuffer);
void *apagar(Pessoa p[], void *pBuffer);
void buscar(Pessoa p[], void *pBuffer);
void listar(Pessoa p[], void *pBuffer);

int main()
{

  Pessoa pessoas[10];
  void *pBuffer;
  pBuffer = malloc((INT * 4) + 10 * CHAR); // contador -> switch menu -> for i -> for j -> auxiliar nome
  *((int *)pBuffer) = 0;

  do
  {
    printf("Menu:\n\n");
    printf("1)Adicionar contato\n");
    printf("2)Remover contato\n");
    printf("3)Buscar contato\n");
    printf("4)Listar contato\n");
    printf("0)Sair...\n");
    scanf("%d", &(*((int *)pBuffer + INT)));

    switch (*((int *)pBuffer + INT))
    {
    case 1:
      *((int *)pBuffer) = *((int *)pBuffer) + 1;
      incluir(pessoas, pBuffer);
      break;
    case 2:
      apagar(pessoas, pBuffer);
      *((int *)pBuffer) = *((int *)pBuffer) - 1;
      break;
    case 3:
      buscar(pessoas, pBuffer);
      break;
    case 4:
      listar(pessoas, pBuffer);
      break;
    case 0:
      printf("Fim da Execução");
      break;
    default:
      printf("Opcao Invalida!\n");
      break;
    }
  } while (*((int *)pBuffer + INT) != 0);

  free(pBuffer);

  return 0;
}

void *incluir(Pessoa p[], void *pBuffer)
{

  if (*((int *)pBuffer) == 10)
  {
    printf("Lista cheia!");
  }
  else
  {
    printf("Digite o nome da pessoa:\n");
    scanf("%s", p[*((int *)pBuffer) - 1].nome);
    getchar();
    printf("Digite a idade da pessoa:\n");
    scanf("%d", &p[*((int *)pBuffer) - 1].idade);
    printf("Digite a altura da pessoa:\n");
    scanf("%d", &p[*((int *)pBuffer) - 1].altura);
  }
}

void *apagar(Pessoa p[], void *pBuffer)
{

  printf("Digite o nome que deve ser removido:\n");
  scanf("%s", (char *)(pBuffer + 4 * INT));
  getchar();

  for (*((int *)pBuffer + (INT * 2)) = 0; *((int *)pBuffer + (INT * 2)) < *((int *)pBuffer); *((int *)pBuffer + (INT * 2)) = *((int *)pBuffer + (INT * 2)) + 1)
  {
    if (strcmp((char *)(pBuffer + 4 * INT), p[*((int *)pBuffer + (INT * 2))].nome) == 0)
    {
      for (*((int *)pBuffer + (INT * 3)) = *((int *)pBuffer + (INT * 2)); *((int *)pBuffer + (INT * 3)) < *((int *)pBuffer); *((int *)pBuffer + (INT * 3)) = *((int *)pBuffer + (INT * 3)) + 1)
      {
        strcpy(p[*((int *)pBuffer + (INT * 3))].nome, p[*((int *)pBuffer + (INT * 3)) + 1].nome);
        p[*((int *)pBuffer + (INT * 3))].idade = p[*((int *)pBuffer + (INT * 3)) + 1].idade;
        p[*((int *)pBuffer + (INT * 3))].altura = p[*((int *)pBuffer + (INT * 3)) + 1].altura;
      }
    }
  }
}

void buscar(Pessoa p[], void *pBuffer)
{
  printf("Digite o nome que deve ser buscado:\n");
  scanf("%s", (char *)(pBuffer + 4 * INT));
  getchar();

  for (*((int *)pBuffer + (INT * 2)) = 0; *((int *)pBuffer + (INT * 2)) < *((int *)pBuffer); *((int *)pBuffer + (INT * 2)) = *((int *)pBuffer + (INT * 2)) + 1)
  {
    if (strcmp((char *)(pBuffer + 4 * INT), p[*((int *)pBuffer + (INT * 2))].nome) == 0)
    {
      printf("Nome:%s\n", p[*((int *)pBuffer + (INT * 2))].nome);
      printf("Idade:%d\n", p[*((int *)pBuffer + (INT * 2))].idade);
      printf("Altura:%d\n", p[*((int *)pBuffer + (INT * 2))].altura);
    }
  }
}

void listar(Pessoa p[], void *pBuffer)
{
  for (*((int *)pBuffer + (INT * 2)) = 0; *((int *)pBuffer + (INT * 2)) < *((int *)pBuffer); *((int *)pBuffer + (INT * 2)) = *((int *)pBuffer + (INT * 2)) + 1)
  {
    printf("Nome:%s\n", p[*((int *)pBuffer + (INT * 2))].nome);
    printf("Idade:%d\n", p[*((int *)pBuffer + (INT * 2))].idade);
    printf("Altura:%d\n", p[*((int *)pBuffer + (INT * 2))].altura);
  }
}