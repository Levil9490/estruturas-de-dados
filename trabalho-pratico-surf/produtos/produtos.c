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
    alocar_no_estoque(tipo, codigo);
    tam++;
}

void imprimir_produtos(){
    printf("Visualizar todos os produtos:\n\n");
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

void imprimir_produtos_por_categoria(char *categoria) {
    printf("Visualizar produtos da categoria %s\n\n", categoria);
    produto *aux = inicio;
    for(int i = 0; i < tam; i++){
        if(strcmp(aux->tipo, categoria) == 0) {
            printf("codigo: %d\n", aux->codigo);
            printf("preco: %.2f\n", aux->preco);
            printf("tipo: %s\n", aux->tipo);
            printf("descricao: %s\n", aux->descricao);
            printf("\n");
        }
        aux = aux->prox;
    }
}

void imprimir_produtos_por_preco(float min, float max) {
    printf("Visualizar produtos no intervalo %.2f-%.2f\n\n", min, max)
    produto *aux = inicio;
    for(int i = 0; i < tam; i++){
        if(aux->preco >= min && aux->preco <= max) {
            printf("codigo: %d\n", aux->codigo);
            printf("preco: %.2f\n", aux->preco);
            printf("tipo: %s\n", aux->tipo);
            printf("descricao: %s\n", aux->descricao);
            printf("\n");
        }
        aux = aux->prox;
    }
}

void criar_pedido(int codigo, char *nome_cliente, int cpf, int cep, char *rua, int numero, char *complemento){
    PRODUTO *produto = NULL;
    if(codigo == inicio->codigo){
        produto = inicio;
        inicio = inicio->prox;
        inicio->ant = NULL;
    }else if(codigo == fim->codigo){
        produto = fim;
        fim = fim->ant;
        fim->prox = NULL;
    }else{
        produto = inicio;
        while(produto->codigo != codigo) produto = produto->prox;
        produto->prox->ant = produto->ant;
        produto->ant->prox = produto->prox;
    }

    // Chamar função pra remover do estoque aqui

    adicionar_pedido(produto, nome_cliente, cpf, cep, rua, numero, complemento);
    tam--;
}
