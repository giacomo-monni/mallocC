//allocazione dinamica di una stringa
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

char *AllocaVettore(int n)
{
  char *array;
  array=malloc(n);
  return array;
}

void *LiberaMemoria(char *array)
{
  free(array);
}

int main()
{
  char *c;
  unsigned int n;
  int bAllocati;
  int i;

  printf("Inserire numero di elementi del vettore: ");
  scanf("%d",&n);

  c=AllocaVettore(n);
  // c=malloc(n);

  if(c==NULL)
  {
    printf("Memoria esaurita\n");
    exit(1);
  }

  bAllocati=sizeof(char)*n;

  printf("Inserire i valori nell'array:\n");
  for(i=0;i<n;i++)
    scanf("%s", &c[i]);

  printf("Gli elementi dell'array sono:\n");
  for(i=0;i<n;i++)
    printf("-%c\n", c[i]);

  printf("\n\nNumero elementi %d\n", n);
  printf("Dimensione elemento %d\n", sizeof(char));
  printf("Bytes allocati %d\n", bAllocati);

  LiberaMemoria(c);

  return 0;
}
