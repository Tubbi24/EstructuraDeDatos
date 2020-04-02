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
        printf("Menu\n1.-Agregar\n2.-Eliminar\n3.- Mostrar\n4.-Invertir\n0.-Salir\n");
        printf("Selecciona la opción deseada: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("Ingrese el numero que registrara en la lista: ");
            scanf("%d", &element);
            if (!insert(element))
            {
                printf("Ha ocurrido un error al ingresar:%d", element);
            }
            else
            {
                printf("\nSe ha agregado correctamente el elemento:%d\n", element);
            }

            break;
        case 2:
            printf("Ingrese el numero que se eliminara de la lista: ");
            scanf("%d", &element);
            if (!removeElement(element))
            {
                printf("Ha ocurrido un error al eliminar:%d\n", element);
            }
            else
            {
                printf("\nSe ha eleminado correctamente el elemento:%d\n", element);
            }

            break;
        case 3:
            show();
            break;
        default:
            break;
        }
    }
    return 0;
}