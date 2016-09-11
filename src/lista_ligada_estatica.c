#include <stdio.h>
#include <stdbool.h>

#define MAX 50

typedef int TIPOCHAVE;


typedef struct
{
    TIPOCHAVE chave;
    int prox;
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX];
    int inicio;
    int dispo;
} LISTA;

// inicializacao
void inicializarListaLigadaEstatica(LISTA *l)
{
    l->inicio = -1;
    l->dispo = 0;
    for(int i = 0; i < MAX ; i++)
    {
        l->A[i].prox = i + 1;
    }
    l->A[MAX - 1].prox = - 1;
}

// exibir lista
void exibirLista(LISTA l)
{
    int i = l.inicio;
    while ( i > -1 ){
        printf("%d ", l.A[i].chave); // TIPOCHAVE deve ser int
        i = l.A[i].prox;
    }
}

// Busca sequencial
int buscaSeqOrd(TIPOCHAVE ch, LISTA l, int *ant)
{
    int i = l.inicio;
    *ant = -1;
    while (i != -1){
        if(l.A[i].chave >= ch)
            break;
        *ant = i;
        i = l.A[i].prox;
    }
    if ((i != - 1) && (l.A[i].chave == ch ))
        return i;
    else
        return (-1);

}

// obter no disponivel

int obterNo(LISTA *l)
{
    int result = l->dispo;
    if(l->dispo > - 1)
    {
        l->dispo = l->A[l->dispo].prox;
    }
    return(result);
}
// devolver no p/ dispo
void devolverNo(LISTA *l, int j)
{
    l->A[j].prox = l ->dispo;
    l->dispo = j;
}

// Exclusao do elemento de chave indicado
bool excluirElemListaEnc(TIPOCHAVE ch, LISTA *l)
{
    int ant, i;
    i = buscaSeqOrd(ch, *l, &ant);
    if(i < 0)
        return(false);
    if(ant == -1)
        l->inicio = l->A[i].prox;
    else
        l->A[ant].prox = l->A[i].prox;
    devolverNo(l, i);

    return(true);
}

// inserção em lista ordenada sem duplicação
bool inserirElemListaEncOrd(TIPOCHAVE ch, LISTA *l)
{
    int ant, i;
    i = buscaSeqOrd(ch, *l, &ant);
    if((l->dispo < 0) || (i != -1))
        return(false);
    i = obterNo(l);
    l->A[i].chave = ch;
    if(l->inicio < 0)
    {
        // insercao do primeiro elemento de lista vazia
        l->inicio = i;
        l->A[i].prox = -1;
    }
    else
    {
        if(ant < 0)
        {
            // insercao no inicio de lista ja existente
            l->A[i].prox = l->inicio;
            l->inicio = i;
        }
        else
        {
            // insercao entre dois elementos
            l->A[i].prox = l->A[ant].prox;
            l->A[ant].prox = i;
        }

    }
    return(true);
}

int main()
{
    LISTA *lista;
    REGISTRO reg;
    inicializarListaLigadaEstatica(lista);
    /*reg.chave = 1;
    lista->A[0] = reg;
    lista->inicio = 0;
    lista->dispo = 49;
    reg.chave = 4;
    lista->A[1] = reg;
    lista->inicio = 0;
    lista->dispo = 48;*/
    inserirElemListaEncOrd(3, lista);
    inserirElemListaEncOrd(355, lista);
    inserirElemListaEncOrd(32, lista);
    exibirLista(*lista);
    return 0;
}