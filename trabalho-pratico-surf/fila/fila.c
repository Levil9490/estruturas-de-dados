#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

FILA_ENTREGA *fila = criar_fila();

void adicionar_pedido(PRODUTO *produto, char *nome_cliente, int cpf, int cep, char *rua, int numero, char *complemento) {
    PEDIDO *novo_pedido = malloc(sizeof(PEDIDO));
    novo_pedido->produto = produto;
    novo_pedido->nome_cliente = nome_cliente;
    novo_pedido->cpf_cliente = cpf;
    novo_pedido->cep_cliente = cep;
    novo_pedido->rua = rua;
    novo_pedido->numero = numero;
    novo_pedido->complemento = complemento;
    novo_pedido->prox = NULL;

    if(fila->primeiro_pedido == NULL && fila->ultimo_pedido == NULL) {
        fila->primeiro_pedido == novo_pedido;
        fila->ultimo_pedido == novo_pedido;
    } else {
        fila->ultimo_pedido->prox = novo_pedido;
        fila->ultimo_pedido = novo_pedido;
    }
}

void concluir_venda() {
    if(fila->primeiro_pedido == NULL && fila->ultimo_pedido == NULL) {
        printf("Fila de entrega vazia.\n");
    }else{
        if(fila->primeiro_pedido->prox != NULL) {
            PEDIDO *aux = fila->primeiro_pedido;
            fila->primeiro_pedido = fila->primeiro_pedido->prox;
            free(aux->produto);
            free(aux);
            printf("Entrega do primeiro pedido da fila realizada!\n");
        }else{
            free(fila->primeiro_pedido->produto);
            free(fila->primeiro_pedido);
            printf("Entrega realizada com sucesso, a fila agora está vazia.\n");
        }
    }
}

FILA_ENTREGA *criar_fila() {
    FILA_ENTREGA *fila = malloc(sizeof(FILA_ENTREGA));

    if(!fila) return NULL;

    fila->primeiro_pedido = NULL;
    fila->ultimo_pedido = NULL;

    return fila;
}
