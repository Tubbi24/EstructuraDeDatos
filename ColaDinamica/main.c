#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main(void)
{
  int elemento = 1;

  struct Cola *cola = NULL;

  insertar(&cola, 1);
  insertar(&cola, 2);
  insertar(&cola, 3);
  insertar(&cola, 4);

  mostrar(cola);

  eliminar(&cola);
  eliminar(&cola);
  insertar(&cola, 5);
  insertar(&cola, 6);
  mostrar(cola);

  elemento = 3;

  if (buscar(cola, elemento) == 1)
  {
    printf("Se ha encontrado el elemento: %d \n", elemento);
  }
  else
  {
    printf("No se ha encontrado el elemento: %d \n", elemento);
  }

  elemento = 9;

  if (buscar(cola, elemento) == 1)
  {
    printf("Se ha encontrado el elemento: %d \n", elemento);
  }
  else
  {
    printf("No se ha encontrado el elemento: %d \n", elemento);
  }

  return 0;
}