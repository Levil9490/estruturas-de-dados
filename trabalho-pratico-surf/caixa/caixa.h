#ifndef CAIXA_H
#define CAIXA_H

#include "../tipos/tipos.h"

typedef struct PRODUTOS {
    int codigo;
    struct PRODUTOS *prox;
} PRODUTOS;

typedef struct CAIXA {
    struct PRODUTOS *produto_inicio;
    struct PRODUTOS *produto_fim;
    struct CAIXA *prox;
    int tam;
    int tam_max;
} CAIXA;

void add_produto_na_caixa(CAIXA *caixa, int codigo);
CAIXA *nova_caixa(TipoProduto tipo);

#endif
