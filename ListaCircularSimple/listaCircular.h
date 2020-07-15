
#ifndef __LISTA_DOBLE_H__
#define __LISTA_DOBLE_H__

#include <stdio.h>
#include <stdlib.h>

struct Lista
{
  int elemento;
  struct Lista *siguiente;
};

struct ListaCircular
{
  struct Lista *inicio;
  struct Lista *final;
};

int insertar(struct ListaCircular **, int);
int eliminar(struct ListaCircular **, int);
void mostrar(struct ListaCircular *);
int buscar(struct ListaCircular *, int);

#endif
