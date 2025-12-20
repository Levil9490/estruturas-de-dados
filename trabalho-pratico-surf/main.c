#include <stdio.h>
#include <stdlib.h>
#include "lista-dup-enc.h"

int main(){
    adicionar_produto(10, 20.45, "Quilha", "...");
    adicionar_produto(20, 22.90, "Leash", "...");
    adicionar_produto(30, 10.25, "Sla", "...");
    imprimir_produtos();

    return 0;
}
