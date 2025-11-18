#include <stdio.h>
#include <stdlib.h>
// #include <windows.h>

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
    } else if(inicio != NULL){
        if(novo->preco < inicio->preco){
            inicio->ant = novo;
            novo->prox = inicio;
            inicio = novo;
        } else if(novo->preco > fim->preco) {
            fim->prox = novo;
            novo->ant = fim;
            fim = novo;
        } else {
            NO *aux = inicio;
            while(aux->preco <= novo->preco) {
                aux = aux->prox;
            }
            novo->prox = aux;
            novo->ant = aux->ant;
            aux->ant->prox = novo;
            aux->ant = novo;
        }
    }
    tam++;
}

void remover(int codigo){
    NO *lixo;
    if(codigo == inicio->codigo){
        lixo = inicio;
        inicio = inicio->prox;
        lixo->prox = NULL;
        inicio->ant = NULL;
        free(lixo);
    }else if(codigo == fim->codigo){
        lixo = fim;
        fim = fim->ant;
        fim->prox = NULL;
        lixo->ant = NULL;
        free(lixo);
    }
    tam--;
}

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
//    SetConsoleCP(CP_UTF8);
//    SetConsoleOutputCP(CP_UTF8);

    add(1, 10, "Parafina", "Descrição");
    add(2, 30, "Deck", "Descrição2");
    add(3, 40, "Quilha", "Descrição3");

    remover(3);

    imprimir();

    return 0;
}
