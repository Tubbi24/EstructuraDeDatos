#include "cola.h"

int total = 5;

int insertar(struct Cola **cola, int elemento)
{
  int posicionModulada = 0;

  if (*cola == NULL)
  {
    *cola = (struct Cola *)malloc(sizeof(struct Cola));

    if (*cola == NULL)
    {
      return 0;
    }
    (*cola)->inicio = 0;
    (*cola)->final = 0;
  }
  else
  {
    posicionModulada = ((*cola)->final + 1) % total;

    if (posicionModulada == (*cola)->inicio)
    {
      return 0;
    }

    (*cola)->final = posicionModulada;
  }

  *((*cola)->elementos + (*cola)->final) = elemento;

  return 1;
}

int eliminar(struct Cola **cola)
{
  if (*cola == NULL)
  {
    return 0;
  }

  if ((*cola)->inicio == (*cola)->final)
  {
    *cola = NULL;
    return 1;
  }

  *((*cola)->elementos + (*cola)->inicio) = 0;
  (*cola)->inicio++;
  return 1;
}

void mostrar(struct Cola *cola)
{
  int i = 0;

  if (cola == NULL)
  {
    return;
  }

  printf("\nCola:\n");

  if (cola->final >= cola->inicio)
  {
    for (i = cola->inicio; i <= cola->final; i++)
    {
      printf("%d\n", *(cola->elementos + i));
    }
  }
  else
  {
    for (i = cola->inicio; i < total; i++)
    {
      printf("%d\n", *(cola->elementos + i));
    }

    for (i = 0; i <= cola->final; i++)
    {
      printf("%d\n", *(cola->elementos + i));
    }
  }

  return;
}

int buscar(struct Cola *cola, int elemento)
{

  int i = 0;

  if (cola == NULL)
  {
    return 0;
  }

  if (cola->final >= cola->inicio)
  {
    for (i = cola->inicio; i <= cola->final; i++)
    {
      if (*(cola->elementos + i) == elemento)
      {
        return 1;
      }
    }
  }
  else
  {
    for (i = cola->inicio; i < total; i++)
    {
      if (*(cola->elementos + i) == elemento)
      {
        return 1;
      }
    }

    for (i = 0; i <= cola->final; i++)
    {
      if (*(cola->elementos + i) == elemento)
      {
        return 1;
      }
    }
  }

  return 0;
}
