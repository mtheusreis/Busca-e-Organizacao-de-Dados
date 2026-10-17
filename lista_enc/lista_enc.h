#ifndef LISTA_ENC_H
#define LISTA_ENC_H

#include "item.h"

typedef struct lista_enc LISTA_ENC;

LISTA_ENC *lista_enc_criar(void);
void lista_enc_liberar(LISTA_ENC *l);
int lista_enc_vazia(LISTA_ENC *l);
int lista_enc_tamanho(LISTA_ENC *l);
int lista_enc_inserir(LISTA_ENC *l, int posicao, ITEM *item);
ITEM *lista_enc_remover(LISTA_ENC *l, int posicao);
ITEM *lista_enc_buscar(LISTA_ENC *l, int posicao);

#endif