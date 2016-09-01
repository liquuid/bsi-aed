#include <stdio.h>
#define MAX 50

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX];
    // numero de elementos da lista, um contator simples
    int nroElem;
} LISTA;

// Inicializa lista
void inicializarListaSequencial(LISTA *l)
{
    l->nroElem = 0;
}

// mostra a lista
void exibirLista(LISTA l)
{
    int i;
    for(i=0; i < l.nroElem; i++)
        printf("%d ", l.A[i].chave);
    printf("\n");
}

// retorna o tamanho da lista
int tamanhoLista(LISTA l)
{
        return l.nroElem;
}

// retorna a chave do primeiro elemento da lista
TIPOCHAVE primeiroElem(LISTA l)
{
    return l.nroElem > 0 ? l.A[0].chave : -1;
}


// retorna a chave do ultimo elemento
TIPOCHAVE ultimoElem(LISTA l)
{
    return l.nroElem > 0 ? l.A[l.nroElem-1].chave : -1;
}

// retorna a chave do n-esimo elemento
TIPOCHAVE enesimoElem(LISTA l, int n)
{
    return n <= l.nroElem ? l.A[n-1].chave : -1;
}

// destroi a lista sequencial
void destroiLista(LISTA *l)
{
    l->nroElem = 0;
}

// insere item na posical i

// busca sequencial em lista

// busca sequencial com sentinela

// busca binaria em lista ordenada

// insercao em lista ordenada com sentinela

// excluir item da lista

int main(){

    LISTA *lista;
    REGISTRO reg;
    reg.chave = 3;
    inicializarListaSequencial(lista);
    printf("numero de elementos: %d \n", lista->nroElem);
    lista->A[0] = reg;
    reg.chave = 4;
    lista->A[1] = reg;
    lista->nroElem = 2;

    printf("numero de elementos: %d \n", tamanhoLista(*lista));
    exibirLista(*lista);

    printf("primeiro elemento: %d \n", primeiroElem(*lista));
    printf("ultimo elemento: %d \n", ultimoElem(*lista));
    printf("enesimo elemento: %d \n", enesimoElem(*lista ,1));
    printf("enesimo elemento: %d \n", enesimoElem(*lista ,10));

    return 0;
}