
#ifndef __LISTA_DOBLE_H__
#define __LISTA_DOBLE_H__

#include <stdio.h>
#include <stdlib.h>

struct Lista
{
  int elemento;
  struct Lista *siguiente;
  struct Lista *anterior;
};

int insertarSiguiente(struct Lista **, int);
int insertarAnterior(struct Lista **, int);
int eliminar(struct Lista **, int);
void mostrar(struct Lista *);
int buscar(struct Lista *, int);

#endif
