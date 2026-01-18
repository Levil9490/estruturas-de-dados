#ifndef PRODUTOS_H
#define PRODUTOS_H

#include "../pilhas/pilha.h"
#include "../fila/fila.h"

typedef struct PRODUTO{
    int codigo;
    float preco;
    char *tipo;
    char *descricao;
    struct PRODUTO *prox;
    struct PRODUTO *ant;
}PRODUTO;

extern PRODUTO *inicio;
extern PRODUTO *fim;
extern int tam;

void adicionar_produto(int codigo, float preco, char *tipo, char *descricao);
void imprimir_produtos();
void imprimir_produtos_por_categoria(char *categoria);
void imprimir_produtos_por_preco(float min, float max);
void criar_pedido(int codigo, char *nome_cliente, int cpf, int cep, char *rua, int numero, char *complemento);

#endif
