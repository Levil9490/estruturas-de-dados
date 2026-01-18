#ifndef PRODUTOS_H
#define PRODUTOS_H

#include "../pilhas/pilha.h"

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
void remover_produto(int codigo);

#endif
