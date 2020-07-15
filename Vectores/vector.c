#include "vector.h"

int inicializar(struct Vector **vector)
{
  *vector = (struct Vector *)malloc(sizeof(struct Vector));

  if (*vector == NULL)
  {
    return 0;
  }

  (*vector)->elementos = (int *)malloc(sizeof(int));

  if ((*vector)->elementos == NULL)
  {
    return 0;
  }

  (*vector)->total = 0;

  (*vector)->capacidad = 1;

  return 1;
}

int insertar(struct Vector **vector, int elemento)
{
  if (*vector == NULL)
  {
    if (inicializar(vector) == 0)
    {
      return 0;
    }
  }

  if (estaLleno(vector) == 0)
  {
    if (agrandar(vector) == 0)
    {
      return 0;
    }
  }

  *((*vector)->elementos + (*vector)->total) = elemento;

  (*vector)->total = (*vector)->total + 1;

  return 1;
}

int estaLleno(struct Vector **vector)
{
  if (*vector == NULL)
  {
    return 1;
  }

  if ((*vector)->total > (*vector)->capacidad)
  {
    return 1;
  }

  return 0;
}

int agrandar(struct Vector **vector)
{
  int *copiaDeVector = NULL;

  int i = 0;

  if (*vector == NULL)
  {
    return 0;
  }

  copiaDeVector = (int *)malloc(sizeof(int) * 2 * (*vector)->capacidad);

  if (copiaDeVector == NULL)
  {
    return 0;
  }

  for (i = 0; i < (*vector)->total; i++)
  {
    *(copiaDeVector + i) = *((*vector)->elementos + i);
  }

  free((*vector)->elementos);

  (*vector)->capacidad = (*vector)->capacidad * 2;

  (*vector)->elementos = copiaDeVector;

  return 1;
}

int eliminar(struct Vector **vector, int elemento)
{
  int *copiaDeVector = NULL;

  int i = 0;

  int elementosEncontrados = 0;

  if (*vector == NULL)
  {
    return 0;
  }

  copiaDeVector = (int *)malloc(sizeof(int) * (*vector)->capacidad);

  if (copiaDeVector == NULL)
  {
    return 0;
  }

  for (i = 0; i < (*vector)->total; i++)
  {
    if (*((*vector)->elementos + i) == elemento)
    {
      elementosEncontrados++;
    }
    else
    {
      *(copiaDeVector + i - elementosEncontrados) = *((*vector)->elementos + i);
    }
  }

  if (elementosEncontrados == 0)
  {
    return 0;
  }

  free((*vector)->elementos);

  (*vector)->total = (*vector)->total - elementosEncontrados;

  (*vector)->elementos = copiaDeVector;

  return 1;
}

int buscar(struct Vector **vector, int elemento)
{
  int i = 0;

  if (*vector == NULL)
  {
    return 0;
  }

  for (i = 0; i < (*vector)->total; i++)
  {
    if (*((*vector)->elementos + i) == elemento)
    {
      return 1;
    }
  }

  return 0;
}

void mostrar(struct Vector **vector)
{
  int i = 0;

  if (*vector == NULL)
  {
    return;
  }

  for (i = 0; i < (*vector)->total; i++)
  {
    if (i == 0)
    {
      printf("%d", *((*vector)->elementos + i));
    }
    else
    {
      printf(", %d", *((*vector)->elementos + i));
    }
  }

  printf("\n");

  return;
}
