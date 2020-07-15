#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main(void)
{
  int elemento = 1;

  struct ColaDePrioridad *colaDePrioridad = NULL;

  insertar(&colaDePrioridad, 1, 1);
  insertar(&colaDePrioridad, 2, 2);
  insertar(&colaDePrioridad, 3, 2);
  insertar(&colaDePrioridad, 4, 3);
  insertar(&colaDePrioridad, 5, 3);
  insertar(&colaDePrioridad, 6, 3);
  insertar(&colaDePrioridad, 7, 4);
  insertar(&colaDePrioridad, 8, 4);
  insertar(&colaDePrioridad, 9, 5);

  mostrar(colaDePrioridad);

  eliminar(&colaDePrioridad);
  eliminar(&colaDePrioridad);
  eliminar(&colaDePrioridad);
  insertar(&colaDePrioridad, 1, 2);
  insertar(&colaDePrioridad, 10, 5);
  mostrar(colaDePrioridad);

  elemento = 3;

  if (buscar(colaDePrioridad, elemento) == 1)
  {
    printf("Se ha encontrado el elemento: %d \n", elemento);
  }
  else
  {
    printf("No se ha encontrado el elemento: %d \n", elemento);
  }

  elemento = 9;

  if (buscar(colaDePrioridad, elemento) == 1)
  {
    printf("Se ha encontrado el elemento: %d \n", elemento);
  }
  else
  {
    printf("No se ha encontrado el elemento: %d \n", elemento);
  }

  return 0;
}