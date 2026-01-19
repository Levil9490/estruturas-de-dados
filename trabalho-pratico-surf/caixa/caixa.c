#include <stdio.h>
#include <stdlib.h>
#include "caixa.h"

void add_produto_na_caixa(CAIXA *caixa, int codigo){
    PRODUTOS *produto = malloc(sizeof(PRODUTOS));

    produto->codigo = codigo;
    produto->prox = NULL;

    if(caixa->produto_inicio == NULL){
        caixa->produto_inicio = produto;
        caixa->produto_fim = produto;
    }else{
        caixa->produto_fim->prox = produto;
        caixa->produto_fim = produto;
    }
    caixa->tam++;
}

CAIXA *nova_caixa(TipoProduto tipo){
    CAIXA *novalista = malloc(sizeof(CAIXA));

    if(!novalista) return NULL;

    novalista->produto_inicio = NULL;
    novalista->produto_fim = NULL;
    novalista->prox = NULL;
    novalista->tam = 0;
    novalista->tam_max = CONFIGS[tipo].capacidade;

    printf("Uma nova caixa foi adicionada.\n");
    return novalista;
}
