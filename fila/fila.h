#ifndef FILA_H
#define FILA_H

#include "item.h"

typedef struct fila FILA;

FILA *fila_criar(void);
void fila_liberar(FILA *f);
int fila_vazia(FILA *f);
int fila_inserir(FILA *f, ITEM *item);
ITEM *fila_remover(FILA *f);
ITEM *fila_frente(FILA *f);
int fila_tamanho(FILA *f);

#endif