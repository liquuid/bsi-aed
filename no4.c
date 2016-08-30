/* alocação dinâmica: não alocação: */

#include <stdio.h>
#include <stdlib.h>

struct no {
int valor;
struct no *prox;
};

void main (void) {
  struct no *n1, *n2;   // isto cria dois ponteiros que armazenarão endereços de estruturas do tipo no.
/* o operador * tem três interpreteções: na declaração de uma variável indica que esta é um ponteiro, 
no acesso a um ponteiro indica que o que deve ser acessado é aquilo para o que o ponteiro aponta
na aritmética, indica multiplicação.
*/
  n1->valor=54;             // isto corrompe a memória pois não foi alocada memória para armazenar os dados.
  n1->prox=NULL;      // isto também corrompe a memória.
  printf ("%d\n",n1->valor); // imprime conteúdo da memória que não foi alocada.

}

/* produziu este resultado (mas poderia produzir outros, ou até executar corretamente....)
fabio@fabio-PORTEGE-M400:~/c$ gcc no4.c
fabio@fabio-PORTEGE-M400:~/c$ ./a.out
Segmentation fault (core dumped)
fabio@fabio-PORTEGE-M400:~/c$ 
*/