#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct estrutura
{
    TIPOCHAVE chave;
    int info;
    struct estrutura *prox;
} NO;

typedef struct
{
    NO* inicio;
} LISTA;

// Inicializacao
void inicializarLista(LISTA *l)
{
    l->inicio = NULL;
}

NO* primeiroElemLista(LISTA *l)
{
    return(l->inicio);
}

NO* ultimoElemLista(LISTA *l)
{
    NO *no;
    no = l->inicio;

    if (no) {
        while (no->prox) {
            no = no->prox;
        }
    }
    return(no);
}

NO* buscaSeqOrd(LISTA l, TIPOCHAVE ch)
{
    NO *no;
    no = l.inicio;
    if (no) {
        while (no->prox && no->chave != ch ) {
            no = no->prox;
        }
    }
    return(no);
}


bool inserirElemListaOrd(LISTA *l, TIPOCHAVE chave)
{
    NO* p = (NO*) malloc(sizeof(NO));
    NO* noTemp;
    NO* anterior;
    if ( l->inicio )
    {
        /*if (tamanhoLista(l) == 1)
        {
            if(chave > l->inicio->chave)
            {
                p->chave = chave;
                p->prox = NULL;
                l->inicio->prox = p;
            }
            else
            {
                noTemp = l->inicio;
                l->inicio = p;
                p->chave = chave;
                p->prox = noTemp;
            }
        }
        else
        {
            noTemp = l->inicio;
            while(noTemp && noTemp->chave < chave)
            {
                anterior = noTemp;
                noTemp = noTemp->prox;
            }
            anterior->prox = p;
            p->prox = noTemp;

        }
        /*
        anterior = l->inicio;
        while(anterior->prox && anterior->chave < chave)
        {
            anterior = anterior->prox;
        }
        anterior->prox
        noTemp = buscaSeqOrd(*l, chave);
        noTemp->prox = p; */

    }
    else
    {
        l->inicio = p;
        p->chave = chave;
        p->prox = NULL;
    }
    return true;
}

void exibirLista(LISTA l)
{
    NO *no;
    no = l.inicio;
    while(no)
    {
        printf("%d ", no->chave);
        no = no->prox;
    }
}
NO* enesimoElemLista(LISTA l, int n)
{
    NO *no;
    NO *anterior;
    no = l.inicio;
    int count = 0;
    if (no) {
        while (no->prox && count <=n ) {
            anterior = no;
            no = no->prox;
            count++;
        }
    }
    return(anterior);
}


int tamanhoLista(LISTA l)
{
    NO *no;
    no = l.inicio;
    int count = 0;
    if (no) {
        count++;
        while (no->prox) {
            no = no->prox;
            count++;
        }
    }
    return(count);
}


/*





void anexarElemLista()
bool excluirElemLista()
void destruirLista()
*/

int main()
{
    LISTA *lista;
    inicializarLista(lista);
    printf("tamanho %d \n", tamanhoLista(*lista));
    inserirElemListaOrd(lista, 3);
    /*inserirElemListaOrd(lista, 2);
    inserirElemListaOrd(lista, 4);
    inserirElemListaOrd(lista, 1);
    exibirLista(*lista);
    printf("\nn = %d \n", enesimoElemLista(*lista,2)->chave );
    printf("\nn = %d \n", enesimoElemLista(*lista,0)->chave );
    printf("tamanho %d \n", tamanhoLista(*lista));
    inserirElemListaOrd(lista, 14);
    inserirElemListaOrd(lista, 52);
    inserirElemListaOrd(lista, 35);
    inserirElemListaOrd(lista, 47);
    printf("tamanho %d \n", tamanhoLista(*lista));
    exibirLista(*lista);*/

    printf("\n");
    return 0;
}