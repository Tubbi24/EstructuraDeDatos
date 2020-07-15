#include "cola.h"

int total = 20; //20 elementos por cola, en total son 100

//Prioridad de 1 -> 5 en forma ascendente

int insertar(struct ColaDePrioridad **colaDePrioridad, int elemento, int prioridad)
{
  int posicionModulada = 0;

  struct Cola *colaActual = NULL;

  if (*colaDePrioridad == NULL)
  {
    *colaDePrioridad = (struct ColaDePrioridad *)malloc(sizeof(struct ColaDePrioridad));

    if (*colaDePrioridad == NULL)
    {
      return 0;
    }
    (*colaDePrioridad)->prioridad = (struct Cola *)malloc(sizeof(struct Cola));
  }

  if (prioridad < 1 || prioridad > 5)
  {
    return 0;
  }

  colaActual = ((*colaDePrioridad)->prioridad + prioridad);

  if ((colaActual)->contenido == NULL)
  {
    (colaActual)->inicio = 0;
    (colaActual)->final = 0;
    (colaActual)->contenido = (int *)malloc(sizeof(int));
  }
  else
  {
    posicionModulada = ((colaActual)->final + 1) % total;

    if (posicionModulada == (colaActual)->inicio)
    {
      return 0;
    }

    (colaActual)->final = posicionModulada;
  }

  *((colaActual)->elementos + (colaActual)->final) = elemento;

  return 1;
}

int eliminar(struct ColaDePrioridad **colaDePrioridad)
{
  int prioridad = 1;
  struct Cola *colaActual = NULL;

  if (*colaDePrioridad == NULL)
  {
    return 0;
  }

  while (prioridad <= 5)
  {
    colaActual = ((*colaDePrioridad)->prioridad + prioridad);
    if (colaActual->contenido != NULL)
    {
      if (colaActual->inicio == colaActual->final)
      {
        colaActual->inicio = 0;
        colaActual->final = 0;
        colaActual->contenido = NULL;

        return 1;
      }

      *(colaActual->elementos + colaActual->inicio) = 0;
      colaActual->inicio++;

      return 1;
    }
    prioridad++;
  }
  return 0;
}

void mostrar(struct ColaDePrioridad *colaDePrioridad)
{
  int i = 0;
  int prioridad = 1;
  struct Cola *colaActual = NULL;

  if (colaDePrioridad == NULL)
  {
    return;
  }

  colaActual = colaDePrioridad->prioridad;

  while (prioridad <= 5)
  {
    colaActual = (colaDePrioridad->prioridad + prioridad);

    printf("\nCola con prioridad: %d \n", prioridad);
    if (colaActual->contenido != NULL)
    {
      if (colaActual->final >= colaActual->inicio)
      {
        for (i = colaActual->inicio; i <= colaActual->final; i++)
        {
          printf("%d\n", *(colaActual->elementos + i));
        }
      }
      else
      {
        for (i = colaActual->inicio; i < total; i++)
        {
          printf("%d\n", *(colaActual->elementos + i));
        }

        for (i = 0; i <= colaActual->final; i++)
        {
          printf("%d\n", *(colaActual->elementos + i));
        }
      }
    }
    else
    {
      printf("Vacía\n");
    }
    prioridad++;
  }
  return;
}

int buscar(struct ColaDePrioridad *colaDePrioridad, int elemento)
{
  int i = 0;
  int prioridad = 1;
  struct Cola *colaActual = NULL;

  if (colaDePrioridad == NULL)
  {
    return 0;
  }

  colaActual = colaDePrioridad->prioridad;

  while (prioridad <= 5)
  {
    colaActual = (colaDePrioridad->prioridad + prioridad);

    if (colaActual->contenido != NULL)
    {
      if (colaActual->final >= colaActual->inicio)
      {
        for (i = colaActual->inicio; i <= colaActual->final; i++)
          if (*(colaActual->elementos + i) == elemento)
          {
            return 1;
          }
      }
      else
      {
        for (i = colaActual->inicio; i < total; i++)
        {
          if (*(colaActual->elementos + i) == elemento)
          {
            return 1;
          }
        }

        for (i = 0; i <= colaActual->final; i++)
        {
          if (*(colaActual->elementos + i) == elemento)
          {
            return 1;
          }
        }
      }
    }
    prioridad++;
  }
  return 0;
}