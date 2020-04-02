#include "functions.h"

struct List *first = NULL;
struct List *end = NULL;

int insert(int element)
{
    struct List *nextList = NULL;

    if (first == NULL)
    {
        first = (struct List *)malloc(sizeof(struct List));
        nextList = (struct List *)malloc(sizeof(struct List));
        nextList->element = element;
        nextList->next = NULL;
        first = nextList;
        first->next = NULL;
        end = first;
    }
    else
    {
        nextList = (struct List *)malloc(sizeof(struct List));
        nextList->element = element;
        nextList->next = NULL;
        end->next = nextList;
        nextList->next = first;
        end = nextList;
    }

    return 1;
}
int removeElement(int element)
{
    struct List *copyFirst = (struct List *)malloc(sizeof(struct List));
    copyFirst = first;

    struct List *prevEnd = (struct List *)malloc(sizeof(struct List));
    prevEnd = NULL;
    int found = 0;

    if (first == NULL)
    {
        return 0;
    }

    while (copyFirst != NULL && found == 0)
    {
        if (copyFirst->element == element)
        {
            if (copyFirst == first)
            {
                first = first->next;
            }
            else
            {
                if (copyFirst == end)
                {
                    prevEnd->next = first;
                    end = prevEnd;
                }
                else
                {
                    prevEnd->next = copyFirst->next;
                }
            }
            found = 1;
        }

        prevEnd = copyFirst;
        copyFirst = copyFirst->next;
    }
    free(prevEnd);
    if (found == 0)
    {
        return 0;
    }
    return 1;
}

void show()
{
    struct List *copyFirst = (struct List *)malloc(sizeof(struct List));
    copyFirst = first;
    printf("\nLista:\n");
    if (first == NULL)
    {
        printf("Vacia\n");
        return;
    }
    while (1)
    {
        printf("%d\n", copyFirst->element);
        if (copyFirst == end)
        {
            break;
        }
        copyFirst = copyFirst->next;
    }
}
