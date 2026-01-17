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

void add_na_lista_enc(PRODUTOS *lista, int codigo);
PRODUTOS *construir_lista();

#endif
