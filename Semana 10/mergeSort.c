/*
 MERGE SORT
   -É um algoritmo no estilo Dividir e Conquistar
   -Divide, recursivamente, o conjunto de dados até que cada subconjunto possua 1 elemento.
   -Combina 2 subconjuntos de forma a obter 1 conjunto maior e ordenado.
   -Esse processo se repete até que exista apenas 1 subconjunto.
   -Utilizado para organizar listas encadeadas.
   -Performance
     = Melhor Caso -> O(N Log(N))
     = Pior Caso -> O(N Log(N))
     =Sempre O(N Log(N)) pois divide o array em duas partes e leva tempo linear para dar
      merge nessas partes.
   -Utiliza um vetor auxiliar durante a ordenação.
   -Lento em caso de tarefas pequenas.
   -Ele realiza todo o processo, mesmo que o array já esteja ordenado.
   -Estável, pois altera a ordem de dados iguais.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

void PrintVetor(int *vetor, int vetorSize);
void Clear(int *vetor);
void TesteOrder(int *vetor, int vetorSize);
void Merge(int *vetor, int inicio, int meio, int fim);
void MergeSort(int *vetor, int inicio, int fim);

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
  MergeSort(vetor, 0, vetorSize - 1);
  gettimeofday(&end, 0);

  // printf("Vetor depois da organização:\n");
  // PrintVetor(vetor, vetorSize);

  TesteOrder(vetor, vetorSize);

  printf("Tempo para ordenar com o Merge Sort: %.3f segundos.\n", (end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec) * 1e-6));

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

void Merge(int *vetor, int inicio, int meio, int fim)
{
  int *temp, p1, p2, tamanho, i, j, k;
  int fim1 = 0, fim2 = 0;
  tamanho = fim - inicio + 1;
  // vetores que serão combinados em temp
  p1 = inicio;
  p2 = meio + 1;
  temp = (int *)malloc(tamanho * sizeof(int));
  // percorre o vetor temporário inteiro
  if (temp != NULL)
  {
    for (i = 0; i < tamanho; i++)
    {
      if (!fim1 && !fim2)
      {
        // combinar ordenando
        // ve entre os dois vetores qual possui o menor valor na determinada posição
        // e avança o vetor que foi escolhido
        if (vetor[p1] < vetor[p2])
          temp[i] = vetor[p1++];
        else
          temp[i] = vetor[p2++];
        // vetor acabou?
        // se um dos vetores acabou, coloca eles para acabar o if
        if (p1 > meio)
          fim1 = 1;
        if (p2 > fim)
          fim2 = 1;
      }
      else
      {
        // Copia o que sobrar do vetor que não acabou para temp
        if (!fim1)
          temp[i] = vetor[p1++];
        else
          temp[i] = vetor[p2++];
      }
    }
    // copia do auxiliar para o original
    for (j = 0, k = inicio; j < tamanho; j++, k++)
      vetor[k] = temp[j];
  }
  free(temp);
}

void MergeSort(int *vetor, int inicio, int fim)
{
  int meio;
  if (inicio < fim)
  {
    meio = floor((inicio + fim) / 2);
    // chama a função para as 2 metades
    MergeSort(vetor, inicio, meio);
    MergeSort(vetor, meio + 1, fim);
    // Combina as 2 metades de forma ordenada
    Merge(vetor, inicio, meio, fim);
  }
}
