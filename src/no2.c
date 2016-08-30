/* mostra uso do operador & */

#include <stdio.h>
#include <stdlib.h>

struct no {
int valor;
struct no *prox;
};

void main (void) {
   struct no n1, n2;   // isto é suficiente para criar a variável do tipo abstrato.
  n1.valor=54;
  n1.prox=&n2;   // & é o operador que retorna o ponteiro para a variável.
  n2.valor=62;
  n2.prox=NULL;
  printf ("%d, %p\n", n1.valor, n1.prox);
}

