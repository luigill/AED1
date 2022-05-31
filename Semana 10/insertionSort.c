/*
INSERTION SORT
  -Similar a ordenação de cartas de baralho na mão
  -Pega-se uma carta de cada vez e a coloca no devido lugar, sempre deixando as cartas
    da mão em ordem
  -Performance
    = Melhor Caso -> O(N) -> caso já esteja ordenado
    = Pior Caso -> O(N^2) -> por causa da série de trocas realizadas
  -Eficiente para conjuntos pequenos de dados
  -Estável, pois não altera a ordem de dados iguais
  -Capaz de ordenar os dados a medida que os recebe (Tempo Real)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void PrintVetor(int *vetor, int vetorSize);
void Clear(int *vetor);
void TesteOrder(int *vetor, int vetorSize);
void InsertionSort(int *vetor, int vetorSize);

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

  // Inserção e teste de velocidade
  gettimeofday(&begin, 0);
  InsertionSort(vetor, vetorSize);
  gettimeofday(&end, 0);

  // printf("Vetor depois da organização:\n");
  // PrintVetor(vetor, vetorSize);

  // Teste de ordenação
  TesteOrder(vetor, vetorSize);

  printf("Tempo para ordenar com o Insertion Sort: %.3f segundos.\n", (end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec) * 1e-6));

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

void InsertionSort(int *vetor, int vetorSize)
{
  int i, j, aux;
  for (i = 1; i < vetorSize; i++)
  {
    aux = vetor[i];
    for (j = i; (j > 0) && (aux < vetor[j - 1]); j--)
    {
      vetor[j] = vetor[j - 1];
    }
    vetor[j] = aux;
  }
}
// os primeiros elementos são comparados entre si
// itera de vetor[1] até vetor[n]
// compara o elemento atual (aux) com seu anterior
// se aux é menor que o seu antecessor, compare-o com os anteriores.
// mova os elementos maiores uma posição pra frente para ter espaco no vetor para o elemento que trocará de lugar.