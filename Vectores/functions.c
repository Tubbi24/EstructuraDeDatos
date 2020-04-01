#include "functions.h"

void init(struct Vector **vector)
{
    *vector = (struct Vector *)malloc(sizeof(struct Vector));

    (*vector)->elements = (int *)malloc(sizeof(int));
    (*vector)->total = 0;
    (*vector)->capacity = 1;
}

int insert(struct Vector **vector, int element)
{
    if (vector == NULL)
    {
        return 0;
    }

    if (isFull(vector))
    {
        if (!enlarge(vector))
        {
            return 0;
        }
    }
    *((*vector)->elements + (*vector)->total) = element;
    (*vector)->total = (*vector)->total + 1;
    return 1;
}

int isFull(struct Vector **vector)
{
    if ((*vector)->total > (*vector)->capacity)
    {
        return 1;
    }
    return 0;
}

int enlarge(struct Vector **vector)
{
    int *copyVector = NULL;

    copyVector = (int *)malloc(sizeof(int) * 2 * (*vector)->capacity);

    if (copyVector == NULL)
    {
        return 0;
    }

    for (int i = 0; i < (*vector)->total; i++)
    {
        *(copyVector + i) = *((*vector)->elements + i);
    }

    free((*vector)->elements);
    (*vector)->capacity = (*vector)->capacity * 2;
    (*vector)->elements = copyVector;
    return 1;
}

void show(struct Vector **vector)
{
    if (vector == NULL)
    {
        return;
    }
    for (int i = 0; i < (*vector)->total; i++)
    {
        if (i == 0)
        {

            printf("%d", *((*vector)->elements + i));
        }
        else
        {
            printf(", %d", *((*vector)->elements + i));
        }
    }
    printf("\n");
    return;
}
