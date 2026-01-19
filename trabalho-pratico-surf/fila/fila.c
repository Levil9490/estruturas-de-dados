#include <stdio.h>
#include <stdlib.h>
#include "../produtos/produtos.h"
#include "fila.h"

FILA_ENTREGA *fila = NULL;

void adicionar_pedido(PRODUTO *produto, char *nome_cliente, int cpf, int cep, char *rua, int numero, char *complemento) {
    if (fila == NULL) {
        fila = criar_fila();
        if (fila == NULL) return;
    }
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
        fila->primeiro_pedido = novo_pedido;
        fila->ultimo_pedido = novo_pedido;
    } else {
        fila->ultimo_pedido->prox = novo_pedido;
        fila->ultimo_pedido = novo_pedido;
    }
}

void concluir_entrega() {
    if(fila->primeiro_pedido == NULL && fila->ultimo_pedido == NULL) {
        printf("Fila de entrega vazia.\n");
    }else{
        PEDIDO *aux = NULL;
        if(fila->primeiro_pedido->prox != NULL) {
            aux = fila->primeiro_pedido;
            fila->primeiro_pedido = fila->primeiro_pedido->prox;
        } else {
            aux = fila->primeiro_pedido;
            fila->primeiro_pedido = NULL;
            fila->ultimo_pedido = NULL;
        }

        printf("Pedido saindo para entrega...\n");
        printf("Produto: %d - %s\n", aux->produto->codigo, aux->produto->descricao);
        printf("Cliente: %s, CPF: %d\n", aux->nome_cliente, aux->cpf_cliente);
        printf("Endereço: %s %d, %d\n\n", aux->rua, aux->numero, aux->cep_cliente);
        free(aux->produto);
        free(aux);
    }
}

FILA_ENTREGA *criar_fila() {
    FILA_ENTREGA *fila = malloc(sizeof(FILA_ENTREGA));

    if(!fila) return NULL;

    fila->primeiro_pedido = NULL;
    fila->ultimo_pedido = NULL;

    return fila;
}
