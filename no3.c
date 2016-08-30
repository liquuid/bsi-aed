/* mostra uso dos operadores * e -> */

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
  printf ("%d\n",( *( n1.prox)).valor); // n1.prox é o ponteiro armazenado em n1 que aponta para n2. *(n1.prox) é n2 de onde recuperamos o atributo valor.
  printf ("%d\n", n1.prox->valor); // n1.prox é o ponteiro armazenado em n1 que aponta para n2 (não é n2). O operador -> recupera o atributo valor daquilo que é apontado pelo ponteiro.

}

