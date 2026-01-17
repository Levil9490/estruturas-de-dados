#ifndef CAIXA_H
#define CAIXA_H

typedef struct CAIXA{
    int codigo;
    struct CAIXA *prox;
}CAIXA;

typedef struct PRODUTOS{
    struct CAIXA *inicio;
    struct CAIXA *fim;
    int tam;
}PRODUTOS;

void add_produto_na_caixa(PRODUTOS *lista, int codigo);
PRODUTOS *nova_caixa();

#endif
