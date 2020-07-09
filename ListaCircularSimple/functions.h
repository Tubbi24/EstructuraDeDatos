
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h>
#include <stdlib.h>

struct List
{
  int element;
  struct List *next;
};

int insert(int);
int removeElement(int);
void show();
#endif
