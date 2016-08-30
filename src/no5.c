/* alocação dinâmica: malloc */

#include <stdio.h>
#include <stdlib.h>

struct no {
int valor;
struct no *prox;
};

void main (void) {
  struct no *n1, *n2;   // isto cria dois ponteiros que armazenarão endereços de estruturas do tipo no.
  n1= (struct no *) malloc (sizeof (struct no));    // aloca


  n1->valor=54;
  n1->prox=NULL;
  printf ("%d\n",n1->valor); // imprime conteúdo da memória que não foi alocada.
  printf ("%d\n",n1->prox); // devia dar pau imediatamente, mas nem sempre dá pau e geralmente demora algumas operações para dar.
  free (n1);   // desaloca
}

