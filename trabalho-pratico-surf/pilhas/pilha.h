#ifndef PILHA_H
#define PILHA_H

#include "../tipos/tipos.h"
#include "../caixa/caixa.h"

typedef struct PILHA {
    TipoProduto tipo;
    CAIXA *topo;
    int tam;
} PILHA;

CAIXA *adicionar_caixa(PILHA *pilha);
void alocar_no_estoque(char *tipo_produto, int codigo);
void add_produto_na_pilha(PILHA *pilha, int codigo);
PILHA *criar_pilha(char *tipo);
TipoProduto retorna_tipo(char *tipo);

#endif
