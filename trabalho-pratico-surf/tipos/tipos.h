#ifndef TIPOS_H
#define TIPOS_H

typedef enum {
    TIPO_PARAFINA,
    TIPO_LEASH,
    TIPO_QUILHA,
    TIPO_DECK
} TipoProduto;

typedef struct ConfigTipo {
    TipoProduto tipo;
    int capacidade;
    char *nome;
} ConfigTipo;

static const ConfigTipo CONFIGS[] = {
    {TIPO_PARAFINA, 50, "parafina"},
    {TIPO_LEASH,    25, "leash"},
    {TIPO_QUILHA,   10, "quilha"},
    {TIPO_DECK,     5, "deck"}
};

#endif
