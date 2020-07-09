
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h>
#include <stdlib.h>

struct Lista
{
  int elemento;
  struct Lista *siguiente;
};

int insertar(struct Lista **, int);
int eliminar(struct Lista **, int);
int buscar(struct Lista *, int);
void mostrar(struct Lista *);
void invertir(struct Lista **);

#endif
