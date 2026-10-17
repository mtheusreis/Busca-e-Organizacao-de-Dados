#ifndef LISTA_ORD_H
#define LISTA_ORD_H

#include "item.h"

typedef struct lista_ord LISTA_ORD;

LISTA_ORD *lista_ord_criar(void);
void lista_ord_liberar(LISTA_ORD *l);
int lista_ord_vazia(LISTA_ORD *l);
int lista_ord_tamanho(LISTA_ORD *l);
int lista_ord_inserir(LISTA_ORD *l, ITEM *item);
ITEM *lista_ord_remover(LISTA_ORD *l, int posicao);
ITEM *lista_ord_buscar(LISTA_ORD *l, int posicao);

#endif