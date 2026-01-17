#include <stdlib.h>
#include "caixa.h"

void add_produto_na_caixa(PRODUTOS *lista, int codigo){
    CAIXA *produto = malloc(sizeof(CAIXA));
    produto->codigo = codigo;
    produto->prox = NULL;

    if(lista->inicio == NULL){
        lista->inicio = produto;
        lista->fim = produto;
    }else{
        lista->fim->prox = produto;
        lista->fim = produto;
    }
    lista->tam++;
}

PRODUTOS *nova_caixa(){
    PRODUTOS *novalista = malloc(sizeof(PRODUTOS));
    novalista->inicio = NULL;
    novalista->fim = NULL;
    novalista->tam = 0;
    return novalista;
}
