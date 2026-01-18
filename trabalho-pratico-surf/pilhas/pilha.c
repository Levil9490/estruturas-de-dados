#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

static PILHA *pilha_parafina = criar_pilha("parafina");
static PILHA *pilha_leash    = criar_pilha("leash");
static PILHA *pilha_quilha   = criar_pilha("quilha");
static PILHA *pilha_deck     = criar_pilha("deck");
static PILHA *estoque[]      = {
    pilha_parafina,
    pilha_leash,
    pilha_quilha,
    pilha_deck
}

CAIXA *adicionar_caixa(PILHA *pilha) {
    CAIXA *caixa = nova_caixa(pilha->tipo);

    if(pilha->topo == NULL) {
        pilha->topo = caixa;
    } else {
        caixa->prox = pilha->topo;
        pilha->topo = caixa;
    }
    pilha->tam += 1;

    return pilha->topo;
}

void alocar_no_estoque(char *tipo_produto, int codigo) {
    TipoProduto tipo = retorna_tipo(tipo_produto);

    for(int i = 0; i < 4; i++) {
        if(estoque[i]->tipo == tipo) {
            add_produto_na_pilha(estoque[i], codigo);
        }
    }
}

void add_produto_na_pilha(PILHA *pilha, int codigo) {
    if(pilha->topo->tam < pilha->topo->tam_max) {
        add_produto_na_caixa(pilha->topo, codigo);
    } else {
        CAIXA *caixa = adicionar_caixa(pilha);
        add_produto_na_caixa(caixa, codigo);
    }
}

PILHA *criar_pilha(char *tipo) {
    PILHA *nova_pilha = malloc(sizeof(PILHA));
    
    if(!nova_pilha) return NULL;

    nova_pilha->tam = 0;
    nova_pilha->tipo = retorna_tipo(tipo);
    
    return nova_pilha;
}

TipoProduto retorna_tipo(char *tipo) {
    if(strcmp(tipo, "parafina") == 0) return TIPO_PARAFINA;
    else if(strcmp(tipo, "leash") == 0) return TIPO_LEASH;
    else if(strcmp(tipo, "quilha") == 0) return TIPO_QUILHA;
    else if(strcmp(tipo, "deck") == 0) return TIPO_DECK;
}
