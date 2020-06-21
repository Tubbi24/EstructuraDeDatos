#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main(void)
{
  int contador = 0;
  int i = 0;
  struct Vector *vector = NULL;

  printf("Ingresa el numero de elementos: ");

  scanf("%d", &contador);

  for (i = 0; i <= contador; i++)
  {
    if (insertar(&vector, i) == 0)
    {
      printf("No ha sido posible insertar el elemento: %d\n", i);

      break;
    }
    mostrar(&vector);
  }

  if (buscar(&vector, 1) == 0)
  {
    printf("No se ha encontrado el elemento : %d\n", 1);
  }
  else
  {
    printf("Se ha encontrado el elemento : %d\n", 1);
  }

  if (buscar(&vector, 6) == 0)
  {
    printf("No se ha encontrado el elemento : %d\n", 6);
  }
  else
  {
    printf("Se ha encontrado el elemento : %d\n", 6);
  }

  if (eliminar(&vector, 1) == 0)
  {
    printf("No se ha eliminado el elemento : %d\n", 1);
  }
  else
  {
    printf("Se ha eliminado el elemento : %d\n", 1);
  }

  if (eliminar(&vector, 6) == 0)
  {
    printf("No se ha eliminado el elemento : %d\n", 6);
  }
  else
  {
    printf("Se ha eliminado el elemento : %d\n", 6);
  }
  mostrar(&vector);

  return 0;
}