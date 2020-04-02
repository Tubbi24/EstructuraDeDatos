
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h>
#include <stdlib.h>

struct List
{
    int element;
    struct List *next;
    struct List *prev;
};

int insertToNext(struct List **, int);
int insertToPrev(struct List **, int);
int removeElement(struct List **, int);
void show(struct List *);
#endif
