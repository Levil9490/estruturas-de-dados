#ifndef FILA_H
#define FILA_H

#include "../produtos/produto.h"

typedef struct PEDIDO {
    PRODUTO *produto;
    char *nome_cliente;
    int cpf_cliente;
    int cep_cliente;
    char *rua;
    int numero;
    char *complemento;
    struct PEDIDO *prox;
} PEDIDO;

typedef struct FILA_ENTREGA {
    PEDIDO *primeiro_pedido;
    PEDIDO *ultimo_pedido;
} FILA_ENTREGA;

void adicionar_pedido(PRODUTO *produto, char *nome_cliente, int cpf, int cep, char *rua, int numero, char *complemento);
void concluir_entrega();
FILA_ENTREGA *criar_fila();

#endif
