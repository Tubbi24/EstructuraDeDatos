#include "cola.h"

int total = 5;

int insertar(struct Cola **cola, int elemento)
{
  struct Cola *siguiente = (struct Cola *)malloc(sizeof(struct Cola));

  struct Cola *auxiliar = NULL;

  if (*cola == NULL)
  {
    *cola = (struct Cola *)malloc(sizeof(struct Cola));

    if (*cola == NULL)
    {
      return 0;
    }

    (*cola)->elemento = elemento;
    (*cola)->siguiente = NULL;
  }
  else
  {
    siguiente = (struct Cola *)malloc(sizeof(struct Cola));

    if (siguiente == NULL)
    {
      return 0;
    }

    auxiliar = *cola;

    while (auxiliar->siguiente != NULL)
    {
      auxiliar = auxiliar->siguiente;
    }
    siguiente->elemento = elemento;
    siguiente->siguiente = NULL;

    auxiliar->siguiente = siguiente;
  }

  return 1;
}

int eliminar(struct Cola **cola)
{
  if (*cola == NULL)
  {
    return 0;
  }

  *cola = (*cola)->siguiente;

  return 1;
}

void mostrar(struct Cola *cola)
{
  if (cola == NULL)
  {
    return;
  }

  printf("\nCola:\n");

  while (cola != NULL)
  {
    printf("%d\n", cola->elemento);
    cola = cola->siguiente;
  }
  return;
}

int buscar(struct Cola *cola, int elemento)
{
  if (cola == NULL)
  {
    return 0;
  }

  while (cola != NULL)
  {
    if (cola->elemento == elemento)
    {
      return 1;
    }
    cola = cola->siguiente;
  }

  return 0;
}
