#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CHAR (sizeof(char))
#define INT (sizeof(int))

void *incluir(void *pBuffer);
void *apagar(void *pBuffer);
void buscar(void *pBuffer);
void listar(void *pBuffer);

int main()
{

  void *pBuffer;
  pBuffer = malloc(sizeof(int));
  int menu = 0;
  *(int *)pBuffer = 0;


  do
  {

    printf("MENU\n");
    printf("Digite a opcao desejada:\n");
    printf("1)Incluir contato.\n");
    printf("2)Apagar contato.\n");
    printf("3)Buscar contato.\n");
    printf("4)Listar contato.\n");
    printf("0)Sair...\n");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
      pBuffer = incluir(pBuffer);
      break;
    case 2:
      pBuffer = apagar(pBuffer);
      break;
    case 3:
      buscar(pBuffer);
      break;
    case 4:
      listar(pBuffer);
      break;
    case 0:
      printf("Final de execução!\n");
      break;
    default:
      printf("Comando Invalido");
      break;
    }
  } while (menu != 0);

  free(pBuffer);

  return 0;
}

void *incluir(void *pBuffer)
{

  pBuffer = realloc(pBuffer, INT + (*(int *)pBuffer + 1) * ((CHAR * 10) + INT + INT));
  printf("Digite o nome do contato:\n");
  scanf("%s", (char *)pBuffer + INT + (*(int *)pBuffer) * ((CHAR * 10) + INT + INT));
  printf("Digite a idade do contato:\n");
  scanf("%d", (int *)(pBuffer + INT + (*(int *)pBuffer) * ((CHAR * 10) + INT + INT) + (CHAR * 10)));
  printf("Digite o telefone do contato:\n");
  scanf("%d", (int *)(pBuffer + INT + (*(int *)pBuffer) * ((CHAR * 10) + INT + INT) + (CHAR * 10) + INT));

  *(int *)pBuffer = *(int *)pBuffer + 1;

  return pBuffer;
}

void *apagar(void *pBuffer)
{
  printf("Indisponível...\n");
  return pBuffer;
}

void buscar(void *pBuffer)
{
  char *nome;
  nome = malloc(10 * sizeof(char));
  printf("Digite o nome que vai ser buscado:\n");
  scanf("%s", nome);
  getchar();

  for (int i = 0; i < *(int *)pBuffer; i++)
  {
    if (strcmp((char *)pBuffer + INT + (i * ((CHAR * 10) + INT + INT)), nome) == 0)
    {
      printf("Nome: %s\n", (char *)pBuffer + INT + (i * ((10 * CHAR) + INT + INT)));
      printf("Idade: %d\n", *((int *)(pBuffer + INT + (i * ((10 * CHAR) + INT + INT)) + (10 * CHAR))));
      printf("Contato: %d\n", *((int *)(pBuffer + INT + (i * ((10 * CHAR) + INT + INT)) + (10 * CHAR) + INT)));
    }
  }
  free(nome);
}

void listar(void *pBuffer)
{

  if (*(int *)pBuffer == 0)
  {
    printf("Lista Vazia!\n");
  }
  else
  {
    for (int i = 0; i < *(int *)pBuffer; i++)
    {
      printf("Nome: %s\n", (char *)pBuffer + INT + (i * ((10 * CHAR) + INT + INT)));
      printf("Idade: %d\n", *((int *)(pBuffer + INT + (i * ((10 * CHAR) + INT + INT)) + (10 * CHAR))));
      printf("Contato: %d\n", *((int *)(pBuffer + INT + (i * ((10 * CHAR) + INT + INT)) + (10 * CHAR) + INT)));
    }
  }
}