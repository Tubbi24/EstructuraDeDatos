#include <stdio.h>
#include <stdlib.h>
#include "listaSimple.h"

int main(void)
{
    struct Lista *lista = NULL;
    int elemento=0;

    insertar(&lista, 1);
    insertar(&lista, 3);
    insertar(&lista, 5);
    insertar(&lista, 7);
    mostrar(lista);
    eliminar(&lista, 3);
    invertir(&lista);
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