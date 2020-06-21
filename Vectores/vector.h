
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h>
#include <stdlib.h>

struct Vector
{
  int capacidad;
  int total;
  int *elementos;
};

int inicializar(struct Vector **);

int insertar(struct Vector **, int);

int buscar(struct Vector **, int);

int eliminar(struct Vector **, int);

int estaLleno(struct Vector **);

int agrandar(struct Vector **);

void mostrar(struct Vector **);

#endif
