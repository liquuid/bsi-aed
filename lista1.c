/* lista ligada */

#include <stdio.h>
#include <stdlib.h>

struct no {
int valor;
struct no **prox;
};

struct no **c=NULL;

void imprime (struct no **cabeca)  {
    while (*cabeca) {   //  em C o inteiro 0, o ponteiro NULL o caracter '\0' significam FALSO em expressões lógicas e relacionais. Não há tipo boolean.
        printf ("%d,%p\n", (*cabeca)->valor, (*cabeca)->prox);
        cabeca=(*cabeca)->prox;
    }
    puts ("Fim da lista");
}

#if 0
void insere (struct no *cabeca, int valor) {
  struct no *n1= (struct no *) malloc (sizeof (struct no));    // aloca
  n1->valor=valor;
  n1->prox=cabeca;
  cabeca=n1;                     // problema!!
}
#endif

void insere (struct no **cabeca, int valor) {
  struct no *n1= (struct no *) malloc (sizeof (struct no));    // aloca
  n1->valor=valor;
  n1->prox=cabeca;
  //printf("%d %d\n", n1->valor, &cabeca);
  cabeca=&n1;                     // problema resolvido
}

int posicao (struct no *cabeca, int valor) {
   int i=0;
   while (cabeca) {
     if (cabeca->valor==valor) return i;
     i++;
  }
  return -1;
}

/*no *remove (struct no *cabeca, int valor) {  // mesmo problema do insere...
    struct no *ant=NULL, *temp;
    temp=*cabeca;
    while (temp) {
        if (temp->valor==valor) {
             if (ant) {  // nao é o primeiro nó.
                  ant->prox=temp->prox;
                  temp->prox=NULL;
             } else {
                  *cabeca=temp->prox;
             }
             return temp;
        }
        ant=temp;
        temp=temp->prox;
    }
    return temp;
}*/

int main (void) {
    imprime(c);
    insere(c, 24);
/*    insere(c,48);
    insere(c,72);
    insere(c,96);
    imprime (c);
    remove(c,72);
    imprime(c);*/
    imprime(c);
    return 0;
}
