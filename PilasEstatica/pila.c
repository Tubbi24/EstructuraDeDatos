#include "pila.h"

int total = 100;

int push(struct Pila **pila, int elemento)
{
  if (*pila == NULL)
  {
    *pila = (struct Pila *)malloc(sizeof(struct Pila));

    if (*pila == NULL)
    {
      return 0;
    }

    (*pila)->tope = -1;
  }

  if ((*pila)->tope >= total - 1)
  {
    return 0;
  }

  (*pila)->tope++;

  *((*pila)->elementos + (*pila)->tope) = elemento;

  return 1;
}

int pop(struct Pila **pila)
{
  if (*pila == NULL)
  {
    return 0;
  }

  *((*pila)->elementos + (*pila)->tope) = 0;

  (*pila)->tope--;

  // return *((*pila)->elementos + (*pila)->tope); si se quiere regresar el elemento tope
  return 1;
}

void mostrarPila(struct Pila *pila)
{
  int i = 0;

  if (pila == NULL)
  {
    return;
  }

  printf("Pila:\n");

  for (i = 0; i <= pila->tope; i++)
  {
    if (i == 0)
    {
      printf("%d", *(pila->elementos + i));
    }
    else
    {
      printf(", %d", *(pila->elementos + i));
    }
  }

  printf("\n");

  return;
}

int buscarPila(struct Pila *pila, int elemento)
{
  int i = 0;

  if (pila == NULL)
  {
    return 0;
  }

  for (i = 0; i <= pila->tope; i++)
  {
    if (*(pila->elementos + i) == elemento)
    {

      return 1;
    }
  }
  return 0;
}
