#include "functions.h"

int insertToNext(struct List **list, int element)
{
    struct List *nextList = NULL;

    if (*list == NULL)
    {
        *list = (struct List *)malloc(sizeof(struct List));
        if (list == NULL)
        {
            return 0;
        }
        (*list)->element = element;
        (*list)->next = NULL;
        (*list)->prev = NULL;
    }
    else
    {
        nextList = (struct List *)malloc(sizeof(struct List));

        nextList->element = element;
        nextList->prev = NULL;
        nextList->next = *list;
        (*list)->prev = nextList;
        *list = nextList;
    }
    return 1;
}

int insertToPrev(struct List **list, int element)
{
    struct List *prevList = NULL;
    struct List *copyList = *list;

    if (*list == NULL)
    {
        *list = (struct List *)malloc(sizeof(struct List));
        if (*list == NULL)
        {
            return 0;
        }
        (*list)->element = element;
        (*list)->next = NULL;
        (*list)->prev = NULL;
    }
    else
    {
        while (copyList->next != NULL)
        {
            copyList = copyList->next;
        }

        prevList = (struct List *)malloc(sizeof(struct List));
        prevList->element = element;
        prevList->prev = copyList;
        prevList->next = NULL;
        copyList->next = prevList;
    }
    return 1;
}

int removeElement(struct List **list, int element)
{
    struct List *copyList = *list;
    struct List *nextList = NULL;
    struct List *prevList = NULL;

    while (copyList != NULL)
    {
        if (copyList->element == element)
        {
            if (copyList == *list)
            {
                *list = copyList->next;
                copyList->next->prev = NULL;
            }
            else
            {
                prevList = copyList->prev;
                copyList->prev = NULL;
                prevList->next = NULL;
                if (copyList->next != NULL)
                {
                    nextList = copyList->next;
                    copyList->next = NULL;
                    prevList->next = nextList;
                    nextList->prev = prevList;
                }
                free(copyList);
                return 1;
            }
        }
        copyList = copyList->next;
    }
    return 0;
}

void show(struct List *list)
{
    struct List *copyList = list;

    printf("\nLista:\n");
    if (copyList == NULL)
    {
        printf("Vacia\n");
        return;
    }
    while (copyList != NULL)
    {
        printf("%d\n", copyList->element);
        copyList = copyList->next;
    }
    free(copyList);
    return;
}
