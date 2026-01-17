#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

PILHA *parafina = NULL;
PILHA *leash    = NULL;
PILHA *quilha   = NULL;
PILHA *deck     = NULL;

void adicionar_caixa(PILHA *pilha) {
    if(pilha == NULL) {
        pilha->tam = 1;

        // Lógica de criar caixa puxando do lista_enc.h
        // pilha->topo = ;
    }
}
