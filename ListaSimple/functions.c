#include "functions.h"

int insert(struct List **list, int element)
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
    }
    else
    {
        nextList = (struct List *)malloc(sizeof(struct List));
        nextList->element = element;
        nextList->next = *list;
        *list = nextList;
    }
    return 1;
}
int removeElement(struct List **list, int element)
{
    struct List *newList = NULL;

    if (*list == NULL)
    {
        return 0;
    }

    while (*list != NULL)
    {
        if ((*list)->element != element)
        {
            insert(&newList, (*list)->element);
        }
        *list = (*list)->next;
    }

    *list = newList;
    revert(list);
    return 1;
}

void revert(struct List **list)
{
    struct List *newList = NULL;

    if (*list == NULL)
    {
        return;
    }

    while (*list != NULL)
    {

        insert(&newList, (*list)->element);
        *list = (*list)->next;
    }

    *list = newList;
    return;
}

void show(struct List *list)
{
    struct List *copyList = list;

    if (copyList == NULL)
    {
        return;
    }
    printf("\nLista:\n");
    while (copyList != NULL)
    {
        printf("%d\n", copyList->element);
        copyList = copyList->next;
    }
    return;
}
