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
    }/*else if(inicio != NULL){
        if(novo->preco >= inicio->preco){
            inicio->prox = novo;
            novo->ant = inicio;
            fim = novo;
        }else{
            inicio->ant = novo;
            novo->prox = inicio;
            inicio = novo;
        }
    }*/else{
        NO *aux = inicio;
        for(int i = 0; i < tam; i++){
            if(novo->preco <= aux->preco){
                novo->prox = aux;
                novo->ant = aux->ant;
            }else{
                aux->prox = novo;
                novo->ant = aux;
            }
            aux = aux->prox;
        }
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
    add(1, 30, "Parafina", "Descrição");
    add(2, 10, "Deck", "Descrição2");
    add(3, 40, "Quilha", "Descrição3");

    //remover no inicio:
    //remover(2);
    imprimir();

    return 0;
}