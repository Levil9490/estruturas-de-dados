#include <stdio.h>
#include <stdlib.h>
#include "caixa.h"

void add_produto_na_caixa(CAIXA *caixa, int codigo){
    PRODUTOS *produto = malloc(sizeof(PRODUTOS));
    
    if(!produto) return NULL;

    produto->codigo = codigo;
    produto->prox = NULL;

    if(caixa->inicio == NULL){
        caixa->inicio = produto;
        caixa->fim = produto;
    }else{
        caixa->fim->prox = produto;
        caixa->fim = produto;
    }
    caixa->tam++;
}

CAIXA *nova_caixa(TipoProduto tipo){
    CAIXA *novalista = malloc(sizeof(PRODUTOS));

    if(!novalista) return NULL;

    novalista->produto_inicio = NULL;
    novalista->produto_fim = NULL;
    novalista->prox = NULL;
    novalista->tam = 0;
    novalista->tam_max = CONFIGS[tipo].capacidade;

    printf("Uma nova caixa foi adicionada.\n");
    return novalista;
}
