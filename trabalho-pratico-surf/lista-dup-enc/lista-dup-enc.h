#ifndef LISTA_DUP_ENC_H
#define LISTA_DUP_ENC_H

typedef struct NO{
    int codigo;
    float preco;
    char *tipo;
    char *descricao;
    struct NO *prox;
    struct NO *ant;
}NO;

extern NO *inicio;
extern NO *fim;
extern int tam;

void adicionar_produto(int codigo, float preco, char *tipo, char *descricao);
void imprimir_produtos();
void remover_produto(int codigo);

#endif
