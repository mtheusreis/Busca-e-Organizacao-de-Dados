#ifndef LISTA_CABECA_H
#define LISTA_CABECA_H

#include "item.h"

typedef struct lista_cabeca LISTA_CABECA;

LISTA_CABECA *lista_cabeca_criar(void);
void lista_cabeca_liberar(LISTA_CABECA *l);
int lista_cabeca_vazia(LISTA_CABECA *l);
int lista_cabeca_tamanho(LISTA_CABECA *l);
int lista_cabeca_inserir(LISTA_CABECA *l, int posicao, ITEM *item);
ITEM *lista_cabeca_remover(LISTA_CABECA *l, int posicao);
ITEM *lista_cabeca_buscar(LISTA_CABECA *l, int posicao);

#endif