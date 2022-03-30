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

void *incluir(void *pBuffer);
void *apagar(void *pBuffer);
void buscar(void *pBuffer);
void listar(void *pBuffer);

int main()
{

  Pessoa pessoas[10];
  void *pBuffer;

  return 0;
}

void *incluir(void *pBuffer)
{
  printf("Digite o nome da pessoa:\n");
  printf("Digite a idade da pessoa:\n");
  printf("Digite o telefone da pessoa:\n");
}

void *apagar(void *pBuffer)
{
}

void buscar(void *pBuffer)
{
}

void listar(void *pBuffer)
{
}