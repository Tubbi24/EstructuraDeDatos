#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
    int opt = 1;
    int element = 1;

    int i = 1;
    struct List *list = NULL;

    while (opt != 0)
    {
        printf("Menu\n1.- Insertar al inicio\n2.-Insertar al final\n3.-Eliminar\n4.- Mostrar\n0.-Salir\n");
        printf("Selecciona la opción deseada: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("Ingrese el numero que registrara al inicio de la lista: ");
            scanf("%d", &element);
            if (!insertToNext(&list, element))
            {
                printf("Ha ocurrido un error al insertar:%d", element);
            }
            else
            {
                printf("\nSe ha insertado correctamente el elemento:%d\n", element);
            }

            break;
        case 2:
            printf("Ingrese el numero que registrara al final de la lista: ");
            scanf("%d", &element);
            if (!insertToPrev(&list, element))
            {
                printf("Ha ocurrido un error al insertar:%d", element);
            }
            else
            {
                printf("\nSe ha insertado correctamente el elemento:%d\n", element);
            }

            break;
        case 3:
            printf("Ingrese el numero que se eliminara de la lista: ");
            scanf("%d", &element);
            if (!removeElement(&list, element))
            {
                printf("Ha ocurrido un error al eliminar:%d", element);
            }
            else
            {
                printf("\nSe ha eleminado correctamente el elemento:%d\n", element);
            }

            break;
        case 4:
            show(list);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("No existe la opción ingresada.");
            break;
        }
    }
    return 0;
}