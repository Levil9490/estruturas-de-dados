#ifndef PILHA_H
#define PILHA_H

#include "../lista-enc/lista-enc.h"

typedef struct PILHA {
    LISTA_ENC_PRODUT *topo;
    int tam;
} PILHA;

extern PILHA *parafina;
extern PILHA *leash;
extern PILHA *quilha;
extern PILHA *deck;

void adicionar_caixa(PILHA *pilha);

#endif
