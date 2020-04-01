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
        printf("Menu\n1.- Agregar\n2.-Eliminar\n3.- Mostrar\n4.-Invertir\n0.-Salir\n");
        printf("Selecciona la opción deseada: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("Ingrese el numero que registrara en la lista: ");
            scanf("%d", &element);
            printf("%d", element);
            if (!insert(&list, element))
            {
                printf("Ha ocurrido un error al ingresar:%d", element);
            }
            break;
        case 2:
            printf("Ingrese el numero que se eliminara de la lista: ");
            scanf("%d", &element);
            if (!removeElement(&list, element))
            {
                printf("Ha ocurrido un error al eliminar:%d", element);
            }
            break;
        case 3:
            show(list);
            break;
        case 4:
            revert(&list);
            break;
        default:
            break;
        }
    }
    return 0;
}