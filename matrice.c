#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int **AllocaMatrice (int r, int c)
{
	int i, j;
  int **matrice;
  int valore;

	matrice=(int**) malloc (r*sizeof (int*));
	for (i=0;i<r; i++)
		matrice [i]=(int*)malloc (c*sizeof(int));

  if (matrice == NULL)
	{
		printf ("Memoria esaurita\r\n");
		exit (1);
	}

	valore = 1;

  for (i=0; i<r; i++)
    for (j=0;j<c; j++)
		{
    	matrice [i][j]=valore;
    	valore++;
		}

  return matrice;
}

void **LiberaMemoria (int **matrice, int r, int c)
{
  int i,j;

  for (i=0;i<r;i++)
		free (matrice[i]);
	free (matrice);

}



int main ()
{
	int **matrice;
	int r, c;
	int i,j;

  printf ("Numero righe della matrice: ");
  scanf ("%d", &r);
	printf ("Numero colonne della matrice: ");
	scanf ("%d", &c);

  matrice = AllocaMatrice (r,c);

  printf ("Valori degli elementi:\n");
  for (i=0;i<r;i++)
  {
   	for (j=0; j<c; j++)
   	  printf ("%6d%c", matrice [i][j], i%10==9 ? ' ':' ');
    printf("\n");
  }

  LiberaMemoria (matrice,r,c);

	return 0;
}
