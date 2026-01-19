#include <stdio.h>
#include <stdlib.h>
#include "produtos/produtos.h"
#include "caixa/caixa.h"

int main(){
    // Para simulação
    const char *tipos[4] = {"parafina", "leash", "quilha", "deck"};

    // Adicionar 100 produtos
    for (int i = 1; i <= 100; i++) {
        const char *tipo = tipos[(i - 1) % 4];
        float preco = 10.0f + (float)i;
        adicionar_produto(i, preco, (char *)tipo, "Descricao do produto");
    }

    imprimir_produtos_por_preco(10.0f, 120.0f);
    imprimir_produtos_por_categoria("deck");

    // Compra de 20 produtos
    for (int codigo = 1; codigo <= 20; codigo++) {
        char nome[32];
        snprintf(nome, sizeof(nome), "Cliente%d", codigo);
        criar_pedido(codigo, nome, 100000000 + codigo, 20000000 + codigo, "Rua Exemplo", 100 + codigo, "Sem");
    }

    // Entrega de 10 produtos vendidos
    for (int i = 0; i < 10; i++) {
        concluir_entrega();
    }
    
    return 0;
}
