#include "listaDoble.h"

int insertarSiguiente(struct Lista **lista, int elemento)
{
  struct Lista *anterior = NULL;

  if (*lista == NULL)
  {
    *lista = (struct Lista *)malloc(sizeof(struct Lista));
    if (lista == NULL)
    {
      return 0;
    }
    (*lista)->elemento = elemento;
    (*lista)->anterior = NULL;
    (*lista)->siguiente = NULL;
  }
  else
  {
    anterior = (struct Lista *)malloc(sizeof(struct Lista));

    anterior->elemento = elemento;
    anterior->siguiente = NULL;
    anterior->anterior = *lista;
    (*lista)->siguiente = anterior;
    *lista = anterior;
  }
  return 1;
}

int insertarAnterior(struct Lista **lista, int elemento)
{
  struct Lista *anterior = NULL;
  struct Lista *copia = *lista;

  if (*lista == NULL)
  {
    *lista = (struct Lista *)malloc(sizeof(struct Lista));
    if (*lista == NULL)
    {
      return 0;
    }
    (*lista)->elemento = elemento;
    (*lista)->anterior = NULL;
    (*lista)->siguiente = NULL;
  }
  else
  {
    while (copia->anterior != NULL)
    {
      copia = copia->anterior;
    }

    anterior = (struct Lista *)malloc(sizeof(struct Lista));
    anterior->elemento = elemento;
    anterior->siguiente = copia;
    anterior->anterior = NULL;
    copia->anterior = anterior;
  }
  return 1;
}

int eliminar(struct Lista **lista, int elemento)
{
  struct Lista *copia = *lista;
  struct Lista *anterior = NULL;
  struct Lista *siguiente = NULL;

  while (copia != NULL)
  {
    if (copia->elemento == elemento)
    {
      if (copia == *lista)
      {
        *lista = copia->anterior;
        copia->anterior->siguiente = NULL;
      }
      else
      {
        siguiente = copia->siguiente;
        copia->siguiente = NULL;
        siguiente->anterior = NULL;
        if (copia->anterior != NULL)
        {
          anterior = copia->anterior;
          copia->anterior = NULL;
          siguiente->anterior = anterior;
          anterior->siguiente = siguiente;
        }
        free(copia);
        return 1;
      }
    }
    copia = copia->anterior;
  }
  return 0;
}

void mostrar(struct Lista *lista)
{
  struct Lista *copia = lista;

  printf("\nLista:\n");
  if (copia == NULL)
  {
    printf("Vacia\n");
    return;
  }
  while (copia != NULL)
  {
    printf("%d\n", copia->elemento);
    copia = copia->anterior;
  }
  free(copia);
  return;
}

int buscar(struct Lista *lista, int elemento)
{
  struct Lista *copia = lista;

  if (copia == NULL)
  {
    return 0;
  }

  while (copia != NULL)
  {
    if (copia->elemento == elemento)
    {
      return 1;
    }
    copia = copia->anterior;
  }
  return 0;
}
