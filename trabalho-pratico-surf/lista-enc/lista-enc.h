typedef struct NO_DA_LISTA_ENC{
    int codigo;
    struct NO_DA_LISTA_ENC *prox;
}NO_DA_LISTA_ENC;

typedef struct LISTA_ENC_PRODUT{
    struct NO_DA_LISTA_ENC *inicio;
    struct NO_DA_LISTA_ENC *fim;
    int tam;
}LISTA_ENC_PRODUT;

void add_na_lista_enc(LISTA_ENC_PRODUT *lista, int codigo){
    NO_DA_LISTA_ENC *produto = malloc(sizeof(NO_DA_LISTA_ENC));
    produto->codigo;
    produto->prox = NULL;

    if(lista->inicio == NULL){
        lista->inicio = produto;
        lista->fim = produto;
    }else{
        lista->fim = produto;
        lista->fim = produto;
    }
    tam++;
}

LISTA_ENC_PRODUT *construir_lista(){
    LISTA_ENC_PRODUT *novalista = malloc(sizeof(LISTA_ENC_PRODUT));
    novalista->inicio = NULL;
    novalista->fim = NULL;
    tam = 0;
    return novalista;
}
