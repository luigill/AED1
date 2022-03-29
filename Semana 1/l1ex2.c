#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *adiciona(void *buffer, int contador);
void *remover(void *buffer, int contador);
void lista(void *buffer, int contador);

int main()
{

  void *buffer;
  buffer = malloc(10 * sizeof(char));

  int contadorPessoas = 0;

  int opcaoMenu = 0;

  do
  {
    printf("MENU\n");
    printf("1)Adicionar Nome:\n");
    printf("2)Remover Nome:\n");
    printf("3)Listar:\n");
    printf("4)Sair:\n");
    scanf("%d", &opcaoMenu);

    switch (opcaoMenu)
    {
    case 1:
      contadorPessoas++;
      buffer = adiciona(buffer, contadorPessoas);
      break;
    case 2:
      buffer = remover(buffer, contadorPessoas);
      contadorPessoas--;
      buffer = realloc(buffer, 10 * sizeof(char) * contadorPessoas);
      break;
    case 3:
      lista(buffer, contadorPessoas);
      break;
    case 4:
      printf("Fim da execucao!\n");
      break;
    default:
      printf("Opcao Inválida...\n");
      break;
    }
  } while (opcaoMenu != 4);

  free(buffer);

  return 0;
}

void *adiciona(void *buffer, int contador)
{

  buffer = realloc(buffer, (10 * sizeof(char)) * contador);
  printf("Digite o nome que vai ser adicionado:\n");
  scanf("%s", (char *)buffer + (10 * sizeof(char) * (contador - 1)));
  getchar();

  return buffer;
}

void *remover(void *buffer, int contador)
{

  char *nome;
  nome = malloc(10 * sizeof(char));
  printf("Digite o nome que vai ser removido:\n");
  scanf("%s", nome);
  getchar();

  for (int i = 0; i < contador; i++)
  {
    if ((strcmp((char *)buffer + (10 * sizeof(char) * i), nome) == 0))
    {
      for (int j = i; j < contador - 1; j++)
      {
        strcpy((char *)buffer + (10 * sizeof(char) * j), (char *)buffer + (10 * sizeof(char) * (j + 1)));
      }
    }
  }

  free(nome);
  return buffer;
}

void lista(void *buffer, int contador)
{

  if (contador == 0)
  {
    printf("Lista Vazia!\n");
  }
  else
  {
    for (int i = 0; i < contador; i++)
    {
      printf("%s\n", (char *)buffer + (10 * sizeof(char)) * (i));
    }
  }
}
