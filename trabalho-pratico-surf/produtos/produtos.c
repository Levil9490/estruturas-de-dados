#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"

PRODUTO *inicio = NULL;
PRODUTO *fim = NULL;
int tam = 0;

void adicionar_produto(int codigo, float preco, char *tipo, char *descricao){
    PRODUTO *produto = malloc(sizeof(PRODUTO));
    produto->codigo = codigo;
    produto->preco = preco;
    produto->tipo = tipo;
    produto->descricao = descricao;
    produto->prox = NULL;
    produto->ant = NULL;

    if(inicio == NULL){
        inicio = produto;
        fim = produto;
    }else{
        if(produto->preco < inicio->preco){
            produto->prox = inicio;
            inicio->ant = produto;
            inicio = produto;
        }else if(produto->preco > fim->preco){
            fim->prox = produto;
            produto->ant = fim;
            fim = produto;
        }else{
            PRODUTO *aux = inicio;
            while(aux->preco <= produto->preco){
                aux = aux->prox;
            }
            produto->prox = aux;
            produto->ant = aux->ant;
            aux->ant->prox = produto;
            aux->ant = produto;
        }
    }
    tam++;
}

void imprimir_produtos(){
    PRODUTO *aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("Codigo: %d\n", aux->codigo);
        printf("Preco: %.2f\n", aux->preco);
        printf("Tipo: %s\n", aux->tipo);
        printf("Descricao: %s\n", aux->descricao);
        printf("\n");
        aux = aux->prox;
    }
}

void remover_produto(int codigo){
    PRODUTO *lixo;
    if(codigo == inicio->codigo){
        lixo = inicio;
        inicio = inicio->prox;
        inicio->ant = NULL;
    }else if(codigo == fim->codigo){
        lixo = fim;
        fim = fim->ant;
        fim->prox = NULL;
    }else{
        lixo = inicio;
        while(lixo->codigo != codigo) lixo = lixo->prox;
        lixo->prox->ant = lixo->ant;
        lixo->ant->prox = lixo->prox;
    }
    free(lixo);
    tam--;
}
