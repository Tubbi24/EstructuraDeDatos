
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h>
#include <stdlib.h>

struct List
{
    int element;
    struct List *next;
};

int insert(struct List **, int);
int removeElement(struct List **, int);
void show(struct List *);
void revert(struct List **);
#endif
