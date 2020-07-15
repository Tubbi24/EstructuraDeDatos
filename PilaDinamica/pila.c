#include "pila.h"

int push(struct Pila **pila, int elemento)
{
  struct Pila *siguiente = NULL;

  if (*pila == NULL)
  {
    *pila = (struct Pila *)malloc(sizeof(struct Pila));

    if (*pila == NULL)
    {
      return 0;
    }
    (*pila)->elemento = elemento;
    (*pila)->siguiente = NULL;
  }
  else
  {
    siguiente = (struct Pila *)malloc(sizeof(struct Pila));

    if (siguiente == NULL)
    {
      return 0;
    }

    siguiente->elemento = elemento;
    siguiente->siguiente = *pila;
    *pila = siguiente;
  }
  return 1;
}

int pop(struct Pila **pila)
{
  if (*pila == NULL)
  {
    return 0;
  }

  *pila = (*pila)->siguiente;
  //return (*pila)->elemento;
  return 1;
}

void mostrarPila(struct Pila *pila)
{
  if (pila == NULL)
  {
    return;
  }

  printf("\nPila:\n");

  while (pila != NULL)
  {
    printf("%d\n", pila->elemento);
    pila = pila->siguiente;
  }

  return;
}

int buscarPila(struct Pila *pila, int elemento)
{
  if (pila == NULL)
  {
    return 0;
  }

  while (pila != NULL)
  {
    if (pila->elemento == elemento)
    {
      return 1;
    }
    pila = pila->siguiente;
  }

  return 0;
}
