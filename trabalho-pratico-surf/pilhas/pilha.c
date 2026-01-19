#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../fila/fila.h"
#include "pilha.h"

static PILHA *pilha_parafina = NULL;
static PILHA *pilha_leash    = NULL;
static PILHA *pilha_quilha   = NULL;
static PILHA *pilha_deck     = NULL;
static PILHA *estoque[]      = {NULL, NULL, NULL, NULL};

void init_estoque(void) {
    pilha_parafina = criar_pilha("parafina");
    pilha_leash    = criar_pilha("leash");
    pilha_quilha   = criar_pilha("quilha");
    pilha_deck     = criar_pilha("deck");
    estoque[0]     = pilha_parafina;
    estoque[1]     = pilha_leash;
    estoque[2]     = pilha_quilha;
    estoque[3]     = pilha_deck;
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
    if(estoque[0] == NULL) init_estoque();

    TipoProduto tipo = retorna_tipo(tipo_produto);

    for(int i = 0; i < 4; i++) {
        if(estoque[i]->tipo == tipo) {
            add_produto_na_pilha(estoque[i], codigo);
            break;
        }
    }
}

void remover_do_estoque(char *tipo_produto, int codigo){
    TipoProduto tipo = retorna_tipo(tipo_produto);

    for(int i = 0; i < 4; i++) {
        if(estoque[i]->tipo == tipo) {
            remover_produto_da_pilha(estoque[i], codigo);
            break;
        }
    }
}

void add_produto_na_pilha(PILHA *pilha, int codigo) {
    if(pilha->topo != NULL && pilha->topo->tam < pilha->topo->tam_max) {
        add_produto_na_caixa(pilha->topo, codigo);
    } else {
        CAIXA *caixa = adicionar_caixa(pilha);
        add_produto_na_caixa(caixa, codigo);
    }
}

void remover_produto_da_pilha(PILHA *pilha, int codigo){
    if (pilha == NULL || pilha->topo == NULL) {
        printf("Pilha vazia.\n");
        return;
    }

    PILHA *pilha_aux = malloc(sizeof(PILHA));
    if (!pilha_aux) return;
    pilha_aux->tipo = pilha->tipo;
    pilha_aux->tam = 0;
    pilha_aux->topo = NULL;
    bool produto_removido = false;

    while (pilha->topo != NULL) {
        CAIXA *caixa = pilha->topo;

        PRODUTOS *ant = NULL;
        PRODUTOS *atual = caixa->produto_inicio;

        while (atual != NULL) {
            if (atual->codigo == codigo) {
                if (ant == NULL) {
                    caixa->produto_inicio = atual->prox;
                } else {
                    ant->prox = atual->prox;
                }
                if (atual->prox == NULL) {
                    caixa->produto_fim = ant;
                }
                caixa->tam--;
                free(atual);
                produto_removido = true;
                printf("Produto saiu do estoque\n");
                break;
            }
            ant = atual;
            atual = atual->prox;
        }

        if (produto_removido) break;

        pilha->topo = caixa->prox;
        caixa->prox = pilha_aux->topo;
        pilha_aux->topo = caixa;
    }

    while (pilha_aux->topo != NULL) {
        CAIXA *c = pilha_aux->topo;
        pilha_aux->topo = c->prox;
        c->prox = pilha->topo;
        pilha->topo = c;
    }

    free(pilha_aux);

    if (!produto_removido) {
        printf("Produto nao encontrado no estoque.\n");
    }
}

PILHA *criar_pilha(char *tipo) {
    PILHA *nova_pilha = malloc(sizeof(PILHA));
    
    if(!nova_pilha) return NULL;
    
    nova_pilha->topo = NULL;
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
