
#ifndef __COLA_H__
#define __COLA_H__

#include <stdio.h>
#include <stdlib.h>

struct Cola
{
  int elementos[20];
  int inicio;
  int final;
  int *contenido;
};
struct ColaDePrioridad
{
  struct Cola *prioridad;
};

int insertar(struct ColaDePrioridad **, int, int);
int eliminar(struct ColaDePrioridad **);
void mostrar(struct ColaDePrioridad *);
int buscar(struct ColaDePrioridad *, int);

#endif
