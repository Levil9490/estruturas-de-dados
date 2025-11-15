#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int codigo;
    float preco;
    char *tipo;
    char *descricao;

    struct NO *prox;
    struct NO *ant;
}NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;

void add(int codigo, float preco, char *tipo, char *descricao){
    NO *novo = malloc(sizeof(NO));

    novo->codigo = codigo;
    novo->preco = preco;
    novo->tipo = tipo;
    novo->descricao = descricao;

    novo->prox = NULL;
    novo->ant = NULL;

    if(inicio == NULL){
        inicio = novo;
        fim = novo;
    }

    tam++;
}

/* void remover(int pos){
    
} */

void imprimir(){
    NO *aux = inicio;
    for(int i=0; i<tam; i++){
        printf("Código = %d\n", aux->codigo);
        printf("Valor = %.2f\n", aux->preco);
        printf("Tipo = %s\n", aux->tipo);
        printf("Descrição = %s\n\n", aux->descricao);
        aux = aux->prox;
    }
}

int main(){
    add(1, 10, "Parafina", "Descrição");

    //remover no inicio:
    //remover(2);
    imprimir();

    return 0;
}
