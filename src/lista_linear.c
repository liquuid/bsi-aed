#include <stdio.h>
#include <stdbool.h>

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
bool inserirElemListaSeq(TIPOCHAVE ch, int pos, LISTA *l ){
    if ( pos < l->nroElem - 1 && pos < MAX){
        l->A[pos].chave = ch;
        return(true);
    }
    return(false);
}

// busca sequencial em lista
int buscaSequencial(TIPOCHAVE ch, LISTA l){
    for (int i=0; i < l.nroElem ; i++){
        if (l.A[i].chave == ch)
            return(i);
    }
    return(-1);
}


// busca sequencial com sentinela
int buscaSequencialSent(TIPOCHAVE ch, LISTA l){
    int i = 0;
    l.A[l.nroElem].chave = ch; // sentinela
    while (l.A[i].chave < ch){
        i++;
    }
    if ((i > (l.nroElem -1)) || (l.A[i].chave != ch )){
        return(-1); // nao achou
    } else {
        return(i);
    }
}

// busca binaria em lista ordenada
int buscaBin(TIPOCHAVE ch, LISTA l){
    int inf, sup, meio;
    inf = 0;
    sup = l.nroElem - 1;
    while (inf <= sup)
    {
        meio = ((inf + sup) / 2);
        if(l.A[meio].chave == ch)
            return(meio); // achou
        else{
            if(l.A[meio].chave < ch)
                inf = meio + 1;
            else
                sup = meio - 1;
        }
    }
    return(-1);
}

// insercao em lista ordenada com sentinela
bool inserirElemListaOrd(TIPOCHAVE ch, LISTA *l){
    int i = 0;
    if (l->nroElem >= MAX)
        return(false); // lista cheia
    l->A[l->nroElem].chave = ch; // sentinela
    while(l->A[i].chave < ch )
        i++;
    if((l->A[i].chave == ch) && (i < l->nroElem))
        return(false);
    else {
        l->nroElem++;
        return (inserirElemListaSeq(ch, i, l));
    }
}

// excluir item da lista
bool excluirElemLista(TIPOCHAVE ch, LISTA *l)
{
    int pos, j;
    pos = buscaSequencialSent(ch, *l);
    if(pos == -1)
        return(false); // nao existe
    for(j=pos; j < l->nroElem - 1; j++)
        l->A[j] = l->A[j+1];
    l->nroElem--;
    return(true);
}


int main(){

    LISTA *lista;
    REGISTRO reg;
    reg.chave = 2;
    inicializarListaSequencial(lista);
    printf("numero de elementos: %d \n", lista->nroElem);
    lista->A[0] = reg;
    reg.chave = 5;
    lista->A[1] = reg;
    lista->nroElem = 2;

    printf("numero de elementos: %d \n", tamanhoLista(*lista));
    exibirLista(*lista);

    printf("primeiro elemento: %d \n", primeiroElem(*lista));
    printf("ultimo elemento: %d \n", ultimoElem(*lista));
    printf("enesimo elemento: %d \n", enesimoElem(*lista ,1));
    printf("enesimo elemento: %d \n", enesimoElem(*lista ,10));

    reg.chave = 53;
    lista->A[2] = reg;
    lista->nroElem = 3;

    printf("Colocando mais um item\n");
    exibirLista(*lista);
    inserirElemListaSeq(6,1,lista);
    exibirLista(*lista);
    //destroiLista(lista);
    //exibirLista(*lista);
    printf("buscando chave 2: %d\n", buscaSequencial(2,*lista));
    printf("buscando chave 6: %d\n", buscaSequencial(6,*lista));
    printf("buscando chave 53: %d\n", buscaSequencial(53,*lista));

    printf("buscando chave 2 com sentinela: %d\n", buscaSequencialSent(2,*lista));
    printf("buscando chave 6 com sentinela: %d\n", buscaSequencialSent(6,*lista));
    printf("buscando chave 53 com sentinela: %d\n", buscaSequencialSent(53,*lista));

    printf("buscando chave 2 bin: %d\n", buscaBin(2,*lista));
    printf("buscando chave 6 bin: %d\n", buscaBin(6,*lista));
    printf("buscando chave 53 bin: %d\n", buscaBin(53,*lista));

    reg.chave = 16;
    inserirElemListaOrd(reg.chave, lista);
    reg.chave = 45;
    inserirElemListaOrd(reg.chave, lista);
    reg.chave = 78;
    inserirElemListaOrd(reg.chave, lista);
    reg.chave = 89;
    inserirElemListaOrd(reg.chave, lista);
    exibirLista(*lista);
    excluirElemLista(45, lista);
    exibirLista(*lista);
    excluirElemLista(16, lista);
    exibirLista(*lista);
    return 0;
}