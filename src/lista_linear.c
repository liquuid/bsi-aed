#define MAX 50

typedef int TIPOCHAVE;

typedef struct
{
    REGISTRO A[MAX];
    // numero de elementos da lista, um contator simples
    int nroElem;
} LISTA;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

// Inicializa lista
void inicializarListaSequencial(LISTA l)
{
    l->nroElem = 0;
}

// mostra a lista
void exibirLista(LISTA l)
{
    int i;
    for(i=0; i < l.nroElem; i++)
        printf("%d ", l.A[i].chave);
}


