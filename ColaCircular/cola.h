
#ifndef __COLA_H__
#define __COLA_H__

#include <stdio.h>
#include <stdlib.h>

struct Cola
{
  int elementos[5];
  int inicio;
  int final;
};

int insertar(struct Cola **, int);
int eliminar(struct Cola **);
void mostrar(struct Cola *);
int buscar(struct Cola *, int);

#endif
