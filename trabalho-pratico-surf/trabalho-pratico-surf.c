#include<stdio.h>
#include<stdlib.h>

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
    }else{
        if(novo->preco < inicio->preco){
            novo->prox = inicio;
            inicio->ant = novo;
            inicio = novo;
        }
    }

    tam++;
}

/* void remover(int pos){
    
} */

void imprimir(){
    NO * aux = inicio;
    for(int i=0; i<tam; i++){
        printf("Valor = %d\n", aux->valor);
        aux = aux->prox;
    } 
}

int main(){
    add(10, 0);
    add(30, 1);
    add(20, 2);
    add(50, 2);

    //remover no inicio:
    //remover(2);
    imprimir();

return 0;
}
