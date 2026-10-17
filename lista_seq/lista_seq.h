#ifndef LISTA_SEQ_H
#define LISTA_SEQ_H

#include "item.h"

typedef struct lista_seq LISTA_SEQ;

LISTA_SEQ *lista_seq_criar(int capacidade);
void lista_seq_liberar(LISTA_SEQ *l);
int lista_seq_vazia(LISTA_SEQ *l);
int lista_seq_cheia(LISTA_SEQ *l);
int lista_seq_tamanho(LISTA_SEQ *l);
int lista_seq_inserir(LISTA_SEQ *l, int posicao, ITEM *item);
ITEM *lista_seq_remover(LISTA_SEQ *l, int posicao);
ITEM *lista_seq_buscar(LISTA_SEQ *l, int posicao);

#endif