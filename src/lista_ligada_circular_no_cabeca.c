#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;

} REGISTRO;

typedef struct tempRegistro
{
    REGISTRO reg;
    struct tempRegistro* prox;

} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct
{
    PONT cabeca;
} LISTA;

/* inicializa()
   numeroDeElementos()
   exibir()
   buscar()
   inserir()
   excluir()
   reinicializar()
   */