#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node
{
  int valor;        // valor do node
  struct node *esq; // filho a esquerda
  struct node *dir; // filho a direita
  int h;            // altura
} node;

node *CriaNode(int valor);
int GetHeight(node *p);
node *Esquerda(node *p);
node *Direita(node *p);
node *ED(node *p);
node *DE(node *p);
node *Insert(node *raiz, int val);
int IsAvlTree(node *raiz);
void PrintTree(node *raiz); // Preorder
node Clear(node *raiz);

int main()
{
  node *raiz = NULL;
  int valor, teste, n;

  printf("Por favor, digite o número de elementos desejados:\n");
  scanf("%d", &n);
  srand(time(0));

  for (int i = 0; i < n; i++)
  {
    printf("Digite o valor desejado:\n");
    scanf("%d", &valor);
    // valor = (rand() % 100);
    raiz = Insert(raiz, valor);
  }

  teste = IsAvlTree(raiz);
  if (teste == 1)
  {
    printf("Sua árvore AVL está balanceada!\n");
  }
  else
  {
    printf("Erro no balanceamento...\n");
  }

  PrintTree(raiz);

  Clear(raiz);

  return 0;
}

node *CriaNode(int valor)
{
  node *newNode;
  newNode = (node *)malloc(sizeof(node));

  newNode->valor = valor;
  newNode->esq = NULL;
  newNode->dir = NULL;
  newNode->h = 0;

  return newNode;
}

int GetHeight(node *p)
{
  if (!p)
  {
    return (-1);
  }
  else
  {
    return p->h;
  }
}

node *Esquerda(node *p)
{
  node *aux;
  aux = p->dir;
  p->dir = aux->esq;
  aux->esq = p;
  if (GetHeight(p->dir) >= GetHeight(p->esq))
  {
    p->h = GetHeight(p->dir) + 1;
  }
  else
  {
    p->h = GetHeight(p->esq) + 1;
  }
  if (GetHeight(aux->dir) >= p->h)
  {
    aux->h = GetHeight(aux->dir) + 1;
  }
  else
  {
    aux->h = p->h + 1;
  }
}

node *Direita(node *p)
{
  node *aux;
  aux = p->esq;
  p->esq = aux->dir;
  aux->dir = p;
  if (GetHeight(p->dir) >= GetHeight(p->esq))
  {
    p->h = GetHeight(p->dir) + 1;
  }
  else
  {
    p->h = GetHeight(p->esq) + 1;
  }
  if (GetHeight(aux->dir) >= p->h)
  {
    aux->h = GetHeight(aux->esq) + 1;
  }
  else
  {
    aux->h = p->h + 1;
  }
}

node *ED(node *p)
{
  p->esq = Esquerda(p->esq);
  return (Direita(p));
}

node *DE(node *p)
{
  p->dir = Direita(p->dir);
  return (Esquerda(p));
}

node *Insert(node *raiz, int valor)
{
  if (!raiz)
  {
    return CriaNode(valor);
  }
  if (valor < raiz->valor)
  {
    raiz->esq = Insert(raiz->esq, valor);
    if (GetHeight(raiz->esq) - GetHeight(raiz->dir) == 2)
    {
      if (valor < raiz->esq->valor)
      {
        raiz = Direita(raiz);
      }
      else
      {
        raiz = ED(raiz);
      }
    }
  }
  if (valor > raiz->valor)
  {
    raiz->dir = Insert(raiz->dir, valor);
    if (GetHeight(raiz->dir) - GetHeight(raiz->esq) == 2)
    {
      if (valor > raiz->dir->valor)
      {
        raiz = Esquerda(raiz);
      }
      else
      {
        raiz = DE(raiz);
      }
    }
  }
  if (GetHeight(raiz->dir) >= GetHeight(raiz->esq))
  {
    raiz->h = GetHeight(raiz->dir) + 1;
  }
  else
  {
    raiz->h = GetHeight(raiz->esq) + 1;
  }

  return raiz;
}

int IsAvlTree(node *raiz)
{
  int fb;
  if (raiz == NULL)
  {
    return 1;
  }
  if (!IsAvlTree(raiz->esq))
  {
    return 0;
  }
  if (!IsAvlTree(raiz->dir))
  {
    return 0;
  }
  fb = (GetHeight(raiz->esq) - GetHeight(raiz->dir));
  if ((fb > 1) || (fb < -1))
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

void PrintTree(node *raiz)
{
  if (raiz == NULL)
  {
    return;
  }
  printf("%d\n", raiz->valor);
  PrintTree(raiz->esq);
  PrintTree(raiz->dir);
}

node Clear(node *raiz)
{
  if (raiz != NULL)
  {
    Clear(raiz->esq);
    Clear(raiz->dir);
    free(raiz);
  }
}