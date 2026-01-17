#include <stdio.h>
#include <stdlib.h>
#include "lista-dup-enc.h"
#include "lista-enc.h"

int main(){
/*    adicionar_produto(10, 20.45, "Quilha", "...");
    adicionar_produto(20, 22.90, "Leash", "...");
    adicionar_produto(30, 10.25, "Outro Leash", "...");
    adicionar_produto(40, 100.99, "Prancha", "Nao sei quanto custa uma");
    adicionar_produto(50, 15.69, "Outra quilha", "O que é quilha?");
    remover_produto(20);
    remover_produto(50);
    imprimir_produtos();
*/
    LISTA_ENC_PRODUT *lista = construir_lista();
    add_na_lista_enc(lista, 1234);

    return 0;
}
