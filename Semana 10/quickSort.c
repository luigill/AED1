/*
QUICK SORT
  -Como o Merge Sort, o Quick Sort é um algoritmo do tipo Dividir e Conquistar.
  -Escolhe um elemento como pivô, e então particiona o array em função do pivô.
  -Recursivamente ordena as 2 partições.
  -Não necessita de memória externa, então é mais utilizado para organizar arrays do que
    o Merge Sort.
  -Performance
    = Melhor Caso -> O(N log(N)) -> O pivô é o elemento central
    = Pior Caso -> O(N^2) -> raramento -> Quando o pivô é o maior ou menor número do conjunto
  -Uma desvantagem para se apontar seria, como escolher o pivô?
  -Instável, porém pode ser implementado de forma estável.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void PrintVetor(int *vetor, int vetorSize);
void Clear(int *vetor);
void TesteOrder(int *vetor, int vetorSize);
void QuickSort(int *vetor, int inicio, int fim);

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
    vetor[i] = (rand() % 10000);
  }

  // printf("Vetor antes da organização:\n");
  // PrintVetor(vetor, vetorSize);

  gettimeofday(&begin, 0);
  QuickSort(vetor, 0, vetorSize - 1);
  gettimeofday(&end, 0);

  // printf("Vetor depois da organização:\n");
  // PrintVetor(vetor, vetorSize);

  TesteOrder(vetor, vetorSize);

  printf("Tempo para ordenar com o Quick Sort: %.3f segundos.\n", (end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec) * 1e-6));

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

void QuickSort(int *vetor, int left, int right)
{
  int i, j, mid, tmp;

  i = left;
  j = right;
  // definição do pivo
  mid = vetor[(left + right) / 2];

  do
  {
    // procura um elemento menor que o pivô, da esquerda até o meio
    while (vetor[i] < mid)
    {
      i++;
    }
    // procura um elemento maior que o pivô,do meio até o fim
    while (vetor[j] > mid)
    {
      j--;
    }
    // troca o elemento i pelo j
    if (i <= j)
    {
      tmp = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = tmp;
      i++;
      j--;
    }
  } while (i <= j);

  // Processo de Recursão quando sobra sublistas
  if (j > left)
  {
    QuickSort(vetor, left, j);
  }
  if (i < right)
  {
    QuickSort(vetor, i, right);
  }
}
