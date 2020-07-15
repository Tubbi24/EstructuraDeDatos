
#ifndef __PILA_H__
#define __PILA_H__

#include <stdio.h>
#include <stdlib.h>

struct Pila
{
  int elemento;
  struct Pila *siguiente;
};

int push(struct Pila **, int);
int pop(struct Pila **);
void mostrarPila(struct Pila *);
int buscarPila(struct Pila *, int);

#endif
