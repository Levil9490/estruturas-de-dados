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

void adicionar_produto(int codigo, float preco, char *tipo, char *descricao){
    NO *produto = malloc(sizeof(NO));
    produto->codigo = codigo;
    produto->preco = preco;
    produto->tipo = tipo;
    produto->descricao = descricao;
    produto->prox = NULL;
    produto->ant = NULL;

    if(inicio == NULL){
        inicio = produto;
        fim = produto;
    } else {
        if(produto->preco <= inicio->preco){
            inicio->ant = produto;
            produto->prox = inicio;
            inicio = produto;
        } else if(produto->preco > inicio->preco){
            inicio->prox = produto;
            produto->ant = inicio;
            fim = inicio->prox;
        }
    }
    tam++;
}

void imprimir_produtos(){
    NO *aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("Codigo: %d\n", aux->codigo);
        printf("Preco: %.2f\n", aux->preco);
        printf("Tipo: %s\n", aux->tipo);
        printf("Descricao: %s\n", aux->descricao);
        printf("\n");
        aux = aux->prox;
    }
}
