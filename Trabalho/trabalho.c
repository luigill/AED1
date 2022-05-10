#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Caminhos Nó
#define PREVIOUS 0
#define NAME (sizeof(void *))
#define AGE (sizeof(void *) + sizeof(char) * 10)
#define PHONE (sizeof(void *) + sizeof(char) * 10 + sizeof(int))
#define NEXT (sizeof(void *) + sizeof(char) * 10 + sizeof(int) + sizeof(int))
#define NODE (sizeof(void *) + sizeof(char) * 10 + sizeof(int) + sizeof(int) + sizeof(void *))
//                prev            nome               idade          tel          next
// utilizando dessa maneira, é como se fosse node->atributo

// Caminhos dentro do pBuffer
#define SWITCH 0
#define FIRST (sizeof(int))
#define LAST (sizeof(int) + sizeof(void *))
#define NAME_AUX (sizeof(int) + sizeof(void *) + sizeof(void *))
#define COUNT (sizeof(int) + sizeof(void *) + sizeof(void *) + 10 * sizeof(char))
#define BUFFER (sizeof(int) + sizeof(void *) + sizeof(void *) + 10 * sizeof(char) + sizeof(int))

void Push(void *pBuffer);

void Pop(void *pBuffer);

void List(void *pBuffer);

void Search(void *pBuffer);

void Clear(void *pBuffer);

void Sort(void *pBuffer, void *node);

int main()
{

  void *pBuffer = (void *)malloc(BUFFER);

  if (pBuffer == NULL)
  {
    printf("FALHA NA ALOCAÇÃO DE MEMÓRIA!\n");
    exit(1);
  }

  // inicializacao do contador
  *((int *)pBuffer + COUNT) = 0;

  // inicializacao das sentinelas
  *(void **)(pBuffer + FIRST) = NULL;
  *(void **)(pBuffer + LAST) = NULL;

  do
  {
    printf("MENU:\n");
    printf("1)Adicionar Pessoa:\n");
    printf("2)Remover Pessoa:\n");
    printf("3)Listar Contatos:\n");
    printf("4)Buscar Contato:\n");
    printf("0)Sair...:\n");

    scanf("%d", &(*((int *)pBuffer + SWITCH)));
    getchar();

    switch (*((int *)pBuffer + SWITCH))
    {
    case 1:
      printf("Adicionando:\n");
      Push(pBuffer);
      break;
    case 2:
      printf("Removendo:\n");
      Pop(pBuffer);
      break;
    case 3:
      printf("Listando:\n");
      List(pBuffer);
      break;
    case 4:
      printf("Buscando:\n");
      Search(pBuffer);
      break;
    case 0:
      printf("Fim de execução!\n");
      break;
    default:
      printf("Opção Inválida...\n");
      break;
    }
  } while (*((int *)pBuffer + SWITCH) != 0);

  Clear(pBuffer);

  return 0;
}

void Push(void *pBuffer)
{
  // aloca um nodo novo
  void *node = (void *)malloc(NODE);

  if (node == NULL)
  {
    printf("FALHA NA ALOCAÇÃO DA MEMÓRIA!\n");
    exit(1);
  }

  // inicializa todos os atributos
  printf("Digite o nome do contato:\n");
  scanf("%s", (char *)(node + NAME));
  getchar();

  printf("Digite a idade do contato:\n");
  scanf("%d", ((int *)(node + AGE)));
  getchar();

  printf("Digite o telefone do contato:\n");
  scanf("%d", ((int *)(node + PHONE)));
  getchar();

  *((void **)node + PREVIOUS) = NULL;
  *((void **)node + NEXT) = NULL;

  // caso nao tenha nenhum nome, esse nodo vira a cabeca e o final da lista
  if (*((int *)pBuffer + COUNT) == 0)
  {
    *(void **)(pBuffer + FIRST) = node;
    *(void **)(pBuffer + LAST) = node;
  }
  else
  {
    Sort(pBuffer, node);
  }

  *((int *)pBuffer + COUNT) = *((int *)pBuffer + COUNT) + 1;
}

void Pop(void *pBuffer)
{
  void *node = *(void **)(pBuffer + FIRST);

  if (*((int *)pBuffer + COUNT) == 0)
  {
    printf("Lista Vazia...\n");
  }
  else
  {
    if (*(void **)(node + NEXT) == NULL)
    {
      *(void **)(pBuffer + FIRST) = NULL;
      *(void **)(pBuffer + LAST) = NULL;
    }
    else
    {
      *(void **)(pBuffer + FIRST) = *(void **)(node + NEXT); // sentinela recebe o 2 da lista
      void *auxNode = *(void **)(pBuffer + FIRST);           // auxNode recebe o novo endereco da cabeca
      *(void **)(auxNode + PREVIOUS) = NULL;                 // anterior da cabeca recebe NULL
    }

    printf("Pessoa removida: %s\n", (char *)(node + NAME));
    free(node);
  }
  *((int *)pBuffer + COUNT) = *((int *)pBuffer + COUNT) - 1;
}

void List(void *pBuffer)
{
  void *node = *(void **)(pBuffer + FIRST);

  if (*((int *)pBuffer + COUNT) == 0)
  {
    printf("Lista Vazia...\n");
  }
  else
  {
    do
    {
      printf("Nome: %s\n", (char *)(node + NAME));
      printf("Idade: %d\n", *(int *)(node + AGE));
      printf("Telefone: %d\n", *(int *)(node + PHONE));
      node = *(void **)(node + NEXT);
    } while (node != NULL);
  }
}

void Search(void *pBuffer)
{
  char *name = &*(char *)(pBuffer + NAME_AUX);
  void *node = *(void **)(pBuffer + FIRST);

  if (*((int *)pBuffer + COUNT) == 0)
  {
    printf("Lista Vazia...\n");
  }
  else
  {

    printf("Digite o nome que deve ser buscado:\n");
    scanf("%s", name);
    getchar();

    do
    {
      if (strcmp(name, (char *)(node + NAME)) == 0)
      {
        printf("Nome: %s\n", (char *)(node + NAME));
        printf("Idade: %d\n", *(int *)(node + AGE));
        printf("Telefone: %d\n", *(int *)(node + PHONE));
        return;
      }
      node = *(void **)(node + NEXT);
    } while (node != NULL);

    printf("Nome não encontrado...\n");
    return;
  }
}

void Clear(void *pBuffer)
{
  void *node = *(void **)(pBuffer + FIRST);
  void *auxNode;

  while (node != NULL)
  {
    auxNode = *(void **)(node + NEXT); // auxNode recebe o endereco do proximo
    free(node);                        // libera node
    node = auxNode;                    // node recebe o endereco do proximo
  }
  free(pBuffer);
}

void Sort(void *pBuffer, void *node)
{

  *(void **)(node + PREVIOUS) = NULL;
  *(void **)(node + NEXT) = NULL;

  void *nodeAux = *(void **)(pBuffer + FIRST); // nodeAux recebe a cabeca da lista

  while (nodeAux != NULL) // enquanto nao chegar no final da lista
  {
    if (strcmp((char *)(node + NAME), (char *)(nodeAux + NAME)) >= 0) // se o novo nome for maior do que o nome que esta na lista
    {
      if (*(void **)(nodeAux + NEXT) == NULL) // caso seja inserido no final da lista
      {
        *(void **)(node + PREVIOUS) = nodeAux;       // o ultimo da lista recebe o endereco do anterior
        void *tempNode = *(void **)(pBuffer + LAST); // tempNode recebe o endereco da sentinela final
        *(void **)(pBuffer + LAST) = node;           // atualiza a sentinela para o final
        *(void **)(tempNode + NEXT) = node;          // o ultimo endereco da lista recebe o node novo no NEXT
        return;
      }
      else // caso seja inserido no meio da lista
      {
        *(void **)(node + PREVIOUS) = nodeAux;                // o novo node recebe o endereco do nodeAux, que esta andando com o while
        *(void **)(node + NEXT) = *(void **)(nodeAux + NEXT); // o novo node recebe o proximo endereco que estava sendo apontado por nodeAux
        void *tempNode = *(void **)(nodeAux + NEXT);          // tempNode recebe o endereco do node que está apos o novo node
        *(void **)(tempNode + PREVIOUS) = node;               // o anterior de tempNode recebe o endereco do novo node
        *(void **)(nodeAux + NEXT) = node;                    // nodeAux, que contem o endereco antes do novoNode, recebe o endereco do novo node

        return;
      }
    }

    nodeAux = *(void **)(nodeAux + NEXT);
  }
  // caso seja inserido no comeco da lista
  *(void **)(node + NEXT) = *(void **)(pBuffer + FIRST); // node NEXT recebe o endereco da sentinela da lista
  *(void **)(pBuffer + FIRST) = node;                    // a sentinela é atualizada
  return;
}
