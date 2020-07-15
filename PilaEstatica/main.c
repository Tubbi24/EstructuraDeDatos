#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main(void)
{
  int elemento = 1;

  struct Pila *pila = NULL;

  push(&pila, 1);
  push(&pila, 3);
  push(&pila, 5);
  push(&pila, 7);

  mostrarPila(pila);

  pop(&pila);
  pop(&pila);

  mostrarPila(pila);

  elemento = 3;

  if (buscarPila(pila, elemento) == 1)
  {
    printf("Se ha encontrado el elemento: %d \n", elemento);
  }
  else
  {
    printf("No se ha encontrado el elemento: %d \n", elemento);
  }

  elemento = 9;

  if (buscarPila(pila, elemento) == 1)
  {
    printf("Se ha encontrado el elemento: %d \n", elemento);
  }
  else
  {
    printf("No se ha encontrado el elemento: %d \n", elemento);
  }

  return 0;
}