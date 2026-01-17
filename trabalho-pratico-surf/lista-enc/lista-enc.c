#include <stdlib.h>
#include "lista-enc.h"

void add_na_lista_enc(LISTA_ENC_PRODUT *lista, int codigo){
    NO_DA_LISTA_ENC *produto = malloc(sizeof(NO_DA_LISTA_ENC));
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

LISTA_ENC_PRODUT *construir_lista(){
    LISTA_ENC_PRODUT *novalista = malloc(sizeof(LISTA_ENC_PRODUT));
    novalista->inicio = NULL;
    novalista->fim = NULL;
    novalista->tam = 0;
    return novalista;
}
