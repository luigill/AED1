/*
SELECTION SORT
  -A cada passo, procura o menor valor do array e o coloca na primeira posição do array.
  -Descarta-se a primeira posição do array e repete-se o processo para a segunda posição.
  -É feito para todas as posições.
  -Performance
    = Melhor Caso -> O(N^2)
    = Pior Caso -> O(N^2)
    = Sempre precisa ir até o fim do vetor para ter certeza que o elemento sendo analisado
      é o menor de todos, ou seja, ele é sempre quadrático.
  -Ineficiente para conjuntos pequenos de dados
  -Instável, pois altera a ordem de dados iguais
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void PrintVetor(int *vetor, int vetorSize);
void Clear(int *vetor);
void TesteOrder(int *vetor, int vetorSize);
void SelectionSort(int *vetor, int vetorSize);

int main()
{

  srand(time(NULL));

  int *vetor = NULL;
  struct timeval begin, end;

  int vetorSize;
  printf("Digite o tamanho do vetor:\n");
  scanf("%d", &vetorSize);
  getchar();

  vetor = malloc(vetorSize * sizeof(int));

  for (int i = 0; i < vetorSize; i++)
  {
    vetor[i] = (rand() % 100);
  }

  // printf("Vetor antes da organização:\n");
  // PrintVetor(vetor, vetorSize);

  // Inserção e teste de velocidade
  gettimeofday(&begin, 0);
  SelectionSort(vetor, vetorSize);
  gettimeofday(&end, 0);

  // printf("Vetor depois da organização:\n");
  // PrintVetor(vetor, vetorSize);

  // Teste de ordenação
  TesteOrder(vetor, vetorSize);

  printf("Tempo para ordenar com o Selection Sort: %.3f segundos.\n", (end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec) * 1e-6));

  Clear(vetor);

  return 0;
}

void PrintVetor(int *vetor, int vetorSize)
{
  printf("VETOR:\n");
  for (int i = 0; i < vetorSize; i++)
  {
    printf("%d\n", vetor[i]);
  }
}

void Clear(int *vetor)
{
  free(vetor);
}

void TesteOrder(int *vetor, int vetorSize)
{
  for (int i = 0; i < vetorSize; i++)
  {
    if (vetor[i] > vetor[i + 1])
    {
      printf("O vetor está desordenado...\n");
      return;
    }
    else
    {
      printf("A ordenação está correta!\n");
      return;
    }
  }
}

void SelectionSort(int *vetor, int vetorSize)
{

  int i, j, menor, troca;
  for (i = 0; i < vetorSize - 1; i++)
  {
    menor = i;
    // Procura o menor elemento em relação a "i"
    for (j = i + 1; j < vetorSize; j++)
    {
      if (vetor[j] < vetor[menor])
      {
        menor = j;
      }
    }
    // Troca os valores da posição atual com a "menor"
    if (i != menor)
    {
      troca = vetor[i];
      vetor[i] = vetor[menor];
      vetor[menor] = troca;
    }
  }
}

// Inicializa o valor minímo na localidade 0
// Percorre o array na procura do menor elemento
// Enquanto percorre o array, caso ache algum elemento menor que o mínimo, os troca de lugar
// Então incrementa para o próximo elemento
// Continua o processo até o array estar ordenado