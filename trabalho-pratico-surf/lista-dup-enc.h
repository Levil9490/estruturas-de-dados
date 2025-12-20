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
            NO *aux = inicio;
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

void remover_produto(int codigo){
    NO *lixo = inicio;
    while(lixo->prox != NULL){
        if(lixo->codigo == codigo){
            if(lixo == inicio){
                inicio = inicio->prox;
                lixo->prox->ant = NULL;
            } else if(lixo == fim){
                fim = fim->ant;
                lixo->ant->prox = NULL;
            }else{
                lixo->ant->prox = lixo->prox;
                lixo->prox->ant = lixo->ant;
            }
        }
        lixo = lixo->prox;
    }
    free(lixo);
    tam--;
}
