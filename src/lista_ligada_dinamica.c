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


NO* buscaSeqOrd(LISTA *l, TIPOCHAVE ch, NO* *ant){
    *ant = NULL;
    NO* atual = l->inicio;
    while ((atual != NULL) && (atual->chave < ch)){
        *ant = atual;
        atual = atual->prox;
    }
}

bool inserirElemListaOrd(LISTA *l, TIPOCHAVE chave)
{
    NO* p = (NO*) malloc(sizeof(NO));
    NO* noTemp = (NO*) malloc(sizeof(NO));
    NO* anterior = (NO*) malloc(sizeof(NO));
    NO* atual = (NO*) malloc(sizeof(NO));

    p->chave = 0;
    p->info = 0;
    p->prox = NULL;

    noTemp->chave = 0;
    noTemp->info = 0;
    noTemp->prox = NULL;

    anterior->chave = 0;
    anterior->info = 0;
    anterior->prox = NULL;

    atual->chave = 0;
    atual->info = 0;
    atual->prox = NULL;

    if ( l->inicio )
    {
        if(tamanhoLista(*l) > 1){
            buscaSeqOrd(l, chave, &anterior);
            p->chave = chave;
            p->prox = NULL;
            if(anterior) {
                p->prox = anterior->prox ;
                anterior->prox = p;
            } else {
                p->prox = l->inicio;
                l->inicio = p;
            }

        } else {
            if ( l->inicio->chave > chave ){
                p->chave = chave;
                p->prox = l->inicio;
                l->inicio = p;

            } else {
                l->inicio->prox = p;
                p->chave = chave;
                p->prox = NULL;
            }
        }
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

bool excluirElemLista(LISTA *l, TIPOCHAVE ch){
    NO *i;
    NO *ant;
    buscaSeqOrd(l,ch,&ant);
    if (ant) {
        i = ant->prox;
        if (ant->prox->prox) {
          ant->prox = ant->prox->prox;

        } else {
            ant->prox = NULL;
        }
    } else {
        i = l->inicio;
        if(l->inicio->prox)
            l->inicio = l->inicio->prox;
        else
            l->inicio = NULL;

    }
    free(i);
    return true;
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
    inserirElemListaOrd(lista, 2);
    inserirElemListaOrd(lista, 4);
    inserirElemListaOrd(lista, 1);
    inserirElemListaOrd(lista, 50);
    inserirElemListaOrd(lista, 81);
    inserirElemListaOrd(lista, 5);
    inserirElemListaOrd(lista, 1);
    exibirLista(*lista);
    printf("n = %d \n", enesimoElemLista(*lista,2)->chave );
    printf("n = %d \n", enesimoElemLista(*lista,0)->chave );

    inserirElemListaOrd(lista, 14);
    inserirElemListaOrd(lista, 52);
    inserirElemListaOrd(lista, 35);
    inserirElemListaOrd(lista, 47);

    exibirLista(*lista);
    printf("\ntamanho: %d \n", tamanhoLista(*lista));

    excluirElemLista(lista, 1);
    excluirElemLista(lista, 50);
    excluirElemLista(lista, 81);

    exibirLista(*lista);


    printf("\n");
    printf("tamanho: %d \n", tamanhoLista(*lista));
    return 0;
}