#ifndef LISTA_ENC_H
#define LISTA_ENC_H

typedef struct NO_DA_LISTA_ENC{
    int codigo;
    struct NO_DA_LISTA_ENC *prox;
}NO_DA_LISTA_ENC;

typedef struct LISTA_ENC_PRODUT{
    struct NO_DA_LISTA_ENC *inicio;
    struct NO_DA_LISTA_ENC *fim;
    int tam;
}LISTA_ENC_PRODUT;

void add_na_lista_enc(LISTA_ENC_PRODUT *lista, int codigo);
LISTA_ENC_PRODUT *construir_lista();

#endif
