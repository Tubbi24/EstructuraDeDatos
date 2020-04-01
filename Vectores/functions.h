
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h>
#include <stdlib.h>

struct Vector
{
    int capacity;
    int total;
    int *elements;
};

void init(struct Vector **);
int insert(struct Vector **, int);
int isFull(struct Vector **);
int enlarge(struct Vector **);
void show(struct Vector **);
#endif
