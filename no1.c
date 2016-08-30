#include <stdio.h>
#include <stdlib.h>

struct no {
int valor;
struct no *prox;
};

void main (void) {
   struct no n;   // isto é suficiente para criar a variável do tipo abstrato.
  n.valor=54;
  n.prox=NULL;   // NULL é uma macro.
  // printf ("%p", n);
  printf ("%d, %p\n", n.valor, n.prox);
}

/*
* no1.c: In function ‘main’:
* no1.c:13:11: warning: format ‘%p’ expects argument of type ‘void *’, but argument 2 has type ‘struct no’ [-Wformat=]
*  printf ("%p", n);
*/
/* Veja como n não é tratado como ponteiro (referência) - o compilador não aceita n como ponteiro. */
 