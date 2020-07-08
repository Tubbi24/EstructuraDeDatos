#include <stdio.h>
#include <stdlib.h>
#include "listaDoble.h"

int main(void)
{

    struct Lista *lista = NULL;
    int elemento=0;

    insertarAnterior(&lista, 1);
    insertarAnterior(&lista, 3);
    insertarAnterior(&lista, 5);
    insertarSiguiente(&lista, 7);

    mostrar(lista);
    eliminar(&lista, 3);
    mostrar(lista);

    elemento=5;

    if(buscar(lista, elemento) == 1)
    {
      printf("Se ha encontrado el elemento: %d \n", elemento);
    }
    else
    {
      printf("No se ha encontrado el elemento: %d \n", elemento);
    }

    elemento=9;

    if(buscar(lista, elemento) == 1)
    {
      printf("Se ha encontrado el elemento: %d \n", elemento);
    }
    else
    {
      printf("No se ha encontrado el elemento: %d \n", elemento);
    }

  return 0;
}