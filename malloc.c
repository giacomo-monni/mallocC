#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> //libreria per utilizzare le funzioni di allocazione
                    // della Memoria

void BubbleSort(int *array, int nElementi)
{
  int i, tmp, ultimo;
  int alto=nElementi; /* elemN è il numero degli elementi del vettore da ordinare */

  printf("[BUBBLE SORT]\nnElementi=%d\n",nElementi);
  for(i=0;i<nElementi;i++)
    printf("array[%d]%d\n",i+1,array[i]);

  while (alto >= 0) /* in questo modo si evita 1 passaggio*/
  {
    ultimo = -1;
    for (i=0; i<alto-1; i++)
    {
      if (array[i]>array[i+1]) /* sostituire ">" con "<" per avere un ordinamento decrescente */
      {
        tmp = array[i];
        array[i] = array[i+1];
        array[i+1] = tmp;
        ultimo = i;
      }
    }
    alto = ultimo;
  }
  printf("[END BUBBLE SORT]");
}

int main()
{
  //Dichiarazione variabili
  int n, *array, i;
  int bAllocati;
  // int v[10];

  printf("Inserire il numero dei valori nell'array: \n");
  scanf("%d", &n);

  //Allocazione dinamica della memoria per un vettore di interi
  array=(int*)malloc(sizeof(int)*n);
  //vettore=(int*)malloc(sizeof(int)*<numeroElementiVettore>)

  //verifica che i bytes da allocare siano disponibili
  //se non sono disponibili entra nell'IF, invia un messaggio
  //e termina l'esecuzione
  //viceversa non entra
  if(array==NULL)
  {
    printf("Memoria esaurita\n");
    exit(1);
  }

  bAllocati=sizeof(int)*n;  //come risultato darà l'equivalente
                            //di 4*n: 4 sono il numero di byte
                            //che occupa una variabile di tipo
                            //int(32 bit)

  //Inserimento dei valori nell'array
  printf("Inserire i valori nell'array: \n");
  for(i=0;i<n;i++)
    scanf("%d",&array[i]);

  BubbleSort(array, n);
  BubbleSort(array, n);

  // Stampa dei numeri inseriti nell'array
  i=0;
  printf("I numeri dell'array (ordinati) sono: \n");
  while(i<n)
  {
    printf("-%d\n",array[i]);
    i++;
  }

  printf("\n\nNumero elementi %d\n", n);
  printf("Dimensione elemento %d\n", sizeof(int));
  printf("Bytes allocati %d\n", bAllocati);

  free(array); //libera la memoria allocata precedentemente

  return 0;
}

// La funzione malloc viene comunemente utilizzata soprattutto per "conquistare"
// una funzione di memoria. Viene definita con l'istruzione:
//
//      char *malloc(int number_of_bytes)
//
// Questa funzione ritorna un puntatore a carattere che corrisponde al
// punto di inizio in memoria della porzione riservata di dimensione
// "number_of_bytes". Se la memoria richiesta non puo' essere allocata, ritorna
// un puntatore nullo.
// Cosi':
//     char *cp;
//     cp = malloc(100);
// tenta di riservare 100 bytes ed assegna l'indirizzo di inizio a "cp".
//
// Se si vuole avere un puntatore ad un altro tipo di dato, si deve utilizzare
// la coercizione. Inoltre solitamente viene utilizzata la funzione sizeof()
// per specificare il numero di bytes:
//     int *ip;
//     ip = (int *) malloc(100*sizeof(int));
//
// Il comando (int *) simboleggia la coercizione ad un pointer integer. La
// coercizione per correggere il tipo dei puntatori e' molto importante per
// garantire che i puntatori aritmetici vengano rappresentati correttamente.
//
// E' buona norma utilizzare sizeof anche nel caso in cui si sia gia' a
// conoscenza della dimensione reale necessaria; questo garantisce codici
// portabili (device independent).
//
// "sizeof" puo' essere usata per trovare la dimensione di un qualsiasi tipo
// di dato, variabile o struttura; e' possibile farlo semplicemente passando
// uno di questi come argomento alla funzione.
// Cosi':
//     int i;
//     struct COORD {float x,y,z};
//     typedef struct COORD PT;
//
//     sizeof(int), sizeof(i), sizeof(struct COORD) e sizeof(PT)
//
//  sono tutti accettabili.
//
// Nell'esempio che segue possiamo utilizzare il collegamento tra pointer e
// array per trattare la memoria riservata come un array,  per poter cioe'
// fare cose come:
//
//     ip[0] = 100;
//
// oppure:
//
//  for(i=0;i<100;++i)
//    scanf("%d",ip++);
