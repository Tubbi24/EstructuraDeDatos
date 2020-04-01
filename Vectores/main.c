#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
    int count = 1;
    int i = 1;
    struct Vector *vector = NULL;

    while (count != 0)
    {
        init(&vector);

        printf("*Ingresa 0 para salir*\n");
        printf("Ingresa el numero de elementos: ");

        scanf("%d", &count);

        for (i = 1; i <= count; i++)
        {
            if (!insert(&vector, i))
            {
                printf("No ha sido posible insertar el elemento:%d", i);
                break;
            }
            show(&vector);
        }
    }
    return 0;
}