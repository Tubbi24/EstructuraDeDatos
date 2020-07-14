#include "listaCircular.h"

int insertar(struct ListaCircular **listaCircular, int elemento)
{
  struct Lista *nuevaLista = NULL;

  if (*listaCircular == NULL)
  {
    *listaCircular = (struct ListaCircular *)malloc(sizeof(struct ListaCircular));
    (*listaCircular)->inicio = NULL;
    (*listaCircular)->final = NULL;
  }

  if (*listaCircular == NULL)
  {
    return 0;
  }

  if ((*listaCircular)->inicio == NULL)
  {
    (*listaCircular)->inicio = (struct Lista *)malloc(sizeof(struct Lista));

    if ((*listaCircular)->inicio == NULL)
    {
      return 0;
    }

    nuevaLista = (struct Lista *)malloc(sizeof(struct Lista));

    if (nuevaLista == NULL)
    {
      return 0;
    }

    nuevaLista->elemento = elemento;
    nuevaLista->siguiente = NULL;

    (*listaCircular)->inicio = nuevaLista;
    (*listaCircular)->inicio->siguiente = NULL;
    (*listaCircular)->final = (*listaCircular)->inicio;
  }
  else
  {
    nuevaLista = (struct Lista *)malloc(sizeof(struct Lista));

    if (nuevaLista == NULL)
    {
      return 0;
    }

    nuevaLista->elemento = elemento;
    nuevaLista->siguiente = NULL;

    (*listaCircular)->final->siguiente = nuevaLista;

    nuevaLista->siguiente = (*listaCircular)->inicio;

    (*listaCircular)->final = nuevaLista;
  }

  return 1;
}

int eliminar(struct ListaCircular **listaCircular, int elemento)
{
  struct Lista *inicioAuxiliar = (struct Lista *)malloc(sizeof(struct Lista));
  int encontrado = 0;

  inicioAuxiliar = (*listaCircular)->inicio;

  struct Lista *penultimo = (struct Lista *)malloc(sizeof(struct Lista));

  penultimo = NULL;

  if ((*listaCircular)->inicio == NULL)
  {
    return 0;
  }

  while (inicioAuxiliar != NULL && encontrado == 0)
  {
    if (inicioAuxiliar->elemento == elemento)
    {
      if (inicioAuxiliar == (*listaCircular)->inicio)
      {
        (*listaCircular)->inicio = (*listaCircular)->inicio->siguiente;
      }
      else
      {
        if (inicioAuxiliar == (*listaCircular)->final)
        {
          penultimo->siguiente = (*listaCircular)->inicio;
          (*listaCircular)->final = penultimo;
        }
        else
        {
          penultimo->siguiente = inicioAuxiliar->siguiente;
        }
      }
      encontrado = 1;
    }

    penultimo = inicioAuxiliar;
    inicioAuxiliar = inicioAuxiliar->siguiente;
  }

  free(penultimo);

  if (encontrado == 0)
  {
    return 0;
  }

  return 1;
}

void mostrar(struct ListaCircular *listaCircular)
{
  struct Lista *inicioAuxiliar = (struct Lista *)malloc(sizeof(struct Lista));

  if (listaCircular == NULL)
  {
    return;
  }

  inicioAuxiliar = listaCircular->inicio;

  printf("\nLista:\n");
  if (listaCircular->inicio == NULL)
  {
    printf("Vacia\n");
    return;
  }
  while (1)
  {
    printf("%d\n", inicioAuxiliar->elemento);
    if (inicioAuxiliar == listaCircular->final)
    {
      return;
    }
    inicioAuxiliar = inicioAuxiliar->siguiente;
  }
}

int buscar(struct ListaCircular *listaCircular, int elemento)
{
  struct Lista *inicioAuxiliar = (struct Lista *)malloc(sizeof(struct Lista));

  if (listaCircular == NULL)
  {
    return 0;
  }

  inicioAuxiliar = listaCircular->inicio;

  if (listaCircular->inicio == NULL)
  {
    return 0;
  }

  while (1)
  {
    if (inicioAuxiliar->elemento == elemento)
    {
      return 1;
    }
    if (inicioAuxiliar == listaCircular->final)
    {
      break;
    }
    inicioAuxiliar = inicioAuxiliar->siguiente;
  }
  return 0;
}
