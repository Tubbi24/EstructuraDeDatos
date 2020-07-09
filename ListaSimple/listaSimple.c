#include "listaSimple.h"

int insertar(struct Lista **lista, int elemento)
{
  struct Lista *siguiente = NULL;

  if (*lista == NULL)
  {
    *lista = (struct Lista *)malloc(sizeof(struct Lista));

    if (lista == NULL)
    {
      return 0;
    }

    (*lista)->elemento = elemento;
    (*lista)->siguiente = NULL;
  }
  else
  {
    siguiente = (struct Lista *)malloc(sizeof(struct Lista));

    if (siguiente == NULL)
    {
      return 0;
    }

    siguiente->elemento = elemento;
    siguiente->siguiente = *lista;
    *lista = siguiente;
  }
  return 1;
}

int eliminar(struct Lista **lista, int elemento)
{
  struct Lista *auxiliar = NULL;

  if (*lista == NULL)
  {
    return 0;
  }

  while (*lista != NULL)
  {
    if ((*lista)->elemento != elemento)
    {
      insertar(&auxiliar, (*lista)->elemento);
    }
    *lista = (*lista)->siguiente;
  }

  *lista = auxiliar;
  invertir(lista);
  return 1;
}

void invertir(struct Lista **lista)
{
  struct Lista *siguiente = NULL;

  if (*lista == NULL)
  {
    return;
  }

  while (*lista != NULL)
  {

    insertar(&siguiente, (*lista)->elemento);
    *lista = (*lista)->siguiente;
  }

  *lista = siguiente;
  return;
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
    copia = copia->siguiente;
  }
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
    copia = copia->siguiente;
  }

  return 0;
}
