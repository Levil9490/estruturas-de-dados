#include<stdio.h>
#include<stdlib.h>

typedef struct NO{
    //dados (depende da aplicação)
    int valor;
    //mecanismo de uniao de nos
    struct NO * prox;
}NO;

NO * inicio = NULL;
int tam = 0;

void add(int valor, int pos){

    //passo 1: criar o NO novo!
    NO *novo = malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    //passo 2: onde este NO novo irá ser  colocado na lista?
    if(inicio == NULL){ //lista vazia
        inicio = novo;
        tam++;
    }else{ //lista nao esta vazia - vamos imitar o insert do python!

        if(pos == 0){ // add no inicio!
            novo->prox = inicio;
            inicio = novo;
            tam++;

        }else if(pos == tam){ // add no fim! :D
            NO * aux = inicio;
            //while(aux->prox != NULL){ //outra opção!
            for(int i=0; i<tam -1; i++){
                aux = aux->prox;
            }
            aux->prox = novo;
            tam++;
        }else{ //entre 1 e tam -1 (depois do inicio, antes do fim - "meio")
            
            NO * aux = inicio;
            for(int i=0; i<pos -1; i++){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
            tam++;
    }

}

void remover(int pos){
    if(pos == 0){ //remover do inicio

        NO * lixo = inicio;
        inicio = inicio->prox;
        free(lixo);
        tam--;


    }else if(pos == tam-1){ //fim
        //aqui vc deve percorrer a lista até a penultima posição e remover o ultimo!    

    }else{ //meio - aqui vc deve percorrer a lista até a posição desejada e remover o no!

    }


}



int main(){
    ...
     add(20, 0);
     add(50, 3);

return 0;
}




